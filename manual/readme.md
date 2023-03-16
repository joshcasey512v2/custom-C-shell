NAME
	myshell

DESCRIPTION
	This is a simple shell that is custom built based
	off the design of the bash shell. 
	This is a command line interface with various commands and options.

COMMANDS
	dir -> display everything in the current working directory

	pwd -> print the contents of the current working directory

	clr(clear) -> clear the command screen

	echo -> print any argument provided after echo on the next
	line seperated by spaces

	pause -> the operation of the shell is paused until the enter
	key is pressed

	environ -> lists all the envoirment variables / strings

	cd -> change the current directory to the previous directory
	unless an argument is passed and then it goes to that directory.

	quit -> exit the shell



ENVIORMENT
	These variables are system wide and are inherited
	by all system processes and shells. These change depending on
	whereand what machine the shell is being run on. Information stored
	that may be used by shell or be usefull for the shell.
 
REDIRECTION
	in progress


BACKGROUND / FOREGROUND
	Background processes run independant of the user and does
	not require the user to start them.
	Foreground processes requires a user to start them or
	interact with them.


STRUDENT_INFO{
	Student Number: 21361783
	Student Name: Josh Casey
	I ackknowlage DCU's academic plagerism integraty policy.
}

REFERENCES{

	Stephen Brennan (), 16/1/2015, brennan.io write a shell in C
	-> line 21 to 41, (linking commands to index).

	CodeVault, 17/may/2020, redirecting standard output in C
	-> concepts for i/o redirection

	Ian G Graham, december 2003
	-> the shells loop and tokenise the input stream.

	Brian W kernighan and Dennis M Ritchie, 1972, The C programming language
	-> syntax and file handling
}  