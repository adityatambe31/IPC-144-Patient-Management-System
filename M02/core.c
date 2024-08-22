/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  :    Aditya Mahesh Tambe	
Student ID#:    171969223
Email      :    amtambe@myseneca.ca
Section    :    ZHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "core.h"

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// get input from user and verify it is a whole number
int inputInt()
{
    int num = 0;
    char c = 0;
    while (c != '\n')
    {
        scanf("%d%c", &num, &c);
        if (c != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return num;
}

// get input from user and verify it is a positive whole number
int inputIntPositive()
{
    int num = 0, outOfRange = 0;
    do
    {
        scanf("%d%*c", &num);
        outOfRange = num < 0;
        if (outOfRange)
        {
            //clearInputBuffer();
            printf("ERROR! Value must be >= 0: ");
        }
    } while (outOfRange);
    return num;
}

// verify if the input is in between the range
int inputIntRange(const int lowBound, const int upperBound)
{
    int num = 0;
    do
    {
        num = inputInt();
        if (num >= lowBound && num <= upperBound)
        {
            return num;
        }
        else if (num < lowBound || num > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowBound, upperBound);
        }
    } while (num < lowBound || num > upperBound);
    return 0;
}

// check if user input matches one of the element in array
char inputCharOption(const char inputArr[])
{
    char c;
    do
    {
        c = getchar();
        if (strchr(inputArr, c))
        {
            clearInputBuffer();
            return c;
        }
        else
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [qwErty]: ");
        }
    } while (c != '\n');
    return c;
}

// check if user input string has length in between the range
void inputCString(char* cstringValue, const int minRange, const int maxRange)
{
    int len = 0;
    char tmpArr[100] = { 0 };
    do
    {
        scanf("%[^\n]s%*c", tmpArr);
        len = strlen(tmpArr);
        if (len > maxRange || len < minRange)
        {
            if (maxRange == minRange)
                printf("ERROR: String length must be exactly %d chars: ", minRange);
            else if (len > maxRange)
                printf("ERROR: String length must be no more than %d chars: ", maxRange);
            else if (minRange < maxRange)
                printf("ERROR: String length must be between %d and %d chars: ", minRange, maxRange);
            clearInputBuffer();
        }
    } while (len > maxRange || len < minRange);
    strcpy(cstringValue, tmpArr);
    clearInputBuffer();
}

// displays the phone number in a proper form
void displayFormattedPhone(const char* phoneNumber)
{
    int i, digit = 0;
    if (phoneNumber == NULL)
        printf("(___)___-____");
    else
    {
        for (i = 0; phoneNumber[i] != '\0'; i++)
        {
            if (isdigit(phoneNumber[i]))
                digit++;
        }
        if (digit == 10)
            printf("(%c%c%c)%c%c%c-%c%c%c%c",
                phoneNumber[0], phoneNumber[1], phoneNumber[2],
                phoneNumber[3], phoneNumber[4], phoneNumber[5],
                phoneNumber[6], phoneNumber[7], phoneNumber[8],
                phoneNumber[9]);
        else
            printf("(___)___-____");
    }
}

//
