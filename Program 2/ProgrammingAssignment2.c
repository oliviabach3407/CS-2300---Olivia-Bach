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


bool getValidDouble(char* input, double* validDoublePtr, const int MAX, const int MIN);
void fgetsRemoveNewLine(char* buff);
bool parametricOrImplicit();

int main(void) {
	
	//Write a program to convert between implicit and parametric equations of a line. You should ask the user 
	//which form they will be entering, prompt them to enter the specific values for the chosen equation, and
	//then display the corresponding converted equation.
	
	bool paraOrImp = false;

	double aValue = 0;
	double bValue = 0;
	double cValue = 0;

	double pValue1 = 0;
	double vValue1 = 0;
	double pValue2 = 0;
	double vValue2 = 0;

	char pInput1[3] = " ";
	char pInput2[3] = " ";

	char vInput1[3] = " ";
	char vInput2[3] = " ";

	char aInput3[4] = " ";
	char bInput3[4] = " ";
	char cInput3[4] = " ";

	paraOrImp = parametricOrImplicit();

	//parametric

	if (!paraOrImp) {
		puts("\nPARAMETRIC TO IMPLICIT");
		puts("-------------------------");

		printf("\nPlease enter two values for the point p and vector v, where l(t) = p + tv\n");
		puts("\nEnter two values for p = (SEPARATE INPUT WITH ENTER)");
		fgets(pInput1, LENGTH, stdin);
		fgetsRemoveNewLine(pInput1);
		fgets(pInput2, LENGTH, stdin);
		fgetsRemoveNewLine(pInput2);


		//gonna need to get the two values for p separately from each other
		
		char* end1;
		pValue1 = strtod(&pInput1[0], &end1);
		pValue2 = strtod(&pInput2[0], &end1);

		puts("\nEnter two values for v = (SEPARATE INPUT WITH ENTER)");
		fgets(vInput1, LENGTH, stdin);
		fgetsRemoveNewLine(vInput1);
		fgets(vInput2, LENGTH, stdin);
		fgetsRemoveNewLine(vInput2);


		char* end2;
		vValue1 = strtod(&vInput1[0], &end2);
		vValue2 = strtod(&vInput2[0], &end2);

		printf("\nP = \n\n");
		printf("\n| %.2lf |", pValue1);
		printf("\n| %.2lf |", pValue2);

		printf("\nV = \n\n");
		printf("\n| %.2lf |", vValue1);
		printf("\n| %.2lf |", vValue2);
	}

	//implicit

	if (paraOrImp) {
		puts("\nIMPLICIT TO PARAMETRIC");
		puts("-------------------------");

		printf("\nPlease enter three values for a, b, and c, where ax1 + bx2 + c = 0 (SEPARATE INPUT WITH ENTER)\n");
		fgets(aInput3, LENGTH, stdin);
		fgetsRemoveNewLine(aInput3);
		fgets(bInput3, LENGTH, stdin);
		fgetsRemoveNewLine(bInput3);
		fgets(cInput3, LENGTH, stdin);
		fgetsRemoveNewLine(cInput3);

		char* end3;
		aValue = strtod(&aInput3[0], &end3);
		bValue = strtod(&bInput3[0], &end3);
		cValue = strtod(&cInput3[0], &end3);

		printf("\nA = \n");
		printf("\n%.2lf\n", aValue);

		printf("\nB = \n");
		printf("\n%.2lf\n", bValue);

		printf("\nC = \n");
		printf("\n%.2lf\n", cValue);
	}

	return 0;
}

bool parametricOrImplicit() {
	bool valid = false;
	char input[LENGTH];

	while (valid != true) {
		printf("What would you like to input?: \n1.Parametric form\n2.Implicit form");
		fgets(input, LENGTH, stdin);
		fgetsRemoveNewLine(input);

		if (strcmp(input, "1")) {
			valid = true;
		}
		else if (strcmp(input, "2")) {
			valid = true;
		}
		else {
			printf("\nInvalid input, please enter 1 or 2.");
			printf("\nWhat would you like to input?: \n1.Parametric form\n2.Implicit form");
			fgets(input, LENGTH, stdin);
			fgetsRemoveNewLine(input);
		}
	}

	//parametric

	if (strcmp(input, "1")) {
		return true;
	}

	//implicit

	if (strcmp(input, "2")) {
		return false;
	}
}

void fgetsRemoveNewLine(char* buff) {
	if (buff[strlen(buff) - 1] == '\n') {
		buff[strlen(buff) - 1] = '\0';
	}
}
