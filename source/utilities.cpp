#include <cstdio>
#include "utilities.h"
#include "input.h"

int readSizeOfFile( FILE * file )
{
    fseek(file, 0L, SEEK_END);
    int sizeOfFile = ftell(file) + 1;

    fseek(file, 0L, SEEK_SET);

    return sizeOfFile;
}

void printText( char ** data, size_t numOfLines, FILE * outputFile )
{
    CASSERT(outputFile);

    for (int numOfReadedLines = 0; numOfReadedLines < numOfLines; numOfReadedLines++) {
        fputs(data[numOfReadedLines], outputFile);
        fputc('\n', outputFile);
    }

    fclose(outputFile);
}
