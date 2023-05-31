#include <stdio.h>
#include <cs50.h>

int get_card_length(long long card_number)
{
    int length = 0;
    while (card_number > 0)
    {
        card_number /= 10;
        length++;
    }
    return length;
}

bool is_valid_checksum(long long n)
{
   int sum1 = 0;
   int sum2 = 0;
   long x = n;
   int total = 0;
   int mod1;
   int mod2;
   int d1;
   int d2;
   do
   {
       // Remove last digit and add to sum1
       mod1 = x % 10;
       x = x / 10;
       sum1 = sum1 + mod1;
       // Remove second last digit
       mod2 = x % 10;
       x = x / 10;
       // Double second last digit and add digits to sum2
       mod2 = mod2 * 2;
       d1 = mod2 % 10;
       d2 = mod2 / 10;
       sum2 = sum2 + d1 + d2;
   }
   while (x > 0);
   total = sum1 + sum2;


// Next check Luhn Algorithm
   if (total % 10 != 0)
   {
       printf("INVALID\n");
       return 0;
   }

}

string get_card_type(long long card_number, int length)
{
    int first_digit = card_number / 10;
    int second_digit = card_number / 100;

    if ((length == 15) && (second_digit == 34 || second_digit == 37))
    {
        return "AMEX";
    }
    else if ((length == 16) && (second_digit >= 51 && second_digit <= 55))
    {
        return "MASTERCARD";
    }
    else if ((length == 13 || length == 16) && (first_digit == 4))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

int main(void)
{
    long long card_number = get_long("Number: ");
    int length = get_card_length(card_number);

    if (is_valid_checksum(card_number))
    {
        string card_type = get_card_type(card_number, length);
        printf("%s\n", card_type);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
