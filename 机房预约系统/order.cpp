#include"order.h"

//构造函数
Order::Order()
{
	ifstream ifs(ORDER_FILE, ios::in);

	string data;//日期
	string time;//时间段
	string room;//机房号
	string stuid;//学生编号
	string stuname;//学生姓名
	string state;//预约状态

	this->m_size = 0;

	while (ifs >> data && ifs >> time && ifs >> room && ifs >> stuid && ifs >> stuname && ifs >> state)
	{
		string key;
		string value;
		map<string, string> m;
		
		int pos = data.find(':');
		if (pos != -1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = time.find(':');
		if (pos != -1)
		{
			key = time.substr(0, pos);
			value = time.substr(pos + 1, time.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = room.find(':');
		if (pos != -1)
		{
			key = room.substr(0, pos);
			value = room.substr(pos + 1, room.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = stuid.find(':');
		if (pos != -1)
		{
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = stuname.find(':');
		if (pos != -1)
		{
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = state.find(':');
		if (pos != -1)
		{
			key = state.substr(0, pos);
			value = state.substr(pos + 1, state.size() - pos);
			m.insert(make_pair(key, value));
		}

		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
}
//更新预约记录
void Order::updateOrder()
{
	if (this->m_size == 0)
		return;

	ofstream ofs(ORDER_FILE, ios::out || ios::trunc);

	for (int i = 0; i < this->m_size; i++)
	{
		ofs << "data:" << this->m_orderData[i]["data:"] << ' ';
		ofs << "time:" << this->m_orderData[i]["time:"] << ' ';
		ofs << "room:" << this->m_orderData[i]["room:"] << ' ';
		ofs << "stuid:" << this->m_orderData[i]["stuid"] << ' ';
		ofs << "stuname:" << this->m_orderData[i]["stuname:"] << ' ';
		ofs << "state:" << this->m_orderData[i]["state:"] << endl;
	}

	ofs.close();
}
