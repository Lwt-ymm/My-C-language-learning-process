#include"manager.h"

Manager::Manager(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}

void Manager::showInfo()
{
	cout << "ְ�����:" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\t���ڸ�λ:" << this->getDeptName()
		<< "\t��λְ��:����ϰ��������񣬲���Ա���·�����"
		<< endl;
}

string Manager::getDeptName()
{
	return string("����");
}