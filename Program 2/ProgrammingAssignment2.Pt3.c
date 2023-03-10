#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 80

void fgetsRemoveNewLine(char* buff);
void getVertices(double A1[2], double A2[2], double A3[2], double B1[2], double B2[2], double B3[2]);
void calculateV(double A1[2], double A2[2], double A3[2], double B1[2], double B2[2], double B3[2], double newV[4], double _newV[4]);
void calculateInverse(double V[4], double inverse[4]);
void findMap(double _V[4], double inverse[4], double answer[4]);

int main(void) {

	double incomingA1[2] = { 0 };
	double incomingA2[2] = { 0 };
	double incomingA3[2] = { 0 };

	double incomingB1[2] = { 0 };
	double incomingB2[2] = { 0 };
	double incomingB3[2] = { 0 };

	double matrixV[4] = { 0 };
	double _matrixV[4] = { 0 };

	double inverse[4] = { 0 }; 
	double completeMap[4] = { 0 };

	getVertices(incomingA1, incomingA2, incomingA3, incomingB1, incomingB2, incomingB3);

	calculateV(incomingA1, incomingA2, incomingA3, incomingB1, incomingB2, incomingB3, matrixV, _matrixV);

	calculateInverse(matrixV, inverse);

	findMap(_matrixV, inverse, completeMap);

	puts("\n----------------------------------------------------\n");

	printf("\nFINAL RESULT:\n");

	puts("\n----------------------------------------------------\n");

	printf("\n|   %5.2lf      %5.2lf   |", completeMap[0], completeMap[2]);
	printf("\n|   %5.2lf      %5.2lf   |", completeMap[1], completeMap[3]);

	return 0;

}

void fgetsRemoveNewLine(char* buff) {
	if (buff[strlen(buff) - 1] == '\n') {
		buff[strlen(buff) - 1] = '\0';
	}
}

void getVertices(double A1[2], double A2[2], double A3[2], double B1[2], double B2[2], double B3[2]) {
	char charA1[4] = " ";
	char charA2[4] = " ";
	char charA3[4] = " ";

	char charB1[4] = " ";
	char charB2[4] = " ";
	char charB3[4] = " ";

	char* end1;

	//A1

	puts("\nAFFINE MAPS");
	puts("\n-------------------------\n\n");

	printf("\n\nPlease enter two values to fill the A1 vertex:");
	puts("\n| a11  |");
	puts("\n| a21  |");

	printf("\nEnter a value for a11:");
	fgets(charA1, LENGTH, stdin);
	fgetsRemoveNewLine(charA1);

	A1[0] = strtod(&charA1[0], &end1);

	printf("\nEnter a value for a21:");
	fgets(charA1, LENGTH, stdin);
	fgetsRemoveNewLine(charA1);

	A1[1] = strtod(&charA1[0], &end1);

	printf("\nThis is the vertex [%.0lf  %.0lf]", A1[0], A1[1]);
		
	//A2

	puts("\n----------------------------------------------------\n");

	printf("\n\nPlease enter two values to fill the A2 vertex:");
	puts("\n| a11  |");
	puts("\n| a21  |");

	printf("\nEnter a value for a11:");
	fgets(charA2, LENGTH, stdin);
	fgetsRemoveNewLine(charA2);

	A2[0] = strtod(&charA2[0], &end1);

	printf("\nEnter a value for a21:");
	fgets(charA2, LENGTH, stdin);
	fgetsRemoveNewLine(charA2);

	A2[1] = strtod(&charA2[0], &end1);

	printf("\nThis is the vertex [%.0lf  %.0lf]", A2[0], A2[1]);

	//A3

	puts("\n----------------------------------------------------\n");

	printf("\n\nPlease enter two values to fill the A3 vertex:");
	puts("\n| a11  |");
	puts("\n| a21  |");

	printf("\nEnter a value for a11:");
	fgets(charA3, LENGTH, stdin);
	fgetsRemoveNewLine(charA3);

	A3[0] = strtod(&charA3[0], &end1);

	printf("\nEnter a value for a21:");
	fgets(charA3, LENGTH, stdin);
	fgetsRemoveNewLine(charA3);

	A3[1] = strtod(&charA3[0], &end1);

	printf("\nThis is the vertex [%.0lf  %.0lf]", A3[0], A3[1]);

	//B1

	puts("\n----------------------------------------------------\n");

	printf("\n\nPlease enter two values to fill the B1 vertex:");
	puts("\n| a11  |");
	puts("\n| a21  |");

	printf("\nEnter a value for a11:");
	fgets(charB1, LENGTH, stdin);
	fgetsRemoveNewLine(charB1);

	B1[0] = strtod(&charB1[0], &end1);

	printf("\nEnter a value for a21:");
	fgets(charB1, LENGTH, stdin);
	fgetsRemoveNewLine(charB1);

	B1[1] = strtod(&charB1[0], &end1);

	printf("\nThis is the vertex [%.0lf  %.0lf]", B1[0], B1[1]);

	//B2

	puts("\n----------------------------------------------------\n");

	printf("\n\nPlease enter two values to fill the B2 vertex:");
	puts("\n| a11  |");
	puts("\n| a21  |");

	printf("\nEnter a value for a11:");
	fgets(charB2, LENGTH, stdin);
	fgetsRemoveNewLine(charB2);

	B2[0] = strtod(&charB2[0], &end1);

	printf("\nEnter a value for a21:");
	fgets(charB2, LENGTH, stdin);
	fgetsRemoveNewLine(charB2);

	B2[1] = strtod(&charB2[0], &end1);

	printf("\nThis is the vertex [%.0lf  %.0lf]", B2[0], B2[1]);

	//B3

	puts("\n----------------------------------------------------\n");

	printf("\n\nPlease enter two values to fill the B3 vertex:");
	puts("\n| a11  |");
	puts("\n| a21  |");

	printf("\nEnter a value for a11:");
	fgets(charB3, LENGTH, stdin);
	fgetsRemoveNewLine(charB3);

	B3[0] = strtod(&charB3[0], &end1);

	printf("\nEnter a value for a21:");
	fgets(charB3, LENGTH, stdin);
	fgetsRemoveNewLine(charB3);

	B3[1] = strtod(&charB3[0], &end1);

	printf("\nThis is the vertex [%.0lf  %.0lf]", B3[0], B3[1]);
}

void calculateV(double A1[2], double A2[2], double A3[2], double B1[2], double B2[2], double B3[2], double newV[4], double _newV[4]) {

	//normal v
	double v2[2] = { 0 };
	double v3[2] = { 0 };

	//v prime '
	double _v2[2] = { 0 };
	double _v3[2] = { 0 };

	for (int i = 0; i < 2; i++) {
		v2[i] = A2[i] - A1[i];
	}

	for (int i = 0; i < 2; i++) {
		v3[i] = A3[i] - A1[i];
	}

	//primes

	for (int i = 0; i < 2; i++) {
		_v2[i] = B2[i] - B1[i];
	}

	for (int i = 0; i < 2; i++) {
		_v3[i] = B3[i] - B1[i];
	}

	newV[0] = v2[0];
	newV[1] = v2[1];
	newV[2] = v3[0];
	newV[3] = v3[1];

	_newV[0] = _v2[0];
	_newV[1] = _v2[1];
	_newV[2] = _v3[0];
	_newV[3] = _v3[1];

	//printf("\n\n\nNewV is : ");
	//printf("\n|   %5.2lf      %5.2lf   |", newV[0], newV[2]);
	//printf("\n|   %5.2lf      %5.2lf   |", newV[1], newV[3]);

	//printf("\n\n\n_NewV is: ");
	//printf("\n|   %5.2lf      %5.2lf   |", _newV[0], _newV[2]);
	//printf("\n|   %5.2lf      %5.2lf   |", _newV[1], _newV[3]);
}

void calculateInverse(double V[4], double inverse[4]) {

	double determinate = 1 / ((V[0] * V[3]) - (V[2] * V[1]));

	double reversed[4] = { 0 };

	reversed[0] = V[3];
	reversed[1] = -(V[1]);
	reversed[2] = -(V[2]);
	reversed[3] = V[1];

	inverse[0] = reversed[0] * determinate;
	inverse[1] = reversed[1] * determinate;
	inverse[2] = reversed[2] * determinate;
	inverse[3] = reversed[3] * determinate;
}

void findMap(double _V[4], double inverse[4], double answer[4]) {

	//need to do _V * inverse 

	answer[0] = (_V[0] * inverse[0]) + (_V[2] * inverse[1]);
	answer[1] = (_V[0] * inverse[2]) + (_V[2] * inverse[3]);
	answer[2] = (_V[1] * inverse[0]) + (_V[3] * inverse[1]);
	answer[3] = (_V[1] * inverse[2]) + (_V[3] * inverse[3]);
}