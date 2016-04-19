#include "Student.h"

Student::Student(Student &myStudent)
{
	studentName_ = myStudent.studentName_;
	year_ = myStudent.year_;
	facNumber_ = myStudent.facNumber_;
}


Student::~Student()
{

};

void Student::setFacNumber(int facNumber = 12345567)
{
	facNumber_ = facNumber;
}
void Student::setYear(int year=2017)
{
	year_ = year;
}

void Student::setStudName(string stName = "John Peters")
{
	studentName_ = stName;
}

int Student::getFacNumber()
{
	return facNumber_;
};
int Student::getYear()
{
	return year_;
};
string Student::getStudName()
{
	return studentName_;
}