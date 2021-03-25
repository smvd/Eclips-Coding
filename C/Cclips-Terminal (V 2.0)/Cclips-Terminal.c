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
Git Commit	- git commit -a -m " "
Git Push	- git push
*/

#include <stdio.h>							// Lib for IO
#include <string.h>							// Lib for string functions

#define TRUE 	1 							// Bool true
#define FALSE 	0 							// Bool false

int main()									// Main entry point
{
	char in[100];							// Char array for input

	while (TRUE)							// Inf loop
	{
		printf("> ");						// IO prompt
		fgets(in, 100, stdin);				// Get the input
		strtok(in, "\n");					// Remove the enter character

		if (strstr("0123456789", &in[0]))	// If its a number
		{
			
		}
		else 								// If it aint a number 
		{
			
		}
	}
	
	return 0;								// End program
}
