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

//input file -- you might need to change the names depending on what test files you're using 
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\test_input_p3.txt";

void getPoints(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
double pointLength(double point[THREE]);
void subtractPoints(double point1[THREE], double point2[THREE], double total[THREE]);
void addPoints(double point1[THREE], double point2[THREE], double total[THREE]);
bool ifZero(double temp[MAX], int i);
void multiplyPointScalar(double point[THREE], double scalar, double total[THREE]);
void normalize(double point[THREE], double total[THREE]);
double dotProduct(double point1[THREE], double point2[THREE]);
int getSize(double temp[MAX]);
bool isStochastic(double temp[MAX], int rowcolumn);
void powerMethod(double* temp, int dimension, double* eigenvector, int* index_vector);

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
        double* eigenvectors = malloc(size * sizeof(double));
        int* indexes = malloc(size * sizeof(int)); 

        powerMethod(temp, size, eigenvectors, indexes);

        for (int i = 0; i < size; i++) {
            printf("%.2lf  ", eigenvectors[i]);
        }

        puts("\n");

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

void powerMethod(double* temp, int dimension, double* eigenvector, int* index_vector) {

    // initialize eigenvector to a uniform distribution
    double norm = sqrt(dimension);
    for (int i = 0; i < dimension; i++) {
        eigenvector[i] = 1.0 / norm;
    }

    // iterate until convergence or max iterations reached
    int iter = 0;
    double error = TOLERANCE + 1.0;
    while (error > TOLERANCE && iter < MAX_ITERATIONS) {
        // calculate matrix-vector product
        double* new_vector = malloc(dimension * sizeof(double));

        for (int i = 0; i < dimension; i++) {
            double sum = 0.0;
            for (int j = 0; j < dimension; j++) {
                sum += temp[i * dimension + j] * eigenvector[j];
            }
            new_vector[i] = sum;
        }

        // normalize and calculate error
        double new_norm = 0.0;
        for (int i = 0; i < dimension; i++) {
            new_norm += new_vector[i] * new_vector[i];
        }
        new_norm = sqrt(new_norm);
        error = 0.0;
        for (int i = 0; i < dimension; i++) {
            double diff = fabs(new_vector[i] / new_norm - eigenvector[i] / norm);
            if (diff > error) {
                error = diff;
            }
            eigenvector[i] = new_vector[i] / new_norm;
        }
        norm = new_norm;
        iter++;

        free(new_vector);
    }

    // calculate index vector by sorting eigenvector
    for (int i = 0; i < dimension; i++) {
        index_vector[i] = i;
    }
    for (int i = 0; i < dimension - 1; i++) {
        for (int j = i + 1; j < dimension; j++) {
            if (eigenvector[index_vector[i]] < eigenvector[index_vector[j]]) {
                int temp_index = index_vector[i];
                index_vector[i] = index_vector[j];
                index_vector[j] = temp_index;
            }
        }
    }
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

void normalize(double point[THREE], double total[THREE]) {

    double pointsLength = 0;

    pointsLength = pointLength(point);

    total[0] = point[0] / pointsLength;
    total[1] = point[1] / pointsLength;
    total[2] = point[2] / pointsLength;
}

double dotProduct(double point1[THREE], double point2[THREE]) {

    double total = 0;

    total = point1[0] * point2[0] + point1[1] * point2[1] + point1[2] * point2[2];

    return total;

}

void multiplyPointScalar(double point[THREE], double scalar, double total[THREE]) {

    total[0] = point[0] * scalar;
    total[1] = point[1] * scalar;
    total[2] = point[2] * scalar;
}

void subtractPoints(double point1[THREE], double point2[THREE], double total[THREE]) {

    total[0] = point1[0] - point2[0];
    total[1] = point1[1] - point2[1];
    total[2] = point1[2] - point2[2];
}

void addPoints(double point1[THREE], double point2[THREE], double total[THREE]) {

    total[0] = point1[0] + point2[0];
    total[1] = point1[1] + point2[1];
    total[2] = point1[2] + point2[2];
}

double pointLength(double point[THREE]) {

    double length = 0;

    length = sqrt(pow(point[0], 2) + pow(point[1], 2) + pow(point[2], 2));

    return length;
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