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

#ifndef CORE_H
#define CORE_H

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

int inputInt();

int inputIntPositive();

int inputIntRange(const int lowBound, const int upperBound);

char inputCharOption(const char inputArr[]);

void inputCString(char *cstringValue, int minRange, int maxRange);

void displayFormattedPhone(const char *phoneNumber);

// get input from user and verify it is a whole number
int inputInt();

// get input from user and verify it is a positive whole number
int inputIntPositive();

// verify if the input is in between the range
int inputIntRange(const int lowBound, const int upperBound);

// check if user input matches one of the element in array
char inputCharOption(const char inputArr[]);

// check if user input string has length in between the range
void inputCString(char* cstringValue, const int minRange, const int maxRange);

// displays the phone number in a proper form
void displayFormattedPhone(const char* phoneNumber);


#endif // !CORE_H