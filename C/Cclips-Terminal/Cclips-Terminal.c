#include <stdio.h>                                                                  // Base lib
#include <string.h>                                                                 // For string actions
#include <windows.h>                                                                // To interact with os functions

#define TRUE    1                                                                   // Bool TRUE
#define FALSE   0                                                                   // Bool FALSE

void error(char type[150], char message[150])                                       // Command to throw and display an error 
{
    printf("\e[0;101mERROR: %s: %s\e[0m\n",type,message);                           // Print the text with a red background
}

void clear()                                                                        // Command to clear the terminal window
{
    system("cls 2> nul");                                                           // Clear screen windows with error supression
    system("clear 2> nul");                                                         // Clear screen linux and mac with error supression
}

int main()                                                                          // Main function
{
    char buff[150];                                                                 // String for use as a buffer
    char in[200];                                                                   // String for user input
    char path[200] = "C:\\";                                                        // String for the current path
    char command[50];                                                               // String for the current command
    char param[150];                                                                // String for the current unparsed parameters
    char params[10][150];                                                           // String array to hold the current parsed parameters

    clear();

    while (TRUE)                                                                    // Inf loop
    {
        strcpy(command,"");                                                         // Clearing the command var
        strcpy(param,"");                                                           // Clearing the param var
        strcpy(in,"");                                                              // Clearing the in var

        printf("%s ~ ",path);                                                       // Display prompt
        fgets(in, 200, stdin);                                                      // Get the user input
        strtok(in, "\n");                                                           // Remove the enter from it
        if (in[strlen(in)-2] == ' ') {strcat(in, " ");}                             // Adding a space to avoid errors

        strcpy(command,in);                                                         // Copy the input to the command var
        strtok(command, "(");                                                       // Cut of all after (

        for(int i = 0; command[i]; i++)                                             // For each character in command
        {
            command[i] = tolower(command[i]);                                       // Convert the character to lowercase
        }   

        strcpy(param,in);                                                           // Copy the input to param
        memmove(param, param+strlen(command)+1, strlen(param));                     // Remove the content of command
        param[strlen(param)-1] = '\0';                                              // Remove the trailing )

        for (int i = 0; i < strlen(param); i++)                                     // Loop threw each character in param
        {
            if (param[i] == '\"')                                                   // If its a "
            {
                memmove(&param[i], &param[i + 1], strlen(param) - i);               // Remove the character
            }
        }

        int x = 0;                                                                  // Var to hold what index we are on
        strcpy(buff, "");                                                           // Clear the buffer

        if (param[strlen(param)-1] != ';') {strcat(param, ";");}                    // Append a ; to the end if its missing

        for (int i = 0; i < strlen(param); i++)                                     // Loop threw each character in param
        {
            if (param[i] == ';')                                                    // If its a ;
            {   
                strcpy(params[x], buff);                                            // Copy the content of the buffer to the parameters
                strcpy(buff, "");                                                   // Clear the buffer

                x++;                                                                // Add 1 to x
            }
            else
            {
                strncat(buff, &param[i], 1);                                        // Add the character to the buffer
            }
        }

        printf("[\"Command\":\"%s\",\"param\":\"%s\"]\n",command,param);            // Display the users input cleanly (I swear)

        if (strcmp(command, "clear") == 0 || strcmp(command, "cls") == 0 || strcmp(command, "!") == 0)  // If it matches clear, cls, !
        {
            if (strcmp(params[0],"?") == 0)                                         // If user gave ? as param
            {
                printf("    -- CLEAR(clear, cls, !) --\n");                         // Display help message
                printf("The clear command wipes the terminal window.\n");
                printf("\n");
            }
            else                          
            { 
                clear();                                                            // Call clear function
            }
        }
        else if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0 || strcmp(command, ";") == 0 || strcmp(command, "close") == 0 || strcmp(command, "q") == 0)   // If it matches exit, quit, close, q ,;
        {
            if (strcmp(params[0],"?") == 0)                                         // If the user entered ? as param
            {
                printf("    -- EXIT(exit, quit, close, q, ;) --\n");                // Display the help message
                printf("The exit command will simply exit the program (you stupid?).\n");
                printf("\n");                                                       // Blank line
            }
            else                                                                    // If no params
            {
                return 0;                                                           // Exit program without error
            }
        }
        else if (strcmp(command, "write") == 0 || strcmp(command, "printf") == 0 || strcmp(command, "print") == 0 || strcmp(command, "w") == 0 || strcmp(command, "p") == 0)    // If it matches write, printf, print, w, p
        {
            if (strcmp(params[0],"?") == 0)                                         // If ? is the parameter
            {
                printf("    -- WRITE(write, printf, print, p, w;) --\n");           // Write the help message
                printf("The write command will simply write the text to the terminal (you stupid?).\n");    
                printf("\n");                                                       // Blank line
            }
            else if (strcmp(params[0],"") == 0)                                     // If there is no message
            {   
                error("PARAMETERS", "No message given to write");                   // Throw error
                printf("\n");                                                       // Blank line
            }
            else                                                                    // If there is a message that isnt ?
            {
                printf("%s\n", params[0]);                                          // Display the message
            }
        }
        else                                                                        // If the command is uknown
        {
            strcpy(buff, "");                                                       // Clear the buffer
            sprintf(buff, "Command \"%s\" not found", command);                     // Format the message
            error("INVALID COMMAND", buff);                                         // Throw error
            printf("\n");                                                           // Blank line
        }
    }
    printf("\n");   
    return 0;                                                                       // If its not 0 there was a issue
}