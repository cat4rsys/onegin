#include <cstdio>
#include "input.h"
#include "utilities.h"
#include "sort.h"

int main()
{
    File text = readFile(fopen("files/Eugene_Onegin.txt", "rb"));

    prepareFile(&text);

    quickSort( (void **) text.arrayOfInfoAboutLines, 0, (size_t) text.numOfLines - 1, clearCompareLinesFromAToZ);
    printText( text.arrayOfInfoAboutLines, (size_t) text.numOfLines, fopen("files/Sorted_Onegin.txt", "wb") );

    quickSort( (void **) text.arrayOfInfoAboutLines, 0, (size_t) text.numOfLines - 1, clearCompareLinesFromZToA);
    printText( text.arrayOfInfoAboutLines, (size_t) text.numOfLines, fopen("files/Reverse_Sorted_Onegin.txt", "wb") );

    quickSort( (void **) text.arrayOfInfoAboutLines, 0, (size_t) text.numOfLines - 1, clearCompareLinesFromBack);
    printText( text.arrayOfInfoAboutLines, (size_t) text.numOfLines, fopen("files/Back_Sorted_Onegin.txt", "wb") );

    printAllText( text.str, (size_t) text.numOfElements, fopen("files/Original_Onegin.txt", "wb") );

    return 0;
}
