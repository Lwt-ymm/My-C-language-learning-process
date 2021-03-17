#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>

#define FILENAME "worker.txt"

using namespace std;

class WorkManager
{
public:
	//记录当前员工个数
	int m_empnum;
	//职工数组的指针
	Worker** m_emparr;
	//判断文件是否为空
	bool isFileEmpty = true;

	WorkManager();
	
	~WorkManager();

	//展示菜单
	void showMenu();
	//退出系统
	void exitSystem();
	//增加职工信息
	void addEmployee();
	//保存文件
	void save();
	//统计文件中记录的人数
	int get_num();
	//初始化员工
	void initEmployee();
	//显示职工信息
	void showEmployee();
	//查询职工是否存在
	int fineEmployee(int id);
	//删除离职职工
	void delEmployee();
	//修改职工信息
	void modEmpoyee();
	//查找职工信息
	void searchEmployee();
	//按照编号排序
	void sortEmployee();
	//清空所有文档
	void cleanFile();
};