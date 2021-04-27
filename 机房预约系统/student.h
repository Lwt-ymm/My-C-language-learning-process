#pragma once
#include"identity.h"
#include<vector>
#include"globalFile.h"
#include<fstream>
#include"computerRoom.h"
#include"order.h"
#include<Windows.h>

class Student :public Identity
{
public:
	int m_id;
	//��������
	vector<ComputerRoom> vC;

	//Ĭ�Ϲ���
	Student();
	//�вι���(���,����������)
	Student(int id, string name, string password);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�ҵ�ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
};