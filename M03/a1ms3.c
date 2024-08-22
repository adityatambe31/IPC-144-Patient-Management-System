/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Aditya Mahesh Tambe
Student ID#: 171969223
Email      : amtambe@myseneca.ca
Section    : ZHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
// ############################################################################
//
//  Assignment:  1 
//  Milestone:   3
//  Description: Main Application Entry Point
//
// +---------------------------------------------------------+
// | *** The contents of this file is NOT to be modified *** |    
// +---------------------------------------------------------+
//
// ############################################################################

#include <stdio.h>

#include "clinic.h"

#define MAX_PETS 20
#define MAX_APPOINTMENTS 50

int main(void)
{
    struct Patient pets[MAX_PETS] = { { 0 } };
    struct Appointment appoints[MAX_APPOINTMENTS] = { { 0 } };
    struct ClinicData data = { pets, MAX_PETS, appoints, MAX_APPOINTMENTS };

    int patientCount = importPatients("patientData.txt", pets, MAX_PETS);
    int appointmentCount = importAppointments("appointmentData.txt", appoints, MAX_APPOINTMENTS);

    printf("Imported %d patient records...\n", patientCount);
    printf("Imported %d appointment records...\n\n", appointmentCount);

    menuMain(&data);
    
    return 0;
}