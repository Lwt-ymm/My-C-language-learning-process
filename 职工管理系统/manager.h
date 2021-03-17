#pragma once
#include"worker.h"

class Manager :public Worker
{
public:
	Manager(int id, string name, int deptid);

	void showInfo();

	string getDeptName();
};
