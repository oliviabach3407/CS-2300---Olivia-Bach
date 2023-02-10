#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define LENGTH_FILE_PATH 100
#define LENGTH 100
#define MATRIX 6
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
	char input1[MATRIX] = " ";
	char input2[MATRIX] = " ";

	char mat1[] = "Mat1";
	char mat2[] = "Mat2";
	char mat3[] = "Mat3";
	char mat4[] = "Mat4";
	char mat5[] = "Mat5";
	char mat6[] = "Mat6";

	double matrix1[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	};

	double matrix2[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	};

	FILE* filePtr1 = 0;
	FILE* filePtr2 = 0;

	FILE* filePtr3 = 0;
	char fullFilePath[LENGTH_FILE_PATH];

	do {
		puts("Please choose one of the following matrices to add: \n");
		puts("1. Mat1\n2. Mat2\n3. Mat3\n4. Mat4\n5. Mat5\n6. Mat6\n");
		fgets(input1, LENGTH, stdin);
		fgetsRemoveNewLine(input1);

		if (!((strcmp(input1, mat1) == 0) || (strcmp(input1, mat2) == 0) || (strcmp(input1, mat3) == 0) || (strcmp(input1, mat4) == 0) || (strcmp(input1, mat5) == 0) || (strcmp(input1, mat6) == 0))) {
			fprintf(stderr, "%s is not a valid matrix name.\n", input1);
			valid = false;
		}
		else {
			valid = true;
		}

	} while (valid == false);

	valid = false;

	do {
		puts("Please choose one of the following matrices to add to your first matrix: \n");
		puts("1. Mat1\n2. Mat2\n3. Mat3\n4. Mat4\n5. Mat5\n6. Mat6\n");
		fgets(input2, LENGTH, stdin);
		fgetsRemoveNewLine(input2);

		if (strcmp(input1, input2) == 0) {
			puts("Please enter a different number than your first matrix.\n");
			valid = false;
		}
		else {
			if (!((strcmp(input2, mat1) == 0) || (strcmp(input2, mat2) == 0) || (strcmp(input2, mat3) == 0) || (strcmp(input2, mat4) == 0) || (strcmp(input2, mat5) == 0) || (strcmp(input2, mat6) == 0))) {
				fprintf(stderr, "%s is not a valid matrix name.\n", input2);
				valid = false;
			}
			else {
				valid = true;
			}
		}

	} while (valid == false);

	//reading in the values

	if ((strcmp(input1, mat1) == 0)) {

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
	else if ((strcmp(input1, mat2) == 0)) {

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
	else if ((strcmp(input1, mat3) == 0)) {

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
	else if ((strcmp(input1, mat4) == 0)) {

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
	else if ((strcmp(input1, mat5) == 0)) {

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
	else if ((strcmp(input1, mat6) == 0)) {

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

	if ((strcmp(input2, mat1) == 0)) {

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
	else if ((strcmp(input2, mat2) == 0)) {

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
	else if ((strcmp(input2, mat3) == 0)) {

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
	else if ((strcmp(input2, mat4) == 0)) {

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
	else if ((strcmp(input2, mat5) == 0)) {

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
	else if ((strcmp(input2, mat6) == 0)) {

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

	//doing the multiplication 

	//6x6
	if (((strcmp(input1, mat1) == 0))) {
		//6x4
		if ((strcmp(input2, mat2) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_12", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < FIRST; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] * matrix2[j][i]));  //flipped j and i for second variable
					if (j == FIRST - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}
		//6x4
		else if ((strcmp(input2, mat3) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_13", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < FIRST; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] * matrix2[j][i]));  //flipped j and i for second variable
					if (j == FIRST - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);

		}
		else {
			printf("\n%s cannot be multiplied with %s.", input1, input2);
		}

	}

	//6x4
	if ((strcmp(input1, mat2) == 0)) {
		//4x6
		if ((strcmp(input2, mat4) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_24", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] + matrix2[j][i]));
					if (j == LAST - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}
		else if ((strcmp(input2, mat5) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_25", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] + matrix2[j][i]));
					if (j == LAST - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}

		else {
			printf("\n%s cannot be multiplied with %s.", input1, input2);
		}
	}

	//6x4
	if ((strcmp(input1, mat3) == 0)) {
		//4x6
		if ((strcmp(input2, mat4) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_34", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] + matrix2[j][i]));
					if (j == LAST - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}
		else if ((strcmp(input2, mat5) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_35", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] + matrix2[j][i]));
					if (j == LAST - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}

		else {
			printf("\n%s cannot be multiplied with %s.", input1, input2);
		}
	}

	//4x6
	if ((strcmp(input1, mat4) == 0)) {
		//6x6
		if (((strcmp(input2, mat1) == 0))) {
			sprintf(fullFilePath, "%sobach_pt3_41", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < MAT_4_R; i++) {
				for (int j = 0; j < MAT_4_C; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] * matrix2[j][i]));  //flipped j and i for second variable
					if (j == MAT_4_C - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}
		//6x4
		else if ((strcmp(input2, mat2) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_42", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < MAT_4_R; i++) {
				for (int j = 0; j < MAT_4_C; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] * matrix2[j][i]));  //flipped j and i for second variable
					if (j == MAT_4_C - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}
		//6x4
		else if ((strcmp(input2, mat3) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_43", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < MAT_4_R; i++) {
				for (int j = 0; j < MAT_4_C; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] * matrix2[j][i]));  //flipped j and i for second variable
					if (j == MAT_4_C - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);

		}
		else {
			printf("\n%s cannot be multiplied with %s.", input1, input2);
		}
	}

	//4x6
	if ((strcmp(input1, mat5) == 0)) {
		//6x6
		if (((strcmp(input2, mat1) == 0))) {
			sprintf(fullFilePath, "%sobach_pt3_51", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < MAT_5_R; i++) {
				for (int j = 0; j < MAT_5_C; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] * matrix2[j][i]));  //flipped j and i for second variable
					if (j == MAT_5_C - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}
		//6x4
		else if ((strcmp(input2, mat2) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_52", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < MAT_5_R; i++) {
				for (int j = 0; j < MAT_5_C; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] * matrix2[j][i]));  //flipped j and i for second variable
					if (j == MAT_5_C - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}
		//6x4
		else if ((strcmp(input2, mat3) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_53", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < FIRST; i++) {
				for (int j = 0; j < LAST; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] * matrix2[j][i]));  //flipped j and i for second variable
					if (j == LAST - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);

		}
		else {
			printf("\n%s cannot be multiplied with %s.", input1, input2);
		}
	}

	//2x4
	if ((strcmp(input1, mat6) == 0)) {
		//4x6
		if ((strcmp(input2, mat4) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_64", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < MAT_6_R; i++) {
				for (int j = 0; j < MAT_6_C; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] + matrix2[j][i]));
					if (j == MAT_6_C - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}
		else if ((strcmp(input2, mat5) == 0)) {
			sprintf(fullFilePath, "%sobach_pt3_65", FILE_PATH);
			filePtr3 = fopen(fullFilePath, "w");

			for (int i = 0; i < MAT_6_R; i++) {
				for (int j = 0; j < MAT_6_C; j++) {
					fprintf(filePtr3, "%3.2lf ", (matrix1[i][j] + matrix2[j][i]));
					if (j == MAT_6_C - 1) {
						fprintf(filePtr3, "\n");
					}
				}
			}

			fclose(filePtr3);
		}

		else {
			printf("\n%s cannot be multiplied with %s.", input1, input2);
		}
	}

	return 0;
}

//I developed this function in CS2060 and copied it from my assignments from that class
void fgetsRemoveNewLine(char* buff) {
	if (buff[strlen(buff) - 1] == '\n') {
		buff[strlen(buff) - 1] = '\0';
	}
}

//I developed this function in CS2060 and copied it from my assignments from that class
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