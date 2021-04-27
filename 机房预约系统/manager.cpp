#include"manager.h"

//默认构造
Manager::Manager()
{

}
//有参构造(姓名，密码)
Manager::Manager(string name, string password)
{
	//初始化管理员信息
	this->m_name = name;
	this->m_password = password;
	//初始化容器，获取学生教师信息
	this->initVector();

	//获取机房信息
	vC.clear();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "机房信息文件打开失败" << endl;
	}
	ComputerRoom c;
	while (ifs >> c.m_id && ifs >> c.m_max)
	{
		vC.push_back(c);
	}
	ifs.close();
}
//菜单界面
void Manager::operMenu()
{
	cout << "=============欢迎管理员" << this->m_name << "登录=============" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          1.添加账号          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          2.查看账号          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          3.查看机房          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          4.清空预约          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          0.注销登录          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "请选择您的操作：" << endl;
}
//添加账号
void Manager::addPerson()
{
	cout << "请输入要添加账号的类型：" << endl;
	cout << "1、添加学生账号" << endl;
	cout << "2、添加教师账号" << endl;

	string fileName;
	string tip;
	string eor;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		eor = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		eor = "职工号重复，请重新输入";
	}

	int id = 0;
	string name;
	string password;
	while (true)
	{
		cout << tip;
		cin >> id;

		if (this->checkRepeat(id, select))
		{
			cout << eor << endl;
		}
		else
		{
			break;
		}
	}
	

	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> password;

	ofs.open(fileName, ios::out | ios::app);
	ofs << id << ' ' << name << ' ' << password << endl;
	ofs.close();
	this->initVector();
	cout << "添加成功" << endl;

	system("pause");
	system("cls");
}
//打印信息
void printfS(Student& s)
{
	cout << "学号：" << s.m_id << ' ' << "姓名：" << s.m_name << ' ' << "密码：" << s.m_password << endl;
}
void printfT(Teacher& t)
{
	cout << "职工号：" << t.m_id << ' ' << "姓名：" << t.m_name << ' ' << "密码：" << t.m_password << endl;
}
void printfC(ComputerRoom& c)
{
	cout << "机房号：" << c.m_id << ' ' << "机房容量：" << c.m_max << endl;
}
//查看账号
void Manager::showPerson()
{
	cout << "请选择要查看的内容：" << endl;
	cout << "1、查看所有学生信息" << endl;
	cout << "2、查看所有教师信息" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vS.begin(),vS.end(), printfS);
	}
	else
	{
		cout << "所有教师信息如下：" << endl;
		for_each(vT.begin(), vT.end(), printfT);
	}
	system("pause");
	system("cls");
}
//查看机房信息
void Manager::showComputer()
{
	cout << "所有机房信息如下：" << endl;
	for_each(vC.begin(), vC.end(), printfC);
	system("pause");
	system("cls");
}
//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空预约成功" << endl;
	system("pause");
	system("cls");
}
//初始化容器
void Manager::initVector()
{
	vS.clear();
	vT.clear();
	//读取信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs>>s.m_password)
	{
		vS.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_id && ifs >> t.m_name && ifs>>t.m_password)
	{
		vT.push_back(t);
	}
	ifs.close();
}
//检测重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vS.begin(); it != vS.end(); it++)
		{
			if (it->m_id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vT.begin(); it != vT.end(); it++)
		{
			if (it->m_id == id)
			{
				return true;
			}
		}
	}
	return false;
}