#include "Interface.h"

int Interface::showMainmap() {
	for (int i = 0;i < 60;i++)
		cout << "#";
	cout << endl;
	for (int i = 0;i < 60;i++) {
		if (i == 0 || i == 59)
			cout << "#";
		else
			cout << " ";
	}
	cout << endl;
	cout << "#\t\t欢迎进入年级学生成绩管理系统";
	for (int i = 0;i < 15;i++)
		cout << " ";
	cout << "#";
	cout << endl;
	for (int i = 0;i < 60;i++) {
		if (i == 0 || i == 59)
			cout << "#";
		else
			cout << " ";
	}
	cout << endl;
	for (int i = 0;i < 60;i++)
		cout << "#";
	cout << endl << endl;

	cout << "1.进入系统" << endl  << "2.退出系统\n";

	int choice;
	cout << "请输入要选择的选项序号\n";
	cin >> choice;
	return choice;
}