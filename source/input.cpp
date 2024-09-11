#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <input.h>

File readFile( FILE * inputFile )
{
    assert(inputFile != NULL);

    File allFile = {};

    fseek(inputFile, 0L, SEEK_END);
    int sizeOfFile = ftell(inputFile) + 1;

    allFile.str = (char * )calloc(sizeOfFile, sizeof(char));
    assert(allFile.str != 0);

    fseek(inputFile, 0L, SEEK_SET);
    allFile.numOfElements = fread(allFile.str, sizeof(char), sizeOfFile, inputFile);

    fclose(inputFile);

    return allFile;
}

void divisionLines(File * allFile)
{
    allFile->numOfLines = 1;

    for (int currentFilePos = 0; currentFilePos < allFile->numOfElements; currentFilePos++) {
        if ( *(allFile->str + currentFilePos) == '\n' ) {
            *(allFile->str + currentFilePos) = '\0';
            allFile->numOfLines++;
        }
    }
}

void readPointersOfLines(File * allFile)
{
    allFile->pointers = (char **)calloc(allFile->numOfLines, sizeof(char *));
    *(allFile->pointers) = allFile->str;
    int readedLines = 1;

    for (int currentFilePos = 0; currentFilePos < allFile->numOfElements; currentFilePos++) {
        if ( *(allFile->str + currentFilePos) == '\0' ) {
            *(allFile->pointers + readedLines) = allFile->str + currentFilePos + 1;
            readedLines += 1;
            if (readedLines == allFile->numOfLines) {
                currentFilePos = allFile->numOfElements;
            }
        }
    }
}


