/*
	Student Number: 21361783
	Student Name: Josh Casey
	I ackknowlage DCU's academic plagerism integraty policy.
*/

#include "utility.h"
#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"



//list of strings to call to access the functions
//in the function list
char *function_strings[] = {
  "pwd",
  "pause",
  "dir",
  "clr",
  "cd",
  "environ",
  "help",
  "echo",
};


//List of function pointers that takes a char** and returns an integer
//the function strings and the address of the functions are linked via index
int (*function_list[]) (char **) = {
  &pwd,
  &halt,
  &dir,
  &clr,
  &cd,
  &env,
  &help,
  &echo
};


//returns the length of the function string list so the
//loop to compare strings does not go out of range
int functions() {
  return sizeof(function_strings) / sizeof(char *);
}


//creates a process if valid to execute the commands passed to it
//specified by the args, waits for child process and executes parent
//returns error if the process is negative
int init(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      printf("Not a valid command, try \"help\"\n");
    }
    exit(1);
  } else if (pid < 0) {
    perror("error");
    printf("Not a valid command :");
  } else {
    // Parent process
   wpid = waitpid(pid, &status, WUNTRACED);
  }

  return 1;
}

//below checks to see if there is any args passed
//and if they are, a loop is started to compare the
//string with the function strings then we return the
//the function based on the index of the loop that satisfies the strcmp
int execute(char **args)
{
  if (args[0] == NULL) {
    return 1;
}


  //functions declared above size = (sizeof(function_strings) / sizeof(char *))
  for (int i = 0; i < functions(); i++) {
    if (strcmp(args[0], function_strings[i]) == 0) {
      return (*function_list[i])(args);
    }
  }
  //call init function for execution process, (parent/child)
  return init(args);
}


//this function changes directory to the previous directory
//if no arguments are passed else it goes to the specified directory
//if it exists
int cd(char **args)
{
  if (args[1] == NULL) {
    chdir("..");
  } else {
    chdir(args[1]);
  }
  return 1;
}


//function to show the current working directory
int pwd(){
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
      printf("%s\n", cwd);
  }
  return 1;
}


//help function to display commands to try
int help(){
    system("more -d ../manual/readme.md");
    return 1;
}


//ls -al alias
int dir(){
    system("ls -al");
    return 1;
}


//clear the screen of previous commands
int clr() {
  printf("\e[1;1H\e[2J");
  return 1;
}


//print the arguments passed to command line seperated by spaces
int echo(char **args) {
  for (int i = 1; args[i] != NULL; ++i)
  {
      printf("%s ", args[i]);
  }
  printf("\n");
  return 1;
}


//print out all the enviorment variables
int env() {
  extern char **environ;

  for (int i = 0; environ[i] != NULL; i++)
    printf("%s\n",environ[i]);
  return 1;
}


//sleeps processes until enter is inputed
int halt(){
  int c;
  c = getchar();
  while (c != '\n')
  {
      pause();
  };
}