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
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format


void displayPatientData(const struct Patient* patient, int fmt)
{


        if (fmt == FMT_FORM)
        {
                printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        
            displayFormattedPhone(patient->phone.number);
                printf(" (%s)\n", patient->phone.description);
        }
        
        else
        {
                printf("%05d %-15s ", patient->patientNumber,
                patient->name);
        
        displayFormattedPhone(patient->phone.number);
                printf(" (%s)\n", patient->phone.description);
        }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do 
    {
            printf("Veterinary Clinic System\n"
                    "=========================\n"
                    "1) PATIENT     Management\n"
                    "2) APPOINTMENT Management\n"
                    "-------------------------\n"
                    "0) Exit System\n"
                    "-------------------------\n"
                    "Selection: ");
        
        selection = inputIntRange(0, 2);
        
        putchar('\n');
        
        switch (selection)
        {
        
        case 0:
                    printf("Are you sure you want to exit? (y|n): ");
                selection = !(inputCharOption("yn") == 'y');
                
                    putchar('\n');
                if (!selection)
                {
                    printf("Exiting system... Goodbye.\n\n");
                }
        break;
        
        case 1:
                menuPatient(data->patients, data->maxPatient);
        break;
        
        case 2:
                printf("<<< Feature not yet available >>>\n\n");
        break;
        }
    } while (selection);
}


// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
        int selection;

    do 
    {
            printf("Patient Management\n"
                "=========================\n"
                "1) VIEW   Patient Data\n"
                "2) SEARCH Patients\n"
                "3) ADD    Patient\n"
                "4) EDIT   Patient\n"
                "5) REMOVE Patient\n"
                "-------------------------\n"
                "0) Previous menu\n"
                "-------------------------\n"
                "Selection: ");
        
        selection = inputIntRange(0, 5);
        
        putchar('\n');
        
        switch (selection)
        {
        case 1:
                displayAllPatients(patient, max, FMT_TABLE);
                suspend();
        break;
        
        case 2:
                searchPatientData(patient, max);
                break;
        
        case 3:
                addPatient(patient, max);
                suspend();
        break;
        
        case 4:
                editPatient(patient, max);
        break;
        
        case 5:
                removePatient(patient, max);
                suspend();
        break;
        }
    } while (selection);
}

// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do 
    {
            printf("Edit Patient (%05d)\n"
                    "=========================\n"
                    "1) NAME : %s\n"
                    "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
            printf("\n"
                    "-------------------------\n"
                    "0) Previous menu\n"
                    "-------------------------\n"
                    "Selection: ");
        
        selection = inputIntRange(0, 2);
        
        putchar('\n');

        if (selection == 1)
        {
                printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
                printf("Patient record updated!\n\n");
        }

        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
                printf("Patient record updated!\n\n");
        }

    } while (selection);
}


void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
        int i, count = 0;
        displayPatientTableHeader();
        
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber != 0)
            {
                displayPatientData(&patient[i], fmt);
                count++;
            }
        }
    
            putchar('\n');
    
        if (count == 0)
        {
            printf("*** No records found ***\n");
        }
}


// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
        int selection = 1;
        while(selection !=0 )
        {
            printf("Search Options\n");
            printf("==========================\n");
            printf("1) By patient number\n");
            printf("2) By phone number\n");
            printf("..........................\n");
            printf("0) Previous menu\n");
            printf("..........................\n");
            printf("Selection: ");
        
        selection = inputIntRange(0, 2);
        
            if (selection == 1)
            {
                searchPatientByPatientNumber(patient, max);
            }
            else if (selection == 2)
            {
                searchPatientByPhoneNumber(patient, max);
            }
        }
    
    putchar('\n');
}

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
        int i, count = 0;
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber == 0)
            {
                patient[i].patientNumber = nextPatientNumber(patient, max);
                inputPatient(&patient[i]);
                count++;
                    printf("*** New patient record added ***\n");
            
                putchar('\n');
                i = max;
            }
        }
    
        if (count == 0)
        {
            printf("ERROR: Patient listing is FULL!\n");
            putchar('\n');
        }
}

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
        int patientNumber = 0, patientPosition = 0;
            printf("Enter the patient number: ");
        patientNumber = inputIntPositive();
        patientPosition = findPatientIndexByPatientNum(patientNumber, patient, max);
    
        if (patientPosition < 0)
        {
            putchar('\n');
            printf("ERROR: Patient record not found!\n");
            putchar('\n');
            suspend();
        }
        else if (patientPosition >= 0)
        {
            menuPatientEdit(&patient[patientPosition]);
        }
}

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
        int patientNumber = 0, patientPosition = 0;
        char choice = 0;
            printf("Enter the patient number: ");
        patientNumber = inputIntPositive();
        patientPosition = findPatientIndexByPatientNum(patientNumber, patient, max);
    
        if (patientPosition < 0)
        {
            putchar('\n');
            printf("ERROR: Patient record not found!\n");
            putchar('\n');
        }
        else
        {
            displayPatientData(&patient[patientPosition], FMT_FORM);
            putchar('\n');
                printf("Are you sure you want to remove this patient record? (y/n): ");
            choice = getchar();
        
            if (choice == 'n')
            {
                printf("Operation aborted.\n");
            }

        else if (choice == 'y')
            {
                patient[patientPosition].patientNumber = 0;
                patient[patientPosition].name[0] = '\0';
                patient[patientPosition].phone.description[0] = '\0';
                patient[patientPosition].phone.number[0] = '\0';
                    printf("Patient record has been removed!\n");
            }
        
        clearInputBuffer();
        putchar('\n');
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
        int patientNumber = 0, patientIndex = 0;
        
            putchar('\n');
            printf("Search by patient number: ");
        
        patientNumber = inputIntPositive();
        patientIndex = findPatientIndexByPatientNum(patientNumber, patient, max);
    
        if (patientIndex < 0)
        {
            putchar('\n');
            printf("*** No records found ***\n");
        }
        else
        {
            displayPatientData(&patient[patientIndex], FMT_FORM);
        }
    
    
        putchar('\n');
        suspend();
}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
        putchar('\n');
        int i, count = 0;
        char phoneNumber[PHONE_LEN + 1] = { 0 };
    
            printf("Search by phone number: ");
        
        inputCString(phoneNumber, PHONE_LEN, PHONE_LEN);
        putchar('\n');
        displayPatientTableHeader();
    
    
        for (i = 0; i < max; i++)
        {
            if (strcmp(patient[i].phone.number, phoneNumber) == 0)
            {
                displayPatientData(&patient[i], FMT_TABLE);
                count++;
            }
        }

        if (count == 0)
        {
            putchar('\n');
            printf("*** No records found ***\n");
        }
    
        putchar('\n');
        suspend();
}

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
        int i, maxNum = 0;
        
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber >= maxNum)
            {
                maxNum = patient[i].patientNumber + 1;
            }
        }
    return maxNum;
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
        int i;
    
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber == patientNumber)
            {
                putchar('\n');
                return i;
            }
        }
    return -1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{
        printf("Patient Data Input\n"
                "------------------\n");
    
        printf("Number: %05d\n", patient->patientNumber);
        printf("Name  : ");
        
        
        inputCString(patient->name, 1, NAME_LEN);
        
        putchar('\n');
        
        inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
        int selection = 0;
        char des1[PHONE_DESC_LEN + 1] = { "CELL" };
        char des2[PHONE_DESC_LEN + 1] = { "HOME" };
        char des3[PHONE_DESC_LEN + 1] = { "WORK" };
        char des4[PHONE_DESC_LEN + 1] = { "TBD" };
            printf("Phone Information\n");
            printf("-----------------\n");
            printf("How will the patient like to be contacted?\n");
            printf("1. Cell\n"
                   "2. Home\n"
                   "3. Work\n"
                   "4. TBD\n");
    
            printf("Selection: ");
    
        selection = inputIntRange(1, 4);
            
            printf("\n");
    
        if (selection == 1)
            strcpy(phone->description, des1);
        else if (selection == 2)
            strcpy(phone->description, des2);
        else if (selection == 3)
            strcpy(phone->description, des3);
        else if (selection == 4)
            strcpy(phone->description, des4);
    
        if(selection != 4)
        {
        
            printf("Contact: %s\n", phone->description);
            printf("Number : ");
        
        inputCString(phone->number, 10, 10);
        
        putchar('\n');
        }
        else
        {
            phone->number[0] = '\0';
        }
}