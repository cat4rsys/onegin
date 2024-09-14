#ifndef UTILITIES_H
#define UTILITIES_H

#include "stdio.h"
#include "input.h"

#define CASSERT(expression) {                                               \
    if( !(expression) ) {                                                   \
        printf("Assertion failed: file %s, line %d\n", __FILE__, __LINE__); \
    }                                                                       \
}

int readSizeOfFile( FILE * file );

int compareLines( const char * firstLine, const char * secondLine );

void changeLines( int numOfFirstLine, int numOfSecondLine, char ** pointer );

void bubbleSort( char ** pointer, int numOfLines );

#endif // UTILITIES_H
