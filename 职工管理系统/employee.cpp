#include"employee.h"

Employee::Employee(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}

void Employee::showInfo()
{
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t所在岗位:" << this->getDeptName()
		<< "\t岗位职责:完成经理分配的任务。"
		<< endl;
}

string Employee::getDeptName()
{
	return string("员工");
}