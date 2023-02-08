#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define LENGTH_FILE_PATH 100
#define LENGTH 100
#define FIRST 6
#define LAST 4
#define MAT_4_R 4
#define MAT_4_C 6
#define MAT_5_R 4
#define MAT_5_C 6
#define MAT_6_R 2
#define MAT_6_C 4

const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 1\\obach_mat1";
const char FULL_FILE_PATH2[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 1\\obach_mat2";
const char FULL_FILE_PATH3[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 1\\obach_mat3";
const char FULL_FILE_PATH4[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 1\\obach_mat4";
const char FULL_FILE_PATH5[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 1\\obach_mat5";
const char FULL_FILE_PATH6[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 1\\obach_mat6";

const char FILE_PATH[] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 1\\";

void fgetsRemoveNewLine(char* buff);
bool getValidDouble(char* input, double* validDoublePtr);

int main(void) {

	bool valid = false;
	char input1[LENGTH];
	char input2[LENGTH];
	double validMatrix1 = 0;
	double validMatrix2 = 0;

	double matrix1[10][10];
	double matrix2[10][10];

	FILE* filePtr1 = 0;
	FILE* filePtr2 = 0;

	FILE* filePtr3 = 0;
	char fullFilePath[LENGTH_FILE_PATH];

	do{
		puts("Please choose one of the following matrices to add (enter a number): \n");
		puts("1. Mat1\n2. Mat2\n3. Mat3\n4. Mat4\n5. Mat5\n6. Mat6\n");
		fgets(input1, LENGTH, stdin);
		fgetsRemoveNewLine(input1);
		valid = getValidDouble(input1, &validMatrix1);

		if ((validMatrix1 < 1) || (validMatrix1 > 6)) {
			fprintf(stderr, "%lf is not in between 1 and 6.\n", validMatrix1);
			valid = false;
		}

	} while (valid == false);

	valid = false;

	do {
		puts("Please choose one of the following matrices to add to your first matrix (enter a number): \n");
		puts("1. Mat1\n2. Mat2\n3. Mat3\n4. Mat4\n5. Mat5\n6. Mat6\n");
		fgets(input2, LENGTH, stdin);
		fgetsRemoveNewLine(input2);
		valid = getValidDouble(input2, &validMatrix2);

		if (validMatrix1 == validMatrix2) {
			puts("Please enter a different number than your first matrix.\n");
			valid = false;
		}

		if ((validMatrix2 < 1) || (validMatrix2 > 6)) {
			fprintf(stderr, "%lf is not in between 1 and 6.\n", validMatrix2);
			valid = false;
		}

	} while (valid == false);

	//reading in the values

	if (validMatrix1 == 1) {

		matrix1[FIRST][FIRST]; 

		filePtr1 = fopen(FULL_FILE_PATH1, "r");

		if (filePtr1 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < FIRST; j++) {
					fscanf(filePtr1, "%lf", &matrix1[i][j]);
				}
			}
		}

		fclose(filePtr1);
	}
	else if (validMatrix1 == 2) {

		matrix1[FIRST][LAST]; 

		filePtr1 = fopen(FULL_FILE_PATH2, "r");

		if (filePtr1 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fscanf(filePtr1, "%lf", &matrix1[i][j]);
				}
			}
		}

		fclose(filePtr1);
	}
	else if (validMatrix1 == 3) {

		matrix1[FIRST][LAST]; 

		filePtr1 = fopen(FULL_FILE_PATH3, "r");

		if (filePtr1 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fscanf(filePtr1, "%lf", &matrix1[i][j]);
				}
			}
		}

		fclose(filePtr1);
	}
	else if (validMatrix1 == 4) {

		matrix1[MAT_4_R][MAT_4_C]; 
		
		filePtr1 = fopen(FULL_FILE_PATH4, "r");

		if (filePtr1 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < MAT_4_R; i++) {
				for (int j = 0; j < MAT_4_C; j++) {
					fscanf(filePtr1, "%lf", &matrix1[i][j]);
				}
			}
		}

		fclose(filePtr1);
	}
	else if (validMatrix1 == 5) {

		matrix1[MAT_5_R][MAT_5_C];

		filePtr1 = fopen(FULL_FILE_PATH5, "r");

		if (filePtr1 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < MAT_5_R; i++) {
				for (int j = 0; j < MAT_5_C; j++) {
					fscanf(filePtr1, "%lf", &matrix1[i][j]);
				}
			}
		}

		fclose(filePtr1);
	}
	else if (validMatrix1 == 6) {

		matrix1[MAT_6_R][MAT_6_C];
		
		filePtr1 = fopen(FULL_FILE_PATH6, "r");

		if (filePtr1 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < MAT_6_R; i++) {
				for (int j = 0; j < MAT_6_C; j++) {
					fscanf(filePtr1, "%lf", &matrix1[i][j]);
				}
			}
		}

		fclose(filePtr1);

	}
	else {
		puts("Not 1-6\n");
	}

	//onto matrix 2

	if (validMatrix2 == 1) {

		matrix2[FIRST][FIRST]; 

		filePtr2 = fopen(FULL_FILE_PATH1, "r");

		if (filePtr2 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < FIRST; j++) {
					fscanf(filePtr2, "%lf", &matrix2[i][j]);
				}
			}
		}

		fclose(filePtr2);
	}
	else if (validMatrix2 == 2) {

		matrix2[FIRST][LAST]; 

		filePtr2 = fopen(FULL_FILE_PATH2, "r");

		if (filePtr2 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fscanf(filePtr2, "%lf", &matrix2[i][j]);
				}
			}
		}

		fclose(filePtr2);
	}
	else if (validMatrix2 == 3) {

		matrix2[FIRST][LAST]; 

		filePtr2 = fopen(FULL_FILE_PATH3, "r");

		if (filePtr2 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fscanf(filePtr2, "%lf", &matrix2[i][j]);
				}
			}
		}

		fclose(filePtr2);
	}
	else if (validMatrix2 == 4) {

		matrix2[MAT_4_R][MAT_4_C]; 

		filePtr2 = fopen(FULL_FILE_PATH4, "r");

		if (filePtr2 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < MAT_4_R; i++) {
				for (int j = 0; j < MAT_4_C; j++) {
					fscanf(filePtr2, "%lf", &matrix2[i][j]);
				}
			}
		}

		fclose(filePtr2);
	}
	else if (validMatrix2 == 5) {

		matrix2[MAT_5_R][MAT_5_C];

		filePtr2 = fopen(FULL_FILE_PATH5, "r");

		if (filePtr2 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < MAT_5_R; i++) {
				for (int j = 0; j < MAT_5_C; j++) {
					fscanf(filePtr2, "%lf", &matrix2[i][j]);
				}
			}
		}

		fclose(filePtr2);
	}
	else if (validMatrix2 == 6) {

		matrix2[MAT_6_R][MAT_6_C]; 

		filePtr2 = fopen(FULL_FILE_PATH6, "r");

		if (filePtr2 == NULL) {
			printf("\nError!\n");
		}
		else {
			for (int i = 0; i < MAT_6_R; i++) {
				for (int j = 0; j < MAT_6_C; j++) {
					fscanf(filePtr2, "%lf", &matrix2[i][j]);
				}
			}
		}

		fclose(filePtr2);
	}
	else {
		puts("Not 1-6\n");
	}

	//doing the addition

	//6x6
	if (validMatrix1 == 1 || validMatrix2 == 1) {
		puts("Matrix 1 is 6x6 and doesn't match the dimensions of any other matrix, so it can't be added.\n");
	}

	//6x4
	if (validMatrix1 == 2) {
		//6x4
		if (validMatrix2 == 3) {
			sprintf(fullFilePath, "%sobach_pt2_23", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] + matrix2[i][j]));
					if (j == LAST - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}

		else {
			printf("Mat%.0lf cannot be added with Mat%.0lf because they don't have the same dimensions.", validMatrix2, validMatrix1);
		}
	}

	//6x4
	if (validMatrix1 == 3) {
		//6x4
		if (validMatrix2 == 2) {
			sprintf(fullFilePath, "%sobach_pt2_32", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] + matrix2[i][j]));
					if (j == LAST - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}

		else {
			printf("Mat%.0lf cannot be added with Mat%.0lf because they don't have the same dimensions.", validMatrix2, validMatrix1);
		}
	}

	//4x6
	if (validMatrix1 == 4) {
		//4x6
		if (validMatrix2 == 5) {
			sprintf(fullFilePath, "%sobach_pt2_45", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < MAT_4_R; i++) {
				for (int j = 0; j < MAT_4_C; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] + matrix2[i][j]));
					if (j == MAT_4_C - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}

		else {
			printf("Mat%.0lf cannot be added with Mat%.0lf because they don't have the same dimensions.", validMatrix2, validMatrix1);
		}
	}

	//4x6
	if (validMatrix1 == 5) {
		//4x6
		if (validMatrix2 == 4) {
			sprintf(fullFilePath, "%sobach_pt2_54", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < MAT_4_R; i++) {
				for (int j = 0; j < MAT_4_C; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] + matrix2[i][j]));
					if (j == MAT_4_C - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}

		else {
			printf("Mat%.0lf cannot be added with Mat%.0lf because they don't have the same dimensions.", validMatrix2, validMatrix1);
		}
	}

	//2x4
	if (validMatrix1 == 6) {
		puts("Matrix 6 is 2x4 and doesn't match the dimensions of any other matrix, so it can't be added.\n");
	}

	return 0;
}

void fgetsRemoveNewLine(char* buff) {
	if (buff[strlen(buff) - 1] == '\n') {
		buff[strlen(buff) - 1] = '\0';
	}
}

bool getValidDouble(char* input, double* validDoublePtr) {
	char* end;
	errno = 0;
	double doubleTest = strtod(input, &end);


	if (end == input) {
		fprintf(stderr, "%s is not a decimal number.\n", input);
		return false;
	}
	else if ('\n' != *end && '\0' != *end) {
		fprintf(stderr, "%s has extra characters at end of input: %s\n", input, end);
		return false;
	}
	else if ((LONG_MIN == doubleTest || LONG_MAX == doubleTest) && ERANGE == errno) {
		fprintf(stderr, "%s is out of range of type long.\n", input);
		return false;
	}
	else {
		*validDoublePtr = doubleTest;
		return true;
	}
}