#include "sort.h"
#include "input.h"
#include "utilities.h"

int compareLinesFromAToZ( const void * firstPtr, const void * secondPtr )
{
    const char * firstLine  = (*(*( (InfoAboutLine * const *) firstPtr  ))).pointerOfBeginning;
    const char * secondLine = (*(*( (InfoAboutLine * const *) secondPtr ))).pointerOfBeginning;
    //printf("%s x %s\n", firstLine, secondLine);

    int currentSymbol = 0;
    for( ; firstLine[currentSymbol] == secondLine[currentSymbol] && firstLine[currentSymbol] != '\0'; currentSymbol++ );

    return firstLine[currentSymbol] - secondLine[currentSymbol];
}

int compareLinesFromZToA( const void * firstPtr, const void * secondPtr )
{
    const char * firstLine  = (*(*( (InfoAboutLine * const *) firstPtr ))).pointerOfBeginning;
    const char * secondLine = (*(*( (InfoAboutLine * const *) secondPtr ))).pointerOfBeginning;

    int currentSymbol = 0;
    for( ; firstLine[currentSymbol] == secondLine[currentSymbol] && firstLine[currentSymbol] != '\0'; currentSymbol++ );

    return secondLine[currentSymbol] - firstLine[currentSymbol];
}

int compareLinesFromBack( const void * firstPtr, const void * secondPtr )
{
    const char * firstLine          = (*(*( (InfoAboutLine * const *) firstPtr  ))).pointerOfBeginning;
    const size_t lenghtOfFirstLine  = (*(*( (InfoAboutLine * const *) firstPtr  ))).lenghtOfLine;
    const char * secondLine         = (*(*( (InfoAboutLine * const *) secondPtr ))).pointerOfBeginning;
    const size_t lenghtOfSecondLine = (*(*( (InfoAboutLine * const *) secondPtr ))).lenghtOfLine;

    size_t currentSymbol = 1;
    for( ; firstLine[lenghtOfFirstLine - currentSymbol] == secondLine[lenghtOfSecondLine - currentSymbol] &&
           firstLine[lenghtOfFirstLine - currentSymbol] != '\0' && lenghtOfFirstLine >= currentSymbol     &&
           lenghtOfSecondLine >= currentSymbol; currentSymbol++ );

    return firstLine[lenghtOfFirstLine - currentSymbol] - secondLine[lenghtOfSecondLine - currentSymbol];
}

void changePointers( size_t numOfFirstElem, size_t numOfSecondElem, void ** pointer )
{
    void * temp = pointer[numOfFirstElem];
    pointer[numOfFirstElem] = pointer[numOfSecondElem];
    pointer[numOfSecondElem] = temp;

}

void universalBubbleSort( void ** data, size_t sizeOfData, compare_funcptr comparing )
{
    for (size_t numOfSortedElem = 0; numOfSortedElem < sizeOfData; numOfSortedElem++) {
        size_t numOfUsefulElem = sizeOfData - numOfSortedElem - 1;

        for (size_t currentElem = 0; (currentElem < numOfUsefulElem) ; currentElem++) {
            if ( comparing( (data + currentElem), (data + (currentElem + 1)) ) > 0) {
                changePointers( currentElem, (currentElem + 1), data);
            }
        }
    }
}
