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
	int32_t avg_mark{};
};

void CheckInputFile(std::istream& fin);

int32_t FindCountOfStudents(std::istream& fin);
void FillStructArrayFromFiles(std::istream& fin_mark, std::istream& fin_stud, Student* student, int32_t size);


void FillBinaryFileFromTextFile(std::ifstream& fin_mark, std::fstream& bin_mark);//çàïîëíÿåò áèíàðíûé ôàéë èç òåêñòîâîãî

void SortStructById(Student*& students, int32_t size);//ñîðòèðóåò ñòðóêòóðó ïî id

void FillStructFromFileWithMarks(std::ifstream& fin_mark, Student* student, int32_t size);//çàïîëíÿåò ñòðóêòóðó èç ôàéëà ñ îöåíêàìè
void FillFileWithMark(std::string& filename, Student* students, int32_t size);//çàïîëíÿåò ôàéë ñ îöåíêàìè 

void FillStructFileWithFIO(std::ifstream& fin_stud, Student* students, int32_t size);//çàïîëíÿåò ñòðóêòóðó èç ôàéëà ñ ôàìèëèÿìè
void FillFileWithFIO(std::string& filename, Student* students, int32_t size);//çàïîëíÿåò ôàéë ñ ôàìèëèÿìè ñòóäåíòîâ

void MakeBinaryFileWithSurnAndMarks(Student* students, int32_t size);//ñîçäàåò áèíàðíûé ôàéë â ïàïêå è çàïèñûâàåò ôàìèëèè ñ îöåíêàìè

void FindAverageMark(Student* students, int32_t size);
void FillBinFileAverageMark(std::fstream& bin_file, Student* students, int32_t size);

int32_t FindCountOfSillyStudents(Student* silly_studs, Student* student, int32_t size);
void FillSillyStudents(Student* student, Student* silly_studs, int32_t size);
void FillBinFileSillyStuds(std::fstream& bin_file, Student* students, int32_t size);

int32_t FindGroup(Student student);

std::string FindSurname(Student student);

int CompareUpStud(const void* el1, const void* el2);
void QsortArrayUpStud(Student* array, int32_t size);

void EnterGroup(int32_t& choice_group);
int CompareUpStudByAlphabet(const void* el1, const void* el2);
void QsortArrayUpStudByAlphabet(Student* array, int32_t size);
void FillBinStatementsOfGroup(std::fstream& bin_file, Student* student, int32_t size, int32_t choice_group);


int32_t FindAverage(Student student);
int CompareDownAvg(const void* el1, const void* el2);
void QsortArrayDownAvg(Student* array, int32_t size);
void FillBinStatementsAvgOfGroup(std::fstream& bin_file, Student* student, int32_t size, int32_t choice_group);


int32_t FindCountOfGoodStudents(Student* good_studs, Student* student, int32_t size);
void FillGoodStudents(Student* student, Student* good_studs, int32_t size);
void FillBinFileGoodStuds(std::fstream& bin_file, Student* students, int32_t size);

void MakeBinaryFileToTextFile(std::fstream& bin_file);

#endif

//4; 456349; ÌÀ; 5; ÃÅÎ; 9; ÏÐÎÃ; 10
//3; 456348; ÌÀ; 4; ÃÅÎ; 2; ÏÐÎÃ; 4
//4; 456340; ÌÀ; 5; ÃÅÎ; 6; ÏÐÎÃ; 10
//1; 456345; ÌÀ; 4; ÃÅÎ; 5; ÏÐÎÃ; 2


//456345; Èâàíîâ; Èâàí; Ïåòðîâè÷
//456348; Ïåòðîâ; Ïåòð; Èâàíîâè÷
//456340; Èâàíîâà; Ìàðèÿ; Ñåìåíîâíà
//456349; Ïåòðîâà; Íàòàëüÿ; Åãîðîâíà