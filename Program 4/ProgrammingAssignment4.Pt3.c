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
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\InputHW4_Part3";

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
int getSize(double temp[MAX]);
bool isStochastic(double temp[MAX], int rowcolumn);

int main() {

    double temp[MAX] = { 0 };
    int size = 0;

    FILE* filePtr1 = 0;

    getPoints(temp, filePtr1, FULL_FILE_PATH1);

    //this gives us the number of rows and columns
    size = sqrt(getSize(temp)); 

    //--Output both i) the eigenvector for the webpagesand ii) the vector whose elements are the
    //webpage indices after sorting from the highest rank to the lowest rank; the output should include
    //these in separate lines.
    if (isStochastic(temp, size)) {

    }
    //-- Print "Invalid input" (for example, the input file includes a negative number or the matrix is
    //not stochastic), or
    else {
        puts("\nInvalid input.");
    }



}

//no negatives + columns/rows add to 1
bool isStochastic(double temp[], int rowcolumn) {

    bool stochastic = true;

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

        //check that the sum of the row and the column is equal to 1
        if (row_sum != 1 || column_sum != 1) {
            stochastic = false;
            return stochastic;
        }
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