#include <stdio.h>
#include <stdlib.h>
#include "csv-handler.h"

int main() {
    printf("Start of the program\n");
    
    //** IMPORTANT PART **/
    // Variable Needed
    int *output_array;
    int size;
    //********************/

    printf("Declare and Define the necessary variable\n");

    readCSV("input.csv", &output_array, &size);

    // Printout all the array content
    for (int i = 0; i < size; i++) {
        printf("%d\n", output_array[i]);
    }

    createCSV("output.csv", &output_array, &size);

    //** IMPORTANT PART **/
    free(output_array);
    //********************/
    return 0;
}