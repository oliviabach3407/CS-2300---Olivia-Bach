/*
Let's build the initial Google PageRank algorithm, following the notations and rules in
Section 15.3. Your input file will correspond to a N x N matrix (N rows with each row having N
columns) where the matrix is stochastic with respect to the rows (the columns sum to one) and
includes non-negative elements.
You should implement your program and solve this problem using the power method. Your
program output should either:
-- Print "Invalid input" (for example, the input file includes a negative number or the matrix is
not stochastic), or
-- Output both i) the eigenvector for the webpages and ii) the vector whose elements are the
webpage indices after sorting from the highest rank to the lowest rank; the output should include
these in separate lines.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LENGTH_FILE_PATH 100
#define MAX 1000
#define THREE 3
#define MAX_ITERATIONS 1000
#define TOLERANCE 1e-6

//input file -- you might need to change the names depending on what test files you're using 
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\input_3.txt";

void getPoints(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
bool ifZero(double temp[MAX], int i);
int getSize(double temp[MAX]);
bool isStochastic(double temp[MAX], int rowcolumn);
void powerMethod(double* temp, int dimension, double* eigenvector, int* index_vector);
void multiplyMatrices(int dim, double mat1[], double mat2[], double answer[]);

int main() {

    double temp[MAX] = { 0 };
    int size = 0;

    FILE* filePtr1 = 0;

    getPoints(temp, filePtr1, FULL_FILE_PATH1);

    //this gives us the number of rows and columns
    size = sqrt(getSize(temp)); 

    //--Output both i) the eigenvector for the webpagesand ii) the vector whose elements are the
    //webpage indices after sorting from the highest rank to the lowest rank; the output should include //these in separate lines.

    if (isStochastic(temp, size)) {

        //dynamically allocate the size and memory
        double* eigenvectors = malloc((size+1) * sizeof(double));
        int* indexes = malloc((size+1) * sizeof(int)); 

        powerMethod(temp, size, eigenvectors, indexes);

        //printing eigen vectors
        for (int i = 0; i < size; i++) {
            printf("%.4lf  ", eigenvectors[i]);
        }

        puts("\n");

        //printing indexes
        for (int i = 0; i < size; i++) {
            printf("%d  ", indexes[i]); 
        }

        free(eigenvectors);
        free(indexes);
    }
    //-- Print "Invalid input" (for example, the input file includes a negative number or the matrix is
    //not stochastic), or
    else {
        puts("\nInvalid input.");
    }

    return 0;
}

//just used the formulas from my notes to figure this one out - lots of trial and error
void powerMethod(double* temp, int dimension, double* eigenvector, int* index_vector) {
    int iterations = 0;
    double* starting = NULL;
    double* sortedEigen = NULL;

    //initialize the eigenvector and index_vector arrays
    for (int i = 0; i < dimension; i++) {
        eigenvector[i] = 0.0;
        index_vector[i] = i + 1; // modify index_vector to start at 1
    }

    // dynamically allocate memory for the array of size dimension
    starting = (double*)malloc(dimension * sizeof(double));
    sortedEigen = (double*)malloc(dimension * sizeof(double));

    // need to initialize it with all 1's as a sample starting array
    for (int i = 0; i < dimension; i++) {
        starting[i] = 1;
    }

    //initialize to 0
    double* next = NULL;
    next = (double*)malloc(dimension * sizeof(double));
    for (int i = 0; i < dimension; i++) {
        next[i] = 0;
    }

    while (iterations < MAX_ITERATIONS) {

        //multiply temp and starting 
        multiplyMatrices(dimension, temp, starting, next);

        //calculate the largest element of next, which is the largest eigenvalue
        double largest = next[0];
        for (int i = 1; i < dimension; i++) {
            if (fabs(next[i]) > fabs(largest)) {
                largest = next[i];
            }
        }

        //normalize next to get the eigenvector
        for (int i = 0; i < dimension; i++) {
            next[i] = next[i] / largest;
        }

        //update starting to be the new eigenvector
        memcpy(starting, next, dimension * sizeof(double));

        iterations++;
    }

    //copy the eigenvector into the eigenvector array
    memcpy(eigenvector, next, dimension * sizeof(double));

    //copy the eigenvectors into sortedEigen so that we can sort
    memcpy(sortedEigen, eigenvector, dimension * sizeof(double));

    //calculate index vector by sorting eigenvector with indices
    for (int i = 1; i <= dimension; i++) { // modify index vector to start at 1
        index_vector[i - 1] = i;
    }
    //sorting the eigenvectors
    for (int i = 0; i < dimension - 1; i++) {
        for (int j = i + 1; j < dimension; j++) {
            if (sortedEigen[i] < sortedEigen[j]) {
                double temp_eigen = sortedEigen[i];
                sortedEigen[i] = sortedEigen[j];
                sortedEigen[j] = temp_eigen;
            }
        }
    }

    //find index vector based on sortedEigen
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (sortedEigen[i] == eigenvector[j])
            {
                index_vector[i] = j+1;
            }
        }
    }

    //free dynamically allocated memory
    free(starting);
    free(next);
    free(sortedEigen);
}

//I had to use a combination of my notes from CS2060 and this resource 
//https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
//to be able to figure out how to do this part
void multiplyMatrices(int dim, double mat1[], double mat2[], double answer[]) {

    //should be a square matrix of size dim^2
    double* A = (double*)malloc(dim * dim * sizeof(double));

    //will be a matrix of dimx1
    double* B = (double*)malloc(dim * sizeof(double));

    //means the answer will be dimx1 as well
    double* C = (double*)malloc(dim * sizeof(double));

    //Copy mat1 and mat2 into A and B, respectively
    memcpy(A, mat1, dim * dim * sizeof(double));
    memcpy(B, mat2, dim * sizeof(double));

    // Compute the product A * B = C
    for (int i = 0; i < dim; i++) {
        double sum = 0;
        for (int j = 0; j < dim; j++) {
            sum += A[i * dim + j] * B[j];
        }
        C[i] = sum;
    }

    //Copy the result back into the answer array
    memcpy(answer, C, dim * sizeof(double));

    //Free the memory
    free(A);
    free(B);
    free(C);

    //have to do the memory allocation with A,B, and C
    //so that you don't cause issues with the arrays 
    //that are actually being passed
}

//no negatives + columns/rows add to 1
bool isStochastic(double temp[MAX], int rowcolumn) {

    double epsilon = 0.5; //tolerance range -- I had to make this pretty large (wouldn't work with 0.1, 0.01, 0.001, etc)

    bool stochastic = true;
    bool rowStochastic = true;
    bool colStochastic = true;

    for (int i = 0; i < rowcolumn; i++) {
        double row_sum = 0;
        double column_sum = 0;

        for (int j = 0; j < rowcolumn; j++) {
            double value = temp[i * rowcolumn + j];

            if (value < 0) {
                //if any value is negative, the matrix is not stochastic
                stochastic = false;
                return stochastic;
            }

            row_sum += value;
            column_sum += temp[j * rowcolumn + i];
        }

        //checking based on tolerance
        if (fabs(row_sum - 1.0) > epsilon) {
            //if row_sum is not equal to 1, the matrix is not stochastic
            rowStochastic = false;
        }

        if (fabs(column_sum - 1.0) > epsilon) {
            //if column_sum is not equal to 1, the matrix is not stochastic
            colStochastic = false;
        }
    }

    //if either the rows are good or the columns are good, then it's stochastic
    if (rowStochastic || colStochastic) {
        stochastic = true;
    }
    else {
        stochastic = false;
    }

    return stochastic;
}

int getSize(double temp[MAX]) {
    
    int count = 0;

    for (int i = 0; i < MAX; i++) {
        if (ifZero(temp, i)) {
            //don't want to increment count if the line is zero

        }
        else {
            count++;
        }
    }

    return count;
}

bool ifZero(double temp[MAX], int i) {

    if (temp[i] == 0 && temp[i + 1] == 0 && temp[i + 2] == 0 && temp[i + 3] == 0 && temp[i + 4] == 0 && temp[i + 5] == 0 && temp[i + 6] == 0 && temp[i + 7] == 0 && temp[i + 8] == 0) {
        return true;
    }
    return false;
}

//based off of getMatrix function from PA2 and PA3
void getPoints(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]) {

    filePtr = fopen(path, "r");

    if (filePtr == NULL) {
        printf("\nError!\n");
    }
    else {
        for (int i = 0; i < MAX; i++) {
            fscanf(filePtr, "%lf", &placeholder[i]);
        }

        fclose(filePtr);
    }
}