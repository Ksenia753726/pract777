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

void FillStructArrayFromFiles(std::istream& fin_mark, std::istream& fin_stud, Student* student, int32_t size) {
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
	for (size_t i = 0; i < size; ++i)
	{
		std::getline(fin_stud, id, ';');
		std::getline(fin_stud, surname, ';');
		std::getline(fin_stud, name, ';');
		fin_stud >> patronymic;
		std::getline(fin_mark, group, ';');
		std::getline(fin_mark, mark_ma, ';');
		std::getline(fin_mark, mark_ma, ';');
		std::getline(fin_mark, mark_ma, ';');
		std::getline(fin_mark, mark_geo, ';');
		std::getline(fin_mark, mark_geo, ';');
		std::getline(fin_mark, mark_prog, ';');
		fin_mark >> mark_prog;

		student[i].id = std::stoi(id);
		student[i].group = std::stoi(group);
		student[i].name = name;
		student[i].surname = surname;
		student[i].patronymic = patronymic;
		student[i].mark_ma = std::stoi(mark_ma);
		student[i].mark_geo = std::stoi(mark_geo);
		student[i].mark_prog = std::stoi(mark_prog);
		
		fin_stud.ignore();
		fin_mark.ignore();
	}
}

void FillBinaryFileFromTextFile(std::ifstream& fin_mark, std::fstream& bin_mark) {
	std::string line;
	while (std::getline(fin_mark, line)) {
		bin_mark << line << '\n';
	}

}



void SortStructById(Student*& students, int32_t size) {
	for (int32_t i = 0; i < size - 1; ++i) {
		
		for (int32_t j = 0; j < size - i - 1; ++j) {
			if (students[j].id > students[j + 1].id) {
				std::swap(students[j], students[j + 1]);
				
			}
		}
		
	}
}


void FillStructFromFileWithMarks(std::ifstream& fin_mark, Student* students, int32_t size) {

	fin_mark.clear();
	fin_mark.seekg(0);
	std::string id;
	std::string group;
	std::string mark_ma;
	std::string mark_geo;
	std::string mark_prog;

	for (size_t i = 0; i < size; ++i)
	{
		std::getline(fin_mark, group, ';');
		std::getline(fin_mark, id, ';');
		std::getline(fin_mark, mark_ma, ';');
		std::getline(fin_mark, mark_ma, ';');

		std::getline(fin_mark, mark_geo, ';');
		std::getline(fin_mark, mark_geo, ';');

		std::getline(fin_mark, mark_prog, ';');
		fin_mark >> mark_prog;

		students[i].group = std::stoi(group);
		students[i].id = std::stoi(id);
		students[i].mark_ma = std::stoi(mark_ma);
		students[i].mark_geo = std::stoi(mark_geo);
		students[i].mark_prog = std::stoi(mark_prog);
		
		fin_mark.ignore();
	}
}

void FillFileWithMark(std::string& filename, Student* students, int32_t size) {
	std::ofstream fout_mark(filename);
	for (size_t i = 0; i < size; ++i)
	{
		fout_mark << students[i].group << ';';
		fout_mark << students[i].id << ';';
		fout_mark << "MA;" << students[i].mark_ma << ';';
		fout_mark << "цен;" << students[i].mark_geo << ';';
		fout_mark << "опнц;" << students[i].mark_prog << '\n';
	}
	fout_mark.close();
}


void FillStructFileWithFIO(std::ifstream& fin_stud, Student* students, int32_t size) {

	fin_stud.clear();
	fin_stud.seekg(0);

	std::string id;
	std::string surname;
	std::string name;
	std::string patronymic;

	for (size_t i = 0; i < size; ++i)
	{
		std::getline(fin_stud, id, ';');
		std::getline(fin_stud, surname, ';');
		std::getline(fin_stud, name, ';');
		fin_stud >> patronymic;

		students[i].id = std::stoi(id);
		students[i].surname = surname;
		students[i].name = name;
		students[i].patronymic = patronymic;

		fin_stud.ignore();
	}
}

void FillFileWithFIO(std::string& filename, Student* students, int32_t size) {
	std::ofstream fout_stud(filename);
	for (size_t i = 0; i < size; ++i)
	{
		fout_stud << students[i].id << ';';
		fout_stud << students[i].surname << ';';
		fout_stud << students[i].name << ';';
		fout_stud << students[i].patronymic << '\n';
	}
	fout_stud.close();
}


void MakeBinaryFileWithSurnAndMarks(Student* students, int32_t size) {
	std::ofstream fout_SMBIN("Project2025/SurnamesMarks.bin", std::ios::binary);

	for (size_t i = 0; i < size; ++i)
	{
		fout_SMBIN << students[i].surname << ';';
		fout_SMBIN << students[i].mark_ma << ';';
		fout_SMBIN << students[i].mark_geo << ';';
		fout_SMBIN << students[i].mark_prog << ';';
		fout_SMBIN << '\n';
	}
	//fout_SMBIN.close();
}