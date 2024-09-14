#include <cstdio>
#include "input.h"
#include "utilities.h"

int main()
{
    File text = readFile(fopen("files/Eugene_Onegin.txt", "rb"));
    prepareFile(&text);

    bubbleSort(text.pointers, text.numOfLines);

    FILE * output = fopen("files/Sorted_Onegin.txt", "w");

    for (int numOfReadedLines = 0; numOfReadedLines < text.numOfLines; numOfReadedLines++) {
        fputs(text.pointers[numOfReadedLines], output);
        fputc('\n', output);
    }

    return 0;
}
