#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LENGTH_FILE_PATH 100
#define NUM_SIZES 4
#define NUM_YN 2
#define SIZE 2
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

void calculations(double matrix[4]);
void getMatrix(double newMatrix[4], FILE* filePtr);
void getEigenVector(double ogMatrix[4], double lambda, double eigenVectors[2]);
void normalize(double eigenVectors[2], double normalized[2]);

int main() {
	//this if for the new file names for the solution
	char fullFilePath[LENGTH_FILE_PATH];

	FILE* filePtr1 = 0;
	FILE* filePtr2 = 0;

	double matrix1[4] = { 0 };
	double matrix2[4] = { 0 };

	getMatrix(matrix1, filePtr1);
	getMatrix(matrix2, filePtr2);

	calculations(matrix1);
	calculations(matrix2);

	return 0;
}

//this function has a lot of the code from my PA2.Pt4
void calculations(double matrix[4]) {
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

	double eigenVector1[2] = { 0 };
	double eigenVector2[2] = { 0 };

	double eigenNormal1[2] = { 0 };
	double eigenNormal2[2] = { 0 };

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
	else {
		absLambda1 = lambda1;
	}

	if (lambda2 < 0) {
		absLambda2 = -(lambda2);
	}
	else {
		absLambda2 = lambda2;
	}

	//figure out which lambda is the dominant one and calculate vectors
	if (absLambda1 > absLambda2) {
		printf("\nDominant eigenvalue: %.2f\n", lambda1);

		getEigenVector(matrix, lambda1, eigenVector1);

		printf("\nEigenvector: [%.2f, %.2f]\n", eigenVector1[0], eigenVector1[1]);

		normalize(eigenVector1, eigenNormal1);

		printf("\nNormalized Eigenvector: [%.2f, %.2f]\n", eigenNormal1[0], eigenNormal1[1]);
	}
	else {
		printf("\nDominant eigenvalue: %.2f\n", lambda2);

		getEigenVector(matrix, lambda2, eigenVector2);

		printf("\nEigenvector: [%.2f, %.2f]\n", eigenVector2[0], eigenVector2[1]);

		normalize(eigenVector2, eigenNormal2);

		printf("\nNormalized Eigenvector: [%.2f, %.2f]\n", eigenNormal2[0], eigenNormal2[1]);
	}
}
//this function has a lot of the code from my PA2.Pt4
void getMatrix(double newMatrix[4], FILE* filePtr) {
	
	double placeholder[THREEXTHREE] = { 0 };

	filePtr = fopen(FULL_FILE_PATH1, "r");

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

	for (int i = 0; i < THREEXTHREE; i++) {
		if (i == 2 || i == 5 || placeholder[i] == 0) {
			//ignore the pieces that were b
		}

		else {
			newMatrix[k] = placeholder[i];
			k++;
		}
	}
}
//this function is from PA2.Pt4
void getEigenVector(double ogMatrix[4], double lambda, double eigenVectors[2]) {

	double newMatrix[4] = { 0 };

	newMatrix[0] = ogMatrix[0] - lambda;
	newMatrix[1] = ogMatrix[1];
	newMatrix[2] = ogMatrix[2];
	newMatrix[3] = ogMatrix[3] - lambda;

	eigenVectors[0] = 1;
	eigenVectors[1] = 0;

	if (newMatrix[0] != 0) {
		eigenVectors[0] = (-newMatrix[2]) / newMatrix[0];
		eigenVectors[1] = 1;
	}
}
//this function is from PA2.Pt4
void normalize(double eigenVectors[2], double normalized[2]) {

	double magnitude = sqrt((eigenVectors[0] * eigenVectors[0]) + (eigenVectors[1] * eigenVectors[1]));

	normalized[0] = eigenVectors[0] / magnitude;
	normalized[1] = eigenVectors[1] / magnitude;
}