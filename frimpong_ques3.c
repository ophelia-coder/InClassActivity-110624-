#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 20

int main() {
    int array[SIZE]; 
    int i = 0;
    FILE* in_file = fopen("scores-data.txt", "r");  // Open the file in read mode
    
    if (!in_file) {  // Check if the file was opened successfully
        printf("Oops, file can't be read\n"); 
        exit(-1); 
    }

    // Attempt to read the values from the file and store them in the array
    while (i < SIZE && fscanf(in_file, "%d", &array[i]) == 1) {
        i++;  // Increment i for each successful read
    }

    fclose(in_file);  // Close the file after reading

    // Check how many elements were actually read
    int n = i;  // Number of elements actually read (not necessarily SIZE)

    // Mode calculation
    int mat[SIZE][2];  // To keep track of elements and their frequencies
    int b, j, counter;
    int counted[SIZE] = {0};  // Array to mark counted elements

    // Populate mat with array entries and their frequencies
    for (b = 0; b < n; ++b) {
        if (counted[b]) continue;  // Skip already counted elements

        mat[b][0] = array[b];  // Store the array entry in mat
        counter = 1;  // Start counter at 1 as each element appears at least once

        for (j = b + 1; j < n; ++j) {
            if (array[j] == array[b]) {
                counter++;  // Increment counter for each occurrence
                counted[j] = 1;  // Mark as counted
            }
        }
        mat[b][1] = counter;  // Store frequency count in mat
        counted[b] = 1;  // Mark the current element as counted
    }

    // Determine the most recurring element (mode)
    int max = mat[0][1];  // Start by assuming the first element is the mode
    int mode = mat[0][0];  // The element corresponding to the highest frequency
    for (b = 1; b < n; ++b) {
        if (mat[b][1] > max) {  // If a new higher frequency is found
            max = mat[b][1];
            mode = mat[b][0];  // Update the mode to this new element
        }
    }

    // Print the mode and its frequency
    printf("The most recurring entry (mode) = %d with frequency %d\n", mode, max);

    // Calculate the average
    double sum = 0.0;
    for (i = 0; i < n; ++i) {
        sum += array[i];
    }
    double avg = sum / n;
    printf("The average score is: %lf\n", avg);

    // Calculate the variance
    double var = 0.0;
    for (i = 0; i < n; ++i) {
        var += pow(array[i] - avg, 2);
    }

    // Calculate the standard deviation
    double sd = sqrt(var / n);  // Divide by the number of elements for the population variance
    printf("The standard deviation is: %lf\n", sd);

    return 0;
}

