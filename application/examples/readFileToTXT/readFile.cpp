#include<iostream>  
#include <windows.h>  
#include <string>  
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

vector<string> find(string FolderDirectory)
{
	vector<string> file;
	string szFileName = FolderDirectory + "/*.*";//指定目录下的直接的所有文件和目录

	WIN32_FIND_DATA FindData;
	HANDLE hFile;//句柄
	hFile = FindFirstFile(szFileName.c_str(), &FindData);

	if (hFile != INVALID_HANDLE_VALUE){
		if (FindData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY){
			string FileDir = FolderDirectory + "\\";
			FileDir += FindData.cFileName;
			file.push_back(FileDir);
		}
		while (FindNextFile(hFile, &FindData)){
			if (FindData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY){
				string FileDir = FolderDirectory + "\\";
				FileDir += FindData.cFileName;
				file.push_back(FileDir);
			}
		}
		FindClose(hFile);
	}
	else
	{
		printf("Invalid file directory !");
	}
	return file;
}
int main()
{
	string path = "E:\\OneDrive\\liurui-doc\\CCPR";

	vector<string> scan = find(path);
	ofstream output("C:\\Users\\liu-rui\\Desktop\\lib.txt", ios::in | ios::out | ios::trunc);
	for (auto &element : scan)
	{
		output << element.substr(path.size() + 1, 1000) << endl;
	}
	return 0;
}