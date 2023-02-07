#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define FIRST 6
#define LAST 4
#define MAT_4_R 4
#define MAT_4_C 6
#define MAT_5_R 4
#define MAT_5_C 6
#define MAT_6_R 2
#define MAT_6_C 4
#define LENGTH_FILE_PATH 100
#define LENGTH 80

const char FIRST_NAME[] = "Olivia";
const char LAST_NAME[] = "Bach";

//when you type in the path, you need to add the extra \\ at the end like I have (at least for windows)
//if you copy the path into this section, make sure to and double the \ to make \\ (for windows)
//this path is where all six files will be stored on your drive - I made a file called CS2300-Matrixes to store the six in this case
const char FILE_PATH[] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\CS2300-Matrixes\\";

void printName();
void fillMatrix1(double matrix[FIRST][FIRST], double starting, double increasing);
void fillMatrix2(double matrix[FIRST][LAST], double starting, double increasing);
void fillMatrix3(double matrix[FIRST][LAST], double starting, double increasing);
void fillMatrix4(double matrix[MAT_4_R][MAT_4_C], double starting, double increasing);
void fillMatrix5(double matrix[MAT_5_R][MAT_5_C], double starting, double increasing);
void fillMatrix6(double matrix[MAT_6_R][MAT_6_C], double starting, double increasing);
void writeToFile(const char filePath[LENGTH_FILE_PATH], double matrix1[FIRST][FIRST], double matrix2[FIRST][LAST], double matrix3[FIRST][LAST],
	double matrix4[MAT_4_R][MAT_4_C], double matrix5[MAT_5_R][MAT_5_C], double matrix6[MAT_6_R][MAT_6_C]);

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

	printName();
	fillMatrix1(mat1, 1, 1);

	//6x4
	double mat2[FIRST][LAST] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
	};

	printName();
	fillMatrix2(mat2, 2, 3);
	
	//6x4
	double mat3[FIRST][LAST] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
	};

	printName();
	fillMatrix3(mat3, 0.2, 0.2);

	//4x6
	double mat4[MAT_4_R][MAT_4_C] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};

	puts("-------------------------");
	puts("Matrix 4:");
	printf("Dimensions: %d x %d\n", MAT_4_R, MAT_4_C);
	puts("-------------------------\n");

	fillMatrix4(mat4, 10, -2);

	double mat5[MAT_5_R][MAT_5_C] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};

	puts("-------------------------");
	puts("Matrix 5:");
	printf("Dimensions: %d x %d\n", MAT_5_R, MAT_5_C);
	puts("-------------------------\n");

	fillMatrix5(mat5, -6, 1.5);

	double mat6[MAT_6_R][MAT_6_C] = {
	{0,0,0,0},
	{0,0,0,0}
	};

	puts("-------------------------");
	puts("Matrix 6:");
	printf("Dimensions: %d x %d\n", MAT_6_R, MAT_6_C);
	puts("-------------------------\n");

	fillMatrix6(mat6, -10, 10);

	writeToFile(FILE_PATH, mat1, mat2, mat3, mat4, mat5, mat6);

	return 0;
}

void writeToFile(const char filePath[LENGTH_FILE_PATH], double matrix1[FIRST][FIRST], double matrix2[FIRST][LAST], double matrix3[FIRST][LAST],
	double matrix4[MAT_4_R][MAT_4_C], double matrix5[MAT_5_R][MAT_5_C], double matrix6[MAT_6_R][MAT_6_C]) {

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

	sprintf(fullFilePath1, "%sobach_mat1", filePath);
	filePtr1 = fopen(fullFilePath1, "w");

	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < FIRST; j++) {
			fprintf(filePtr1, "| %2.0lf |", matrix1[i][j]);
			if (j == FIRST - 1) {
				fprintf(filePtr1, "\n");
			}
		}
	}

	fclose(filePtr1);

	sprintf(fullFilePath2, "%sobach_mat2", filePath);
	filePtr2 = fopen(fullFilePath2, "w");

	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < LAST; j++) {
			fprintf(filePtr2, "| %2.0lf |", matrix2[i][j]);
			if (j == LAST - 1) {
				fprintf(filePtr2, "\n");
			}
		}
	}

	fclose(filePtr2);

	sprintf(fullFilePath3, "%sobach_mat3", filePath);
	filePtr3 = fopen(fullFilePath3, "w");

	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < LAST; j++) {
			fprintf(filePtr3, "| %2.2lf |", matrix3[i][j]);
			if (j == LAST - 1) {
				fprintf(filePtr3, "\n");
			}
		}
	}

	fclose(filePtr3);

	sprintf(fullFilePath4, "%sobach_mat4", filePath);
	filePtr4 = fopen(fullFilePath4, "w");

	for (int i = 0; i < MAT_4_R; i++) {
		for (int j = 0; j < MAT_4_C; j++) {
			fprintf(filePtr4, "| %3.0lf |", matrix4[i][j]);
			if (j == MAT_4_C - 1) {
				fprintf(filePtr4, "\n");
			}
		}
	}

	fclose(filePtr4);

	sprintf(fullFilePath5, "%sobach_mat5", filePath);
	filePtr5 = fopen(fullFilePath5, "w");

	for (int i = 0; i < MAT_5_R; i++) {
		for (int j = 0; j < MAT_5_C; j++) {
			fprintf(filePtr5, "| %2.2lf |", matrix5[i][j]);
			if (j == MAT_5_C - 1) {
				fprintf(filePtr5, "\n");
			}
		}
	}

	fclose(filePtr5);

	sprintf(fullFilePath6, "%sobach_mat6", filePath);
	filePtr6 = fopen(fullFilePath6, "w");

	for (int i = 0; i < MAT_6_R; i++) {
		for (int j = 0; j < MAT_6_C; j++) {
			fprintf(filePtr6, "| %2.0lf |", matrix6[i][j]);
			if (j == MAT_6_C - 1) {
				fprintf(filePtr6, "\n");
			}
		}
	}

	fclose(filePtr6);
}

void printName() {
	puts("-------------------------");
	printf("%s = %d\n", FIRST_NAME, FIRST);
	printf("%s = %d\n", LAST_NAME, LAST);
	puts("-------------------------\n");
}

//columns first, rows second
void fillMatrix1(double matrix[FIRST][FIRST], double starting, double increasing) {
	
	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < FIRST; j++) {
			matrix[i][j] = starting;
			starting += increasing;
		}
	}

	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < FIRST; j++) {
			printf("| %2.0lf |", matrix[i][j]);
			if (j == FIRST-1) {
				puts("\n");
			}
		}
	}
}

//rows first, columns second
void fillMatrix2(double matrix[FIRST][LAST], double starting, double increasing) {
	
	for (int i = 0; i < LAST; i++) {
		for (int j = 0; j < FIRST; j++) {
			matrix[j][i] = starting;
			starting += increasing;
		}
	}

	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < LAST; j++) {
			printf("| %2.0lf |", matrix[i][j]);
			if (j == LAST - 1) {
				puts("\n");
			}
		}
	}
}

//columns first, rows second
void fillMatrix3(double matrix[FIRST][LAST], double starting, double increasing) {

	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < LAST; j++) {
			matrix[i][j] = starting;
			starting += increasing;
		}
	}

	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < LAST; j++) {
			printf("| %2.2lf |", matrix[i][j]);
			if (j == LAST - 1) {
				puts("\n");
			}
		}
	}
}

//columns first, rows second
void fillMatrix4(double matrix[MAT_4_R][MAT_4_C], double starting, double increasing) {

	for (int i = 0; i < MAT_4_R; i++) {
		for (int j = 0; j < MAT_4_C; j++) {
			matrix[i][j] = starting;
			starting += increasing;
		}
	}

	for (int i = 0; i < MAT_4_R; i++) {
		for (int j = 0; j < MAT_4_C; j++) {
			printf("| %3.0lf |", matrix[i][j]);
			if (j == MAT_4_C - 1) {
				puts("\n");
			}
		}
	}
}

//rows first, columns second
void fillMatrix5(double matrix[MAT_5_R][MAT_5_C], double starting, double increasing) {

	for (int i = 0; i < MAT_5_C; i++) {
		for (int j = 0; j < MAT_5_R; j++) {
			matrix[j][i] = starting;
			starting += increasing;
		}
	}

	for (int i = 0; i < MAT_5_R; i++) {
		for (int j = 0; j < MAT_5_C; j++) {
			printf("| %2.2lf |", matrix[i][j]);
			if (j == MAT_5_C - 1) {
				puts("\n");
			}
		}
	}
}

//rows first, columns second
void fillMatrix6(double matrix[MAT_6_R][MAT_6_C], double starting, double increasing) {

	for (int i = 0; i < MAT_6_C; i++) {
		for (int j = 0; j < MAT_6_R; j++) {
			matrix[j][i] = starting;
			starting += increasing;
		}
	}

	for (int i = 0; i < MAT_6_R; i++) {
		for (int j = 0; j < MAT_6_C; j++) {
			printf("| %2.0lf |", matrix[i][j]);
			if (j == MAT_6_C - 1) {
				puts("\n");
			}
		}
	}
}


