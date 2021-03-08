#pragma once
#ifndef STUDENT
#define STUDENT

#include <bits/stdc++.h>
#include "Subject.h"
using namespace std;
class Student {
private:
	string id, name, sex, phone, class1;//°à¼¶
	int age = 0, subjectNum=0;

public:
	Subject subject[101];

	Student();
	Student(string Id, string Name, string Sex, int Age, string Phone);

	string GetId();
	string GetName();
	string GetSex();
	string GetPhone();
	string GetClass1();
	int GetAge();
	int GetSubjectNum();
	int IsRepeatSub(string a);

	void SetSubjectNum(int );
	void DisplayStudent();
	void SetId(string);
	void SetName(string);
	void SetSex(string);
	void SetPhone(string);
	void SetClass1(string);
	void SetAge(int);
	void DeleteSubject(string a);
	void AddSubject(string a,double b);
};

#endif // !STUDENT


