#ifndef __csv_handler
#define __csv_handler

void readCSV(char *filename, int **output_array, int *size);
void createCSV(char *filename, int **input_array, int *size);

#endif