#pragma once
#ifndef SUBJECT
#define SUBJECT

#include <bits/stdc++.h>
using namespace std;
class Subject {
private:
	string subjectId;
	double score = 0;
public:
	Subject();
	Subject(string subjectId, double score);

	string GetSubjectId();
	double GetScore();

	void SetSubjectId(string);
	void SetScore(double);
};

#endif // !SUBJECT

