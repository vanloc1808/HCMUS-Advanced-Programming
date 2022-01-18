#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "PositiveIntegers.h"
#include "MatrixFile.h"
#include "Fraction.h"
#include "Point.h"
#include "Circle.h"
#include "Student.h"

int main()
{
    FILE* fi, * fo, * fsub;
    fi = fopen("input.txt", "r");
    fo = fopen("output.txt", "wb");
    if (!fi || !fo)
    {
        printf("Error. Cannot open file.");
    }
    else
    {
        processPosInt(fi, fo);
        int row = 0, column = 0;
        int** matrix = NULL;


        fclose(fo);
        fsub = fopen("output.txt", "rb");

        binaryToConsolePI(fsub);
        printf("\n");
        fclose(fsub);
        
        if (!readMatrix(matrix, row, column, fi))
        {
            printf("Error. Not enough memory.\n");
        }
        else
        {
            writeMatrix(matrix, row, column, fo);
            binaryToConsoleMT(matrix, row, column, fsub);
            free(matrix[0]);
            free(matrix);
        }
    
       

        FRAC fr = { 0,0 };
        readFracStruct(fr, fi);
        fo = fopen("fraction.txt", "wb");
        writeFracStruct(fr, fo);
        fclose(fo);
        fsub = fopen("fraction.txt", "rb");
        printf("The fraction is: ");
        binaryToConSoleFR(fr, fsub);
        printf("\n");
        fclose(fsub);
        printf("\n");
        
        int nFracArr = 0;
        fscanf(fi, "%d", &nFracArr);
        FRAC* frArr = NULL;
        frArr = (FRAC*)calloc(nFracArr, sizeof(FRAC));
        if (!readFracStructArray(frArr, nFracArr, fi)) {

        }
        else {
            fo = fopen("fractionarray.txt", "wb");
            writeFracStructArray(frArr, nFracArr, fo);
            fclose(fo);
            fsub = fopen("fractionarray.txt", "rb");
            printf("The fraction array is:\n");
            binaryToConsoleFRArr(frArr, nFracArr, fsub);
            printf("\n");
            fclose(fsub);
            free(frArr);
        }

        FRAC** frMat = NULL;
        int nRow = 0, nColumn = 0;
        if (!readFracStructMatrix(frMat, nRow, nColumn, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else
        {
            fo = fopen("fractionmatrix.txt", "wb");
            writeFracStructMatrix(frMat, nRow, nColumn, fo);
            fclose(fo);
            fsub = fopen("fractionmatrix.txt", "rb");
            printf("The fraction matrix is:\n");
            binaryToConsoleFRMa(frMat, nRow, nColumn, fsub);
            printf("\n");
            fclose(fsub);
        }
        PNT M = { 0,0 };
        readPointStruct(M, fi);
        fo = fopen("point.txt", "wb");
        writePointStruct(M, fo);
        fclose(fo);
        fsub = fopen("point.txt", "rb");
        printf("The point has the coordinates: ");
        binaryToConsolePNT(M, fsub);
        printf("\n");
        fclose(fsub);

        int nPoiArr = 0;
        fscanf(fi, "%d", &nPoiArr);
        PNT* pointArr = (PNT*)calloc(nPoiArr, sizeof(PNT));
        if (!readPointStructArray(pointArr, nPoiArr, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else
        {
            fo = fopen("pointarray.txt", "wb");
            writePointStructArray(pointArr, nPoiArr, fo);
            fclose(fo);
            fsub = fopen("pointarray.txt", "rb");
            printf("The point array is: \n");
            binaryToConsolePArr(pointArr, nPoiArr, fsub);
            fclose(fsub);
            free(pointArr);

        }
        PNT** pointMat = NULL;
        int nPoRow = 0, nPoCol = 0;
        if (!readPointStructMatrix(pointMat, nPoRow, nPoCol, fi))
        {
            printf("Error. Not enough memory.\n");
        }
        else {
            fo = fopen("pointmatrix.txt", "wb");
            writePointStructMatrix(pointMat, nPoRow, nPoCol, fo);
            fclose(fo);
            fsub = fopen("pointmatrix.txt", "rb");
            printf("The point matrix is:\n");
            binaryToConsolePMat(pointMat, nPoRow, nPoCol, fsub);
            fclose(fsub);
            free(pointMat[0]);
            free(pointMat);
        }

        CIR c = { 0,0,0 };
        readCircle(c, fi);
        fo = fopen("circle.txt", "wb");
        writeCircle(c, fo);
        fclose(fo);
        fsub = fopen("circle.txt", "rb");
        printf("The circle is:\n");
        binaryToConsoleCIR(c, fsub);
        printf("\n");
        fclose(fsub);

        CIR* cArr = NULL;
        int nCirArr = 0;
        fscanf(fi, "%d", &nCirArr);
        cArr = (CIR*)calloc(nCirArr, sizeof(CIR));
        if (!readCircleArray(cArr, nCirArr, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            fo = fopen("circlearray.txt", "wb");
            writeCircleArray(cArr, nCirArr, fo);
            fclose(fo);
            fsub = fopen("circlearray.txt", "rb");
            printf("The circle array is:\n");
            binaryToConsoleCIRArr(cArr, nCirArr, fsub);
            printf("\n");
            fclose(fsub);
            free(cArr);
        }

        CIR** cMat = NULL;
        int nCirRow = 0, nCirCol = 0;
        if (!readCircleMatrix(cMat, nCirRow, nCirCol, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            fo = fopen("circlematrix.txt", "wb");
            writeCircleMatrix(cMat, nCirRow, nCirCol, fo);
            fclose(fo);
            fsub = fopen("circlematrix.txt", "rb");
            printf("The circle matrix is:\n");
            binaryToConsoleCIRMat(cMat, nCirRow, nCirCol, fsub);
            fclose(fsub);
            free(cMat[0]);
            free(cMat);
        }

        int nStuArr = 0;
        fscanf(fi, "%d", &nStuArr);
        STU* stuArr = (STU*)calloc(nStuArr, sizeof(STU));
        if (!readStudentArray(stuArr, nStuArr, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            fo = fopen("studentarray.txt", "wb");
            writeStudentArray(stuArr, nStuArr, fo);
            fclose(fo);
            fsub = fopen("studentarray.txt", "rb");
            binaryToConsoleSTArr(stuArr, nStuArr, fsub);
            fclose(fsub);
            free(stuArr);
        }

        fclose(fi);
        
        fi = fopen("student.csv", "r");
        char header[100];
        while (!feof(fi)) {
            fgets(header, 100, fi);
            printf("%s", header);
        }
        fclose(fi);

    }
	

}

