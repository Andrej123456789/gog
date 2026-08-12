/**
 * @author Andrej Bartulin
 * PROJECT: gog
 * LICENSE: GPL-2.0 license
 * DESCRIPTION: Entry point | Main file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>
#include <time.h>

#include "gmp.h"

/* Needed for random number generation */
static gmp_randstate_t state;

/**
 * Return random number between a range [min, max>
 * @param result variable where random number will be stored
 * @param min minimum number
 * @param max maximum range
 * @return void
 */
void random_mpz(mpz_t result, const mpz_t min, const mpz_t max)
{
    static int initialized = 0;

    /* Initialize and seed GMP state once */
    if (!initialized)
    {
        gmp_randinit_mt(state);
        srand((unsigned int)time(NULL));
        unsigned long seed = ((unsigned long)rand() << 16) | rand();  // more bits for seed
        gmp_randseed_ui(state, seed);
        initialized = 1;
    }

    mpz_t range, random_number;
    mpz_init(range);
    mpz_init(random_number);

    mpz_sub(range, max, min);

    mpz_urandomm(random_number, state, range);

    mpz_add(result, random_number, min);

    mpz_clear(random_number);
    mpz_clear(range);
}

/**
 * Add underscores (digit separation) to uint64_t number
 * @param number number to be separated
 * @return char*
 */
char* add_underscores(uint64_t number)
{
    /* Convert the number to a string */
    char str[21]; /* maximum 20 characters for uint64_t plus null terminator */
    sprintf(str, "%lu", number);

    /* Number of digits in the string */
    int num_digits = strlen(str);

    /* Calculate the number of underscores needed */
    int num_underscores = num_digits / 3;
    if (num_digits % 3 == 0)
    {
        num_underscores--;
    }

    /* Allocate memory for the new string */
    char *new_str = malloc(num_digits + num_underscores + 1); /* plus null terminator */

    /* Copy the digits and underscores into the new string */
    int j = 0;
    for (int i = 0; i < num_digits; i++)
    {
        if (i > 0 && (num_digits - i) % 3 == 0)
        {
            new_str[j] = '_';
            j++;
        }

        new_str[j] = str[i];
        j++;
    }

    new_str[j] = '\0';
    return new_str;
}

/**
 * Add underscores (digit separation) to GMP number
 * @param num number to be separated
 * @return char*
 */
char* separate_mpz(mpz_t num)
{
    char *num_str = mpz_get_str(NULL, 10, num);
    int num_len = strlen(num_str);
    int sep_len = num_len / 3 + ((num_len % 3) == 0 ? -1 : 0);
    char *sep_str = malloc(num_len + sep_len + 1);

    int i = 0, j = 0;
    for (; i < num_len; i++, j++)
    {
        sep_str[j] = num_str[i];
        if (((num_len - i - 1) % 3 == 0) && (i < num_len - 1))
        {
            sep_str[++j] = '_';
        }
    }

    sep_str[j] = '\0';

    free(num_str);
    return sep_str;
}

int main()
{
    /* ------------------------------------------ */
    /*              Input numbers                 */
    /* ------------------------------------------ */

    mpz_t one, googol;
    uint16_t num_cards = 0;

    char num_cards_input[4];
    char yes_or_no;

    printf("Enter number of cards (1 - 999): ");
    scanf("%3s", num_cards_input);
    num_cards = atoi(num_cards_input);

    if (num_cards < 1)
    {
        printf("Minimum number of cards is 1!\n");
        printf("Setting number of cards to 10.\n\n");

        num_cards = 10;
    }

    mpz_init(googol);
    printf("Enter maximum number (1 - googol): ");
    gmp_scanf("%101Zd", googol);

    if (mpz_cmp_si(googol, 2) < 0)
    {
        printf("Minimum number is 2!\n");
        printf("Setting number to 100.\n\n");

        mpz_set_si(googol, 100);
    }

    /* ------------------------------------------ */
    /*              Define array                  */
    /* ------------------------------------------ */

    mpz_t* cards = calloc(num_cards, sizeof(mpz_t));
    uint16_t last_card_id = num_cards - 1; // card that player thinks it is the largest

    /* ------------------------------------------ */
    /*             Initialize numbers             */
    /* ------------------------------------------ */

    mpz_init(one);
    //mpz_init(googol);

    mpz_set_ui(one, 1);
    // mpz_ui_pow_ui(googol, 10, 100);

    for (uint64_t i = 0; i < num_cards; i++)
    {
        mpz_init(cards[i]);
        random_mpz(cards[i], one, googol);
    }

    /* ------------------------------------------ */
    /*                Game loop                   */
    /* ------------------------------------------ */

    for (uint16_t i = 0; i < num_cards; i++)
    {
        char* underscored_text = add_underscores(i);
        char* separated_text = separate_mpz(cards[i]);

        printf("Number on card %s is: %s\n", underscored_text, separated_text);
        printf("Are you quitting? [yes - 1 | no - 0]: ");

        free(underscored_text);
        free(separated_text);

        scanf(" %c", &yes_or_no);
        if (yes_or_no == 'y' || yes_or_no == '1')
        {
            last_card_id = i;
            break;
        }
    }

    /* ------------------------------------------ */
    /*               Declare winner               */
    /* ------------------------------------------ */

    printf("\nYou...\n");

    mpz_t max_number;
    mpz_init(max_number);

    for (size_t i = 0; i < num_cards; i++)
    {
        if (mpz_cmp(cards[i], max_number) > 0)
        {
            mpz_set(max_number, cards[i]);
        }
    }

    if (mpz_cmp(cards[last_card_id], max_number) < 0) // player's number is smaller than the largest number
    {
        printf("...lost :( \n");

        char* separated_text = separate_mpz(max_number);
        printf("Largest number is %s\n", separated_text);

        free(separated_text);
    }

    else
    {
        printf("...won :) \n");

        char* separated_text = separate_mpz(max_number);
        printf("Largest number is %s\n", separated_text);

        free(separated_text);
    }

    /* ------------------------------------------ */
    /*             Free all variables             */
    /* ------------------------------------------ */

    for (size_t i = 0; i < num_cards; i++)
    {
        mpz_clear(cards[i]);
    }

    free(cards);

    gmp_randclear(state);

    mpz_clear(max_number);

    mpz_clear(one);
    mpz_clear(googol);

    return 0;
}
