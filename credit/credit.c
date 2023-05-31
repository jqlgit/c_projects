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

bool is_valid_checksum(long long card_number, int length)
{
    int sum = 0;
    bool multiply = false;

    while (card_number > 0)
    {
        int digit = card_number % 10;
        if (multiply)
        {
            digit *= 2;
            sum += digit / 10 + digit % 10;
        }
        else
        {
            sum += digit;
        }

        card_number /= 10;
        multiply = !multiply;
    }

    return sum % 10 == 0;
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
        printf("testcard");
        return "VISA";
    }
    else
    {
        printf("testcard2");
        return "INVALID";
    }
}

int main(void)
{
    long long card_number = get_long("Number: ");
    int length = get_card_length(card_number);

    if (is_valid_checksum(card_number, length))
    {
        string card_type = get_card_type(card_number, length);
        printf("%s\n", card_type);
    }
    else
    {
        printf("test");
        printf("INVALID\n");
    }

    return 0;
}
