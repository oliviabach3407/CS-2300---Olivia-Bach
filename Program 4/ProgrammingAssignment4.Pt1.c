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
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\test_file.txt";
const char FULL_FILE_PATH2[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\test_input_2.txt";
const char FULL_FILE_PATH3[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\3D_test_input_1.txt";

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

int main(void) {

    double temp[MAX] = { 0 };

    FILE* filePtr1 = 0;

    getPoints(temp, filePtr1, FULL_FILE_PATH1);

    //this one will have to call all the other functions inside it
    createDivideArray(temp);

    for (int i = 0; i < MAX; i++) {
 
        if (i % 9 == 0) {
            printf("\n");
        }

        printf("%.2lf  ", temp[i]);
    }

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

    //cant dynamically assign the size of the array so work around that

    fillValues(point1, normal1, direction1, placeholder);

   for (int i = 9; i < MAX; i += 9) {
        
        if (!ifZero(placeholder, i)) {

            fillPoints(placeholder, i, point2, point3, point4);
            //calculate function

            for (int j = 0; j < 3; j++) {
                printf("\nPoint 2 = %.2lf  -  Point 3 = %.2lf  -  Point 4 = %.2lf", point2[j], point3[j], point4[j]);
            }

            printf("\n----------------------------------------------\n");

        }
        else {

        }

    }

    for (int k = 0; k < 3; k++) {
        printf("\nPoint 1 = %.2lf  -  Normal 1 = %.2lf  -  Direction 1 = %.2lf", point1[k], normal1[k], direction1[k]);
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
/*
void writeToFile(const char filePath[LENGTH_FILE_PATH], double solution[TWOXONE], int result) {

    char fullFilePath1[LENGTH_FILE_PATH];

    FILE* filePtr3;

    sprintf(fullFilePath1, "%spart1.answer%d", filePath, result);
    filePtr3 = fopen(fullFilePath1, "w");

    if (result == 1) {
        fprintf(filePtr3, "System underdetermined\n");
    }
    else if (result == 2) {
        fprintf(filePtr3, "System inconsistent\n");
    }
    else {
        fprintf(filePtr3, "%.4lf\n%.4lf", solution[0], solution[1]);
    }


    fclose(filePtr3);
}
*/