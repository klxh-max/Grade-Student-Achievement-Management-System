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
	cout << "#\t\t��ӭ�����꼶ѧ���ɼ�����ϵͳ";
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

	cout << "1.����ϵͳ" << endl  << "2.�˳�ϵͳ\n";

	int choice;
	cout << "������Ҫѡ���ѡ�����\n";
	cin >> choice;
	return choice;
}