#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>

#define FILENAME "worker.txt"

using namespace std;

class WorkManager
{
public:
	//��¼��ǰԱ������
	int m_empnum;
	//ְ�������ָ��
	Worker** m_emparr;
	//�ж��ļ��Ƿ�Ϊ��
	bool isFileEmpty = true;

	WorkManager();
	
	~WorkManager();

	//չʾ�˵�
	void showMenu();
	//�˳�ϵͳ
	void exitSystem();
	//����ְ����Ϣ
	void addEmployee();
	//�����ļ�
	void save();
	//ͳ���ļ��м�¼������
	int get_num();
	//��ʼ��Ա��
	void initEmployee();
	//��ʾְ����Ϣ
	void showEmployee();
	//��ѯְ���Ƿ����
	int fineEmployee(int id);
	//ɾ����ְְ��
	void delEmployee();
	//�޸�ְ����Ϣ
	void modEmpoyee();
	//����ְ����Ϣ
	void searchEmployee();
	//���ձ������
	void sortEmployee();
	//��������ĵ�
	void cleanFile();
};