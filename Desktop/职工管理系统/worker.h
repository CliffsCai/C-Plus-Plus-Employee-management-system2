#pragma once
#include<iostream>;
using namespace std;

class Worker {
public:

	Worker();


	virtual void showInfor() = 0;

	virtual string getInfor() = 0;

	string m_name;
	int m_id;
	int  m_deptname;



};