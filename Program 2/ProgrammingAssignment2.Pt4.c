#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LENGTH 80
#define LENGTH_FILE_PATH 100
#define NUM_SIZES 4
#define NUM_YN 2
#define SIZE 2

void getMatrix(double newMatrix[4]);
void fgetsRemoveNewLine(char* buff);
void getEigenVector(double ogMatrix[4], double lambda);

int main() {
   
	double matrix[4] = {0}; 
	double absLambda1 = 0;
	double absLambda2 = 0;
	double lambda1 = 0;
	double lambda2 = 0;
	double determinant = 0;
	double trace = 0;

	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;

	getMatrix(matrix);

	a = matrix[0];
	b = matrix[1];
	c = matrix[2];
	d = matrix[3];

	trace = a + d;
	determinant = ((a * d) - (b * c));

	lambda1 = (trace + sqrt(trace * trace - 4 * determinant)) / 2;
    lambda2 = (trace - sqrt(trace * trace - 4 * determinant)) / 2;

	puts("\n-----------------------------------------");

    printf("\n\n\nCharacteristic equation: x^2 - %.2fx + %.2f = 0\n", trace, determinant);
    printf("\nEigenvalues: %.2f, %.2f\n", lambda1, lambda2);

	//get absolute values of lambda values
	if (lambda1 < 0) {
		absLambda1 = -(lambda1);
	}

	if (lambda2 < 0) {
		absLambda2 = -(lambda2);
	}

	//figure out which lambda is the dominant one and calculate vectors
    if (absLambda1 > absLambda2) {
        printf("\nDominant eigenvalue: %.2f\n", lambda1);

		getEigenVector(matrix, lambda1);

        printf("\nEigenvector: [%.2f, %.2f]\n", (b / (lambda1 - a)), 1);
    }
    else {
        printf("\nDominant eigenvalue: %.2f\n", lambda2);

		getEigenVector(matrix, lambda2);

        printf("\nEigenvector: [%.2f, %.2f]\n", (b / (lambda2 - a)), 1);
    }

    return 0;
}

void getMatrix(double newMatrix[4]) {
	char aOneOne[4] = " ";
	char aTwoOne[4] = " ";
	char aOneTwo[4] = " ";
	char aTwoTwo[4] = " ";

	double a11 = 0;
	double a21 = 0;
	double a12 = 0;
	double a22 = 0;

	puts("\nEIGEN VALUES AND EIGEN VECTORS");
	puts("\n-------------------------------\n\n");

	printf("\nPlease enter four values to fill a 2x2 matrix:");
	puts("\n| a11   a12 |");
	puts("\n| a21   a22 |");

	printf("\nEnter a value for a11:");
	fgets(aOneOne, LENGTH, stdin);
	fgetsRemoveNewLine(aOneOne);

	printf("\n| %s   a12 |", aOneOne);
	puts("\n| a21   a22 |");

	printf("\nEnter a value for a21:");
	fgets(aTwoOne, LENGTH, stdin);
	fgetsRemoveNewLine(aTwoOne);

	printf("\n| %s   a12 |", aOneOne);
	printf("\n| %s   a22 |", aTwoOne);

	printf("\nEnter a value for a12:");
	fgets(aOneTwo, LENGTH, stdin);
	fgetsRemoveNewLine(aOneTwo);

	printf("\n| %s   %s |", aOneOne, aOneTwo);
	printf("\n| %s   a22 |", aTwoOne);

	printf("\nEnter a value for a22:");
	fgets(aTwoTwo, LENGTH, stdin);
	fgetsRemoveNewLine(aTwoTwo);

	printf("\n| %s   %s |", aOneOne, aOneTwo);
	printf("\n| %s   %s |", aTwoOne, aTwoTwo);

	char* end1;
	a11 = strtod(&aOneOne[0], &end1);
	a21 = strtod(&aTwoOne[0], &end1);
	a12 = strtod(&aOneTwo[0], &end1);
	a22 = strtod(&aTwoTwo[0], &end1);

	newMatrix[0] = a11;
	newMatrix[1] = a21;
	newMatrix[2] = a12;
	newMatrix[3] = a22;
}

void fgetsRemoveNewLine(char* buff) {
	if (buff[strlen(buff) - 1] == '\n') {
		buff[strlen(buff) - 1] = '\0';
	}
}

void getEigenVector(double ogMatrix[4], double lambda) {

}