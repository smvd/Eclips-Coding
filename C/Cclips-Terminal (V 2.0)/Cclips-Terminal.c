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

#define TRUE 	1 																// Bool true
#define FALSE 	0 																// Bool false

void error(char type[100], char message[100])									// Function to throw custom error
{
	printf("\e[0;31m");															// Set text color to red
	printf("ERROR > %s > %s\n",type, message);									// Display error message
	printf("\e[0;0m");															// Reset text color
}

int main()																		// Main entry point
{
	
	char in[100];																// Char array for input
	char buff[100];																// A place to store temps values

	while (TRUE)																// Inf loop
	{
		top:																	// Point the jump to wich will restart cycle
		printf("> ");															// IO prompt
		fgets(in, 100, stdin);													// Get the input
		strtok(in, "\n");														// Remove the enter character

		if (strchr("0123456789", in[0]))										// If its a number
		{
			/* - MATH LEXER - */
			for (unsigned int i = 0; i < strlen(in); i++)						// Loop threw each character in the input
			{
				if (strchr("0123456789.", in[i]))								// If its a number or a .
				{
					
				}
				else if (strchr("+-*/%", in[i]))								// If its a math operator
				{
					
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
		}
		else 																	// If it aint a number 
		{
			/* - MAIN LEXER - */
		}
	}
	
	return 0;																	// End program
}
