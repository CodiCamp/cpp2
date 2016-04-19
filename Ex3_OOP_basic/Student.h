#include <iostream>
#include "string"

using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_

class Student
{
private:
	string studentName_;
	int year_;
	int facNumber_;

public:
	Student::Student();
	
	Student::Student(Student &myStudent);

	Student::Student(string studentName, int year, int facNumber) :
		studentName_(studentName),
		year_(year),
		facNumber_(facNumber)
	{

	}


	Student::~Student();

	void Student::setFacNumber(int facNumber);
	void Student::setYear(int year);
	void Student::setStudName(string stName);

	int Student::getFacNumber();
	int Student::getYear();
	string Student::getStudName();


};


#endif