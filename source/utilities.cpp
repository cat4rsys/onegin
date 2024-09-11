#include <cstdio>
#include "utilities.h"
#include "input.h"

int compareLines( const char * firstLine, const char * secondLine )
{
    int currentSymbol = 0;
    for( ; firstLine[currentSymbol] == secondLine[currentSymbol] && firstLine[currentSymbol] != '\0'; currentSymbol++ );

    return firstLine[currentSymbol] - secondLine[currentSymbol];
}

void changeLines( int numOfFirstLine, int numOfSecondLine, char ** pointer )
{
    char * temp = pointer[numOfFirstLine];
    pointer[numOfFirstLine] = pointer[numOfSecondLine];
    pointer[numOfSecondLine] = temp;
}

void bubbleSort( char ** pointer, int numOfLines )
{
    for (int numOfSortedLines = 0; numOfSortedLines < numOfLines; numOfSortedLines++) {
        int numOfUsefulLines = numOfLines - numOfSortedLines - 1;

        for (int currentLine = 0; currentLine < numOfUsefulLines; currentLine++) {
            if ( compareLines(pointer[currentLine], pointer[currentLine + 1]) > 0) {
                changeLines(currentLine, currentLine + 1, pointer);
            }
        }
    }
}
