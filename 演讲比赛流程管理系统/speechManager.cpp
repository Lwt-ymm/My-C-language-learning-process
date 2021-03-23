#include"speechManager.h"
#include<algorithm>

SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->creatSpeaker();
	this->loadRecord();
}

void  SpeechManager::initSpeech()
{
	this->m_index = 1;

	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m.clear();
	this->m_Record.clear();
}

void SpeechManager::creatSpeaker()
{
	string nameSpeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSpeed.size(); i++)
	{
		Speaker p;
		p.m_name = "选手";
		p.m_name += nameSpeed[i];
		
		for (int j = 0; j < 2; j++)
		{
			p.m_score[j] = 0;
		}

		this->v1.push_back(i + 10001);

		this->m.insert(make_pair(i + 10001, p));
	}
}

void SpeechManager::showMenu()
{
	cout << "**********************************" << endl;
	cout << "******** 欢迎参加演讲比赛 ********" << endl;
	cout << "********* 1.开始演讲比赛 *********" << endl;
	cout << "********* 2.查看往届记录 *********" << endl;
	cout << "********* 3.清空比赛记录 *********" << endl;
	cout << "********* 0.退出管理系统 *********" << endl;
	cout << "**********************************" << endl;
}

void SpeechManager::startSpeech()
{
	//第一轮比赛
	//抽签  比赛  显示晋级结果
	this->speakerDraw();
	this->speakContect();
	this->showScore();
	//第二轮比赛
	//抽签  比赛  显示最终结果 
	this->m_index++;

	this->speakerDraw();
	this->speakContect();
	this->showScore();
	//保存记录
	this->saveRecord();
	cout << "本届比赛结束" << endl;
	system("pause");
	system("cls");

	this->initSpeech();
	this->creatSpeaker();
	this->loadRecord();
}

void  SpeechManager::speakerDraw()
{
	cout << "第<<" << this->m_index << ">>轮抽签结果，演讲顺序如下：" << endl;
	cout << "-------------------------------------" << endl;
	if (this->m_index == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << ' ';
		}
	}
	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << ' ';
		}
	}
	cout << endl;
	cout << "-------------------------------------" << endl;
	system("pause");
}

void SpeechManager::speakContect()
{
	cout << "第<<" << this->m_index << ">>轮比赛开始：" << endl;
	cout << endl;

	multimap<double, int, greater<double>> groupScore;
	int num = 0;

	vector<int> v;
	if (this->m_index == 1)
	{
		v = this->v1;
	}
	else
	{
		v = this->v2;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		num++;
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (double)(rand() % 401 + 600) / 10;
			//cout << score << ' ';
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_back();
		d.pop_front();
		double sum = accumulate(d.begin(), d.end(), 0);
		double avg = sum / (double)d.size();

		this->m[*it].m_score[this->m_index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));

		if (num % 6 == 0)
		{
			cout << "第<<" << num / 6 << ">>组比赛结果为：" << endl;
			for (multimap<double, int>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << it->second << ' ' << this->m[it->second].m_name << ' ' << it->first << endl;
			}

			int count = 0;
			for (multimap<double, int>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					v3.push_back(it->second);
				}
			}

			groupScore.clear();
			cout << endl;
		}
	}
	cout << "第<<" << this->m_index << ">>轮比赛完成：" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "第<<" << this->m_index << ">>轮晋级选手如下：" << endl;
	vector<int> v;
	if (this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = v3;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ' << this->m[*it].m_name << ' ' << this->m[*it].m_score[this->m_index - 1] <<endl;
	}
	system("pause");
	system("cls");
	this->showMenu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << ',' << this->m[*it].m_name << ',' << this->m[*it].m_score[1] << ',';
	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;

	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	char ch = 0;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		cout << "文件为空" << endl;
		return;
	}

	fileIsEmpty = false;

	ifs.putback(ch);
	vector<string> v;
	string data;
	int index = 0;
	while (ifs >> data)
	{
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(',', start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

void  SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届" << endl <<
			"冠军： " << "编号：" << this->m_Record[i][0] << ' ' << "姓名：" << this->m_Record[i][1] << ' ' << "得分：" << this->m_Record[i][2] << ' ' <<
			"亚军： " << "编号：" << this->m_Record[i][3] << ' ' << "姓名：" << this->m_Record[i][4] << ' ' << "得分：" << this->m_Record[i][5] << ' ' <<
			"季军： " << "编号：" << this->m_Record[i][6] << ' ' << "姓名：" << this->m_Record[i][7] << ' ' << "得分：" << this->m_Record[i][8] << endl;
	}

	system("pause");
	system("cls");
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用。" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{

}