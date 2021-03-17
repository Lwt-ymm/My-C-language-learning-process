#include"boss.h"

Boss::Boss(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}

void Boss::showInfo()
{
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t所在岗位:" << this->getDeptName()
		<< "\t岗位职责:管理公司所有事务。"
		<< endl;
}

string Boss::getDeptName()
{
	return string("总裁");
}