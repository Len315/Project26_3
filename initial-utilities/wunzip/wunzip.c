/*
Sources: https://www.geeksforgeeks.org/dsa/run-length-encoding/
AI usage: Checking grammar, style and spelling
*/

// Unzip zipped files using run-length encoding (RLE).
// Reads compressed binary data from a single file.
// Outputs the decompressed data to stdout.
#include <stdio.h>
#include <stdlib.h>

#define ERROR_OPEN_FILE "wunzip: cannot open file %s\n"
#define ERROR_FILE_FORMAT "wunzip: file format error\n"
#define ERROR_ARGUMENTS "wunzip: file1 [file2 ...]\n"

// Function to decompress a single file
void unzipFile(FILE *file){
  int iCount = 0;// Number of times the character is repeated
  char cCharacter = EOF;

  // Unzip the compressed file
  while(fread(&iCount, sizeof(int), 1, file) == 1){
    if(fread(&cCharacter, sizeof(char), 1, file) != 1){
      fprintf(stderr, ERROR_FILE_FORMAT);
      exit(1);
    }
    for(int i = 0; i < iCount; i++){
      fprintf(stdout, "%c", cCharacter);
    }
  }
}

int main(int argc, char *argv[]){
  FILE *file = NULL;
  
  // Check if at least one file is provided
  if(argc < 2){
    fprintf(stdout, ERROR_ARGUMENTS);
    exit(1);
  }
  // Iterate through each file provided as an argument
  for(int i = 1; i < argc; i++){
    file = fopen(argv[i], "rb");
    if(!file){
      fprintf(stderr, ERROR_OPEN_FILE, argv[i]);
      exit(1);
    }
    unzipFile(file);
    fclose(file);
  }
  return 0;
}
