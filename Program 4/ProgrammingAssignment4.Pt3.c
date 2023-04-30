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
#define MAX 99
#define THREE 3
#define MAX_ITERATIONS 1000
#define TOLERANCE 1e-6

//input files -- you might need to change the names depending on what test files you're using 
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\test_file_2.txt";
const char FULL_FILE_PATH2[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\test_input_2.txt";
const char FULL_FILE_PATH3[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\3D_test_input_1.txt";

//output files -- this is where the output is being sent
const char FILE_PATH[] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\";

void getPoints(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
void createDivideArray(double placeholder[MAX]);
void fillPoints(double temp[MAX], int i, double point1[THREE], double point2[THREE], double point3[THREE]);
double pointLength(double point[THREE]);
void subtractPoints(double point1[THREE], double point2[THREE], double total[THREE]);
void addPoints(double point1[THREE], double point2[THREE], double total[THREE]);
bool ifZero(double temp[MAX], int i);
void multiplyPointScalar(double point[THREE], double scalar, double total[THREE]);
void normalize(double point[THREE], double total[THREE]);
double dotProduct(double point1[THREE], double point2[THREE]);
void writeToFile(const char filePath[LENGTH_FILE_PATH], double answer);

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: pagerank input_file\n");
        exit(1);
    }

    char* filename = argv[1];

    // Open input file
    FILE* input_file = fopen(filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: cannot open input file %s\n", filename);
        exit(1);
    }

    // Read matrix size from input file
    int n;
    fscanf(input_file, "%d", &n);

    // Allocate memory for matrix and vector
    double** matrix = (double**)malloc(n * sizeof(double*));
    double* vector = (double*)malloc(n * sizeof(double));
    double* temp_vector = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
        vector[i] = 1.0 / n;  // initialize vector to 1/n
    }

    // Read matrix from input file and check for errors
    for (int i = 0; i < n; i++) {
        double row_sum = 0.0;
        for (int j = 0; j < n; j++) {
            if (fscanf(input_file, "%lf", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error: invalid input in row %d, column %d\n", i, j);
                exit(1);
            }
            if (matrix[i][j] < 0.0 || matrix[i][j] > 1.0) {
                fprintf(stderr, "Error: invalid input in row %d, column %d\n", i, j);
                exit(1);
            }
            row_sum += matrix[i][j];
        }
        if (fabs(row_sum - 1.0) > TOLERANCE) {
            fprintf(stderr, "Error: row %d does not sum to 1\n", i);
            exit(1);
        }
    }

    // Close input file
    fclose(input_file);

    // Iterate using power method
    for (int k = 0; k < MAX_ITERATIONS; k++) {
        // Compute matrix-vector product
        for (int i = 0; i < n; i++) {
            temp_vector[i] = dotProduct(matrix[i], vector, n);
        }
        // Normalize result
        normalize(temp_vector, n);
        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += fabs(temp_vector[i] - vector[i]);
        }
        if (error < TOLERANCE) {
            break;
        }
        // Update vector
        for (int i = 0; i < n; i++) {
            vector[i] = temp_vector[i];
        }
    }

    // Check for convergence
    if (k == MAX_ITERATIONS) {
        fprintf(stderr, "Error: power method did not converge\n");
        exit(1);
    }

    // Output eigenvector
    printf("Eigenvector:\n");
    for (int i = 0; i < n; i++) {
        printf("%f\n", vector[i]);
    }

    // Sort vector indices
    int* indices = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vector[i] < vector[j]) {
                double temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
                int temp_index = indices[i];
                indices[i] = indices[j];
                indices[j] = temp_index;
            }
        }
    }

    // Output sorted indices
    printf("Sorted indices:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", indices[i]);
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(vector);
    free(temp_vector);
    free(indices);

    return 0;
}


double dotProduct(double point1[THREE], double point2[THREE]) {

    double total = 0;

    total = point1[0] * point2[0] + point1[1] * point2[1] + point1[2] * point2[2];

    return total;

}

void normalize(double point[THREE], double total[THREE]) {

    double pointsLength = 0;

    pointsLength = pointLength(point);

    total[0] = point[0] / pointsLength;
    total[1] = point[1] / pointsLength;
    total[2] = point[2] / pointsLength;
}
