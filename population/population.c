#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int count = 0, start_pop = 0, end_pop = 0;
    // TODO: Prompt for start size
    do
    {
        start_pop = get_int("Start size: ");
    }
    while (start_pop < 9);

    // TODO: Prompt for end size
    do
    {
        end_pop = get_int("End size: ");
    }
    while (end_pop < start_pop);

    // TODO: Calculate number of years until we reach threshold
    while (start_pop < end_pop)
    {
        start_pop = start_pop + (start_pop/3) - (start_pop/4);
        count++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", count);
}
