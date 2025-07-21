#pragma once
#include"Enum.h"
#include"StudentProperties.h"
#include<vector>
#include<iostream>
using namespace std;
class BachelorProperties :public StudentProperties
{
private:
	//属性
	Major StudentMajor;
	Class StudentClass;
	vector<double> StudentCoreCurriculumScore = { 0,0,0,0,0 };
	bool StudentPracticeCondition;
	vector<bool> StudentSpecificIdentification = { 1,0,0 };//特定标识,用于查找
	//属性
public:
	//构造析构
	BachelorProperties(string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear, Major Major, Class Class, bool PracticeCondition, double Score1, double Score2, double Score3, double Score4, double Score5);
	virtual ~BachelorProperties()override = default;
	//构造析构
	//Set
	void SetMajor(Major Major);
	void SetClass(Class Class);
	void SetCoreCurriculumScore1(double CoreCurriculumScore1);
	void SetCoreCurriculumScore2(double CoreCurriculumScore2);
	void SetCoreCurriculumScore3(double CoreCurriculumScore3);
	void SetCoreCurriculumScore4(double CoreCurriculumScore4);
	void SetCoreCurriculumScore5(double CoreCurriculumScore5);
	void SetPracticeCondition(bool PracticeCondition);
	//Set
	//Get
	Major GetMajor()const;
	Class GetClass()const;
	vector<double> GetCoreCurriculumScore()const;
	bool GetPracticeCondition()const;
	vector<bool> GetSpecificIdentification()const;
	//Get
	//重载
	friend ostream &operator<<(ostream &out,const BachelorProperties& Bachelor);//第一个&表示返回ostream类对象引用 第二个&表示引用ostream类对象
	//重载
};