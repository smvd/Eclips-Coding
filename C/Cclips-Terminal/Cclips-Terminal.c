#include <stdio.h>                                              // Base lib
#include <string.h>                                             // For string actions
#include <windows.h>                                            // To interact with os functions

#define TRUE    1                                               // Bool TRUE
#define FALSE   0                                               // Bool FALSE

void error(char type[150], char message[150])                   // Function to throw error with type and message
{
    printf("\e[0;101mERROR: %s: %s\e[0m\n",type,message);       // Print the actual error
}

void clear()                                                    // Function to clear the terminal window
{
    system("cls 2> nul");                                       // Windows clear with error dump
    system("clear 2> nul");                                     // Linux clear with error dump
}

void logo()                                                     // Function to draw the logo
{
    // Contains number to character
    // 0 = ' '
    // 1 = '█'
    // 2 = '\n'
    char num[] = "11111112100000000011111100100000001001111110011111100000000000000000000111111100111111001111110010000001001001000100001100001210000000001000000010000000000100001001000000000011111111110000000010000010000000100001001110011100000110010001001000121000000000100000001000000010011111100111111000001111111111000000001000001111000011111100100110010010010101000100100012100000000010000000100000001001000000000000100000000000000000000000100000100000001000100010000001001001001100111111001211111110001111110011111100100100000001111110000000000000000000000010000011111100100001001000000100100100010010000100111112";
    
    for (int i = 0; i < 620; i++)                               // Loop 620 times
    {
        if (num[i] == '0') {printf(" ");}                       // If its a 0 print ' '
        if (num[i] == '1') {printf("%c",219);}                  // If its a 1 print '█'
        if (num[i] == '2') {printf("\n");}                      // If its a 2 print '\n'
    }
}

int main()
{
    char in[200];                                               // The users input
    char buff[100];                                             // The buffer 
    char splits[10][100];                                       // The array to hold the parsed input
    char path[] = "C:\\";                                       // A string that holds the current path

    clear();                                                    // Clear the terminal
    logo();                                                     // Print the logo
    printf("\n");                                               // Print a blank line                                

    while (TRUE)                                                // Main loop
    {
        strcpy(in, "");                                         // Clear the in variable
        strcpy(buff, "");                                       // Clear the buffer
        for (int i = 0; i < 10; i++)                            // Loop 10 times
        {
            strcpy(splits[i], "");                              // Clear the splits[i] variable
        }

        printf("%s %c ", path, 175);
        fgets(in, 200, stdin);                                  // Get the users input
        strtok(in, "\n");                                       // Remove the newline character

        int quotes = FALSE;                                     // Set quotes to 0
        int x = 0;                                              // Set x to 0
        strcpy(buff, "");                                       // Clear the buffer
        for (int i = 0; i < strlen(in); i++)                    // Loop threw each character in the users input
        {
            if (in[i] == '\"')                                  // If the character is a quote
            {
                if (quotes == TRUE) {quotes = FALSE;}           // If we are in quotes we leave them
                else if (quotes == FALSE) {quotes = TRUE;}      // If we arnt in quotes we enter them
            }
            else if (in[i] == ' ' && quotes == FALSE)           // If we arnt in quotes and we hit a space
            {
                strcpy(splits[x], buff);                        // Push the buffer to the array
                strcpy(buff, "");                               // Clear the array
                x++;                                            // Add 1 to x
            }
            else                                                // If we hit any other character
            {
                strncat(buff, &in[i], 1);                       // Add it to the buffer
            }
        }
        strcpy(splits[x], buff);                                // Dump the current buffer as it may contain data

        printf("[ %s", splits[0]);                              // Print a '[ and the first item'
        for (int i=1; i < 100; i++)                             // Loop 100 times
        {
            if (splits[i][0] == '\0') {break;}                  // If we hit the end leave loop
            printf(" : %s", splits[i]);                         // Print ' : and the current item'
        }
        printf(" ]\n");                                         // Print ' ]' and a new line

        if (splits[0][0] != '\0')                               // If we gave a command
        {
            if (strcmp(splits[0], "exit") == 0 || strcmp(splits[0], ";") == 0) // If command = exit or ;
            {
                if (splits[1][0] == '?')                        // If params = ?
                {
                    // Display help message
                    printf("    -- EXIT --\n");
                    printf("exit - ;\n");
                    printf(" - exit\n");
                    printf("Closes the program\n");
                    printf(" - exit ?\n");
                    printf("Displays this help message\n\n");
                }
                else 
                {
                    return 0;                                   // Quit program
                }
            }
            else if (strcmp(splits[0], "clear") == 0 || strcmp(splits[0], "!") == 0) // If command = clear or cls or !
            {
                if (splits[1][0] == '?')                        // If params = ?
                {
                    // Display help message
                    printf("    -- CLEAR --\n");
                    printf("clear - !\n");
                    printf(" - clear\n");
                    printf("Wipes the content of the terminal\n");
                    printf(" - clear -NoLogo\n");
                    printf("Clears the terminal without displaying the logo again\n");
                    printf(" - clear ?\n");
                    printf("Displays this help message\n\n");
                }
                else if (strcmp(splits[1], "-NoLogo") == 0)
                {
                    clear();                                    // Clear the screen
                }
                else
                {
                    clear();                                    // Clears the screen
                    logo();                                     // Displays the logo
                }
            }
            else if (strcmp(splits[0], "write") == 0 || strcmp(splits[0], "print") == 0) // If it matches write or print 
            {
                if (splits[1][0] == '?')                        // If params = ?
                {
                    // Display help message
                    printf("    -- WRITE --\n");
                    printf("write - print\n");
                    printf(" - write {message}\n");
                    printf("Writes the message to the terminal\n");
                    printf(" - write ?\n");
                    printf("Displays this help message\n\n");
                }
                else
                {
                    printf("%s\n",splits[1]);                   // Write the message
                }
            }
            else if (strcmp(splits[0], "error") == 0 || strcmp(splits[0], "throw") == 0) // If it matches error or throw
			{
				if (splits[1][0] == '?')                        // If params = ?
				{
                    // Display help message
                    printf("    -- ERROR --\n");
                    printf("error - throw\n");
                    printf(" - error {type} {message}\n");
                    printf("Throw the given error of the given type.\n");
                    printf(" - error ?\n");
                    printf("Displays this help message\n\n");
				}
				else
				{
					error(splits[1],splits[2]);					// Throw the given error of the given type
				}
			}
            else
            {
                strcat(splits[0], " is not a valid command");
                error("UNKNOWN COMMAND", splits[0]);
                printf("\n");
            }
        }
    }

    return 0;                                                   // End function
}
