#include "header.h"

void CheckInputFile(std::istream& fin) {
	if (!fin.good()) {
		throw "file isnt exist\n";
	}
	if (!fin) {
		throw "input file error\n";
	}
	if (fin.peek() == EOF) {
		throw "file is empty\n";
	}
}

int32_t FindCountOfStudents(std::istream& fin) {
	int32_t counter{};
	std::string str{};
	while (std::getline(fin, str)) {
		++counter;
	}
	return counter;
}

void FillArrayFromFileStud(std::istream& fin_mark, std::istream& fin_stud, Student* student, int32_t size) {
	fin_stud.clear();
	fin_stud.seekg(0);

	fin_mark.clear();
	fin_mark.seekg(0);
	std::string id;
	std::string group;
	std::string surname;
	std::string name;
	std::string patronymic;
	std::string mark_ma;
	std::string mark_geo;
	std::string mark_prog;
	int32_t i{};
	while (i < size && std::getline(fin_stud, id, ';') && std::getline(fin_mark, group, ';') && std::getline(fin_stud, surname, ';') && std::getline(fin_stud, name, ';') && std::getline(fin_stud, patronymic, ';') && std::getline(fin_mark, mark_ma, ';') && std::getline(fin_mark, mark_geo, ';') && fin_mark >> mark_prog) {
		student[i].id = std::stoi(id);
		student[i].group = std::stoi(group);
		student[i].name = name;
		student[i].name = surname;
		student[i].name = patronymic;
		student[i].mark_ma = std::stoi(mark_ma);
		student[i].mark_geo = std::stoi(mark_geo);
		student[i].mark_prog = std::stoi(mark_prog);
		++i;
		fin_stud.ignore();
		fin_mark.ignore();
	}
}