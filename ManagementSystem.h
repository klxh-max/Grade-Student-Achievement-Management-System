#pragma once
#ifndef MANAGEMENTSYSTEM
#define MANAGEMENTSYSTEM

#include <bits/stdc++.h>
#include "Subject.h"
#include "Student.h"
#include "ClassSystem.h"
using namespace std;
class ManagementSystem {
private:
	int classNum=0;//°à¼¶ÊýÁ¿

public:
	ClassSystem classSystem[61];

	ManagementSystem();

	int GetClassNum();
	int IsRepeat(string a);
	int ReturnNum(string a);

	void AddClass(string classid);
	void DeleteClass(string a);
	void SetClassNum(int);
	void DisplayClass(int);
};

#endif // !MANAGEMENTSYSTEM

