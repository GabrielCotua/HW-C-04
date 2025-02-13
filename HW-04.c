//HW04 Gabriel Cotua

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define NAME_LENGTH 20

int isVowel(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return 1;
    }
    return 0;

}


int main(void) {
    printf("\n\n|#####################|\n|HW #04, Gabriel Cotua|\n|#####################|\n\n");


    char First[NAME_LENGTH];
    char Middle = ' ';
    char Last[NAME_LENGTH] = "Aguilera";
    char FullName[NAME_LENGTH * 2];
    int index = 0; // location in FullName
    srand(time(0)); // set seed for random middle name initial
    Middle = 65 + rand() % 26;
    int alpha = 0;

    do {
        alpha = 0;
        // asks for user input
        printf("\nEnter first name: \n");
        scanf("%20s", First);

        for (int i = 0; i < strlen(First); i++) {
            if (isalpha(First[i])) {
                alpha += 1;
            }
        }
        // printf("\n%c \n", Middle); // checks the middle name value
    } while (alpha != strlen(First));

    if (isVowel(Middle)) // Middle name is a vowel
    {
        for (index = 0; index < strlen(Last); index++) // Adding last name
        {
            FullName[index] = Last[index];
        }

        FullName[index] = ',';
        ++index;
        FullName[index] = ' ';
        ++index;
        FullName[index] = toupper(First[0]);
        ++index;

        for (int j = 1; j < strlen(First); j++) // Adding first name
        {
            FullName[index] = tolower(First[j]);
            ++index;
        }
        FullName[index] = ' ';
        ++index;
        FullName[index] = Middle; // Adding middle name initial
        ++index;
        FullName[index] = '.';
        ++index;
        FullName[index] = '\0';
    } // end of if statement
    else // Middle name isn't a vowel
    {
        FullName[0] = toupper(First[0]);
        ++index;
        for (index = 1; index < strlen(First); index++) // Adding first name
        {
            FullName[index] = tolower(First[index]);
        }

        FullName[index] = ' ';
        ++index;
        FullName[index] = Middle; // Adding middle name
        ++index;
        FullName[index] = '.';
        ++index;
        FullName[index] = ' ';
        ++index;

        for (int j = 0; j < strlen(Last); j++) // Adding last name
        {

            FullName[index] = Last[j];
            ++index;
        }
        FullName[index] = '\0';
    } // end of else statement


    printf("\nThe full name is: %s\n\n", FullName);

    printf("Bye.");

    return 0;
}
