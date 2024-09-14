#ifndef UTILITIES_H
#define UTILITIES_H

#include "stdio.h"
#include "input.h"

#define CASSERT(expression) {                                               \
    if( !(expression) ) {                                                   \
        printf("Assertion failed: file %s, line %d\n", __FILE__, __LINE__); \
    }                                                                       \
}

typedef int (* compare_funcptr)(const void * firstElem, const void * secondElem);

int readSizeOfFile( FILE * file );

int compareLinesFromAToZ( const void * firstPtr, const void * secondPtr );

int compareLinesFromZToA( const void * firstPtr, const void * secondPtr );

void changeLines( int numOfFirstLine, int numOfSecondLine, size_t sizeOfElem, char ** pointer );

void universalBubbleSort( void ** data, size_t sizeOfData, size_t sizeOfElem, compare_funcptr comparing );

void printText( char ** data, size_t numOfLines, FILE * outputFile );

#endif // UTILITIES_H
