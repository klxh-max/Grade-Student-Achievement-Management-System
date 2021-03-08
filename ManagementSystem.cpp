#include "ManagementSystem.h"

ManagementSystem::ManagementSystem() {

}

int ManagementSystem::GetClassNum() {
	return classNum;
}

int ManagementSystem::IsRepeat(string a) {
	
	for (int i = 0;i < 60;i++) {
		if (classSystem[i].GetClassId() == a) {
			if(i<=GetClassNum() )
				return i;
		}
	}
	return -1;
}

void ManagementSystem::DisplayClass(int i) {
	cout << classSystem[i].GetClassId() << "，班级学生总人数为" << classSystem[i].GetStudentNumber()+1 << "人\n";
}

void ManagementSystem::SetClassNum(int a) {
	classNum = a;
}

void ManagementSystem::AddClass(string classid) {
	classNum++;
	classSystem[classNum] = ClassSystem(classid);
}
void ManagementSystem::DeleteClass(string a) {
	for (int i = 0;i < 60;i++) {
		if (classSystem[i].GetClassId() == a) {
			for (int j = i;j < classNum;j++)
				classSystem[i] = classSystem[i + 1];
			break;
		}
	}
	classNum--;
}