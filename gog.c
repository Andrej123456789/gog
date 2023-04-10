#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>
#include <time.h>

typedef struct card_T
{
    __uint64_t number;
} Card;

uint64_t random_uint64(uint64_t x, uint64_t y) 
{
    if (x >= y) 
    {
        fprintf(stderr, "Error: x must be less than y.\n");
        exit(EXIT_FAILURE);
    }

    uint64_t range = y - x + 1;
    uint64_t random_number;

    // Generate random number using arc4random()
    // We need to generate two 32-bit numbers and combine them to form a 64-bit number
    uint32_t random_number_low = arc4random();
    uint32_t random_number_high = arc4random();

    random_number = ((uint64_t)random_number_high << 32) | (uint64_t)random_number_low;

    // Scale the random number to the desired range
    random_number = random_number % range + x;

    return random_number;
}

char* add_underscores(uint64_t number) 
{
    // Convert the number to a string
    char str[21]; // maximum 20 characters for uint64_t plus null terminator
    sprintf(str, "%llu", number);

    // Count the number of digits in the string
    int num_digits = strlen(str);

    // Calculate the number of underscores needed
    int num_underscores = num_digits / 3;
    if (num_digits % 3 == 0) 
    {
        num_underscores--;
    }

    // Allocate memory for the new string
    char* new_str = malloc(num_digits + num_underscores + 1); // plus null terminator

    // Copy the digits and underscores into the new string
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

int main()
{
    __uint64_t num_cards = 0;

    char* input = (char*)malloc(sizeof(char) * 1024);
    char* yes_or_no = (char*)malloc(sizeof(char) * 1024);

    printf("Enter number of cards: ");
    scanf("%s", input);

    sscanf(input, "%" SCNu64, &num_cards); /* num_cards = strtoull(input, NULL, 0); */
    free(input);

    /* printf("%" SCNu64, num_cards);
    printf("\n"); */

    Card cards[num_cards];

    srand(time(NULL));

    uint64_t x = random_uint64(1, 18446744073709551615 - 2);
    uint64_t y = random_uint64(x + 1, 18446744073709551615);

    for (__uint64_t i = 0; i < num_cards; i++)
    {
        cards[i].number = random_uint64(x, y);
    }

    for (__uint64_t i = 0; i < num_cards; i++)
    {
        printf("Number on card %s is: %s\n", add_underscores(i), add_underscores(cards[i].number));
        printf("Are you quitting? [yes - 1 | no - 0]\n");

        int quit = 0;

        scanf("%s", yes_or_no);
        quit = atoi(yes_or_no);

        if (quit == 1)
        {
            printf("\nYou...\n");

            // Find the largest number in the cards array
            uint64_t max_number = 0;
            for (int i = 0; i < num_cards; i++) 
            {
                if (cards[i].number > max_number) 
                {
                    max_number = cards[i].number;
                }
            }

            if (max_number > cards[i].number)
            {
                printf("...lost :( \n");
                printf("Largest number is %s\n", add_underscores(max_number));
            }

            else
            {
                printf("...won :) \n");
                printf("Largest number is %s\n", add_underscores(max_number));
            }

            free(yes_or_no);
            exit(0);
        }
    }

    printf("\nYou...\n");

    // Find the largest number in the cards array
    uint64_t max_number = 0;
    for (int i = 0; i < num_cards; i++) 
    {
        if (cards[i].number > max_number) 
        {
            max_number = cards[i].number;
        }
    }

    if (max_number > cards[num_cards].number)
    {
        printf("...lost :( \n");
        printf("Largest number is %s\n", add_underscores(max_number));
    }

    else
    {
        printf("...won :) \n");
        printf("Largest number is %s\n", add_underscores(max_number));
    }

    free(yes_or_no);
    return 0;
}
