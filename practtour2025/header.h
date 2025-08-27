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


void FillBinaryFileFromTextFile(std::ifstream& fin_mark, std::fstream& bin_mark);//заполняет бинарный файл из текстового

void SortStructById(Student*& students, int32_t size);//сортирует структуру по id

void FillStructFromFileWithMarks(std::ifstream& fin_mark, Student* student, int32_t size);//заполняет структуру из файла с оценками
void FillFileWithMark(std::string& filename, Student* students, int32_t size);//заполняет файл с оценками 

void FillStructFileWithFIO(std::ifstream& fin_stud, Student* students, int32_t size);//заполняет структуру из файла с фамилиями
void FillFileWithFIO(std::string& filename, Student* students, int32_t size);//заполняет файл с фамилиями студентов

void MakeBinaryFileWithSurnAndMarks(Student* students, int32_t size);//создает бинарный файл в папке и записывает фамилии с оценками
#endif

//4; 456349; МА; 5; ГЕО; 9; ПРОГ; 10
//3; 456348; МА; 4; ГЕО; 2; ПРОГ; 4
//4; 456340; МА; 5; ГЕО; 6; ПРОГ; 10
//1; 456345; МА; 4; ГЕО; 5; ПРОГ; 2


//456345; Иванов; Иван; Петрович
//456348; Петров; Петр; Иванович
//456340; Иванова; Мария; Семеновна
//456349; Петрова; Наталья; Егоровна