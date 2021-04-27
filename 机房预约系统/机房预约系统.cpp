#include<iostream>
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<conio.h>

using namespace std;

//进入管理员子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		//将父类指针转为子类指针，调用子类指针其他接口
		Manager* man = (Manager*)manager;
		
		int select = 0;
		//接收用户选择
		cin >> select;
		if (select == 1)
		{
			man->addPerson();//添加账号
		}
		else if (select == 2)
		{
			man->showPerson();//查看账号
		}
		else if (select == 3)
		{
			man->showComputer();//查看机房
		}
		else if (select == 4)
		{
			man->cleanFile();//清空预约
		}
		else
		{
			delete manager;//注销管理员
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();
		//将父类指针转为子类指针，调用子类指针其他接口
		Student* man = (Student*)student;

		int select = 0;
		//接收用户选择
		cin >> select;
		if (select == 1)
		{
			man->applyOrder();//申请预约
		}
		else if (select == 2)
		{
			man->showMyOrder();//查看我的预约
		}
		else if (select == 3)
		{
			man->showAllOrder();//查看所有预约
		}
		else if (select == 4)
		{
			man->cancelOrder();//取消预约
		}
		else
		{
			delete student;//注销学生
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用学教师菜单
		teacher->operMenu();
		//将父类指针转为子类指针，调用子类指针其他接口
		Teacher* man = (Teacher*)teacher;

		int select = 0;
		//接收用户选择
		cin >> select;
		if (select == 1)
		{
			man->showAllOrder();//查看预约
		}
		else if (select == 2)
		{
			man->validOrder();//审核预约
		}
		else
		{
			delete teacher;//注销教师
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录 操作1文件 身份类型
void loginIn(string fileName, int type)
{
	//父类指针指向子类对象
	Identity* person = NULL;
	
	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in); 
	
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id = 0;
	string name;
	string password;

	//判断身份
	if (type == 1)//学生
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)//教师
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	//密码回显*号
	char temp = 0;
	while (1)
	{
		temp = _getch();
		if (temp == 13)
		{
			cout << endl;
			break;
		}
		else if (temp == 8)
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
			password.pop_back();
		}
		else
		{
			password += temp;
			cout << "*";
		}
	}

	//身份验证
	if (type == 1)//学生
	{
		//准备接受文件信息
		int fid = 0;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (fid == id && fname == name && fpassword == password)
			{
				cout << "学生登录验证成功。" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				//进入学生的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)//教师
	{
		//准备接受文件信息
		int fid = 0;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (fid == id && fname == name && fpassword == password)
			{
				cout << "教师登录验证成功。" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				//进入教师的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)//管理员
	{
		//准备接受文件信息
		string fname;
		string fpassword;
		while (ifs >> fname && ifs >> fpassword)
		{
			if (fname == name && fpassword == password)
			{
				cout << "管理员教师登录验证成功。" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);
				//进入管理员的子菜单
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;

	while (1)
	{
		cout << "=======================欢迎使用机房预约系统=======================" << endl;
		cout << "请选择您的身份：" << endl;
		cout << "\t\t ------------------------------ " << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          1.学    生          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          2.教    师          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          3.管 理 员          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          0.退    出          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t ------------------------------ " << endl;

		cin >> select;
		switch (select)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用。" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择" << endl;
			system("pause");
			break;
		}
	}

	return 0;
}