#pragma once
#define HEADER_H
#ifdef HEADER_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

struct Student {
	int32_t id{};
	int32_t group{};
	std::string name;
	std::string surname;
	std::string patronymic;
	int32_t mark_ma{};
	int32_t mark_geo{};
	int32_t mark_prog{};
};

void CheckInputFile(std::istream& fin);

int32_t FindCountOfStudents(std::istream& fin);
void FillStructArrayFromFiles(std::istream& fin_mark, std::istream& fin_stud, Student* student, int32_t size);


void FillBinaryFileFromTextFile(std::ifstream& fin_mark, std::fstream& bin_mark);//��������� �������� ���� �� ����������

void SortStructById(Student*& students, int32_t size);//��������� ��������� �� id

void FillStructFromFileWithMarks(std::ifstream& fin_mark, Student* student, int32_t size);//��������� ��������� �� ����� � ��������
void FillFileWithMark(std::string& filename, Student* students, int32_t size);//��������� ���� � �������� 

void FillStructFileWithFIO(std::ifstream& fin_stud, Student* students, int32_t size);//��������� ��������� �� ����� � ���������
void FillFileWithFIO(std::string& filename, Student* students, int32_t size);//��������� ���� � ��������� ���������

void MakeBinaryFileWithSurnAndMarks(Student* students, int32_t size);//������� �������� ���� � ����� � ���������� ������� � ��������
#endif

//4; 456349; ��; 5; ���; 9; ����; 10
//3; 456348; ��; 4; ���; 2; ����; 4
//4; 456340; ��; 5; ���; 6; ����; 10
//1; 456345; ��; 4; ���; 5; ����; 2


//456345; ������; ����; ��������
//456348; ������; ����; ��������
//456340; �������; �����; ���������
//456349; �������; �������; ��������