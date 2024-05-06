#pragma once
#include<iostream>;
#include<string>;
using namespace std;
#include"worker.h";

class Employer :public Worker {
public:
	Employer(int id, string name, int  deptname);

		virtual void showInfor();

		virtual string getInfor();
	

};