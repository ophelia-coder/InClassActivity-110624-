#include <stdio.h>
#include <math.h>

int main() {
    int array[5] = {10, 7, 5, 9, 10};
    double avg = -5.0;
    int mat[5][2];  // To keep track of elements and their frequencies
    int i, j, counter;
    int counted[5] = {0};  // Array to mark counted elements

    // Populate mat with array entries and their frequencies
    for (i = 0; i < 5; ++i) {
        if (counted[i]) continue; // Skip already counted elements

        mat[i][0] = array[i];  // Store the array entry in mat
        counter = 1;  // Start counter at 1 as each element appears at least once

        for (j = i + 1; j < 5; ++j) {
            if (array[j] == array[i]) {
                counter++;  // Increment counter for each occurrence
                counted[j] = 1;  // Mark as counted
            }
        }
        mat[i][1] = counter;  // Store frequency count in mat
        counted[i] = 1;  // Mark the current element as counted
    }

    // Determine the most recurring element (mode)
    int max = mat[0][1];
    int mode = mat[0][0];
    for (i = 1; i < 5; ++i) {
        if (mat[i][1] > max) {
            max = mat[i][1];
            mode = mat[i][0];
        }
    }

    // Print the mode and its frequency
    printf("The most recurring entry (mode) = %d with frequency %d\n", mode, max);

    // Calculate the a

    double sum = 0.0;
    for (i = 0; i < 5; ++i) {
        sum += array[i];
    }
    avg = sum / 5;
    printf("The average score is: %lf\n", avg);

    // Calculate the variance
    double var = 0.0;
    for (i = 0; i < 5; ++i) {
        var += pow(array[i] - avg, 2);
    }
    
    // Calculate the standard deviation
    double sd = sqrt(var / 5); // Divide by the number of elements for the population variance
    
    printf("The standard deviation is: %lf\n", sd);

    return 0;
}

