/**
 *
 * This program parses lines from stdio.
 * It will stdout every line of a file.
 * When it sees a
 * >>>"relative/path/to/file.txt"
 * it will output that file instead of the next line.
 * Afterwards it will continue with the original input.
 * This has been created as a simple solution for including snippets like
 * headers and footers to HTML-files.
 *
 * USAGE: executable ./path/to/sourcefile
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>



void outputFile(char *filePath) {

  // open file with fopen(), read only
  FILE *sourceFile;
  sourceFile = fopen(filePath, "r");

  if(sourceFile == NULL) {

    printf("Couldn't open file %s\n", filePath);
    return;

  } else {


    // placeholder for each line being iterated over
    char lineBuffer[500] = "";

    // for each line of the sourceFile, repeat
    while( fgets(lineBuffer, sizeof lineBuffer, sourceFile) ) {

      // Reset to original path
      char *pathToActiveFile = dirname(filePath);

      // check if the current line is not empty
      if( sscanf(lineBuffer, "%500[^\n]\n", lineBuffer) ) {

        // if line contains the string ">>>", this is an include-line
        if(strstr(lineBuffer, ">>>")) {

          // placeholder for the file path, which will now be read from the line
          char *relativePathToIncludedFile;
          // parse the full path out of the quotation-marks on the include-line
          relativePathToIncludedFile = strtok(lineBuffer, "\"");
          relativePathToIncludedFile = strtok(NULL, "\"");

          // Need to copy filePath, since dirname() will destroy it
          char backupFilePath[500];
          strcpy(backupFilePath, filePath);
          char *pathToActiveFile = dirname(backupFilePath);

          char fullPathToIncludedFile[500] = "";
          strcat(fullPathToIncludedFile, pathToActiveFile);
          strcat(fullPathToIncludedFile, "/");
          strcat(fullPathToIncludedFile, relativePathToIncludedFile);

          //call self-function recursively and do same on the included file
          outputFile(fullPathToIncludedFile);

        } else {
          // if it's not an include-line, just print out the line to stdout
          printf("%s\n", lineBuffer);
        }
      }
    }

    //close file when done
    fclose(sourceFile);
  }
}


int main(int argc, char * argv[]) {

  if(argc < 2) {
    printf("Some arguments may be missing!");
  }
  outputFile(argv[1]);
  return 0;
}
