
// Copy the below commented "header" section to all your source code files!

/*/////////////////////////////////////////////////////////////////////////
						Assignment 1 - Milestone 1
Full Name  : Aditya Mahesh Tambe
Student ID#: 171969223
Email      : amtambe@myseneca.ca
Section    : ZHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
//#define MAX_LENGTH 6
//#define MIN_LENGTH 5
// clear the standard input buffer
void clearinputbuffer(void);
// wait for user to input the "enter" key to continue
void suspend(void);

int inputInt(void);
int  inputIntPositive(void);
int inputIntRange(int MINbound, int MAXbound);

char inputCharOption( char VALID_character[]);
void inputCString(char *StRiNg, int MIN, int MAX);
void displayFormattedPhone(const char* CSTR);
