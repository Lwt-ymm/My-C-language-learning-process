#include"employee.h"

Employee::Employee(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}

void Employee::showInfo()
{
	cout << "ְ�����:" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\t���ڸ�λ:" << this->getDeptName()
		<< "\t��λְ��:��ɾ�����������"
		<< endl;
}

string Employee::getDeptName()
{
	return string("Ա��");
}