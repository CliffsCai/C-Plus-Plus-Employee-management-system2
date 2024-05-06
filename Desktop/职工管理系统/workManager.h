#pragma once
#include<iostream>;
using namespace std;
#include"worker.h"
#include<fstream>;
#define FILENAME "emFile.txt"

class WorkManager {
public:
	WorkManager();

	//展示菜单功能
	void ShowMenu();

	void ExitSystem();

	void AddPerson();
	int m_EmpNum;
	Worker ** m_EmpArray;

	void SaveFile();

	bool m_IsFileEmpty;

	int get_EmpNum();

	void init_Emp();

	void DisplayPersonInformation();

	void DeletePerson();

	void CorrectPerson();

	void FindPerson();

	void SortInformation();

	void CleanInformation();

	~WorkManager();
};
