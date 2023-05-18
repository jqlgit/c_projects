#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get size of grid
    int n = get_size();

    // print grid of bricks
    print_grid(n);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n
}

string print_grid(void)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}