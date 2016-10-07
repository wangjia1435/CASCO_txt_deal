// ReadTxtContend.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
void txtParseFilenameExtrate(FILE* pfile, char filename[][100], const char* dirname);

int _tmain(int argc, _TCHAR* argv[])
{
	char FILENAME[100][100] = {0};
	FILE *pFile=NULL;
	char dirName[100] = "D:\\ResearchContent\\Exercise_Programm\\CogCount\\TEST\\test1.txt";
	txtParseFilenameExtrate(pFile, FILENAME, dirName);
	//char def;
	////"D:\\ResearchContent\\Exercise_Programm\\CogCount\\TEST\\test1.txt"
	//if (fopen_s(&pFile, "D:\\ResearchContent\\Exercise_Programm\\CogCount\\TEST\\test1.txt", "r") != NULL)
	//{
	//	printf_s("file open error");
	//}
	//
	//int fileNum = 0;
	//int row = 0, i = 0;
	//while ((def=fgetc(pFile)) != EOF)
	//{
	//	if (def == '\n')
	//	{
	//		fileNum++;
	//		row++;
	//		i = 0;
	//	}
	//	if (def != '\n')
	//	FILENAME[row][i++] = def;

	//}

	//fclose(pFile);
	return 0;
}

void txtParseFilenameExtrate(FILE* pfile, char filename[][100], const char* dirname)
{
	char def;
	//"D:\\ResearchContent\\Exercise_Programm\\CogCount\\TEST\\test1.txt"
	if (fopen_s(&pfile, dirname, "r") != NULL)
	{
		printf_s("file open error");
	}

	int fileNum = 0;
	int row = 0, i = 0;
	while ((def = fgetc(pfile)) != EOF)
	{
		if (def == '\n')
		{
			fileNum++;
			row++;
			i = 0;
		}
		if (def != '\n')
			filename[row][i++] = def;

	}

	fclose(pfile);
}

