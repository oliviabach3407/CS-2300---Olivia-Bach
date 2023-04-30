/*
Second, the first line of the input defines a line defined by the two points, where Num11,
Num12, and Num13 yields one point and Num14, Num15, and Num16 provides the other point
coordinates. The rest of the lines on the input defines the three vertex points of a triangle plane (a
bounded plane). If the input had K lines, there are K-1 triangles for testing. For each triangle, if it
intersects with the line, find the point of intersection. If it does not intersect, output "Does not
intersect." Generate a file for your output including K-1 lines for one triangle per line.
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
double dotProduct(double point1[THREE], double point2[THREE]);
void crossProduct(double point1[THREE], double point2[THREE], double answer[THREE]);
bool pointTriangle(double lPoint1[THREE], double lPoint2[THREE], double point1[THREE], double point2[THREE], double point3[THREE], double ans[THREE]);

int main(void) {

    double temp[MAX] = { 0 };

    FILE* filePtr1 = 0;

    getPoints(temp, filePtr1, FULL_FILE_PATH1);

    //this one will have to call all the other functions inside it
    createDivideArray(temp);

    //NEED TO DO FILES

    return 0;
}

bool pointTriangle(double lPoint1[THREE], double lPoint2[THREE], double point1[THREE], double point2[THREE], double point3[THREE], double ans[THREE]) {

    bool inTriangle = false;

    double vector1[THREE] = { 0 };
    double vector2[THREE] = { 0 };

    double cross[THREE] = { 0 };
    double planeDir[THREE] = { 0 }; //normalized cross

    double planePt[THREE] = { 0 };
    double lineDir[THREE] = { 0 };

    double distToLine = 0;

    double intersectPoint[THREE] = { 0 };
    double distVec[THREE] = { 0 };

    double subtract1[THREE] = { 0 };
    double subtract2[THREE] = { 0 };
    double subtract3[THREE] = { 0 };

    double dotProduct1 = 0;
    double dotProduct2 = 0;

    double vectorPlane = 0;
    
    double qMinusP[THREE] = { 0 };
    double topParameter = 0;

    subtractPoints(point1, point2, vector1);
    subtractPoints(point1, point3, vector2);

    crossProduct(vector1, vector2, cross);

    normalize(cross, planeDir);

    planePt[0] = point1[0];
    planePt[1] = point1[1];
    planePt[2] = point1[2];

    vectorPlane = dotProduct(vector1, vector2); //denominator
    subtractPoints(lPoint2, lPoint1, lineDir);

    if (vectorPlane != 0) {
        
        subtractPoints(planePt, lPoint1, qMinusP);
        topParameter = dotProduct(qMinusP, planeDir);
        
        distToLine = topParameter / vectorPlane;


        
    }
   

}

void crossProduct(double point1[THREE], double point2[THREE], double answer[THREE]) {

    answer[0] = point1[1] * point2[2] - point2[1] * point1[2];
    answer[1] = point1[2] * point2[0] - point2[2] * point1[0];
    answer[2] = point1[0] * point2[1] - point2[0] * point1[1];
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

    point1[0] = temp[i];
    point1[1] = temp[i + 1];
    point1[2] = temp[i + 2];

    point2[0] = temp[i + 3];
    point2[1] = temp[i + 4];
    point2[2] = temp[i + 5];

    point3[0] = temp[i + 6];
    point3[1] = temp[i + 7];
    point3[2] = temp[i + 8];
}

void fillValues(double point[THREE], double norm[THREE], double dir[THREE], double temp[MAX]) {
    //every three numbers a different array should be assigned

    point[0] = temp[0];
    point[1] = temp[1];
    point[2] = temp[2];

    norm[0] = temp[3];
    norm[1] = temp[4];
    norm[2] = temp[5];

    dir[0] = temp[6];
    dir[1] = temp[7];
    dir[2] = temp[8];

}

void createDivideArray(double placeholder[MAX]) {

    double linePoint1[THREE] = { 0 };
    double linePoint2[THREE] = { 0 };
    double direction1[THREE] = { 0 };

    double point2[THREE] = { 0 };
    double point3[THREE] = { 0 };
    double point4[THREE] = { 0 };

    double answer[THREE] = { 0 };

    bool hits = false;

    //cant dynamically assign the size of the array so work around that

    fillValues(linePoint1, linePoint2, direction1, placeholder);

    for (int i = 9; i < MAX; i += 9) {

        if (!ifZero(placeholder, i)) {

            fillPoints(placeholder, i, point2, point3, point4);
            //calculate function
            hits = pointTriangle(linePoint1, linePoint2, point2, point3, point4, answer);
            

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