#include<iostream>;
using namespace std;
#include"employer.h";

Employer::Employer(int id, string name, int deptname) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptname = deptname;
}

void Employer::showInfor() {
	cout << "Ա�����: " << this->m_id << endl;
	cout << "Ա������: " << this->m_name << endl;
	switch (m_deptname)
	{
	case 1:
		cout << "Ա��ְλ: " << "Ա��" << endl;
		break;
	case 2:
		cout << "Ա��ְλ: " << "����" << endl;
		break;
	case 3:
		cout << "Ա��ְλ: " << "�ϰ�" << endl;
		break;
	default:
		break;
	}
	cout << "����ϰ岼�õ����񣬸�Ա����������" << endl;
}

string Employer::getInfor() {
	return string ("����");
}