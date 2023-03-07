
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 80
#define LENGTH_FILE_PATH 100
#define NUM_SIZES 4
#define NUM_YN 2
#define SIZE 2

void fgetsRemoveNewLine(char* buff);
void getMatrix(double newMatrix[4]);
bool determinate(double testMatrix[4]);
void firstElimination(double firstMatrix[4], double firstStep[4], double identity[4]);

int main(void) {

	//Given a 2x2 matrix(you will need to prompt the user to enter), first determine if an inverse to the matrix
	//exists and if so, calculate the inverse using gauss elimination.

	double matrix[4] = { 0 };
	double firstMatrix[4] = { 0 };
	double identityMatrix[4] = {1, 0, 0, 1};  //in order of a11, a21, a12, a22
	bool inverseOrNo = true;

	getMatrix(matrix);

	//check if determinate == 0
	//determinate == 0 if returns false
	inverseOrNo = determinate(matrix);

	if (inverseOrNo) {
		//calculate inverse with gauss elimination

		if (matrix[1] != 0) {
			firstElimination(matrix, firstMatrix, identityMatrix);
		}


	}
	else {
		//end program
		printf("\nThe matrix you have entered doesn't have an inverse.");
	}

	
	return 0;
}

void fgetsRemoveNewLine(char* buff) {
	if (buff[strlen(buff) - 1] == '\n') {
		buff[strlen(buff) - 1] = '\0';
	}
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

	puts("\nINVERSE OF A MATRIX");
	puts("\n-------------------------\n\n");

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

bool determinate(double testMatrix[4]) {

	double a11 = testMatrix[0];
	double a21 = testMatrix[0];
	double a12 = testMatrix[0];
	double a22 = testMatrix[0];

	double determinate = (a11 * a22 + a21 * a12);

	if (determinate == 0) {
		return false;
	}

	else {
		return true;
	}

}

void firstElimination(double firstMatrix[4], double firstStep[4], double identity[4]) {
	
	double total = 0;

	double sOne11 = 1;
	double sOne21 =  (-(firstMatrix[1])) / firstMatrix[0];
	double sOne12 = 0;
	double sOne22 = 1;


	//multiplying with S matrix 

	for (int i = 0; i < SIZE; i++) { //num rows for matrix 1
		if (i == 0) {
			total = total + (firstMatrix[i] * sOne11);
			firstStep[i] = total;
		}
		else if (i == 1) {
			total = total + (firstMatrix[i] * sOne21);
			firstStep[i] = total;
		}
		else if (i == 2) {
			total = total + (firstMatrix[i] * sOne12);
			firstStep[i] = total;
		}
		else if (i == 3) {
			total = total + (firstMatrix[i] * sOne22);
			firstStep[i] = total;
		}
		
		total = 0;
	}
}