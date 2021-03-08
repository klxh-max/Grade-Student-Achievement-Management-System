#pragma once
#ifndef CLASSSYSTEM
#define CLASSSYSTEM

#include <bits/stdc++.h>
#include "Subject.h"
#include "Student.h"
using namespace std;
class ClassSystem {
private:
	string classId;
	int studentNumber=-1;//学生人数

public:
	Student student[61];

	ClassSystem();
	ClassSystem(string classid);

	int GetStudentNumber();
	string GetClassId();
	int IsRepeatS(string a);

	void SetStudentNumber(int);
	void SetClassId(string);
	void AddStudent(string Id, string Name, string Sex, int Age, string Phone);
	void DeleteStudent(string);
	void DisplayS(int a);
};

#endif // !CLASSSYSTEM

