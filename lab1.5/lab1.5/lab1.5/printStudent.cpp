#include <iostream>
#include <locale.h>
#include <Windows.h>
#include "StudentStruct.h"

void printStudent(student targetStudent) {

	printf("������� %s %s ��������� �� ���������� %s, ����� �������� ������ %s\n", targetStudent.lastName, targetStudent.firstName, targetStudent.faculty, targetStudent.studentSerialNumber);

}