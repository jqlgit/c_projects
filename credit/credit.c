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


// Check if length is valid
   if (i != 13 && i != 15 && i != 16)
   {
       printf("INVALID\n");
       return 0;
   }


// Calculate checksum
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


// Get starting digits
   long start = n;
   do
   {
       start = start / 10;
   }
   while (start > 100);


// Next check starting digits for card type
   if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
   {
       printf("MASTERCARD\n");
   }
   else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
   {
       printf("AMEX\n");
   }
   else if (start / 10 == 4)
   {
       printf("VISA\n");
   }
   else
   {
       printf("INVALID\n");
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
        printf("INVALID\n");
    }

    return 0;
}
The program first defines a helper function get_card_length that calculates the length of the credit card number. It iteratively divides the number by 10 and counts the number of iterations until the number becomes 0.

The function is_valid_checksum implements the Luhn's algorithm. It calculates the checksum of the card number by multiplying every other digit by 2 and summing the digits of the products along with the digits that weren't multiplied by 2. If the sum modulo 10 is 0, it returns true, indicating a valid card number.

The get_card_type function determines the card type based on the length and the starting digits of the card number. It checks the conditions for American Express, MasterCard, and Visa card numbers, and returns the appropriate card type as a string.

In the main function, the program prompts the user for a credit card number using get_long and calculates its length. It then checks if the checksum is valid using is_valid_checksum. If it is valid, it determines the card type using get_card_type and prints it. Otherwise, it prints "INVALID" as requested.

Note: This program assumes you have the CS50 library installed. If you don't, you can modify the get_long function to use the standard C scanf function instead.





User
double check get_card_type
ChatGPT
Apologies for the mistake. There was an error in the get_card_type function in the previous response. Here's the corrected version:

c
Copy code
string get_card_type(long long card_number, int length)
{
    int first_digit = card_number / (int)pow(10, length - 1);
    int second_digit = card_number / (int)pow(10, length - 2);

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
In the corrected version, we use the (int)pow(10, length - 1) and (int)pow(10, length - 2) expressions to extract the first and second digits respectively. This ensures that we obtain the correct digits for comparison.

Please use this updated code for the get_card_type function.







