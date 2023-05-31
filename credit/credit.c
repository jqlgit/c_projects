#include <stdio.h>
#include <cs50.h>

// Get card number
    long n = get_long("Number: ");
    // Count length
    int i = 0;
    long cc = n;
    while (cc > 0)
    {
        cc = cc / 10;
        i++;
    }