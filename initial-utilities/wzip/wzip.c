/*
Sources: https://www.geeksforgeeks.org/dsa/run-length-encoding/
AI usage: AI usage: Checking grammar, style and spelling
*/

// Implements a simple run-length encoding (RLE) compression algorithm.
// Compresses input files by replacing
// consecutive occurrences of the same character
// with the character and the number of times it appears consecutively.
// Outputs the compressed data in binary format to stdout.
#include <stdio.h>
#include <stdlib.h>

#define ERROR_OPEN_FILE "wzip: can not open file %s\n"
#define ERROR_ARGUMENTS "wzip: file1 [file2 ...]\n"

// Write the count and character to stdout if count is greater than 0
void writeToStdout(int iCount, char cPreviousCharacter){
  if(iCount > 0){
    fwrite(&iCount, sizeof(int), 1, stdout);
    fwrite(&cPreviousCharacter, sizeof(char), 1, stdout);
  }
}

void compressFile(FILE *file, char *cPreviousCharacter, int *iCount){
  char cCurrentCharacter;

  while((cCurrentCharacter = fgetc(file)) != EOF){
    if(cCurrentCharacter == *cPreviousCharacter){
      (*iCount)++;
    }else{
      writeToStdout(*iCount, *cPreviousCharacter);
      *cPreviousCharacter = cCurrentCharacter;
      *iCount = 1;
    }
  }
}

int main(int argc, char *argv[]){
  char cPreviousCharacter = EOF;
  int iCount = 0;
  FILE *file = NULL;

  // Check if at least one file is provided
  if(argc < 2){
    fprintf(stdout, ERROR_ARGUMENTS);
    exit(1);
  }
  
  // Open each file provided as an argument
  for(int i = 1; i < argc; i++){
    file = fopen(argv[i], "r");
    if(!file){
      fprintf(stderr, ERROR_OPEN_FILE, argv[i]);
      exit(1);
    }
    // The compressing process
    compressFile(file, &cPreviousCharacter, &iCount);  
    fclose(file);
  }
  // Write out the final run
  writeToStdout(iCount, cPreviousCharacter);

  return 0;
}
