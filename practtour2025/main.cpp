#include "header.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string fileNameMark = "Group_ID_MA_Mark_GEO_Mark_PROG_Mark.txt";
	std::string fileNameStud = "ID_SNP.txt";


	std::ifstream fin_mark("Group_ID_MA_Mark_GEO_Mark_PROG_Mark.txt");
	std::ifstream fin_stud("ID_SNP.txt");
	std::fstream bin_mark("Bin_Group_ID_MA_Mark_GEO_Mark_PROG_Mark.bin", std::ios::in | std::ios::out | std::ios::binary);
	std::fstream bin_stud("Bin_ID_SNP.bin", std::ios::in | std::ios::out | std::ios::binary);

	try {
		CheckInputFile(fin_mark);
		CheckInputFile(fin_stud);

		int32_t size = FindCountOfStudents(fin_mark);
		Student* students = new Student[size];

		//a
		FillBinaryFileFromTextFile(fin_mark, bin_mark);
		FillBinaryFileFromTextFile(fin_stud, bin_stud);


		FillStructFromFileWithMarks(fin_mark, students, size);
		SortStructById(students, size);
		FillFileWithMark(fileNameMark, students, size);

		FillStructFileWithFIO(fin_stud, students, size);
		SortStructById(students, size);
		FillFileWithFIO(fileNameStud, students, size);

		FillStructArrayFromFiles(fin_mark, fin_stud, students, size);

		//b
		MakeBinaryFileWithSurnAndMarks(students, size);

	}
	catch (const char* m) {
		std::cout << m;
	}
	return 0;
}