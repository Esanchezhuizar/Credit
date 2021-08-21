#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number;

    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    long savenumber2 = number;
    long savenumber3 = number;
    long savenumber4 = number;



// Check Sum
    int sum = 0;
    for (int digit = 0; number != 0; digit++, number /= 10) // works left to right
    {
        if (digit % 2 != 0) // second to last number
        {
            int stl = 2 * (number % 10);
            sum += stl / 10 + stl % 10;
        }
        else 
        {
            sum += number % 10;
        }
    }


// first digit
    while (savenumber2 >= 10)
    {
        savenumber2 = savenumber2 / 10;
    }
    int fd = savenumber2;

// First Two Digits
    while (savenumber3 >= 100)
    {
        savenumber3 = savenumber3 / 10;
    }
    int ftd = savenumber3;

//Length
    int length = 0;
    while (savenumber4 != 0)
    {
        savenumber4 = savenumber4 / 10;
        length++;
    }

//Type
    if (sum % 10 == 0)
    {
        if ( ( ftd == 34 || ftd == 37 ) && length == 15 )
        {
            printf("AMEX\n");
        }
        else if ( ( ftd == 51 || ftd == 52 || ftd == 53 || ftd == 54 || ftd == 55 ) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ( fd == 4 && ( length == 13 || length == 16 ) ) 
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");   
        }
    }
    else
    {
        printf("INVALID\n");
    }

}


