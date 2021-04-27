#include"student.h"

//默认构造
Student::Student()
{

}
//有参构造(编号，姓名，密码)
Student::Student(int id, string name, string password)
{
	this->m_id = id;
	this->m_name = name;
	this->m_password;

	//获取机房信息
	ifstream ifs;
	ComputerRoom c;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "机房信息文件打开失败" << endl;
	}

	while (ifs >> c.m_id && ifs >> c.m_max)
	{
		vC.push_back(c);
	}
	ifs.close();
}
//菜单界面
void Student::operMenu()
{
	cout << "=============欢迎学生" << this->m_name << "登录=============" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          1.申请预约          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|        2.查看我的预约        |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|        3.查看所有预约        |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          4.取消预约          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          0.注销登录          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "请选择您的操作：" << endl;
}
//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一到周五！" << endl;
	cout << "请选择要预约的日期：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	
	int data = 0;
	int time = 0;
	int room = 0;

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择要预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> time;
		if (time >= 1 && time <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择要预约的机房：" << endl;
	cout << "1号机房容量：" << vC[0].m_max << endl;
	cout << "2号机房容量：" << vC[1].m_max << endl;
	cout << "3号机房容量：" << vC[2].m_max << endl;


	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功，审核中……" << endl;

	ofstream ofs(ORDER_FILE, ios::in);

	ofs << "data:" << data << ' ';
	ofs << "time:" << time << ' ';
	ofs << "room:" << room << ' ';
	ofs << "stuid:" << this->m_id << ' ';
	ofs << "stuname:" << this->m_name << ' ';
	ofs << "state:"<< 1 <<endl;

	ofs.close();
	system("pause");
	system("cls");
}
//查看我的预约
void Student::showMyOrder()
{
	Order od;
	
	if (od.m_size == 0)
	{
		cout << "无预约记录" << endl;
		cout << "pause" << endl;
		cout << "cls" << endl;
		return;
	}
	for (int i = 0; i < od.m_size; i++)
	{
		if (atoi(od.m_orderData[i]["stuid"].c_str()) == this->m_id)//string->char*（.c_str（））->int（atoi）
		{
			cout << "预约日期：周" << od.m_orderData[i]["data"] << ' ';
			cout << "时段：" << (od.m_orderData[i]["time"] == "1" ? "上午" : "下午") << ' ';
			cout << "机房：" << od.m_orderData[i]["room"] << ' ';
			string state = "状态：";//0：取消预约 1：预约审核中 2：预约成功 3：预约失败
			if (od.m_orderData[i]["state"] == "0")
			{
				state += "预约已取消";
			}
			else if (od.m_orderData[i]["state"] == "1")
			{
				state += "预约审核中";
			}
			else if (od.m_orderData[i]["state"] == "2")
			{
				state += "预约成功";
			}
			else if (od.m_orderData[i]["state"] == "-1")
			{
				state += "预约失败";
			}
			cout << state << endl;
		}
	}

	system("pause");
	system("cls");
}
//查看所有预约
void Student::showAllOrder()
{
	Order od;

	if (od.m_size == 0)
	{
		cout << "无预约记录" << endl;
		cout << "pause" << endl;
		cout << "cls" << endl;
		return;
	}
	for (int i = 0; i < od.m_size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << od.m_orderData[i]["data"] << ' ';
		cout << "时段：" << (od.m_orderData[i]["time"] == "1" ? "上午" : "下午") << ' ';
		cout << "机房：" << od.m_orderData[i]["room"] << ' ';
		cout << "学号：" << od.m_orderData[i]["stuid"] << ' ';
		cout << "姓名：" << od.m_orderData[i]["stuname"] << ' ';
		string state = "状态：";//0：取消预约 1：预约审核中 2：预约成功 3：预约失败
		if (od.m_orderData[i]["state"] == "0")
		{
			state += "预约已取消";
		}
		else if (od.m_orderData[i]["state"] == "1")
		{
			state += "预约审核中";
		}
		else if (od.m_orderData[i]["state"] == "2")
		{
			state += "预约成功";
		}
		else if (od.m_orderData[i]["state"] == "-1")
		{
			state += "预约失败";
		}
		cout << state << endl;
	}

	system("pause");
	system("cls");
}
//取消预约
void Student::cancelOrder()
{
	cout << "审核中和预约成功的申请可以删除，" ;
	int index = 1;
	vector<int> v;
	Order od;

	if (od.m_size == 0)
	{
		cout << "无预约记录" << endl;
		cout << "pause" << endl;
		cout << "cls" << endl;
		return;
	}
	for (int i = 0; i < od.m_size; i++)
	{
		if (atoi(od.m_orderData[i]["stuid"].c_str()) == this->m_id)//string->char*（.c_str（））->int（atoi）
		{
			if (od.m_orderData[i]["state"] == "1" || od.m_orderData[i]["state"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";

				cout << "预约日期：周" << od.m_orderData[i]["data"] << ' ';
				cout << "时段：" << (od.m_orderData[i]["time"] == "1" ? "上午" : "下午") << ' ';
				cout << "机房：" << od.m_orderData[i]["room"] << ' ';
				string state = "状态：";//0：取消预约 1：预约审核中 2：预约成功 3：预约失败
				if (od.m_orderData[i]["state"] == "0")
				{
					state += "预约已取消";
				}
				else if (od.m_orderData[i]["state"] == "1")
				{
					state += "预约审核中";
				}
				else if (od.m_orderData[i]["state"] == "2")
				{
					state += "预约成功";
				}
				else if (od.m_orderData[i]["state"] == "-1")
				{
					state += "预约失败";
				}
				cout << state << endl;
			}
		}
	}
	cout << "请输入要删除的预约申请，输入0返回。" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
				break;
			else
			{
				od.m_orderData[v[select] - 1]["state"] == "0";
				od.updateOrder();
				cout << "预约取消成功。" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入：" << endl;
	}

	system("pause");
	system("cls");
}