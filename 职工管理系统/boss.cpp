#include"boss.h"

Boss::Boss(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}

void Boss::showInfo()
{
	cout << "ְ�����:" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\t���ڸ�λ:" << this->getDeptName()
		<< "\t��λְ��:����˾��������"
		<< endl;
}

string Boss::getDeptName()
{
	return string("�ܲ�");
}