#include"teacher.h"

//默认构造
Teacher::Teacher()
{

}
//有参构造(编号,姓名，密码)
Teacher::Teacher(int id, string name, string password)
{
	this->m_id = id;
	this->m_name;
	this->m_password = password;
}
//菜单界面
void Teacher::operMenu()
{
	cout << "=============欢迎教师" << this->m_name << "登录=============" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          1.查看预约          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          2.审核预约          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          0.注销登录          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "请选择您的操作：" << endl;
}
//查看预约
void Teacher::showAllOrder()
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
//审核预约
void Teacher::validOrder()
{
	cout << "待审核的申请如下：" << endl;
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
		if (od.m_orderData[i]["state"] == "1" )
		{
			v.push_back(i);
			cout << index++ << "、";

			cout << "预约日期：周" << od.m_orderData[i]["data"] << ' ';
			cout << "时段：" << (od.m_orderData[i]["time"] == "1" ? "上午" : "下午") << ' ';
			cout << "机房：" << od.m_orderData[i]["room"] << ' ';
			string state = "状态：";//0：取消预约 1：预约审核中 2：预约成功 3：预约失败
		if (od.m_orderData[i]["state"] == "1")
		{
			state += "预约审核中";
		}
			cout << state << endl;
		}
	}
	cout << "请输入要操作的申请，输入0返回。" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
				break;
			else
			{
				cout << "请输入审核结果：" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					od.m_orderData[v[select] - 1]["state"] == "2";
				}
				else
				{
					od.m_orderData[v[select] - 1]["state"] == "-1";
				}
				od.updateOrder();
				cout << "预约审核成功。" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入：" << endl;
	}

	system("pause");
	system("cls");
}