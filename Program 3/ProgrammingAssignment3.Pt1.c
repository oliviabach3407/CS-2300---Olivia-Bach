/*
Part 1) Write a program which reads the matrix A(2x2 matrix taking the first two column
vectors from the input file) and the vector b(the third column vector) and solve for x in Ax = b
for general A.
If there is a unique solution, your output should be a 2x1 matrix with two lines and two numbers
per line.The output should contain numbers with up to four significant digits.If the system is
unsolvable or inconsistent, then your output should be a single line printing "System
inconsistent". If the system is underdetermined, your output should be a single line printing
"System underdetermined".
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
#define LENGTH 100
#define THREEXTHREE 9
#define TWOXTWO 4
#define TWOXONE 2

//input files -- you might need to change the names depending on what test files you're using 
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\test_input_1.txt";
const char FULL_FILE_PATH2[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\test_input_2.txt";
const char FULL_FILE_PATH3[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\3D_test_input_1.txt";

//output files -- this is where the output is being sent
const char FILE_PATH[] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\";

void getMatrix(double matrixA[TWOXTWO], double vectorB[TWOXONE], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
void gaussAndBack(double matrixA[TWOXTWO], double vectorB[TWOXONE], double solutionX[TWOXONE]);
void writeToFile(const char filePath[LENGTH_FILE_PATH], double solution[TWOXONE], int result);

int main(void) {

    //this if for the new file names for the solution
    char fullFilePath[LENGTH_FILE_PATH];

    FILE* filePtr1 = 0;
    FILE* filePtr2 = 0;

    double mat1A[TWOXTWO] = { 0 };
    double mat2A[TWOXTWO] = { 0 };

    double vec1B[TWOXONE] = { 0 };
    double vec2B[TWOXONE] = { 0 };

    double sol1X[TWOXONE] = { 0 };
    double sol2X[TWOXONE] = { 0 };

    getMatrix(mat1A, vec1B, filePtr1, FULL_FILE_PATH1);
    getMatrix(mat2A, vec2B, filePtr2, FULL_FILE_PATH2);

    //gaussian elimination with back-substitution
   
    gaussAndBack(mat1A, vec1B, sol1X);
    gaussAndBack(mat2A, vec2B, sol2X);

    return 0;
}

//based off of my PA1.Pt1
void writeToFile(const char filePath[LENGTH_FILE_PATH], double solution[TWOXONE], int result) {

	char fullFilePath1[LENGTH_FILE_PATH];

	FILE* filePtr3;

	sprintf(fullFilePath1, "%ssolution%d", filePath, result);
	filePtr3 = fopen(fullFilePath1, "w");

    if (result == 1) {
        fprintf(filePtr3, "System underdetermined\n");
    }
    else if (result == 2) {
        fprintf(filePtr3, "System inconsistent\n");
    }
    else {
        fprintf(filePtr3, "%.4lf\n%.4lf", solution[0], solution[1]);
    }


	fclose(filePtr3);
}
//this function has a lot of the code from my PA2.Pt4
void getMatrix(double matrixA[TWOXTWO], double vectorB[TWOXONE], FILE* filePtr, const char path[LENGTH_FILE_PATH]) {

    double placeholder[THREEXTHREE] = { 0 };

    filePtr = fopen(path, "r");

    if (filePtr == NULL) {
        printf("\nError!\n");
    }
    else {
        for (int i = 0; i < THREEXTHREE; i++) {
            fscanf(filePtr, "%lf", &placeholder[i]);
        }

        fclose(filePtr);
    }

    int k = 0;
    int j = 0;

    for (int i = 0; i < THREEXTHREE; i++) {
        if (i == 2 || i == 5) {
            vectorB[j] = placeholder[i];
            j++;
        }
        else if (placeholder[i] == 0) {

        }
        else {
            matrixA[k] = placeholder[i];
            k++;
        }
    }
}
//had to make this one from scratch - no borrowed code from previous programs
void gaussAndBack(double matrixA[TWOXTWO], double vectorB[TWOXONE], double solutionX[TWOXONE]) {
    if (matrixA[0] == 0 && matrixA[1] == 0 && vectorB[0] == 0) {
        printf("System underdetermined\n");
		writeToFile(FILE_PATH, solutionX, 1);
    }
    else if (matrixA[0] == 0 && matrixA[1] == 0 && vectorB[0] != 0) {
        printf("System inconsistent\n");
		writeToFile(FILE_PATH, solutionX, 2);
    }
    else if (matrixA[0] == 0 && matrixA[1] != 0) {
        double temp = matrixA[0];
        matrixA[0] = matrixA[1];
        matrixA[1] = temp;

        temp = vectorB[0];
        vectorB[0] = vectorB[1];
        vectorB[1] = temp;

        solutionX[1] = vectorB[0] / matrixA[1];

        printf("Solution: (%.4lf, %.4lf)\n", solutionX[0], solutionX[1]);
		writeToFile(FILE_PATH, solutionX, 3);
    }
    else {
        double determinant = matrixA[0] * matrixA[3] - matrixA[1] * matrixA[2];

        if (determinant == 0) {
            printf("System inconsistent\n");
			writeToFile(FILE_PATH, solutionX, 2);
        }
        else {
            solutionX[0] = (matrixA[3] * vectorB[0] - matrixA[1] * vectorB[1]) / determinant;
            solutionX[1] = (matrixA[0] * vectorB[1] - matrixA[2] * vectorB[0]) / determinant;

            printf("Solution: (%.4lf, %.4lf)\n", solutionX[0], solutionX[1]);
			writeToFile(FILE_PATH, solutionX, 3);
        }
    }
}