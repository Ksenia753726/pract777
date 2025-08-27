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

void FillArrayFromFileStud(std::istream& fin_mark, std::istream& fin_stud, Student* student, int32_t size);
void CheckInputFile(std::istream& fin);

void FillBinaryFileFromTextFile(std::ifstream& fin_mark, std::fstream& bin_mark);

#endif