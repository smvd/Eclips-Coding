/*
 __  
/  \  __  _      ___
|__| |_/ | | | |  |
|  | |_\ |_| |_|  |
========================
Maker			- "smvd"

Discord			- "smvd#4197"
Reddit			- "No_War3219"
Stack Overflow	- "smvd"

Github(user)	- "smvd"
Github(Project)	- "https://github.com/smvd/Eclips-Coding"

Youtube(user)	- "Eclips-Coding
Youtube Channel - "https://cutt.ly/Eclips-Coding"
_____
  |   _   _      __
  |  | | | | |  |_
  |  |_| |_| |_ __|
========================
Compiler	- Gcc
Editor		- micro
Recorder	- OBS
TTS			- Babolka
Storage		- GitHub

____
|    _  _  _ _  _  _        _   __
|   | | |\/| |\/| /_\ |\ | | \ |_
|__ |_| |  | |  | | | | \| |_/ __|
========================
Compile 	- gcc "Cclips-Terminal.c" -o "Cclips-Terminal.exe" && Cclips-Terminal
Git Commit	- git commit -a -m "-"
Git Push	- git push
Enable ANSI - reg add HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000001 /f
*/

#include <stdio.h>																// Lib for IO
#include <string.h>																// Lib for string functions
#include "CustomMath.c"															// Import the file holding the math functions

#define TRUE 	1 																// Bool true
#define FALSE 	0 																// Bool false

void error(char type[100], char message[100])									// Function to throw custom error
{
	printf("\e[0;31m");															// Set text color to red
	printf("ERROR > %s > %s\n",type, message);									// Display error message
	printf("\e[0;0m");															// Reset text color
}

void append(char* s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

int main()																		// Main entry point
{
	
	char in[100];																// Char array for input
	char buff[100];																// A place to store temps values
	char parsed[10][100];														// String array to hold the parsed input

	while (TRUE)																// Inf loop
	{
		for (int i = 0; i < 10; i++)											// Loop 10 times
		{
			if (parsed[i][0] == '\0') {break;}									// If its the end of the array, stop
			strcpy(parsed[i], "");												// Set the current slot to blank
		}

		top:																	// Point the jump to wich will restart cycle
		printf("~ ");															// IO prompt
		fgets(in, 100, stdin);													// Get the input
		strtok(in, "\n");														// Remove the enter character

		if (strchr("0123456789", in[0]))										// If its a number
		{
			/* - MATH LEXER - */
			int x = 0;															// Var to hold the current slot we are writing
			for (unsigned int i = 0; i < strlen(in); i++)						// Loop threw each character in the input
			{
				if (strchr("0123456789.", in[i]))								// If its a number or a .
				{
					append(parsed[x], in[i]);									// Append the character to the current slot
					x++;														// Activate the next slot
					if (strchr("0123456789", in[i+1])) 							// If the next character is a number
					{
						x--;													// Activat the last slot
					}
				}
				else if (in[i] == ')' || in[i] == '(')							// If its parentheses
				{
					append(parsed[x], in[i]);									// Append the character to the current slot
					x++;														// Activate the next slot
				}
				else if (strchr("+-*/%", in[i]))								// If its a math operator
				{
					append(parsed[x], in[i]);									// Append the character to the current slot
					x++;														// Activate the next slot
					if (in[i+1] == '*')				 							// If the next character is *
					{
						x--;													// Activat the last slot
					}
				}
				else															// If it isnt one of the above
				{
					if (in[i] == ' ')											// If its a space 
					{
						continue;												// Ignore it
					}
					snprintf(buff, 100, "Invalid character at index: %d", i); 	// Put error message into buffer
					error("SYNTAX", buff);										// Throw error
					goto top;													// End operation
				}				
			}

			/* - FORMAT THE PARSED OUTPUT - */
			printf("[ %s", parsed[0]);											// Print some stuff
			for (int i = 1; i < 10; i++)										// Loop 10 times
			{
				if (parsed[i][0] == '\0') {break;}								// If its the end of the array, stop
				printf(" : %s", parsed[i]);										// Print some stuff
			}
			printf("]\n");														// Print some stuff
		}
		else 																	// If it aint a number 
		{
			/* - MAIN LEXER - */
		}
	}
	
	return 0;																	// End program
}
