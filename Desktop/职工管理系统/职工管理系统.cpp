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
		cout << "���������Ĳ���" << endl;
		cin >> num;
		switch (num) 
		{
		case 0: //�˳�
			wm.ExitSystem();
			break;
		case 1: //���
			wm.AddPerson();
			break;
		case 2: //��ʾ
			wm.DisplayPersonInformation();
			break;
		case 3: //ɾ��
			wm.DeletePerson();
			break;
		case 4: //�޸�
			wm.CorrectPerson();
			break;
		case 5: //����
			wm.FindPerson();
			break;
		case 6: //����
			wm.SortInformation();
			break;
		case 7: //���
			wm.CleanInformation();
			break;
		default:
			break;
		}
	}

	return 0;
}