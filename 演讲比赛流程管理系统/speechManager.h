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
	//比赛的轮数
	int m_index;

	//第一轮成员编号
	vector<int> v1;
	//第二轮成员编号
	vector<int> v2;
	//第三轮成员编号
	vector<int> v3;

	//存放编号以及对应选手的容器
	map<int, Speaker> m;

	//存放往届记录的容器
	map<int,vector<string>> m_Record;

	//记录文件是否为空
	bool fileIsEmpty;

	//构造函数
	SpeechManager();

	//初始化容器
	void initSpeech();

	//创建选手
	void creatSpeaker();
	
	//展示菜单
	void showMenu();

	//开始比赛
	void startSpeech();

	//选手抽签
	void speakerDraw();

	//比赛过程
	void speakContect();

	//显示得分
	void showScore();

	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();

	//显示记录
	void showRecord();

	//退出系统
	void exitSystem();

	//析构函数
	~SpeechManager();
};
