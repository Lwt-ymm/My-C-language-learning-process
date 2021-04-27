#pragma once
#include"identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include"globalFile.h"
#include<fstream>
#include<algorithm>

class Manager :public Identity
{
public:
	//ѧ������
	vector<Student> vS;
	//��ʦ����
	vector<Teacher> vT;
	//��������
	vector<ComputerRoom> vC;

	//Ĭ�Ϲ���
	Manager();
	//�вι���(����������)
	Manager(string name, string password);
	//�˵�����
	virtual void operMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();
	//��ʼ������
	void initVector();
	//����ظ�
	bool checkRepeat(int id, int type);
};