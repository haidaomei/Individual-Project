#pragma once
#include<string>
#include"Enum.h"
using namespace std;
class StudentProperties
{
private:
	//����
	int StudentNumber;
	string StudentName;
	Age StudentAge;
	bool StudentGender;
	EnrollmentYear StudentEnrollmentYear;
	//����
public:
	//��������
	StudentProperties(int StudentNumber, string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear);
	virtual ~StudentProperties() = default;
	//��������
	//Set
	void SetStudentNumber(int StudentNumber);
	void SetName(string Name);
	void SetAge(Age Age);
	void SetGender(bool Gender);
	void SetEnrollmentYear(EnrollmentYear EnrollmentYear);
	//Set
	//Get
	int GetStudentNumber()const;
	string GetName()const;
	Age GetAge()const;
	bool GetGender()const;
	EnrollmentYear GetEnrollmentYear()const;
	//Get
private:
	//����
	virtual void function()const;//���������Ҫ��Ϊ�˼���dynamiccast,����������Ļ��޷�ʹ��ָ���������
	//����
};