#pragma once
#include"worker.h"

class Employee :public Worker
{
public:
	Employee(int id, string name, int deptid);

	void showInfo(); 

	string getDeptName();
};