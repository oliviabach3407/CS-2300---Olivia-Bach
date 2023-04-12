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

void calculations(double matrix[4], int x);
void getMatrix(double newMatrix[4], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
void getEigenVector(double ogMatrix[4], double lambda, double eigenVectors[2]);
void normalize(double eigenVectors[2], double extraVector[2], double normalized[2], double normalized2[2]);
void lambdaAndR(double l1, double l2, double vector1[2], double vector2[2], int x, bool dominate);
void rLambdaRT(double bigLambda[TWOXTWO], double bigR[TWOXTWO], double transposeR[TWOXTWO], int x);
void writeToFile(const char filePath[LENGTH_FILE_PATH], double lambda[TWOXTWO], double bigR[TWOXTWO], double rLambdaRT[TWOXTWO], int x);

int main() {
	//this if for the new file names for the solution
	char fullFilePath[LENGTH_FILE_PATH];

	FILE* filePtr1 = 0;
	FILE* filePtr2 = 0;

	double matrix1[4] = { 0 };
	double matrix2[4] = { 0 };

	getMatrix(matrix1, filePtr1, FULL_FILE_PATH1);
	getMatrix(matrix2, filePtr2, FULL_FILE_PATH2);

	//something wrong with the eigen vectors??? Need to normalizze maybe?

	calculations(matrix1, 1);
	calculations(matrix2, 2);

	return 0;
}

//this function has a lot of the code from my PA2.Pt4
void calculations(double matrix[4], int x) {
	bool domLambda = NULL;

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
		getEigenVector(matrix, lambda2, eigenVector2);

		printf("\nEigenvector: [%.2f, %.2f]\n", eigenVector1[0], eigenVector1[1]);

		normalize(eigenVector1, eigenVector2, eigenNormal1, eigenNormal2);

		printf("\nNormalized Eigenvector: [%.2f, %.2f]\n", eigenNormal1[0], eigenNormal1[1]);

		domLambda = true;
	}
	else {
		printf("\nDominant eigenvalue: %.2f\n", lambda2);

		getEigenVector(matrix, lambda1, eigenVector1);
		getEigenVector(matrix, lambda2, eigenVector2);

		printf("\nEigenvector: [%.2f, %.2f]\n", eigenVector2[0], eigenVector2[1]);

		normalize(eigenVector2, eigenVector1, eigenNormal2, eigenNormal1);

		printf("\nNormalized Eigenvector: [%.2f, %.2f]\n", eigenNormal2[0], eigenNormal2[1]);

		domLambda = false;
	}

	//dominate will be true if lambda1 is the dominate - false if lambda2 is the dominate

	lambdaAndR(lambda1, lambda2, eigenNormal1, eigenNormal2, x, domLambda);
}

void lambdaAndR(double l1, double l2, double vector1[2], double vector2[2], int x, bool dominate) {

	double bigLambda[TWOXTWO] = { 0 };
	double bigR[TWOXTWO] = { 0 };
	double transposeR[TWOXTWO] = { 0 };

	bigLambda[0] = l1;
	bigLambda[1] = 0;
	bigLambda[2] = 0;
	bigLambda[3] = l2;

	//lambda 1 is dominate --> goes on left side
	if (dominate) {
		bigR[0] = vector1[0];
		bigR[1] = vector1[1];
		bigR[2] = vector2[0];
		bigR[3] = vector2[1];
	}
	//lambda 2 is dominate --> goes on left side side
	else {
		bigR[0] = vector2[0];
		bigR[1] = vector2[1];
		bigR[2] = vector1[0];
		bigR[3] = vector1[1];
	}

	transposeR[0] = vector1[0];
	transposeR[1] = vector2[0];
	transposeR[2] = vector1[1];
	transposeR[3] = vector2[1];

	rLambdaRT(bigLambda, bigR, transposeR, x);
}

void rLambdaRT(double bigLambda[TWOXTWO], double bigR[TWOXTWO], double transposeR[TWOXTWO], int x) {

	double rLambdaRT[TWOXTWO] = { 0 };
	double rLambda[TWOXTWO] = { 0 };

	//first multiplication
	rLambda[0] = bigR[0] * bigLambda[0] + bigR[2] * bigLambda[1];
	rLambda[1] = bigR[1] * bigLambda[0] + bigR[3] * bigLambda[1];
	rLambda[2] = bigR[0] * bigLambda[2] + bigR[2] * bigLambda[3];
	rLambda[3] = bigR[1] * bigLambda[2] + bigR[3] * bigLambda[3];

	//second multiplication
	rLambdaRT[0] = rLambda[0] * transposeR[0] + rLambda[2] * transposeR[1];
	rLambdaRT[1] = rLambda[1] * transposeR[0] + rLambda[3] * transposeR[1];
	rLambdaRT[2] = rLambda[0] * transposeR[2] + rLambda[2] * transposeR[3];
	rLambdaRT[3] = rLambda[1] * transposeR[2] + rLambda[3] * transposeR[3];

	writeToFile(FILE_PATH, bigLambda, bigR, rLambdaRT, x);
}

void writeToFile(const char filePath[LENGTH_FILE_PATH], double lambda[TWOXTWO], double bigR[TWOXTWO], double rLambdaRT[TWOXTWO], int x) {

	char fullFilePath1[LENGTH_FILE_PATH];

	FILE* filePtr3;

	sprintf(fullFilePath1, "%sanswer%d", filePath, x);
	filePtr3 = fopen(fullFilePath1, "w");


	printf("\n%.4lf %.4lf", lambda[0], lambda[2]);
	printf("\n%.4lf %.4lf", lambda[1], lambda[3]);

	printf("\n%.4lf %.4lf", bigR[0], bigR[2]);
	printf("\n%.4lf %.4lf", bigR[1], bigR[3]);

	printf("\n%.4lf %.4lf", rLambdaRT[0], rLambdaRT[2]);
	printf("\n%.4lf %.4lf", rLambdaRT[1], rLambdaRT[3]);

	fprintf(filePtr3, "%.4lf %.4lf", lambda[0], lambda[2]);
	fprintf(filePtr3, "\n%.4lf %.4lf", lambda[1], lambda[3]);
	
	fprintf(filePtr3, "\n%.4lf %.4lf", bigR[0], bigR[2]);
	fprintf(filePtr3, "\n%.4lf %.4lf", bigR[1], bigR[3]);

	fprintf(filePtr3, "\n%.4lf %.4lf", rLambdaRT[0], rLambdaRT[2]);
	fprintf(filePtr3, "\n%.4lf %.4lf", rLambdaRT[1], rLambdaRT[3]);

	fclose(filePtr3);
}
//this function has a lot of the code from my PA2.Pt4
void getMatrix(double newMatrix[4], FILE* filePtr, const char path[LENGTH_FILE_PATH]){
	
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
void normalize(double eigenVectors[2], double extraVector[2], double normalized1[2], double normalized2[2]) {

	double magnitude1 = sqrt((eigenVectors[0] * eigenVectors[0]) + (eigenVectors[1] * eigenVectors[1]));

	normalized1[0] = eigenVectors[0] / magnitude1;
	normalized1[1] = eigenVectors[1] / magnitude1;

	double magnitude2 = sqrt((extraVector[0] * extraVector[0]) + (extraVector[1] * extraVector[1]));

	normalized2[0] = extraVector[0] / magnitude2;
	normalized2[1] = extraVector[1] / magnitude2;
}