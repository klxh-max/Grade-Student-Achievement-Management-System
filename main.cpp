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
			cout << "1.�鿴�༶��Ϣ\n2.��Ӱ༶\n3.ɾ���༶\n4.�˳��༶ģ��\n������������Ҫ���еĲ�����ţ�����1\n";
			cin >> classchoice;
			while (classchoice == 1) {
				cout << "��������Ҫ�鿴�İ༶����\n";
				cin >> classid;
				judge = managementSystem.IsRepeat(classid);
				if (judge == -1) {
					cout << "�ð༶�����ڣ��޷��鿴��\n";
					break;
				}

				else {
					while (true) {
						managementSystem.DisplayClass(judge);
						cout << "�����Ƿ�����԰༶���в�����\n1.���ѧ��\n2.ɾ��ѧ��\n3.�鿴ĳ��ѧ����Ϣ\n4.�鿴�༶ѧ��������\n5.�˳�\n������������Ҫ���еĲ�����ţ�����1\n";
						cin >> studentchoice;
						while (studentchoice == 1) {
							cout << "����������ѧ����ѧ�š��������Ա����䡢�绰���롣\n����2019339964003 С�� Ů 20 19858873603\n";
							cin >> Id >> Name >> Sex >> Age >> Phone;
							if (managementSystem.classSystem[judge].IsRepeatS(Id) == -1) {

								managementSystem.classSystem[judge].AddStudent(Id, Name, Sex, Age, Phone);
								managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].GetStudentNumber() - 1].SetClass1(managementSystem.classSystem[judge].GetClassId());//����ѧ����Ϣ�����ڰ༶��һ��Ϣ
								cout << "�����ϣ�\n";
								break;
							}
							else {
								cout << "��ע�⣺ѧ����Ψһ�ģ���ѧ���Ѵ��ڣ��޷���ӣ�\n";
								break;
							}
						}
						while (studentchoice == 2) {
							cout << "��������ɾ����ѧ����ѧ�ţ�����2019339964003\n";
							cin >> studentid;
							if (managementSystem.classSystem[judge].IsRepeatS(studentid) == -1) {
								cout << "��ע�⣺ѧ����Ψһ�ģ���ѧ�������ڣ��޷�ɾ����\n";
								break;
							}
							else {
								managementSystem.classSystem[judge].DeleteStudent(studentid);
								cout << "ɾ����ϣ�\n";
								break;
							}
						}
						while (studentchoice == 3) {
							cout << "��������鿴��ѧ����ѧ�ţ�����2019339964003\n";
							cin >> studentid;
							if (managementSystem.classSystem[judge].IsRepeatS(studentid) == -1) {
								cout << "��ע�⣺ѧ����Ψһ�ģ���ѧ�������ڣ��޷��鿴��\n";
								break;
							}
							else {
								while (true) {
									managementSystem.classSystem[judge].DisplayS(managementSystem.classSystem[judge].IsRepeatS(studentid));
									cout << "�����Ƿ�����Ը�ѧ�����в�����\n1.�޸�ѧ������\n2.�޸�ѧ���Ա�\n3.�޸�ѧ������\n4.�޸�ѧ����ϵ�绰\n5.�鿴ѧ������ɼ�\n6.ɾ��ĳ�γ��Լ��ɼ�\n7.���ĳ�γ��Լ��ɼ�\n8.�޸�ĳ�γ̳ɼ�\n9.�˳�\n��ѡ��������еĲ������\n";
									cin >> choice;
									if (choice == 1) {
										cout << "������Ҫ�޸ĵ�������������Ҫ�޸�ѧ������Ϊ����С������������С\n";
										cin >> tongyong;
										managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].SetName(tongyong);
										cout << "���޸ģ�\n";
									}
									else if (choice == 2) {
										cout << "������Ҫ�޸ĵ��Ա�������Ҫ�޸�ѧ���Ա�Ϊ�У���������\n";
										cin >> tongyong;
										managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].SetSex(tongyong);
										cout << "���޸ģ�\n";
									}
									else if (choice == 3) {
										cout << "������Ҫ�޸ĵ����䣬������Ҫ�޸�ѧ������Ϊ23��������23\n";
										cin >> tongyong1;
										managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].SetAge(tongyong1);
										cout << "���޸ģ�\n";
									}
									else if (choice == 4) {
										cout << "������Ҫ�޸ĵ���ϵ�绰��������Ҫ�޸�ѧ����ϵ�绰Ϊ12345��������12345\n";
										cin >> tongyong;
										managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].SetPhone(tongyong);
										cout << "���޸ģ�\n";
									}
									else if (choice == 5) {
										if (managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].GetSubjectNum() == 0)
											cout << "��ѧ���γ���Ϣδ¼�룡\n";
										else {
											
											managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].DisplayStudent();
										}
									}
									else if (choice == 6) {
										cout << "������Ҫɾ���Ŀγ�����������Ҫɾ��ѧ���γ���Ϊ���������������\n";
										cin >> tongyong;
										if (managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].IsRepeatSub(tongyong) == -1)
											cout << "�޸ÿγ���Ϣ���޷��޸ģ�\n";
										else {
											managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].DeleteSubject(tongyong);
											cout << "��ɾ����\n";
										}
									}
									else if (choice == 7) {
										cout << "������Ҫ��ӵĿγ����Լ�������������Ҫ���ѧ���γ���Ϊ����������Ϊ100�֣���������� 100\n";
										cin >> tongyong >> tongyong2;
										if (managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].IsRepeatSub(tongyong) != -1)
											cout << "�ÿγ��Ѵ��ڣ��޷�������ӣ�\n";
										else {
											managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].AddSubject(tongyong, tongyong2);
											cout << "����ӣ�\n";
										}
									}
									else if (choice == 8) {
										cout << "������Ҫ�޸ĵĿγ����Լ�������������Ҫ�޸�ѧ�������ĳɼ�Ϊ60�֣���������� 60\n";
										cin >> tongyong >> tongyong2;
										if (managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].IsRepeatSub(tongyong) == -1)
											cout << "�ÿγ̲����ڣ��޷��޸ģ�\n";
										else {
											managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].subject[managementSystem.classSystem[judge].student[managementSystem.classSystem[judge].IsRepeatS(studentid)].IsRepeatSub(tongyong)].SetScore(tongyong2);
											cout << "����ӣ�\n";
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
								cout << "�ð༶û��ѧ���޷�չʾ�����ᣡ\n";
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
				cout << "��������Ҫ��ӵİ༶����\n";
				cin >> classid;
				if (managementSystem.IsRepeat(classid) != -1)
					cout << "�ð༶�Ѿ����ڣ��޷���ӣ�\n";
				else {
					managementSystem.AddClass(classid);
					cout << "����ӣ������Խ�������������\n";
				}
			}
			if (classchoice == 3) {
				cout << "��������Ҫɾ���İ༶����\n";
				cin >> classid;
				if (managementSystem.IsRepeat(classid) == -1)
					cout << "�ð༶�����ڣ��޷�ɾ����\n";
				else {
					managementSystem.DeleteClass(classid);
					cout << "��ɾ���������Խ�������������\n";
				}
			}
			if (classchoice == 4)
				break;
		}
		while (choice == 2) {
			cout << "������������������¼����ϵͳ��ף��������죡\n";
			flag = 0;
			break;
		}
	}
	return 0;
}