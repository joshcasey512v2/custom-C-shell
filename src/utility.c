/*
I ackknowlage DCU's academic plagerism integraty policy.
*/

#include "utility.h"
#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"


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

int functions() {
  return sizeof(function_strings) / sizeof(char *);
}


int init(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("error");
    }
    exit(1);
  } else if (pid < 0) {
    // Error forking
    perror("error");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}


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

int cd(char **args)
{
  if (args[1] == NULL) {
    chdir("..");
  } else {
    chdir(args[1]);
  }
  return 1;
}

int pwd(){
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
      printf("%s\n", cwd);
  }
  return 1;
}


int help(){
    system("cat readme.md");
    return 1;
}

int dir(){
    system("ls -al");
    return 1;
}

int clr() {
  printf("\e[1;1H\e[2J");
  return 1;
}

int echo(char **args) {
  for (int i = 1; args[i] != NULL; ++i)
  {
      printf("%s ", args[i]);
  }
  printf("\n");
  return 1;
}

int env() {
  extern char **environ;

  for (int i = 0; environ[i] != NULL; i++)
    printf("%s\n",environ[i]);
  return 1;
  
}

int halt(){
  int c;
  c = getchar();
  while (c != '\n')
  {
      pause();
  };
}