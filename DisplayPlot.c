#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_FIELD_SIZE 100

static char data[MAX_ROWS][MAX_COLS][MAX_FIELD_SIZE]; // 2D array to store CSV data

int main() 
{

    return 0;
}

void StoreDataFromCSV()
{
    FILE *file = fopen("data.csv", "r"); // Open the CSV file for reading *change the data.csv to the actual csv
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    int rows = 0;
    int cols = 0;

    char buffer[MAX_FIELD_SIZE];

    while (fgets(buffer, sizeof(buffer), file)) { // Read each line from the file
        char *token = strtok(buffer, ","); // Tokenize the line based on commas
        while (token != NULL) {
            strcpy(data[rows][cols], token); // Copy the token into the 2D array
            token = strtok(NULL, ","); // Move to the next token
            cols++;
        }
        cols = 0; // Reset the column count for the next row
        rows++; // Move to the next row
    }

    // Now, data[][] contains the CSV data in a 2D array

    // Print the data for checking
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
        {
            printf("%s\t", data[i][j]); 
        }
        printf("\n"); // Move to the next row
    }

    fclose(file); // Close the file
}



