
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
void firstElimination(double firstMatrix[4], double firstStep[4], double identity[4], double newIdentity[4], double sOne[4]);
void secondElimination(double original[4], double incomingMatrix[4], double newMatrix[4], double incomingIdentity[4], double newIdentity[4], double sTwo[4]);
void thirdElimination(double original[4], double incomingMatrix[4], double newMatrix[4], double incomingIdentity[4], double newIdentity[4], double sThree[4]);
void calculateInverse(double sOne[4], double sTwo[4], double sThree[4], double completeInverse[4]);

int main(void) {

	//Given a 2x2 matrix(you will need to prompt the user to enter), first determine if an inverse to the matrix
	//exists and if so, calculate the inverse using gauss elimination.

	double matrix[4] = { 0 };
	double firstMatrix[4] = { 0 };
	double identityMatrix[4] = {1, 0, 0, 1};  //in order of a11, a21, a12, a22
	double newIdentity[4] = { 0 };

	double secondMatrix[4] = { 0 };
	double newIdentity2[4] = { 0 }; 

	double thirdMatrix[4] = { 0 };
	double newIdentity3[4] = { 0 };

	double finalInverse[4] = { 0 };

	double s1[4] = { 0 };
	double s2[4] = { 0 };
	double s3[4] = { 0 };

	bool inverseOrNo = true;

	getMatrix(matrix);

	//check if determinate == 0
	//determinate == 0 if returns false
	inverseOrNo = determinate(matrix);

	if (inverseOrNo) {
		//calculate inverse with gauss elimination

			if (matrix[1] != 0) { //if that spot isn't already a 0
				firstElimination(matrix, firstMatrix, identityMatrix, newIdentity, s1);

				puts("\n\nRESULTS OF FIRST STEP:");
				puts("\n-------------------------");

				puts("\nOriginal matrix multiplied with S:");

				printf("\n| %5.2lf   %5.2lf |", firstMatrix[0], firstMatrix[2]);
				printf("\n| %5.2lf   %5.2lf |", firstMatrix[1], firstMatrix[3]);

				puts("\n\n\nIdentity matrix multiplied with S:");

				printf("\n| %5.2lf   %5.2lf |", newIdentity[0], newIdentity[2]);
				printf("\n| %5.2lf   %5.2lf |", newIdentity[1], newIdentity[3]);
			}

			if (matrix[2] != 0) {
				secondElimination(matrix, firstMatrix, secondMatrix, newIdentity, newIdentity2, s2);

				puts("\n\nRESULTS OF SECOND STEP:");
				puts("\n-------------------------");

				puts("\nPrevious matrix multiplied with S:");

				printf("\n| %5.2lf   %5.2lf |", secondMatrix[0], secondMatrix[2]);
				printf("\n| %5.2lf   %5.2lf |", secondMatrix[1], secondMatrix[3]);

				puts("\n\n\nPrevious identity matrix multiplied with S:");

				printf("\n| %5.2lf   %5.2lf |", newIdentity2[0], newIdentity2[2]);
				printf("\n| %5.2lf   %5.2lf |", newIdentity2[1], newIdentity2[3]);
			}

			if (matrix[0] != 1 && matrix[3] != 1) {
				thirdElimination(matrix, secondMatrix, thirdMatrix, newIdentity2, newIdentity3, s3);

				puts("\n\nRESULTS OF THIRD STEP:");
				puts("\n-------------------------");

				puts("\nPrevious matrix multiplied with S:");

				printf("\n| %5.2lf   %5.2lf |", thirdMatrix[0], thirdMatrix[2]);
				printf("\n| %5.2lf   %5.2lf |", thirdMatrix[1], thirdMatrix[3]);

				puts("\n\n\nPrevious identity matrix multiplied with S:");

				printf("\n| %5.2lf   %5.2lf |", newIdentity3[0], newIdentity3[2]);
				printf("\n| %5.2lf   %5.2lf |", newIdentity3[1], newIdentity3[3]);
			}

			calculateInverse(s1, s2, s3, finalInverse);

			puts("\n\n-------------------------");
			puts("\nFINAL INVERSE:");
			puts("\n-------------------------");

			printf("\n| %5.2lf   %5.2lf |", finalInverse[0], finalInverse[2]);
			printf("\n| %5.2lf   %5.2lf |", finalInverse[1], finalInverse[3]);
			
	}
	else {
		//end program
		puts("\n\n---------------------------------------------------------------------------");
		printf("THE MATRIX YOU HAVE ENTERED DOES NOT HAVE AN INVERSE BECAUSE IT IS SINGULAR");
		puts("\n---------------------------------------------------------------------------");
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
	double a21 = testMatrix[1];
	double a12 = testMatrix[2];
	double a22 = testMatrix[3];

	double determinate = ((a11 * a22) - (a21 * a12));

	if (determinate == 0) {
		return false;
	}

	else {
		return true;
	}

}

void firstElimination(double firstMatrix[4], double firstStep[4], double identity[4], double newIdentity[4], double sOne[4]) {

	double sOne11 = 1;
	double sOne21 = (-(firstMatrix[1])) / firstMatrix[0];
	double sOne12 = 0;
	double sOne22 = 1;

	sOne[0] = sOne11;
	sOne[1] = sOne21;
	sOne[2] = sOne12;
	sOne[3] = sOne22;

	//multiplying og matrix and identity matrix with S matrix 

	firstStep[0] = (sOne11 * firstMatrix[0]) + (sOne12 * firstMatrix[1]);  //a11 for firstStep
	firstStep[1] = (sOne21 * firstMatrix[0]) + (sOne22 * firstMatrix[1]);  //a21 for firstStep

	firstStep[2] = (sOne11 * firstMatrix[2]) + (sOne12 * firstMatrix[3]);  //a12 for firstStep
	firstStep[3] = (sOne21 * firstMatrix[2]) + (sOne22 * firstMatrix[3]);  //a22 for firstStep

	newIdentity[0] = (sOne11 * identity[0]) + (sOne12 * identity[1]);  //a11 for newIdentity
	newIdentity[1] = (sOne21 * identity[0]) + (sOne22 * identity[1]);  //a21 for newIdentity

	newIdentity[2] = (sOne11 * identity[2]) + (sOne12 * identity[3]);  //a12 for newIdentity
	newIdentity[3] = (sOne21 * identity[2]) + (sOne22 * identity[3]);  //a22 for newIdentity

}

void secondElimination(double original[4], double incomingMatrix[4], double newMatrix[4], double incomingIdentity[4], double newIdentity[4], double sTwo[4]) {

	double sOne11 = 1;
	double sOne21 = 0;
	double sOne12 = (-(incomingMatrix[2])) / incomingMatrix[3];
	double sOne22 = 1;

	sTwo[0] = sOne11;
	sTwo[1] = sOne21;
	sTwo[2] = sOne12;
	sTwo[3] = sOne22;

	//multiplying incoming matrix and incoming identity with new S matrix

	newMatrix[0] = (sOne11 * incomingMatrix[0]) + (sOne12 * incomingMatrix[1]);  //a11 for firstStep
	newMatrix[1] = (sOne21 * incomingMatrix[0]) + (sOne22 * incomingMatrix[1]);  //a21 for firstStep

	newMatrix[2] = (sOne11 * incomingMatrix[2]) + (sOne12 * incomingMatrix[3]);  //a12 for firstStep
	newMatrix[3] = (sOne21 * incomingMatrix[2]) + (sOne22 * incomingMatrix[3]);  //a22 for firstStep

	newIdentity[0] = (sOne11 * incomingIdentity[0]) + (sOne12 * incomingIdentity[1]);  //a11 for newIdentity
	newIdentity[1] = (sOne21 * incomingIdentity[0]) + (sOne22 * incomingIdentity[1]);  //a21 for newIdentity

	newIdentity[2] = (sOne11 * incomingIdentity[2]) + (sOne12 * incomingIdentity[3]);  //a12 for newIdentity
	newIdentity[3] = (sOne21 * incomingIdentity[2]) + (sOne22 * incomingIdentity[3]);  //a22 for newIdentity

}

void thirdElimination(double original[4], double incomingMatrix[4], double newMatrix[4], double incomingIdentity[4], double newIdentity[4], double sThree[4]) {

	double sOne11 = 1/incomingMatrix[0];
	double sOne21 = 0;
	double sOne12 = 0;
	double sOne22 = 1/incomingMatrix[3];

	sThree[0] = sOne11;
	sThree[1] = sOne21;
	sThree[2] = sOne12;
	sThree[3] = sOne22;

	//multiplying incoming matrix and incoming identity with new S matrix

	newMatrix[0] = (sOne11 * incomingMatrix[0]) + (sOne12 * incomingMatrix[1]);  //a11 for firstStep
	newMatrix[1] = (sOne21 * incomingMatrix[0]) + (sOne22 * incomingMatrix[1]);  //a21 for firstStep

	newMatrix[2] = (sOne11 * incomingMatrix[2]) + (sOne12 * incomingMatrix[3]);  //a12 for firstStep
	newMatrix[3] = (sOne21 * incomingMatrix[2]) + (sOne22 * incomingMatrix[3]);  //a22 for firstStep

	newIdentity[0] = (sOne11 * incomingIdentity[0]) + (sOne12 * incomingIdentity[1]);  //a11 for newIdentity
	newIdentity[1] = (sOne21 * incomingIdentity[0]) + (sOne22 * incomingIdentity[1]);  //a21 for newIdentity

	newIdentity[2] = (sOne11 * incomingIdentity[2]) + (sOne12 * incomingIdentity[3]);  //a12 for newIdentity
	newIdentity[3] = (sOne21 * incomingIdentity[2]) + (sOne22 * incomingIdentity[3]);  //a22 for newIdentity

}

void calculateInverse(double sOne[4], double sTwo[4], double sThree[4], double completeInverse[4]) {
	
	//multiply all the s's together --> s3 * s2 * s1

	double tempMatrix[4] = { 0 };

	//first multiplication (s3 * s2)

	tempMatrix[0] = (sThree[0] * sTwo[0]) + (sThree[2] * sTwo[1]);
	tempMatrix[1] = (sThree[1] * sTwo[0]) + (sThree[3] * sTwo[1]);

	tempMatrix[2] = (sThree[0] * sTwo[2]) + (sThree[2] * sTwo[3]);
	tempMatrix[3] = (sThree[1] * sTwo[2]) + (sThree[3] * sTwo[3]);

	//second multiplication ((s3*s2) * s1)

	completeInverse[0] = (tempMatrix[0] * sOne[0]) + (tempMatrix[2] * sOne[1]);
	completeInverse[1] = (tempMatrix[1] * sOne[0]) + (tempMatrix[3] * sOne[1]);

	completeInverse[2] = (tempMatrix[0] * sOne[2]) + (tempMatrix[2] * sOne[3]);
	completeInverse[3] = (tempMatrix[1] * sOne[2]) + (tempMatrix[3] * sOne[3]);

}