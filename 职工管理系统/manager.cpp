#include"manager.h"

Manager::Manager(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}

void Manager::showInfo()
{
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t所在岗位:" << this->getDeptName()
		<< "\t岗位职责:完成老板分配的任务，并给员工下发任务。"
		<< endl;
}

string Manager::getDeptName()
{
	return string("经理");
}