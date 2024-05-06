#include<iostream>;
using namespace std;
#include"workManager.h"
#include"worker.h";
#include"employee.h";
#include"employer.h";
#include"boss.h";

void test01() {
	Employee* employee1 = new Employee(001, "cwl", 1);
	employee1->showInfor();
	delete employee1;
}

int main() {

	WorkManager wm;
	int num;
	while (true) {
		wm.ShowMenu();
		cout << "请输入您的操作" << endl;
		cin >> num;
		switch (num) 
		{
		case 0: //退出
			wm.ExitSystem();
			break;
		case 1: //添加
			wm.AddPerson();
			break;
		case 2: //显示
			wm.DisplayPersonInformation();
			break;
		case 3: //删除
			wm.DeletePerson();
			break;
		case 4: //修改
			wm.CorrectPerson();
			break;
		case 5: //查找
			wm.FindPerson();
			break;
		case 6: //排序
			wm.SortInformation();
			break;
		case 7: //清空
			wm.CleanInformation();
			break;
		default:
			break;
		}
	}

	return 0;
}