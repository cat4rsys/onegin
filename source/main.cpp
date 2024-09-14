#include <cstdio>
#include "input.h"
#include "utilities.h"
#include "sort.h"

int main()
{
    File text = readFile(fopen("files/Eugene_Onegin.txt", "rb"));

    prepareFile(&text);

    universalBubbleSort( (void **) text.pointers, (size_t) text.numOfLines, sizeof(char *), compareLinesFromAToZ);
    printText( text.pointers, (size_t) text.numOfLines, fopen("files/Sorted_Onegin.txt", "w") );

    universalBubbleSort( (void **) text.pointers, (size_t) text.numOfLines, sizeof(char *), compareLinesFromZToA);
    printText( text.pointers, (size_t) text.numOfLines, fopen("files/Reverse_Sorted_Onegin.txt", "w") );

    return 0;
}
