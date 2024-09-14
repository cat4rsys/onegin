#include <cstdio>
#include "utilities.h"
#include "input.h"

int readSizeOfFile( FILE * file )
{
    fseek(file, 0L, SEEK_END);
    int sizeOfFile = (int)ftell(file) + 1;

    fseek(file, 0L, SEEK_SET);

    return sizeOfFile;
}

void printText( char ** data, size_t numOfLines, FILE * outputFile )
{
    CASSERT(outputFile);

    for (size_t numOfReadedLines = 0; numOfReadedLines < numOfLines; numOfReadedLines++) {
        fputs(data[numOfReadedLines], outputFile);
        fputc('\n', outputFile);
    }

    fclose(outputFile);
}
