/*
Sources:
AI usage: Checking grammar, style and spelling
*/

// This is a simplified version of the UNIX "cat" command.
// It reads one or more files specified on the command line
// and prints the contents of each file to standard output.

#include <stdio.h>
#include <stdlib.h>

#define ERROR_OPEN_FILE "wcat: cannot open file\n"

void printFileContents(char *pFilename){
  char cBuffer[4096];// Buffer to store each line of the file
  FILE *file = NULL;

  file = fopen(pFilename, "r");
  if(!file){// Print error message and exit if the file cannot be opened
    fprintf(stdout, ERROR_OPEN_FILE);
    exit(1);
  }
  // Print each line to standard output
  while(fgets(cBuffer, sizeof(cBuffer), file) != NULL){
    printf("%s", cBuffer);
  }
  fclose(file);
}

int main(int argc, char *argv[]){
  // Iterate through each file specified on the command line if there are any arguments
  if(argc > 1){
    for(int i = 1; i < argc; i++){
      printFileContents(argv[i]);
    }
  }
  return 0;
}
