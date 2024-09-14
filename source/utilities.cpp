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

int compareLinesFromAToZ( const void * firstPtr, const void * secondPtr )
{
    const char * firstLine = *( (const char **) firstPtr );
    const char * secondLine = *( (const char **) secondPtr );

    int currentSymbol = 0;
    for( ; firstLine[currentSymbol] == secondLine[currentSymbol] && firstLine[currentSymbol] != '\0'; currentSymbol++ );

    return firstLine[currentSymbol] - secondLine[currentSymbol];
}

int compareLinesFromZToA( const void * firstPtr, const void * secondPtr )
{
    const char * firstLine = *( (const char **) firstPtr );
    const char * secondLine = *( (const char **) secondPtr );

    int currentSymbol = 0;
    for( ; firstLine[currentSymbol] == secondLine[currentSymbol] && firstLine[currentSymbol] != '\0'; currentSymbol++ );

    return secondLine[currentSymbol] - firstLine[currentSymbol];
}

void changePointers( int numOfFirstElem, int numOfSecondElem, size_t sizeOfElem, void ** pointer )
{
    void * temp = *( pointer + numOfFirstElem );
    *(pointer + numOfFirstElem) = *(pointer + numOfSecondElem);
    *(pointer + numOfSecondElem) = temp;
}

void universalBubbleSort( void ** data, size_t sizeOfData, size_t sizeOfElem, compare_funcptr comparing )
{
    for (int numOfSortedElem = 0; numOfSortedElem < sizeOfData; numOfSortedElem++) {
        int numOfUsefulElem = sizeOfData - numOfSortedElem - 1;

        for (int currentElem = 0; currentElem < numOfUsefulElem; currentElem++) {
            if ( comparing( (data + currentElem), (data + (currentElem + 1)) ) > 0) {
                changePointers(currentElem, currentElem + 1, sizeOfElem, data);
            }
        }
    }
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
