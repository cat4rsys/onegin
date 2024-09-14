#ifndef SORT_H
#define SORT_H
#include <cstdio>

typedef int (* compare_funcptr)(const void * firstElem, const void * secondElem);

int compareLinesFromAToZ( const void * firstPtr, const void * secondPtr );

int compareLinesFromZToA( const void * firstPtr, const void * secondPtr );

void changeLines( int numOfFirstLine, int numOfSecondLine, size_t sizeOfElem, char ** pointer );

void universalBubbleSort( void ** data, size_t sizeOfData, size_t sizeOfElem, compare_funcptr comparing );

#endif // SORT_H
