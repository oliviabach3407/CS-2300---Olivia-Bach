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
//I've edited my code so that the output file will be overwritten each time you run this program (same output file no matter what the input file is)
const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\input_1.txt";
//const char FULL_FILE_PATH1[LENGTH_FILE_PATH] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\input_2.txt";

//output file -- this is where the output is being sent
const char FILE_PATH[] = "C:\\GithubRepos\\CS2060\\CS-2300---Olivia-Bach\\Program 4\\";

void getPoints(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
void createDivideArray(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]);
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
void intersection(double lPoint1[THREE], double lPoint2[THREE], double point1[THREE], double point2[THREE], double point3[THREE], double ans[THREE]);
void distPointLine(double point1[THREE], double point2[THREE], double point3[THREE], double ans[THREE]);
double distTwoPoints(double point1[THREE], double point2[THREE]);
void writeToFile(const char filePath[LENGTH_FILE_PATH], FILE* filePtr, double ans[THREE], bool intersects);
void overwrite(const char filePath[LENGTH_FILE_PATH], FILE* filePtr, const char path[LENGTH_FILE_PATH]);

int main(void) {

    double temp[MAX] = { 0 };

    FILE* filePtr1 = 0;

    overwrite(FILE_PATH, filePtr1, FULL_FILE_PATH1);

    getPoints(temp, filePtr1, FULL_FILE_PATH1);

    //this one will have to call all the other functions inside it
    createDivideArray(temp, filePtr1, FULL_FILE_PATH1);

    return 0;
}

//determining if the point on the plane is within the boundaries of the triangle
bool boundsCheck(double lPoint1[THREE], double lPoint2[THREE], double point1[THREE], double point2[THREE], double point3[THREE], double ans[THREE]) {

    double pointOnPlane1[THREE] = { 0 };
    double pointOnPlane2[THREE] = { 0 };

    double subtract1[THREE] = { 0 };
    double subtract2[THREE] = { 0 };

    double add1[THREE] = { 0 };
    double add2[THREE] = { 0 };

    double u1 = 0;
    double u2 = 0;

    bool intersects = false;

    distPointLine(point1, point2, ans, pointOnPlane1);
    distPointLine(point1, point3, ans, pointOnPlane2);

    subtractPoints(point2, pointOnPlane1, subtract1);
    subtractPoints(point3, pointOnPlane2, subtract2);

    addPoints(point1, subtract1, add1);
    addPoints(point1, subtract2, add2);

    u1 = distTwoPoints(point1, add1);
    u2 = distTwoPoints(point1, add2);

    if (0 <= u1 && u1 <= 1 && 0 <= u2 && u2 <= 1 && u1 + u2 <= 1) {
        intersects = true;
    }

    return intersects;
}

void intersection(double lPoint1[THREE], double lPoint2[THREE], double point1[THREE], double point2[THREE], double point3[THREE], double ans[THREE]) {

    /*
    Intersection Point = p + tv
    Intersection Point = p1 + u1(p2 - p1) + u2(p3 - p1)
    Intersection Point = u1p2 + u2p3 + (1 - u1 - u2)p1

    plane point = q, line point = p

    Equation for intersection:

    t = [q - p] dot n
         -----------
          v dot n

    Plane = x1 + x2 + x3 + c = 0
    (parametric form)
    */

    double vector1[THREE] = { 0 };
    double vector2[THREE] = { 0 };

    double cross[THREE] = { 0 };
    double planeDir[THREE] = { 0 }; //normalized cross

    double planePt[THREE] = { 0 };
    double lineDir[THREE] = { 0 };

    double distToLine = 0;
  
    double intersectPoint[THREE] = { 0 };
    double distVec[THREE] = { 0 };

    double vectorPlane = 0;
    
    double qMinusP[THREE] = { 0 };
    double topParameter = 0;

    //getting vectors from the points given
    subtractPoints(point1, point2, vector1);
    subtractPoints(point1, point3, vector2);

    //plane direction (before normalization)
    crossProduct(vector1, vector2, cross);

    //plane direction (after normalization)
    normalize(cross, planeDir);

    //copying values over
    planePt[0] = point1[0];
    planePt[1] = point1[1];
    planePt[2] = point1[2];
    
    //getting denominator of equation
    //v dot n
    vectorPlane = dotProduct(vector1, vector2);
    subtractPoints(lPoint2, lPoint1, lineDir);

    if (vectorPlane != 0) {
        
        //[q - p] dot n

        //getting q - p
        subtractPoints(planePt, lPoint1, qMinusP);
        //dotting that with n
        topParameter = dotProduct(qMinusP, planeDir);
        
        //dividing numerator by denominator
        distToLine = topParameter / vectorPlane;
    }
    else {

    }

    //position of the point (where is it on the plane?)
    multiplyPointScalar(vector1, distToLine, distVec);

    addPoints(lPoint1, distVec, intersectPoint);

    //copying answer from intersectPoint to ans
    memcpy(ans, intersectPoint, THREE);

}

void crossProduct(double point1[THREE], double point2[THREE], double answer[THREE]) {

    answer[0] = point1[1] * point2[2] - point2[1] * point1[2];
    answer[1] = point1[2] * point2[0] - point2[2] * point1[0];
    answer[2] = point1[0] * point2[1] - point2[0] * point1[1];
}

void distPointLine(double point1[THREE], double point2[THREE], double point3[THREE], double ans[THREE]) {

    double subtract1[THREE] = { 0 };
    double subtract2[THREE] = { 0 };
    double subtract3[THREE] = { 0 };

    double dotProd = 0;
    double scalMagnitude = 0;

    subtractPoints(point2, point1, subtract1);
    subtractPoints(point1, point3, subtract2);

    dotProd = dotProduct(subtract1, subtract1);

    if (dotProd == 0) {
        
        memcpy(ans, point1, THREE);
    }
    else {

        scalMagnitude = dotProduct(subtract1, subtract2) / dotProd;
        subtractPoints(point1, subtract1, subtract3);

        multiplyPointScalar(subtract3, scalMagnitude, ans);
    }
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

double distTwoPoints(double point1[THREE], double point2[THREE]) {

    double temp[THREE] = { 0 };
    double length = 0;

    subtractPoints(point1, point2, temp);
    length = pointLength(temp);

    return length;
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

void createDivideArray(double placeholder[MAX], FILE* filePtr, const char path[LENGTH_FILE_PATH]) {

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
            intersection(linePoint1, linePoint2, point2, point3, point4, answer);
            hits = boundsCheck(linePoint1, linePoint2, point2, point3, point4, answer);
            writeToFile(FILE_PATH, filePtr, answer, hits);
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
void writeToFile(const char filePath[LENGTH_FILE_PATH], FILE* filePtr, double ans[THREE], bool intersects) {

    char fullFilePath1[LENGTH_FILE_PATH];

    FILE* filePtr3;

    sprintf(fullFilePath1, "%spart2-sub2", filePath);
    filePtr3 = fopen(fullFilePath1, "a");

    if (intersects) {

        fprintf(filePtr3, "\n");

        for (int i = 0; i < THREE; i++) {
            fprintf(filePtr3, "%.2lf ", ans[i]);
        }
    }
    else {
        fprintf(filePtr3, "\nDoes not intersect.");
    }
    
    fclose(filePtr3);
}

//clears any file that had that name previously
void overwrite(const char filePath[LENGTH_FILE_PATH], FILE* filePtr, const char path[LENGTH_FILE_PATH]) {

    char fullFilePath1[LENGTH_FILE_PATH];

    FILE* filePtr3;

    sprintf(fullFilePath1, "%spart2-sub2", filePath);
    filePtr3 = fopen(fullFilePath1, "w");

    //simply opening the file so that I can overwrite the whole thing 

    fclose(filePtr3);
}