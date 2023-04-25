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
#define MAX 100
#define THREE 3

//input files -- you might need to change the names depending on what test files you're using 
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\test_input_1.txt";
const char FULL_FILE_PATH2[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\test_input_2.txt";
const char FULL_FILE_PATH3[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\3D_test_input_1.txt";

//output files -- this is where the output is being sent
const char FILE_PATH[] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 3\\";

void getPoints(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
void createDivideArray(double placeholder[MAX]);
bool fillValues(double point[THREE], double norm[THREE], double dir[THREE], double temp[MAX], int i);

int main(void) {

    double temp[MAX] = { 0 };

    FILE* filePtr1 = 0;

    getPoints(temp, filePtr1, FULL_FILE_PATH1);

    //this one will have to call all the other functions inside it
    createDivideArray(temp);

    return 0;
}

bool fillValues(double point[THREE], double norm[THREE], double dir[THREE], double temp[MAX], int i) {
    //every three numbers a different array should be assigned
    if (i % 9 == 0) {

        dir[0] = temp[i - 2];
        dir[1] = temp[i - 1];
        dir[2] = temp[i];

        return true;

    }
    else if (i % 6 == 0) {

        norm[0] = temp[i - 2];
        norm[1] = temp[i - 1];
        norm[2] = temp[i];

    }
    else if (i % 3 == 0) {

        point[0] = temp[i - 2];
        point[1] = temp[i - 1];
        point[2] = temp[i];

    }
    else {
        //don't do anything
    }
}

void createDivideArray(double placeholder[MAX]) {

    double point1[THREE] = { 0 };
    double normal1[THREE] = { 0 };
    double direction1[THREE] = { 0 };

    double point2[THREE] = { 0 };
    double normal2[THREE] = { 0 };
    double direction2[THREE] = { 0 };

    double point3[THREE] = { 0 };
    double normal3[THREE] = { 0 };
    double direction3[THREE] = { 0 };

    double point4[THREE] = { 0 };
    double normal4[THREE] = { 0 };
    double direction4[THREE] = { 0 };

    bool full1 = false;
    bool full2 = false;
    bool full3 = false;
    bool full4 = false;

    //cant dynamically assign the size of the array so work around that

    for (int i = 0; i < MAX; i++) {

        while (full1 == false) {
            full1 = fillValues(point1, normal1, direction1, placeholder, i);
        }

        while (full2 == false) {
            full2 = fillValues(point2, normal2, direction2, placeholder, i);
        }

        while (full3 == false) {
            full3 = fillValues(point3, normal3, direction3, placeholder, i);
        }

        while (full4 == false) {
            full4 = fillValues(point4, normal4, direction4, placeholder, i);
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