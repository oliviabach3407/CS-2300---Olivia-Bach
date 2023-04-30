/*
First, each line of the input defines a plane (first six numbers) and a point (the last three number).
For the K-th line on the input, NumK1, NumK2, and NumK3 correspond to the point on the
plane and NumK4, NumK5, and NumK6 define the normal to the plane before normalization.
NumK7, NumK8, NumK9 are the point coordinates. Compute the distance between the point and
the plane and output K numbers for K lines on the input. Generate an output file for this sub-part.
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
#define MAX 99
#define THREE 3

//input files -- you might need to change the names depending on what test files you're using 
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\test_file_2.txt";
const char FULL_FILE_PATH2[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\test_input_2.txt";
const char FULL_FILE_PATH3[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\3D_test_input_1.txt";

//output files -- this is where the output is being sent
const char FILE_PATH[] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\";

void getPoints(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
void createDivideArray(double placeholder[MAX]);
void fillPoints(double temp[MAX], int i, double point1[THREE], double point2[THREE], double point3[THREE]);
double pointLength(double point[THREE]);
void subtractPoints(double point1[THREE], double point2[THREE], double total[THREE]);
void addPoints(double point1[THREE], double point2[THREE], double total[THREE]);
bool ifZero(double temp[MAX], int i);
void multiplyPointScalar(double point[THREE], double scalar, double total[THREE]);
void normalize(double point[THREE], double total[THREE]);
double dotProduct(double point1[THREE], double point2[THREE]);
void writeToFile(const char filePath[LENGTH_FILE_PATH], double answer);

int main(void) {

    double temp[MAX] = { 0 };

    FILE* filePtr1 = 0;

    getPoints(temp, filePtr1, FULL_FILE_PATH1);

    //this one will have to call all the other functions inside it
    createDivideArray(temp);

    //NEED TO DO FILES

    return 0;
}

//t = (c + n dot p) / (n dot n)
double distPointPlane(double planePt[THREE], double planeDir[THREE], double point[THREE]) {

    double cValue = 0;
    double nDotP = 0;
    double nDotN = 0;
    double answer = 0;

    cValue = -(dotProduct(planePt, planeDir));

    nDotP = dotProduct(planeDir, point);

    nDotN = dotProduct(planeDir, planeDir);

    answer = (cValue + nDotP) / nDotN;
    
    return answer;
}

void normalize(double point[THREE], double total[THREE]) {

    double pointsLength = 0;

    pointsLength = pointLength(point);

    total[0] = point[0] / pointsLength;
    total[1] = point[1] / pointsLength;
    total[2] = point[2] / pointsLength;
}

double dotProduct(double point1[THREE], double point2[THREE]) {

    double total = 0;

    total = point1[0] * point2[0] + point1[1] * point2[1] + point1[2] * point2[2];

    return total;

}

void multiplyPointScalar(double point[THREE], double scalar, double total[THREE]) {

    total[0] = point[0] * scalar;
    total[1] = point[1] * scalar;
    total[2] = point[2] * scalar;
}

void subtractPoints(double point1[THREE], double point2[THREE], double total[THREE]) {

    total[0] = point1[0] - point2[0];
    total[1] = point1[1] - point2[1];
    total[2] = point1[2] - point2[2];
}

void addPoints(double point1[THREE], double point2[THREE], double total[THREE]) {

    total[0] = point1[0] + point2[0];
    total[1] = point1[1] + point2[1];
    total[2] = point1[2] + point2[2];
}

double pointLength(double point[THREE]) {

    double length = 0;

    length = sqrt(pow(point[0], 2) + pow(point[1], 2) + pow(point[2], 2));

    return length;
}

bool ifZero(double temp[MAX], int i) {

    if (temp[i] == 0 && temp[i + 1] == 0 && temp[i + 2] == 0 && temp[i + 3] == 0 && temp[i + 4] == 0 && temp[i + 5] == 0 && temp[i + 6] == 0 && temp[i + 7] == 0 && temp[i + 8] == 0) {
        return true;
    }
    return false;
}

void fillPoints(double temp[MAX], int i, double point1[THREE], double point2[THREE], double point3[THREE]) {

    double normal[THREE] = { 0 };

    point1[0] = temp[i];
    point1[1] = temp[i + 1];
    point1[2] = temp[i + 2];

    normal[0] = temp[i + 3];
    normal[1] = temp[i + 4];
    normal[2] = temp[i + 5];

    point3[0] = temp[i + 6];
    point3[1] = temp[i + 7];
    point3[2] = temp[i + 8];

    normalize(normal, point2);
}

void createDivideArray(double placeholder[MAX]) {

    double point2[THREE] = { 0 };
    double point3[THREE] = { 0 };
    double point4[THREE] = { 0 };
    double answer = 0;

    //cant dynamically assign the size of the array so work around that

    for (int i = 0; i < MAX; i += 9) {

        if (!ifZero(placeholder, i)) {

            fillPoints(placeholder, i, point2, point3, point4);
            //calculate function
            answer = distPointPlane(point2, point3, point4);

            printf("\nThis is the answer: %.2lf", answer);

            writeToFile(FILE_PATH, answer);
        }
        else {

        }

    }
}

//based off of getMatrix function from PA2 and PA3
void getPoints(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]) {

    filePtr = fopen(path, "r");

    if (filePtr == NULL) {
        printf("\nError!\n");
    }
    else {
        for (int i = 0; i < MAX; i++) {
            fscanf(filePtr, "%lf", &placeholder[i]);
        }

        fclose(filePtr);
    }
}

//based off of my PA1.Pt1
void writeToFile(const char filePath[LENGTH_FILE_PATH], double answer) {

    char fullFilePath1[LENGTH_FILE_PATH];

    FILE* filePtr1;

    sprintf(fullFilePath1, "%spart2-sub1", filePath);
    filePtr1 = fopen(fullFilePath1, "a");

    fprintf(filePtr1, "\n%.2lf", answer);
}