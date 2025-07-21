#pragma once
#include<vector>
#include"StudentProperties.h"
using namespace std;
class StudentManage
{	
public:
	StudentManage() = default;
	virtual ~StudentManage() = default;
	static vector<StudentProperties*> StudentArray;//在AddStudent时append一次
	virtual void AddStudent();
	virtual void DeleteStudent();
	virtual void ChangeInformation();
	virtual void SearchStudent();
	virtual void ShowAllStudent();
	static void Print(vector<StudentProperties*>& Result, int temp);
	static int Input(int Min, int Max, string Sentence);
	static double Input2(string Sentence);
	void SaveData(string filename);
	void ReadData(string filename);
};