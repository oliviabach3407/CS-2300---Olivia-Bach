/*
This is a projection problem. The first line of the input defines the plane and the
projection direction (if it is parallel projection). Num11, Num12, and Num13 corresponds to the
point on the plane and Num14, Num15, and Num16 defines the normal to the plane before
normalization. If it is a parallel projection, Num17, Num18, Num19 defines the projection
direction. The rest of the input lines define points where there are three points per line.
First, let's program parallel projection; for each point, project it along the projection direction to
into the plane. Second, let's implement perspective projection; for each point (let's say x), have
the projection direction depend on the point coordinates and be that of the vector from the point
to the origin (o-x = -x) and project the point into the plane. Output two separate files for the two
sub-parts where each line includes three projected image points, similarly to the input file format.
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
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\input_1.txt";

//output files -- this is where the output is being sent
const char FILE_PATH[] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\";

void getPoints(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
void createDivideArray(double placeholder[MAX]);
void fillValues(double point[THREE], double norm[THREE], double dir[THREE], double temp[MAX]);
void fillPoints(double temp[MAX], int i, double point1[THREE], double point2[THREE], double point3[THREE]);
double pointLength(double point[THREE]);
void subtractPoints(double point1[THREE], double point2[THREE], double total[THREE]);
void addPoints(double point1[THREE], double point2[THREE], double total[THREE]);
bool ifZero(double temp[MAX], int i);
void multiplyPointScalar(double point[THREE], double scalar, double total[THREE]);
void normalize(double point[THREE], double total[THREE]);
void parallelProjection(double point[THREE], double ppoint[THREE], double planeDir[THREE], double projDir[THREE], double answer[THREE]);
double dotProduct(double point1[THREE], double point2[THREE]);
void perspectiveProj(double point[THREE], double ppoint[THREE], double planeDir[THREE], double answer[THREE]);
void writeToFile(const char filePath[LENGTH_FILE_PATH], double a11[THREE], double a12[THREE], double a13[THREE], double a21[THREE], double a22[THREE], double a23[THREE]);

int main(void) {

    double temp[MAX] = { 0 };

    FILE* filePtr1 = 0;

    getPoints(temp, filePtr1, FULL_FILE_PATH1);

    //this one will have to call all the other functions inside it
    createDivideArray(temp);

    //NEED TO DO FILES

    return 0;
}

//equation: x' = ((q dot n) / (x dot n)) * x
void perspectiveProj(double point[THREE], double ppoint[THREE], double planeDir[THREE], double answer[THREE]) {

    double qdotn = 0;
    double xdotn = 0;

    qdotn = dotProduct(ppoint, planeDir);
    xdotn = dotProduct(point, planeDir);

    if (xdotn != 0) {
        multiplyPointScalar(point, qdotn / xdotn, answer);
    }
}

void normalize(double point[THREE], double total[THREE]) {

    double pointsLength = 0;

    pointsLength = pointLength(point);

    total[0] = point[0] / pointsLength;
    total[1] = point[1] / pointsLength;
    total[2] = point[2] / pointsLength;
}

//equation: x' = x + (([q-x] dot n)/(v dot n)) * v
void parallelProjection(double point[THREE], double ppoint[THREE], double planeDir[THREE], double projDir[THREE], double answer[THREE]) {

    double qminusx[THREE] = { 0 };
    double qxdotn = 0;
    double qxnvn = 0;
    double temp[THREE];

    subtractPoints(ppoint, point, qminusx);

    qxdotn = dotProduct(qminusx, planeDir);

    qxnvn = qxdotn / (dotProduct(projDir, planeDir));

    multiplyPointScalar(projDir, qxnvn, temp);

    addPoints(point, temp, answer);
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

    point1[0] = temp[i];
    point1[1] = temp[i+1];
    point1[2] = temp[i+2];

    point2[0] = temp[i+3];
    point2[1] = temp[i+4];
    point2[2] = temp[i+5];

    point3[0] = temp[i+6];
    point3[1] = temp[i+7];
    point3[2] = temp[i+8];
}

void fillValues(double point[THREE], double norm[THREE], double dir[THREE], double temp[MAX]) {
    //every three numbers a different array should be assigned
    double normT[THREE] = {0};
        
    point[0] = temp[0];
    point[1] = temp[1];
    point[2] = temp[2];

    normT[0] = temp[3];
    normT[1] = temp[4];
    normT[2] = temp[5];

    dir[0] = temp[6];
    dir[1] = temp[7];
    dir[2] = temp[8];

    normalize(normT, norm);
}

void createDivideArray(double placeholder[MAX]) {

    double point1[THREE] = { 0 };
    double normal1[THREE] = { 0 };
    double direction1[THREE] = { 0 };

    double point2[THREE] = { 0 };
    double point3[THREE] = { 0 };
    double point4[THREE] = { 0 };

    double answer11[THREE] = { 0 }; 
    double answer12[THREE] = { 0 };
    double answer13[THREE] = { 0 };

    double answer21[THREE] = { 0 };
    double answer22[THREE] = { 0 };
    double answer23[THREE] = { 0 };

    //cant dynamically assign the size of the array so work around that

    fillValues(point1, normal1, direction1, placeholder);

    for (int i = 9; i < MAX; i += 9) {
        
        if (!ifZero(placeholder, i)) {

            fillPoints(placeholder, i, point2, point3, point4);

            //calculate function
            perspectiveProj(point2, point1, normal1, answer11);
            perspectiveProj(point3, point1, normal1, answer12);
            perspectiveProj(point4, point1, normal1, answer13);

            parallelProjection(point2, point1, normal1, direction1, answer21);
            parallelProjection(point3, point1, normal1, direction1, answer22);
            parallelProjection(point4, point1, normal1, direction1, answer23);

            writeToFile(FILE_PATH, answer11, answer12, answer13, answer21, answer22, answer23);
           
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
void writeToFile(const char filePath[LENGTH_FILE_PATH], double a11[THREE], double a12[THREE], double a13[THREE], double a21[THREE], double a22[THREE], double a23[THREE]) {

    char fullFilePath1[LENGTH_FILE_PATH];
    char fullFilePath2[LENGTH_FILE_PATH];

    FILE* filePtr1;
    FILE* filePtr2;

    sprintf(fullFilePath1, "%spart1-perspective", filePath);
    filePtr1 = fopen(fullFilePath1, "a");

    fprintf(filePtr1, "\n%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf", a11[0], a11[1], a11[2],
        a12[0], a12[1], a12[2],
        a13[0], a13[1], a13[2]);

    sprintf(fullFilePath2, "%spart1-parallel", filePath);
    filePtr2 = fopen(fullFilePath2, "a");

    fprintf(filePtr2, "\n%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf", a21[0], a21[1], a21[2],
        a22[0], a22[1], a22[2],
        a23[0], a23[1], a23[2]);
}