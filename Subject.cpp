#include "Subject.h"

Subject::Subject() {

}

Subject::Subject(string subjectid, double Score) {
	subjectId = subjectid;
	score = Score;
}

void Subject::SetSubjectId(string a) {
	subjectId = a;
}

void Subject::SetScore(double a) {
	score = a;
}

string Subject::GetSubjectId() {
	return subjectId;
}

double Subject::GetScore() {
	return score;
}
