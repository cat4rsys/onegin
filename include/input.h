#ifndef INPUT_H
#define INPUT_H

typedef struct
{
    char * str;
    int numOfElements;
    int numOfLines;
    char ** pointers;
} File;

File readFile( FILE * inputFile );

void divisionLines(File * allFile);

void readPointersOfLines(File * allFile);

#endif // INPUT_H
