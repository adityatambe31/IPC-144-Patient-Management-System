
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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "core.h"

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearinputbuffer(void)
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
	clearinputbuffer();
	putchar('\n');
}
int inputInt(void)
{
	char nEwLiNe = 'x';
    int VALUE = 0;
	while (nEwLiNe != '\n') {
		scanf("%d%c", &VALUE, &nEwLiNe);
		if (nEwLiNe != '\n') {
			clearinputbuffer();
			printf("Error! Input a whole number: ");
		}
	}
	return VALUE;
}
//
int  inputIntPositive(void) {
	int VALUE;
	do {
        VALUE = inputInt();
		if (VALUE <= 0) {
			printf("ERROR! Value must be > 0: ");
		}
	} while (VALUE <= 0);
	return VALUE;
}
//
int inputIntRange(int MINbound, int MAXbound) {
	char nEwLiNe = 'x';
    int VALUE = 0;
	while (nEwLiNe != '\n' || (VALUE > MAXbound || VALUE < MINbound)) {
		scanf("%d%c", &VALUE, &nEwLiNe);
		if (nEwLiNe != '\n') {
			clearinputbuffer();
			printf("Error! Input a whole number: ");
		}
		else  if (VALUE > MAXbound || VALUE < MINbound) {
			/*if (VALUE > MAXbound || VALUE < MINbound) {*/
			printf("ERROR! Value must be between -3 and 11 inclusive: ");
		}
	}
	return VALUE;
}
//
char inputCharOption(char character_valid[]) {
	char ChArActEr;
	int OUT = 0;
	int i;
	do {
		scanf(" %c", &ChArActEr);
		for (i = 0; character_valid[i] != '\0'; i++) {
			if (ChArActEr == character_valid[i]) {
				OUT++;
			}
		}
		if (OUT == 0) {
			printf("ERROR: Character must be one of [qwErty]: ");
		}
	} while (OUT == 0);
	clearinputbuffer();
	return ChArActEr;
}
//
void inputCString(char* StRiNg, int minLengtH, int maxLengtH)
{
	char ChArActEr ='x';
	int OUT = 0;
	do
	{
		int STR_len = 0;
		int i;
		for (i = 0; ChArActEr != '\n' && STR_len <= maxLengtH; i++)
		{
            ChArActEr = getchar();
            StRiNg[i] = ChArActEr;
			STR_len++;
		}
		if (ChArActEr == '\n' && STR_len <= (maxLengtH + 1))
		{
			STR_len--;
            StRiNg[STR_len] = '\0';
		}
		else 
		{
            StRiNg[maxLengtH] = '\0';
			clearinputbuffer();
		}
		if (minLengtH != maxLengtH)
		{
			if (STR_len < minLengtH) 
			{
				printf("ERROR: String length must be between %d and %d chars: ", minLengtH, maxLengtH);
                ChArActEr = 'x';
			}
			else if (STR_len > maxLengtH) 
			{
				printf("ERROR: String length must be no more than 6 chars: ");
                ChArActEr = 'x';
			}
			else
			{
				OUT = 1;
			}
		}
		else if (minLengtH == maxLengtH) 
		{
			if (STR_len != minLengtH) 
			{
				printf("ERROR: String length must be exactly 6 chars: ");
                ChArActEr = 'x';
			}
			else
			{
				OUT = 1;
			}
		}
	} while (OUT == 0);
}
//
void  displayFormattedPhone(const char* CSTR)
{
	int i;
	int stringLeNgtH = 0;
	int DcOunT = 0;

	if (CSTR != NULL) {
		for (i = 0; CSTR[i] != '\0'; i++) {
			stringLeNgtH++;
		}
	}
	if (stringLeNgtH == 10) {
		for (i = 0; CSTR[i] != '\0'; i++) {
			if (CSTR[i] >= '0' && CSTR[i] <= '9') {
				DcOunT++;
			}
		}
		if (DcOunT == 10) {

				printf("(");
			for (i = 0; CSTR[i] != '\0'; i++) {
				if (i < 3) {
					printf("%c", CSTR[i]);
				}
			}
			printf(")");
			for (i = 0; CSTR[i] != '\0'; i++) {
				if (i >= 3 && i<6) {
					printf("%c", CSTR[i]);
				}
			}
			printf("-");
			for (i = 0; CSTR[i] != '\0'; i++) {
				if (i >=6 && i < 10) {
					printf("%c", CSTR[i]);
				}
			}
		}
		else {
			printf("(___)___-____");
		}

	}
	else {
		printf("(___)___-____");
	}
}
