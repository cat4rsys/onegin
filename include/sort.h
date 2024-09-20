#ifndef SORT_H
#define SORT_H
#include <cstdio>

typedef int (* compare_funcptr)(const void * firstElem, const void * secondElem);

int compareLinesFromAToZ( const void * firstPtr, const void * secondPtr );

int compareLinesFromZToA( const void * firstPtr, const void * secondPtr );

int compareLinesFromBack( const void * firstPtr, const void * secondPtr );

void changePointers( size_t numOfFirstLine, size_t numOfSecondLine, void ** pointer );

void universalBubbleSort( void ** data, size_t sizeOfData, compare_funcptr comparing );

void quickSort( void ** data, size_t low, size_t high, compare_funcptr comparing );

size_t distribution( void ** data, size_t low, size_t high, size_t pivot, compare_funcptr comparing);

#endif // SORT_H
