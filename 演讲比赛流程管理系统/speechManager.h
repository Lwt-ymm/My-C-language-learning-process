#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<deque>
#include<numeric>
#include<fstream>

using namespace std;

class SpeechManager
{
public:
	//����������
	int m_index;

	//��һ�ֳ�Ա���
	vector<int> v1;
	//�ڶ��ֳ�Ա���
	vector<int> v2;
	//�����ֳ�Ա���
	vector<int> v3;

	//��ű���Լ���Ӧѡ�ֵ�����
	map<int, Speaker> m;

	//��������¼������
	map<int,vector<string>> m_Record;

	//��¼�ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//���캯��
	SpeechManager();

	//��ʼ������
	void initSpeech();

	//����ѡ��
	void creatSpeaker();
	
	//չʾ�˵�
	void showMenu();

	//��ʼ����
	void startSpeech();

	//ѡ�ֳ�ǩ
	void speakerDraw();

	//��������
	void speakContect();

	//��ʾ�÷�
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//��ʾ��¼
	void showRecord();

	//�˳�ϵͳ
	void exitSystem();

	//��������
	~SpeechManager();
};
