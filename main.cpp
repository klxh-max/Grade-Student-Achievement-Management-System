#include<bits/stdc++.h>
using namespace std;

#include "Subject.h"
#include "Student.h"
#include "ClassSystem.h"
#include "Interface.h"
#include "ManagementSystem.h"

Interface interface;
ManagementSystem managementSystem;

int main() {
	int choice, flag = 1;
	while (flag) {
		choice = interface.showMainmap();
		while (choice == 1) {
			int classchoice = 0, judge = 0, studentchoice = 0, Age = 0, choice = 0, tongyong1 = 0;
			string classid, Id, Name, Sex, Phone, studentid, tongyong;
			double tongyong2 = 0;
			cout << "1.查看班级信息\n2.添加班级\n3.删除班级\n4.退出班级模块\n请输入你所想要进行的操作序号，例如1\n";
			cin >> classchoice;
			while (classchoice == 1) {
				cout << "请输入想要查看的班级名！\n";
				cin >> classid;
				judge = managementSystem.IsRepeat(classid);
				if (judge == -1) {
					cout << "该班级不存在，无法查看！\n";
					break;
				}

				else {
					while (true) {
						managementSystem.DisplayClass(judge);
						cout << "请问是否继续对班级进行操作？\n1.添加学生\n2.删除学生\n3.查看某个学生信息\n4.查看班级学生花名册\n5.退出\n请输入你所想要进行的操作序号，例如1\n";
						cin >> studentchoice;
						while (studentchoice == 1) {
							cout << "请依次输入学生的学号、姓名、性别、年龄、电话号码。\n例如2019339964003 小慧 女 20 19858873603\n";
							cin >> Id >> Name >> Sex >> Age >> Phone;
							if (managementSystem.classSystem[judge].IsRepeatS(Id) == -1) {

								managementSystem.classSystem[judge].AddStudent(Id, Name, Sex, Age, Phone);
								managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].GetStudentNumber() - 1].SetClass1(managementSystem.classSystem[judge].GetClassId());//设置学生信息中所在班级这一信息
								cout << "添加完毕！\n";
								break;
							}
							else {
								cout << "请注意：学号是唯一的！该学生已存在，无法添加！\n";
								break;
							}
						}
						while (studentchoice == 2) {
							cout << "请输入想删除的学生的学号，例如2019339964003\n";
							cin >> studentid;
							if (managementSystem.classSystem[judge].IsRepeatS(studentid) == -1) {
								cout << "请注意：学号是唯一的！该学生不存在，无法删除！\n";
								break;
							}
							else {
								managementSystem.classSystem[judge].DeleteStudent(studentid);
								cout << "删除完毕！\n";
								break;
							}
						}
						while (studentchoice == 3) {
							cout << "请输入想查看的学生的学号，例如2019339964003\n";
							cin >> studentid;
							if (managementSystem.classSystem[judge].IsRepeatS(studentid) == -1) {
								cout << "请注意：学号是唯一的！该学生不存在，无法查看！\n";
								break;
							}
							else {
								while (true) {
									managementSystem.classSystem[judge].DisplayS(managementSystem.classSystem[judge].IsRepeatS(studentid));
									cout << "请问是否继续对该学生进行操作？\n1.修改学生姓名\n2.修改学生性别\n3.修改学生年龄\n4.修改学生联系电话\n5.查看学生各项成绩\n6.删除某课程以及成绩\n7.添加某课程以及成绩\n8.修改某课程成绩\n9.退出\n请选择您想进行的操作序号\n";
									cin >> choice;
									if (choice == 1) {
										cout << "请输入要修改的姓名，例如您要修改学生姓名为王二小，请输入王二小\n";
										cin >> tongyong;
										managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].SetName(tongyong);
										cout << "已修改！\n";
									}
									else if (choice == 2) {
										cout << "请输入要修改的性别，例如您要修改学生性别为男，请输入男\n";
										cin >> tongyong;
										managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].SetSex(tongyong);
										cout << "已修改！\n";
									}
									else if (choice == 3) {
										cout << "请输入要修改的年龄，例如您要修改学生年龄为23，请输入23\n";
										cin >> tongyong1;
										managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].SetAge(tongyong1);
										cout << "已修改！\n";
									}
									else if (choice == 4) {
										cout << "请输入要修改的联系电话，例如您要修改学生联系电话为12345，请输入12345\n";
										cin >> tongyong;
										managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].SetPhone(tongyong);
										cout << "已修改！\n";
									}
									else if (choice == 5) {
										if (managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].GetSubjectNum() == 0)
											cout << "该学生课程信息未录入！\n";
										else {
											
											managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].DisplayStudent();
										}
									}
									else if (choice == 6) {
										cout << "请输入要删除的课程名，例如您要删除学生课程名为高数，请输入高数\n";
										cin >> tongyong;
										if (managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].IsRepeatSub(tongyong) == -1)
											cout << "无该课程信息，无法修改！\n";
										else {
											managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].DeleteSubject(tongyong);
											cout << "已删除！\n";
										}
									}
									else if (choice == 7) {
										cout << "请输入要添加的课程名以及分数，例如您要添加学生课程名为高数，分数为100分，请输入高数 100\n";
										cin >> tongyong >> tongyong2;
										if (managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].IsRepeatSub(tongyong) != -1)
											cout << "该课程已存在，无法重新添加！\n";
										else {
											managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].AddSubject(tongyong, tongyong2);
											cout << "已添加！\n";
										}
									}
									else if (choice == 8) {
										cout << "请输入要修改的课程名以及分数，例如您要修改学生高数的成绩为60分，请输入高数 60\n";
										cin >> tongyong >> tongyong2;
										if (managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].IsRepeatSub(tongyong) == -1)
											cout << "该课程不存在，无法修改！\n";
										else {
											managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].subject[managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].IsRepeatSub(tongyong)].SetScore(tongyong2);
											cout << "已添加！\n";
										}
									}
									else if (choice == 9) {
										studentchoice = 9;
										break;
									}

								}
							}
						}
						while (studentchoice == 4) {
							if (managementSystem.classSystem[judge].GetStudentNumber() > -1) {
								for (int k = 0;k <= managementSystem.classSystem[judge].GetStudentNumber();k++)
									managementSystem.classSystem[judge].DisplayS(k);
							}
							else
								cout << "该班级没有学生无法展示花名册！\n";
							break;
						}
						if (studentchoice == 5) {
							classchoice = 9;
							break;
						}

					}
				}
			}
			if (classchoice == 2) {
				cout << "请输入想要添加的班级名！\n";
				cin >> classid;
				if (managementSystem.IsRepeat(classid) != -1)
					cout << "该班级已经存在，无法添加！\n";
				else {
					managementSystem.AddClass(classid);
					cout << "已添加！您可以进行其他操作！\n";
				}
			}
			if (classchoice == 3) {
				cout << "请输入想要删除的班级名！\n";
				cin >> classid;
				if (managementSystem.IsRepeat(classid) == -1)
					cout << "该班级不存在，无法删除！\n";
				else {
					managementSystem.DeleteClass(classid);
					cout << "已删除！您可以进行其他操作！\n";
				}
			}
			if (classchoice == 4)
				break;
		}
		while (choice == 2) {
			cout << "如需进行其他操作请登录进入系统！祝您生活愉快！\n";
			flag = 0;
			break;
		}
	}
	return 0;
}