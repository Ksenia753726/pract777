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

		FillBinaryFileFromTextFile(fin_mark, bin_mark);
		FillBinaryFileFromTextFile(fin_stud, bin_stud);


	}
	catch (const char* m) {
		std::cout << m;
	}
	return 0;
}