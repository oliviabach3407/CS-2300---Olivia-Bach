/*
The columns of the input file correspond to the point coordinates, for example, the first
column provides the coordinates of the first point and the column length indicates whether it is
2D vs. 3D. First, compute the area of the triangle (the first line of your output file). Second,
using the first two points, construct a line if 2D or a plane if 3D (the bisector of the two points)
and find the distance of the third point to that line or plane (the second line of your output file).
The output should have two numbers in separate lines. The output should contain numbers with
up to four significant digits.
*/

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
#define THREEXONE 3
#define TWOXTHREE 6
#define TWOXTWO 4
#define TWOXONE 2
#define THREED 3
#define TWOD 2

//input files -- you might need to change the names depending on what test files you're using 
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\test_input_1.txt";
const char FULL_FILE_PATH2[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\test_input_2.txt";
const char FULL_FILE_PATH3[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\3D_test_input_1.txt";

//output files -- this is where the output is being sent
const char FILE_PATH[] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\";

void getMatrix(double newMatrix2[4], double newMatrix3[9], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
double computeArea(double point1[], double point2[], double point3[]);
double computeDistance(double point1[], double point2[], double point3[], int dimension);
void writeToFile(const char filePath[LENGTH_FILE_PATH], double area, double distance, int x);

int main() {

	double area1 = 0;
	double area2 = 0;
	double area3 = 0;

	double distance1 = 0;
	double distance2 = 0;
	double distance3 = 0;

	FILE* filePtr1 = 0;
	FILE* filePtr2 = 0;
	FILE* filePtr3 = 0;

	double empty[10] = { 0 };

	double matrix1[TWOXTHREE] = { 0 };
	double matrix2[TWOXTHREE] = { 0 };
	double matrix3[THREEXTHREE] = { 0 };

	getMatrix(matrix1, empty, filePtr1, FULL_FILE_PATH1);
	getMatrix(matrix2, empty, filePtr2, FULL_FILE_PATH2);
	getMatrix(empty, matrix3, filePtr3, FULL_FILE_PATH3);

	double p11[TWOXONE] = { 0 };
	double p12[TWOXONE] = { 0 };
	double p13[TWOXONE] = { 0 };

	double p21[TWOXONE] = { 0 };
	double p22[TWOXONE] = { 0 };
	double p23[TWOXONE] = { 0 };

	double p31[THREEXONE] = { 0 };
	double p32[THREEXONE] = { 0 };
	double p33[THREEXONE] = { 0 };

	//lots of busy code to separate the points correctly

	p11[0] = matrix1[0];
	p11[1] = matrix1[1];

	p12[0] = matrix1[2];
	p12[1] = matrix1[3];

	p13[0] = matrix1[4];
	p13[1] = matrix1[5];

	p21[0] = matrix2[0];
	p21[1] = matrix2[1];

	p22[0] = matrix2[2];
	p22[1] = matrix2[3];

	p23[0] = matrix2[4];
	p23[1] = matrix2[5];

	p31[0] = matrix3[0];
	p31[1] = matrix3[1];
	p31[2] = matrix3[2];

	p32[0] = matrix3[3];
	p32[1] = matrix3[4];
	p32[2] = matrix3[5];

	p33[0] = matrix3[6];
	p33[1] = matrix3[7];
	p33[2] = matrix3[8];

	area1 = computeArea(p11, p12, p13);
	area2 = computeArea(p21, p22, p23);
	area3 = computeArea(p31, p32, p33);

	distance1 = computeDistance(p11, p12, p13, TWOD);
	distance2 = computeDistance(p21, p22, p23, TWOD);
	distance3 = computeDistance(p31, p32, p33, THREED);

	writeToFile(FILE_PATH, area1, distance1, 1);
	writeToFile(FILE_PATH, area2, distance2, 2);
	writeToFile(FILE_PATH, area3, distance3, 3);

	return 0;
}
//similar principles to my previous programs
void writeToFile(const char filePath[LENGTH_FILE_PATH], double area, double distance, int x) {

	char fullFilePath1[LENGTH_FILE_PATH];

	FILE* filePtr3;

	sprintf(fullFilePath1, "%spart3.answer%d", filePath, x);
	filePtr3 = fopen(fullFilePath1, "w");

	fprintf(filePtr3, "%.4lf", area);
	fprintf(filePtr3, "\n%.4lf", distance);

	fclose(filePtr3);
}

double computeDistance(double point1[], double point2[], double point3[], int dimension) {
	double distance = 0;

	//2d
	if (dimension == TWOD) {
		//construct the line from the first two points (point1 and point2)
		//get the slope and y-intercept of the line
		double slope = (point2[1] - point1[1]) / (point2[0] - point1[0]);
		double yIntercept = point1[1] - slope * point1[0];

		//compute the distance from the third point to the line
		distance = fabs(slope * point3[0] - point3[1] + yIntercept) / sqrt(pow(slope, 2) + 1);
	}
	//3d
	else if (dimension == THREED) {
		//construct the plane from the first two points (point1 and point2)
		//get the normal vector of the plane
		double normalVector[3];
		normalVector[0] = point1[1] * point2[2] - point1[2] * point2[1] + point2[1] * point3[2] - point2[2] * point3[1] + point3[1] * point1[2] - point3[2] * point1[1];
		normalVector[1] = point1[2] * point2[0] - point1[0] * point2[2] + point2[2] * point3[0] - point2[0] * point3[2] + point3[2] * point1[0] - point3[0] * point1[2];
		normalVector[2] = point1[0] * point2[1] - point1[1] * point2[0] + point2[0] * point3[1] - point2[1] * point3[0] + point3[0] * point1[1] - point3[1] * point1[0];

		//compute the distance from the third point to the plane
		distance = fabs(normalVector[0] * point3[0] + normalVector[1] * point3[1] + normalVector[2] * point3[2] - (normalVector[0] * point1[0] + normalVector[1] * point1[1] + normalVector[2] * point1[2])) / sqrt(pow(normalVector[0], 2) + pow(normalVector[1], 2) + pow(normalVector[2], 2));
	}

	return distance;
}

double computeArea(double point1[], double point2[], double point3[]) {
	
	double area = 0;

	//3d triangle --> also works for 2d
	//Compute the cross product of two sides of the triangle to get the area
	double crossProduct[3];
	crossProduct[0] = (point2[1] - point1[1]) * (point3[2] - point1[2]) - (point3[1] - point1[1]) * (point2[2] - point1[2]);
	crossProduct[1] = (point2[2] - point1[2]) * (point3[0] - point1[0]) - (point3[2] - point1[2]) * (point2[0] - point1[0]);
	crossProduct[2] = (point2[0] - point1[0]) * (point3[1] - point1[1]) - (point3[0] - point1[0]) * (point2[1] - point1[1]);
	area = 0.5 * sqrt(pow(crossProduct[0], 2) + pow(crossProduct[1], 2) + pow(crossProduct[2], 2));

	return area;
}

//similar principles to previous programs
void getMatrix(double newMatrix2[4], double newMatrix3[9],  FILE* filePtr, const char path[LENGTH_FILE_PATH]) {

	double newMatrix1[THREEXTHREE] = { 0 };
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

	//2x2
	if (placeholder[6] == 0) {

		for (int i = 0; i < THREEXTHREE; i++) {
			if (placeholder[i] == 0) {
			
			}

			else {
				newMatrix1[i] = placeholder[i];
			}
		}

		//change organization to make sense as a matrix
		newMatrix2[0] = newMatrix1[0];
		newMatrix2[1] = newMatrix1[3];
		newMatrix2[2] = newMatrix1[1];
		newMatrix2[3] = newMatrix1[4];
		newMatrix2[4] = newMatrix1[2];
		newMatrix2[5] = newMatrix1[5];
	}
	//3x3
	else {
		for (int i = 0; i < THREEXTHREE; i++) {
			newMatrix1[i] = placeholder[i];
		}

		//change organization to make sense as a matrix
		newMatrix3[0] = newMatrix1[0];
		newMatrix3[1] = newMatrix1[3];
		newMatrix3[2] = newMatrix1[6];
		newMatrix3[3] = newMatrix1[1];
		newMatrix3[4] = newMatrix1[4];
		newMatrix3[5] = newMatrix1[7];
		newMatrix3[6] = newMatrix1[2];
		newMatrix3[7] = newMatrix1[5];
		newMatrix3[8] = newMatrix1[8];
	}
}