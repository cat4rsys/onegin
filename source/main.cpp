#include <cstdio>
#include "input.h"
#include "utilities.h"

int main()
{
    File text = readFile(fopen("files/Eugene_Onegin.txt", "r"));
    divisionLines(&text);
    readPointersOfLines(&text);

    bubbleSort(text.pointers, text.numOfLines);

    for (int numOfReadedLines = 0; numOfReadedLines < text.numOfLines; numOfReadedLines++) {
        printf("%s\n", text.pointers[numOfReadedLines]);
    }

    return 0;
}
