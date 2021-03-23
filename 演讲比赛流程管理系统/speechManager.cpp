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
		p.m_name = "ѡ��";
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
	cout << "******** ��ӭ�μ��ݽ����� ********" << endl;
	cout << "********* 1.��ʼ�ݽ����� *********" << endl;
	cout << "********* 2.�鿴�����¼ *********" << endl;
	cout << "********* 3.��ձ�����¼ *********" << endl;
	cout << "********* 0.�˳�����ϵͳ *********" << endl;
	cout << "**********************************" << endl;
}

void SpeechManager::startSpeech()
{
	//��һ�ֱ���
	//��ǩ  ����  ��ʾ�������
	this->speakerDraw();
	this->speakContect();
	this->showScore();
	//�ڶ��ֱ���
	//��ǩ  ����  ��ʾ���ս�� 
	this->m_index++;

	this->speakerDraw();
	this->speakContect();
	this->showScore();
	//�����¼
	this->saveRecord();
	cout << "�����������" << endl;
	system("pause");
	system("cls");

	this->initSpeech();
	this->creatSpeaker();
	this->loadRecord();
}

void  SpeechManager::speakerDraw()
{
	cout << "��<<" << this->m_index << ">>�ֳ�ǩ������ݽ�˳�����£�" << endl;
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
	cout << "��<<" << this->m_index << ">>�ֱ�����ʼ��" << endl;
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
			cout << "��<<" << num / 6 << ">>��������Ϊ��" << endl;
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
	cout << "��<<" << this->m_index << ">>�ֱ�����ɣ�" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "��<<" << this->m_index << ">>�ֽ���ѡ�����£�" << endl;
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
	cout << "��¼�Ѿ�����" << endl;

	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	char ch = 0;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		cout << "�ļ�Ϊ��" << endl;
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
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "��" << endl <<
			"�ھ��� " << "��ţ�" << this->m_Record[i][0] << ' ' << "������" << this->m_Record[i][1] << ' ' << "�÷֣�" << this->m_Record[i][2] << ' ' <<
			"�Ǿ��� " << "��ţ�" << this->m_Record[i][3] << ' ' << "������" << this->m_Record[i][4] << ' ' << "�÷֣�" << this->m_Record[i][5] << ' ' <<
			"������ " << "��ţ�" << this->m_Record[i][6] << ' ' << "������" << this->m_Record[i][7] << ' ' << "�÷֣�" << this->m_Record[i][8] << endl;
	}

	system("pause");
	system("cls");
}

void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�á�" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{

}