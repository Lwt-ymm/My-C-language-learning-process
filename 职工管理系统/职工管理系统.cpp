#include"workManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	WorkManager wm;
	
	int choice = 0;
	while (1)
	{
		wm.showMenu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			wm.addEmployee();
			break;
		case 2:
			wm.showEmployee();
			break;
		case 3:
			wm.delEmployee();
			break;
		case 4:
			wm.modEmpoyee();
			break;
		case 5:
			wm.searchEmployee();
			break;
		case 6:
			wm.sortEmployee();
			break;
		case 7:
			wm.cleanFile();
			break;
		case 0:
			wm.exitSystem();
			break;
		default:
			cout << "选择错误,请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}