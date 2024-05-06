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
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_IsFileEmpty = true;
		ifs.close();
		return;
	}
	//文件存在但为空
	char ch;
	ifs >> ch;
	if (ifs.eof())   // 检测是否已到文件末尾
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_IsFileEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且有数据
	int num = this->get_EmpNum();
	cout << "当前职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号： " << this->m_EmpArray[i]->m_id 
	//	<< "职工姓名： " << this->m_EmpArray[i]->m_name 
	//	<< "职工部门： " << this->m_EmpArray[i]->m_deptname << endl;
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
	//文件存在且有数据
	int num = this->get_EmpNum();
	cout << "当前职工人数为：" << num << endl;
	this->m_EmpNum = num;
	cout << "*******************************" << endl;
	cout << "*****欢迎使用职工管理系统******" << endl;
	cout << "********0.退出管理系统*********" << endl;
	cout << "********1.增加员工信息*********" << endl;
	cout << "********2.显示员工信息*********" << endl;
	cout << "********3.删除离职员工*********" << endl;
	cout << "********4.修改职工信息*********" << endl;
	cout << "********5.查找职工信息*********" << endl;
	cout << "************6.排序*************" << endl;
	cout << "************7.清空*************" << endl;
	cout << "*******************************" << endl;
}

void WorkManager::ExitSystem() 
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkManager::AddPerson() 
{
	cout << "输入想加入的职工数量" << endl;
	
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
		int insertIndex = this->m_EmpNum;  //添加索引
		for (int i = 0; i < addNum; i++) 
		{
			int id;
			string name;
			int  deptname;
			int  dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工名字" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工的岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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

		delete[] this->m_EmpArray;   //释放原有空间

		this->m_EmpArray = newSpace;  //更改新空间的指向

		this->m_EmpNum = newSize;    //更新职工人数
		cout << "成功添加" << addNum << "名员工" << endl;
		this->m_IsFileEmpty = false;
		this->SaveFile();
	}
	else {
		cout << "您输入的数据有误" << endl;
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
		cout << "文件不存在或为空" << endl;
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
	cout << "请输入你想扇的人的编号：" << endl;
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
	this->m_EmpArray = newSpace;   //this->m_EmpArray 是一个指针，指向了新的一个内存空间
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