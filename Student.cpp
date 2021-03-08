#include "Student.h"

Student::Student() {

}

Student::Student(string Id, string Name, string Sex, int Age, string Phone) {
	id = Id;
	name = Name;
	sex = Sex;
	age = Age;
	phone = Phone;
}

string Student::GetId() {
	return id;
}

string Student::GetName() {
	return name;
}

string Student::GetSex() {
	return sex;
}

string Student::GetPhone() {
	return phone;
}

string Student::GetClass1() {
	return class1;
}

int Student::GetAge() {
	return age;
}

int Student::GetSubjectNum() {
	return subjectNum;
}

int Student::IsRepeatSub(string a) {
	for (int i = 0;i < 60;i++) {
		if (subject[i].GetSubjectId() == a) {
			if (i <= GetSubjectNum())
				return i;
		}
	}
	return -1;
}

void Student::DisplayStudent() {
	cout << "学生"<<this->name << "的课程信息如下:\n";
	for (int k = 0;k < GetSubjectNum();k++) {
		cout << subject[k].GetSubjectId() << " " << subject[k].GetScore() << "分"<<endl;
	}
}

void Student::DeleteSubject(string a) {
	for (int i = 0;i < 60;i++) {
		if (subject[i].GetSubjectId() == a) {
			for (int j = i;j < subjectNum;j++)
				subject[i] = subject[i + 1];
		}
	}
	subjectNum--;
}

void Student::AddSubject(string a,double b) {
	subject[subjectNum] = Subject(a,b);
	subjectNum++;
}

void Student::SetId(string a) {
	id = a;
}

void Student::SetName(string a) {
	name = a;
}

void Student::SetSex(string a) {
	sex = a;
}

void Student::SetPhone(string a) {
	phone = a;
}

void Student::SetClass1(string a) {
	class1 = a;
}

void Student::SetAge(int a) {
	age = a;
}

void Student::SetSubjectNum(int a) {
	subjectNum = a;
}
