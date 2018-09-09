
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv-handler.h"

#define ARRAY_MAX 5
#define LINE_MAX 1024

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}


void readCSV(char *filename, int **output_array, int *size)
{
    printf("Reading %s file\n",filename);

    // Assumes filename already has csv format
    FILE *stream = fopen(filename, "r");
    char line[LINE_MAX];

    int *temporary_array = (int*) calloc(ARRAY_MAX, sizeof(int));

    *output_array = temporary_array;

    int i = 0;
    while (fgets(line, LINE_MAX, stream))
    {
        char* tmp = strdup(line);
        temporary_array[i] = atoi(getfield(tmp, 1));
        // NOTE strtok clobbers tmp
        i++;
        free(tmp);
    }

    // Return real size of the array
    *size = i;
}

void createCSV(char *filename, int **input_array, int *size) {
    // Assume filename already include the .csv part
    printf("Creating %s file\n",filename);

    FILE *stream;

    stream = fopen(filename,"w+");
    
    for (int i = 0; i < *size; i++) {
        fprintf(stream, "%d,\n", (*input_array)[i]);
    }

    fclose(stream);

    printf("%s file created\n",filename);
}