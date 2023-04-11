/**
 * @author Andrej Bartulin
 * PROJECT: gog
 * LICENSE: Public Domain
 * DESCRIPTION: Entry point | Main file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>
#include <time.h>

#include "gmp.h"

typedef struct card_T
{
    mpz_t number;
} Card;

void random_mpz(mpz_t result, const mpz_t min, const mpz_t max)
{
    mpz_t range, random_number;

    mpz_init(range);
    mpz_init(random_number);

    /* Calculate the range */
    mpz_sub(range, max, min);

    /* Generate a random number within the range */
    unsigned long seed;

    gmp_randstate_t state;
    gmp_randinit_mt(state);

    FILE *urandom = fopen("/dev/urandom", "r");
    fread(&seed, sizeof(seed), 1, urandom);

    seed = (seed / rand()) / rand();
    fclose(urandom);

    gmp_randseed_ui(state, seed);
    mpz_urandomm(random_number, state, range);

    /* Add the minimum value to the random number */
    mpz_add(result, random_number, min);

    gmp_randclear(state);
    mpz_clear(random_number);
    mpz_clear(range);
}

char *add_underscores(uint64_t number)
{
    /* Convert the number to a string */
    char str[21]; /* maximum 20 characters for uint64_t plus null terminator */
    sprintf(str, "%llu", number);

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

char *mpz_separate(mpz_t num)
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

void find_largest_number(mpz_t max_number, Card *cards, size_t num_cards)
{
    for (size_t i = 0; i < num_cards; i++)
    {
        if (mpz_cmp(cards[i].number, max_number) > 0)
        {
            mpz_set(max_number, cards[i].number);
        }
    }
}

int main()
{
    int flag;
    uint64_t num_cards;

    char *input = (char *)malloc(sizeof(char) * 1024);
    char *yes_or_no = (char *)malloc(sizeof(char) * 1024);

    printf("Enter number of cards: ");
    scanf("%1023s", input);

    sscanf(input, "%" SCNu64, &num_cards); /* num_cards = strtoull(input, NULL, 0); */
    free(input);

    /* ------------------------------------ */

    Card cards[num_cards];

    /* ------------------------------------ */

    mpz_t one, googol;

    mpz_init(one);
    mpz_init(googol);

    mpz_set_ui(one, 1);
    mpz_set_ui(googol, 18446744073709551615); /* googol is currently broken */

    for (uint64_t i = 0; i < num_cards; i++)
    {
        mpz_init(cards[i].number);
        random_mpz(cards[i].number, one, googol);
    }

    for (uint64_t i = 0; i < num_cards; i++)
    {
        printf("Number on card %s is: %s\n", add_underscores(i), mpz_separate(cards[i].number));
        printf("Are you quitting? [yes - 1 | no - 0]\n");

        int quit = 0;

        scanf("%s", yes_or_no);
        quit = atoi(yes_or_no);

        if (quit == 1)
        {
            printf("\nYou...\n");

            mpz_t max_number;
            mpz_init(max_number);

            for (size_t i = 0; i < num_cards; i++)
            {
                if (mpz_cmp(cards[i].number, max_number) > 0)
                {
                    mpz_set(max_number, cards[i].number);
                }
            }

            if (mpz_cmp(max_number, cards[i].number) > 0) /* +1 */
            {
                printf("...lost :( \n");
                printf("Largest number is %s\n", mpz_separate(max_number));
            }

            else
            {
                printf("...won :) \n");
                printf("Largest number is %s\n", mpz_separate(max_number));
            }

            mpz_clear(max_number);
            free(yes_or_no);

            exit(0);
        }
    }

    printf("\nYou...\n");

    mpz_t max_number;
    mpz_init(max_number);

    for (size_t i = 0; i < num_cards; i++)
    {
        if (mpz_cmp(cards[i].number, max_number) > 0)
        {
            mpz_set(max_number, cards[i].number);
        }
    }

    if (mpz_cmp(max_number, cards[num_cards - 1].number) > 0) /* +1 */
    {
        printf("...lost :( \n");
        printf("Largest number is %s\n", mpz_separate(max_number));
    }

    else
    {
        printf("...won :) \n");
        printf("Largest number is %s\n", mpz_separate(max_number));
    }

    mpz_clear(max_number);

    mpz_clear(one);
    mpz_clear(googol);

    free(yes_or_no);
    return 0;
}
