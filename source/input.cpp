#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <input.h>
#include <utilities.h>

File readFile( FILE * inputFile )
{
    CASSERT(inputFile != NULL);

    File allFile = {};

    allFile.numOfElements = readSizeOfFile(inputFile);

    allFile.str = (char * )calloc( allFile.numOfElements, sizeof(char) );
    CASSERT(allFile.str != NULL);

    fread(allFile.str, sizeof(char), allFile.numOfElements, inputFile);

    fclose(inputFile);

    return allFile;
}

void prepareFile( File * inputFile )
{
    divisionLines(inputFile);
    readPointersOfLines(inputFile);
}

void divisionLines(File * allFile)
{
    allFile->numOfLines = 1;

    for (int currentFilePos = 0; currentFilePos < allFile->numOfElements; currentFilePos++) {
        if ( *(allFile->str + currentFilePos) == '\r' ) {
            *(allFile->str + currentFilePos) = '\0';
            allFile->numOfLines++;
        }
    }

    *( (allFile->str) + (allFile->numOfElements - 1) ) = '\0';
}

void readPointersOfLines(File * allFile)
{
    allFile->pointers = (char **)calloc(allFile->numOfLines, sizeof(char *));
    *(allFile->pointers) = allFile->str;
    int readedLines = 1;

    for (int currentFilePos = 0; currentFilePos < allFile->numOfElements; currentFilePos++) {
        if ( *(allFile->str + currentFilePos) == '\n' ) {
            *(allFile->pointers + readedLines) = allFile->str + currentFilePos + 1;
            readedLines += 1;

            if (readedLines == allFile->numOfLines) {
                currentFilePos = allFile->numOfElements;
            }
        }
    }

    if ( *( (allFile->str) + (allFile->numOfElements - 2) ) == '\n' )
    {
        allFile->numOfLines -= 1;
    }
}


