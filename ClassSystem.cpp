#include "ClassSystem.h"


ClassSystem::ClassSystem() {

}

ClassSystem::ClassSystem(string classid) {
	classId = classid;
}

int ClassSystem::GetStudentNumber() {
	return studentNumber;
}

int ClassSystem::IsRepeatS(string a) {
	for (int i = 0;i < 60;i++) {
		if (student[i].GetId() == a)
			if (i <= GetStudentNumber())
			return i;
	}
	return -1;
}

string ClassSystem::GetClassId() {
	return classId;
}

void ClassSystem::SetStudentNumber(int a) {
	studentNumber = a;
}

void ClassSystem::DisplayS(int a) {
	cout << student[a].GetClass1() << "学生" << student[a].GetName() << ",学号为" <<
		student[a].GetId() << "，性别" << student[a].GetSex() << "，年龄" <<
		student[a].GetAge() << "岁，联系电话为" << student[a].GetPhone() << endl;
}

void ClassSystem::SetClassId(string a) {
	classId = a;
}

void ClassSystem::AddStudent(string Id, string Name, string Sex, int Age, string Phone) {
	studentNumber++;
	student[studentNumber] = Student(Id, Name, Sex, Age, Phone);
	student[studentNumber].SetClass1(GetClassId());
}

void ClassSystem::DeleteStudent(string a) {
	for (int i = 0;i < 60;i++) {
		if (student[i].GetId() == a) {
			for (int j = i;j < studentNumber;j++)
				student[i] = student[i + 1];
		}
	}
	studentNumber--;
}
