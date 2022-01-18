#include "Student.h"

void readStudent(STU& student, FILE* fi) {
	fscanf(fi, "%s", student.id);
	fscanf(fi, "%lf", &student.averPoint);
	char fullName[50];
	getc(fi);
	fgets(fullName, 50, fi);
	int len = strlen(fullName);
	if (fullName[len - 1] == '\n') {
		fullName[len - 1] = '\0';
		len -= 1;
	}
	student.fullName = (char*)calloc(len, sizeof(char));
	strcpy(student.fullName, fullName);
	
}

void writeStudent(STU student, FILE* fo) {
	fwrite(&student, sizeof(STU), 1, fo);
}

void binaryToConsoleSTU(STU student, FILE* fsub) {
	fread(&student, sizeof(STU), 1, fsub);
	printf("%s %s %f\n", student.id, student.fullName, student.averPoint);
	
}

bool readStudentArray(STU*& stuArr, int& nStuArr, FILE* fi) {
	if (!stuArr) {
		return false;
	}
	else {
		for (int i = 0; i < nStuArr; i++) {
			readStudent(stuArr[i], fi);
		}
		return true;
	}
}

void writeStudentArray(STU* stuArr, int nStuArr, FILE* fo) {
	for (int i = 0; i < nStuArr; i++) {
		writeStudent(stuArr[i], fo);
	}
}

void binaryToConsoleSTArr(STU* stuArr, int nStuArr, FILE* fsub) {
	for (int i = 0; i < nStuArr; i++) {
		binaryToConsoleSTU(stuArr[i], fsub);
	}
}