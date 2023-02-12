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

void writeToFile(const char filePath[LENGTH_FILE_PATH], double matrix1[FIRST][FIRST], double matrix2[LAST][FIRST], double matrix3[LAST][FIRST],
	double matrix4[MAT_4_C][MAT_4_R], double matrix5[MAT_5_C][MAT_5_R], double matrix6[MAT_6_C][MAT_6_R]);

int main(void) {

	//6x6
	double mat1[FIRST][FIRST] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};

	//6x6
	double mat1_1[FIRST][FIRST] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};

	//6x4
	double mat2[FIRST][LAST] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
	};

	//4x6
	double mat2_2[LAST][FIRST] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};

	//6x4
	double mat3[FIRST][LAST] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
	};

	//4x6
	double mat3_3[LAST][FIRST] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};

	//4x6
	double mat4[MAT_4_R][MAT_4_C] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};

	//6x4
	double mat4_4[MAT_4_C][MAT_4_R] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
	};

	//4x6
	double mat5[MAT_5_R][MAT_5_C] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};

	//6x4
	double mat5_5[MAT_5_C][MAT_5_R] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
	};

	//2x4
	double mat6[MAT_6_R][MAT_6_C] = {
	{0,0,0,0},
	{0,0,0,0}
	};

	//4x2
	double mat6_6[MAT_6_C][MAT_6_R] = {
	{0,0,},
	{0,0,},
	{0,0,},
	{0,0,}
	};


	FILE* filePtr1 = 0;
	FILE* filePtr2 = 0;
	FILE* filePtr3 = 0;
	FILE* filePtr4 = 0;
	FILE* filePtr5 = 0;
	FILE* filePtr6 = 0;

	char fullFilePath[LENGTH_FILE_PATH];


	//reading in the values

	/*Write code to transpose each of the six (6) matrices you created in Part 1. Write output to 
	files of the format: “name_p6_mat1.txt”, “name_p6_mat2.txt” , “name_p6_mat3.txt” , 
	“name_p6_mat4.txt”... etc */

	filePtr1 = fopen(FULL_FILE_PATH1, "r");

	if (filePtr1 == NULL) {
		printf("\nError!\n");
	}
	else {
		for (int i = 0; i < FIRST; i++) {
			for (int j = 0; j < FIRST; j++) {
				fscanf(filePtr1, "%lf", &mat1[i][j]);
			}
		}
	}

	fclose(filePtr1);

	//-----------------------------------------------------

	filePtr1 = fopen(FULL_FILE_PATH2, "r");

	if (filePtr1 == NULL) {
		printf("\nError!\n");
	}
	else {
		for (int i = 0; i < FIRST; i++) {
			for (int j = 0; j < LAST; j++) {
				fscanf(filePtr1, "%lf", &mat2[i][j]);
			}
		}
	}

	fclose(filePtr1);

	//-----------------------------------------------------

	filePtr1 = fopen(FULL_FILE_PATH3, "r");

	if (filePtr1 == NULL) {
			printf("\nError!\n");
	}
	else {
		for (int i = 0; i < FIRST; i++) {
			for (int j = 0; j < LAST; j++) {
				fscanf(filePtr1, "%lf", &mat3[i][j]);
			}
		}
	}

	fclose(filePtr1);

	//-----------------------------------------------------

	filePtr1 = fopen(FULL_FILE_PATH4, "r");

	if (filePtr1 == NULL) {
		printf("\nError!\n");
	}
	else {
		for (int i = 0; i < MAT_4_R; i++) {
			for (int j = 0; j < MAT_4_C; j++) {
				fscanf(filePtr1, "%lf", &mat4[i][j]);
			}
		}
	}

	fclose(filePtr1);

	//-----------------------------------------------------

	filePtr1 = fopen(FULL_FILE_PATH5, "r");

	if (filePtr1 == NULL) {
		printf("\nError!\n");
	}
	else {
		for (int i = 0; i < MAT_5_R; i++) {
			for (int j = 0; j < MAT_5_C; j++) {
				fscanf(filePtr1, "%lf", &mat5[i][j]);
			}
		}
	}

	fclose(filePtr1);

	//-----------------------------------------------------

	filePtr1 = fopen(FULL_FILE_PATH6, "r");

	if (filePtr1 == NULL) {
		printf("\nError!\n");
	}
	else {
		for (int i = 0; i < MAT_6_R; i++) {
			for (int j = 0; j < MAT_6_C; j++) {
				fscanf(filePtr1, "%lf", &mat6[i][j]);
			}
		}
	}

	fclose(filePtr1);

	//transposing

	//-----------------------------------------------------

	for (int i = 0; i < FIRST; i++) {  //rows mat1
		for (int j = 0; j < FIRST; j++) {  //columns mat1
			mat1_1[j][i] = mat1[i][j];
		}
	}

	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < FIRST; j++) {
			printf("%.0lf ", mat1_1[i][j]);
		}
		puts("\n");
	}

	puts("\n-------------------------------------------------");

	//-----------------------------------------------------

	for (int i = 0; i < FIRST; i++) {  //rows mat2
		for (int j = 0; j < LAST; j++) {  //columns mat2
			mat2_2[j][i] = mat2[i][j];
		}
	}

	for (int i = 0; i < LAST; i++) {
		for (int j = 0; j < FIRST; j++) {
			printf("%.0lf ", mat2_2[i][j]);
		}
		puts("\n");
	}

	puts("\n-------------------------------------------------");

	//-----------------------------------------------------

	for (int i = 0; i < FIRST; i++) {  //rows mat3
		for (int j = 0; j < LAST; j++) {  //columns mat3
			mat3_3[j][i] = mat3[i][j];
		}
	}

	for (int i = 0; i < LAST; i++) {
		for (int j = 0; j < FIRST; j++) {
			printf("%.0lf ", mat3_3[i][j]);
		}
		puts("\n");
	}

	puts("\n-------------------------------------------------");

	//-----------------------------------------------------

	for (int i = 0; i < MAT_4_R; i++) {  //rows mat4
		for (int j = 0; j < MAT_4_C; j++) {  //columns mat4
			mat4_4[j][i] = mat4[i][j];
		}
	}

	for (int i = 0; i < MAT_4_C; i++) {
		for (int j = 0; j < MAT_4_R; j++) {
			printf("%.0lf ", mat4_4[i][j]);
		}
		puts("\n");
	}

	puts("\n-------------------------------------------------");

	//-----------------------------------------------------

	for (int i = 0; i < MAT_5_R; i++) {  //rows mat5
		for (int j = 0; j < MAT_5_C; j++) {  //columns mat5
			mat5_5[j][i] = mat5[i][j];
		}
	}

	for (int i = 0; i < MAT_5_C; i++) {
		for (int j = 0; j < MAT_5_R; j++) {
			printf("%.0lf ", mat5_5[i][j]);
		}
		puts("\n");
	}

	puts("\n-------------------------------------------------");

	//-----------------------------------------------------

	for (int i = 0; i < MAT_6_R; i++) {  //rows mat6
		for (int j = 0; j < MAT_6_C; j++) {  //columns mat6
			mat6_6[j][i] = mat6[i][j];
		}
	}

	for (int i = 0; i < MAT_6_C; i++) {
		for (int j = 0; j < MAT_6_R; j++) {
			printf("%.0lf ", mat6_6[i][j]);
		}
		puts("\n");
	}

	puts("\n-------------------------------------------------");

	//-----------------------------------------------------

	//writing to file

	writeToFile(FILE_PATH, mat1_1, mat2_2, mat3_3, mat4_4, mat5_5, mat6_6);

	return 0;
}

void writeToFile(const char filePath[LENGTH_FILE_PATH], double matrix1[FIRST][FIRST], double matrix2[LAST][FIRST], double matrix3[LAST][FIRST],
	double matrix4[MAT_4_C][MAT_4_R], double matrix5[MAT_5_C][MAT_5_R], double matrix6[MAT_6_C][MAT_6_R]) {

	char fullFilePath1[LENGTH_FILE_PATH];
	char fullFilePath2[LENGTH_FILE_PATH];
	char fullFilePath3[LENGTH_FILE_PATH];
	char fullFilePath4[LENGTH_FILE_PATH];
	char fullFilePath5[LENGTH_FILE_PATH];
	char fullFilePath6[LENGTH_FILE_PATH];

	FILE* filePtr1;
	FILE* filePtr2;
	FILE* filePtr3;
	FILE* filePtr4;
	FILE* filePtr5;
	FILE* filePtr6;

	sprintf(fullFilePath1, "%sobach_p6_mat1.txt", filePath);
	filePtr1 = fopen(fullFilePath1, "w");

	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < FIRST; j++) {
			fprintf(filePtr1, "%2.0lf ", matrix1[i][j]);
			if (j == FIRST - 1) {
				fprintf(filePtr1, "\n");
			}
		}
	}

	fclose(filePtr1);

	sprintf(fullFilePath2, "%sobach_p6_mat2.txt", filePath);
	filePtr2 = fopen(fullFilePath2, "w");

	for (int i = 0; i < LAST; i++) {
		for (int j = 0; j < FIRST; j++) {
			fprintf(filePtr2, "%2.0lf ", matrix2[i][j]);
			if (j == FIRST - 1) {
				fprintf(filePtr2, "\n");
			}
		}
	}

	fclose(filePtr2);

	sprintf(fullFilePath3, "%sobach_p6_mat3.txt", filePath);
	filePtr3 = fopen(fullFilePath3, "w");

	for (int i = 0; i < LAST; i++) {
		for (int j = 0; j < FIRST; j++) {
			fprintf(filePtr3, "%2.2lf ", matrix3[i][j]);
			if (j == FIRST - 1) {
				fprintf(filePtr3, "\n");
			}
		}
	}

	fclose(filePtr3);

	sprintf(fullFilePath4, "%sobach_p6_mat4.txt", filePath);
	filePtr4 = fopen(fullFilePath4, "w");

	for (int i = 0; i < MAT_4_C; i++) {
		for (int j = 0; j < MAT_4_R; j++) {
			fprintf(filePtr4, "%3.0lf ", matrix4[i][j]);
			if (j == MAT_4_R - 1) {
				fprintf(filePtr4, "\n");
			}
		}
	}

	fclose(filePtr4);

	sprintf(fullFilePath5, "%sobach_p6_mat5.txt", filePath);
	filePtr5 = fopen(fullFilePath5, "w");

	for (int i = 0; i < MAT_5_C; i++) {
		for (int j = 0; j < MAT_5_R; j++) {
			fprintf(filePtr5, "%2.2lf ", matrix5[i][j]);
			if (j == MAT_5_R - 1) {
				fprintf(filePtr5, "\n");
			}
		}
	}

	fclose(filePtr5);

	sprintf(fullFilePath6, "%sobach_p6_mat6.txt", filePath);
	filePtr6 = fopen(fullFilePath6, "w");

	for (int i = 0; i < MAT_6_C; i++) {
		for (int j = 0; j < MAT_6_R; j++) {
			fprintf(filePtr6, "%2.0lf ", matrix6[i][j]);
			if (j == MAT_6_R - 1) {
				fprintf(filePtr6, "\n");
			}
		}
	}

	fclose(filePtr6);
}