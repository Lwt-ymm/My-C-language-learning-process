#pragma once
#include<iostream>
#include<string>

using namespace std;

class Worker
{
public:
	int m_id;
	string m_name;
	int m_deptid;

	virtual void showInfo() = 0;

	virtual string getDeptName() = 0;

};