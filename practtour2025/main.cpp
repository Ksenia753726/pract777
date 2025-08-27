#include "header.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream fin_mark("Group_ID_MA_Mark_GEO_Mark_PROG_Mark.txt");
	std::ifstream fin_stud("ID_SNP.txt");
	std::fstream bin_mark("Bin_Group_ID_MA_Mark_GEO_Mark_PROG_Mark.bin", std::ios::in | std::ios::out | std::ios::binary);
	std::fstream bin_stud("Bin_ID_SNP.bin", std::ios::in | std::ios::out | std::ios::binary);

	try {
		CheckInputFile(fin_mark);
		CheckInputFile(fin_stud);
		int32_t size{ FindCountOfStudents(fin_stud) };
		Student* array_stud = new Student[size];

		FillArrayFromFileStud(fin_mark, fin_stud, array_stud, size);
		/*std::string* lines_mark = new std::string[size];
		std::string* lines_stud = new std::string[size];

		FillLinesFromFile(fin_mark, fin_stud, lines_mark, lines_stud, size);

		

		FillBinaryFile(bin_stud, lines_stud, size);
		FillBinaryFile(bin_mark, lines_mark, size);*/
	}
	catch (const char* m) {
		std::cout << m;
	}
	return 0;
}