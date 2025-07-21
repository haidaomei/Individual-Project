#pragma once
#include<string>
#include"Enum.h"
using namespace std;
class StudentProperties
{
private:
	//属性
	int StudentNumber;
	string StudentName;
	Age StudentAge;
	bool StudentGender;
	EnrollmentYear StudentEnrollmentYear;
	//属性
public:
	//构造析构
	StudentProperties(int StudentNumber, string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear);
	virtual ~StudentProperties() = default;
	//构造析构
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
	//辅助
	virtual void function()const;//这个函数主要是为了兼容dynamiccast,不存在这个的话无法使用指针输出重载
	//辅助
};