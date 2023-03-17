/*
I ackknowlage DCU's academic plagerism integraty policy.
*/
#include "utility.h"
#include "utility.c"

int main (int argc, char ** argv)
{
    char buf[MAX_BUFFER]; 
    char * args[MAX_ARGS];            
    char ** arg;                             

    if (argc == 2)
    {
      printf("Opening: %s\n", argv[1]);
      int fp = open(argv[1], O_RDONLY);
      char line[MAX_BUFFER];
      if (fp < 0)
      {
        printf("Failed to open: %s\n", argv[1]);
        return 1; // exit program if file cannot be opened
      }
      dup2(fp, 0);
      close(fp);
    }

    char cwd[1024];
    while (!feof(stdin)) { 
        
        printf("(%s)-->", getcwd(cwd, sizeof(cwd))); // write prompt

        if (fgets (buf, MAX_BUFFER, stdin )) { // read a line
            /* tokenize the input into args array */
            arg = args;
            *arg++ = strtok(buf,SEPARATORS);   // tokenise input

            while ((*arg++ = strtok(NULL,SEPARATORS)));


      
            if (args[0]) {

              if (!strcmp(args[0], "quit"))
              {
                exit(0);
              }        
              execute(args);
  
            }
        }
    }
    return 0; 
}
