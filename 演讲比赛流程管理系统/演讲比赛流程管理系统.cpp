#include"speechManager.h"
#include<algorithm>

//class Print
//{
//public:
//	void operator()(pair<int, Speaker> m)
//	{
//		cout << m.first << ' ' << m.second.m_name << ' ' << m.second.m_score[0] << endl;
//	}
//};

int main()
{
	SpeechManager sm;

	//for_each(sm.m.begin(),sm.m.end(), Print());
	
	int choice = 0;
	while (1)
	{
		sm.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.showRecord();
			break;

		case 3:

			break;
		case 0:
			sm.exitSystem();
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}