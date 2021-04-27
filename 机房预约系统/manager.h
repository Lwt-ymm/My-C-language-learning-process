#pragma once
#include"identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include"globalFile.h"
#include<fstream>
#include<algorithm>

class Manager :public Identity
{
public:
	//学生容器
	vector<Student> vS;
	//教师容器
	vector<Teacher> vT;
	//机房容器
	vector<ComputerRoom> vC;

	//默认构造
	Manager();
	//有参构造(姓名，密码)
	Manager(string name, string password);
	//菜单界面
	virtual void operMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void cleanFile();
	//初始化容器
	void initVector();
	//检测重复
	bool checkRepeat(int id, int type);
};