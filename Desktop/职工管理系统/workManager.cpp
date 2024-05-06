#include<iostream>;
using namespace std;
#include"workManager.h";
#include"employee.h";
#include"employer.h";
#include"boss.h";

WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_IsFileEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())   // ����Ƿ��ѵ��ļ�ĩβ
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_IsFileEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�������������
	int num = this->get_EmpNum();
	cout << "��ǰְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ� " << this->m_EmpArray[i]->m_id 
	//	<< "ְ�������� " << this->m_EmpArray[i]->m_name 
	//	<< "ְ�����ţ� " << this->m_EmpArray[i]->m_deptname << endl;
	//}
	this->m_IsFileEmpty = false;
}

void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1) 
{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Employer(id, name, dId);
		}
		else{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

}

int WorkManager::get_EmpNum() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int num = 0;
	int id;
	string name;
	int deptname;
	while (ifs >> id && ifs >> name && ifs >> deptname)
	{
		num++;
	}
	ifs.close();
	return num;
}


void WorkManager::ShowMenu() 
{	
	//�ļ�������������
	int num = this->get_EmpNum();
	cout << "��ǰְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	cout << "*******************************" << endl;
	cout << "*****��ӭʹ��ְ������ϵͳ******" << endl;
	cout << "********0.�˳�����ϵͳ*********" << endl;
	cout << "********1.����Ա����Ϣ*********" << endl;
	cout << "********2.��ʾԱ����Ϣ*********" << endl;
	cout << "********3.ɾ����ְԱ��*********" << endl;
	cout << "********4.�޸�ְ����Ϣ*********" << endl;
	cout << "********5.����ְ����Ϣ*********" << endl;
	cout << "************6.����*************" << endl;
	cout << "************7.���*************" << endl;
	cout << "*******************************" << endl;
}

void WorkManager::ExitSystem() 
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void WorkManager::AddPerson() 
{
	cout << "����������ְ������" << endl;
	
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		int insertIndex = this->m_EmpNum;  //�������
		for (int i = 0; i < addNum; i++) 
		{
			int id;
			string name;
			int  deptname;
			int  dSelect;
			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����ְ���ĸ�λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: {
				deptname = 1;
				worker = new Employee(id, name, deptname);
				break;
			}
			case 2: {
				deptname = 2;
				worker = new Employer(id, name, deptname);
				break;
			}
			case 3: {
				deptname = 3;
				worker = new Boss(id, name, deptname);
				break;
			}
			default:
				break;
			}
			newSpace[insertIndex++] = worker;
		}

		delete[] this->m_EmpArray;   //�ͷ�ԭ�пռ�

		this->m_EmpArray = newSpace;  //�����¿ռ��ָ��

		this->m_EmpNum = newSize;    //����ְ������
		cout << "�ɹ����" << addNum << "��Ա��" << endl;
		this->m_IsFileEmpty = false;
		this->SaveFile();
	}
	else {
		cout << "���������������" << endl;
	}
	system("pause");
	system("cls");
};

void WorkManager::SaveFile() 
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_deptname << endl;
	}
	ofs.close();
}


void WorkManager::DisplayPersonInformation() 
{
	if (this->m_IsFileEmpty) {
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfor();
		}
	}
	system("pause");
	system("cls");
};
void WorkManager::DeletePerson() 
{
	int num;
	cout << "�����������ȵ��˵ı�ţ�" << endl;
	cin >> num;
	int j = 0;
	Worker** newSpace = new Worker * [this->m_EmpNum];
	for (int i = 0; i < this->m_EmpNum; i++) 
	{
		if (this->m_EmpArray[i]->m_id != num) {
			newSpace[j++] = this->m_EmpArray[i];
		}
		
	}
	delete[] m_EmpArray;
	this->m_EmpArray = newSpace;   //this->m_EmpArray ��һ��ָ�룬ָ�����µ�һ���ڴ�ռ�
	this->m_EmpNum--;
	if (this->m_EmpNum == 0)
	{
		this->m_IsFileEmpty = true;
	}
	this->SaveFile();

};
void WorkManager::CorrectPerson() 
{

};
void WorkManager::FindPerson() 
{

};
void WorkManager::SortInformation() 
{

};
void WorkManager::CleanInformation() 
{

};


WorkManager::~WorkManager() {
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}