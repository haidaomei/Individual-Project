#include"DoctorManage.h"
#include"Enum.h"
#include<string>
#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;
void DoctorManage::AddStudent()
{
	string Temp1;
	Age Temp2;
	bool Temp3;
	EnrollmentYear Temp4;
	ResearchField Temp5;
	bool Temp6;
	cout << "请输入学生信息:" << endl;
	//
	cout << "姓名:";
	cin >> Temp1;
	//
	int CastTemp1 = StudentManage::Input(0, 2, "年龄(0:18岁,1:19岁,2:20岁):");
	Temp2 = static_cast<Age>(CastTemp1);
	//
	Temp3 = StudentManage::Input(0, 1, "性别(0:女,1:男): ");
	//
	int CastTemp2 = StudentManage::Input(0, 4, "入学年份(0:第一年,1:第二年,2:第三年,3:第四年,4:第五年):");
	Temp4 = static_cast<EnrollmentYear>(CastTemp2);
	//
	int CastTemp3 = StudentManage::Input(0, 4, "研究方向(0:人工智能,1:嵌入式,2:计算机图形学,3:物联网,4:网络安全):");
	Temp5 = static_cast<ResearchField>(CastTemp3);
	//
	Temp6 = StudentManage::Input(0, 1, "是否参与教学(0:否,1:是):");
	//
	StudentProperties* temp = new DoctorProperties(Temp1, Temp2, Temp3, Temp4, Temp5, Temp6);
	StudentArray.push_back(temp);
	cout << "学生已添加!" << endl;
}
void DoctorManage::DeleteStudent()
{
	int StudentNumber = StudentManage::Input2("请输入学号:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Doctor) {return Doctor->GetStudentNumber() == StudentNumber; });
	if (it != StudentArray.end())
	{
		StudentArray.erase(it);
		cout << "删除完成!" << endl;
	}
	else
	{
		cout << "未找到学生!" << endl;
	}
}
void DoctorManage::ChangeInformation()
{
	int StudentNumber = StudentManage::Input2("请输入学号:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Doctor) {return Doctor->GetStudentNumber() == StudentNumber; });
	if (it != StudentArray.end())
	{
		DoctorProperties* temp2 = dynamic_cast<DoctorProperties*>(*it);
		int temp1 = StudentManage::Input(1, 6, "请输入选项:(1:姓名,2:年龄,3:性别,4:入学年份,5:研究方向,6:是否参与教学)");
		if (temp1 == 1)
		{
			string temp3;
			cin >> temp3;
			temp2->SetName(temp3);
			cout << "修改完成!" << endl;
		}
		else if (temp1 == 2)
		{
			int CastTemp = StudentManage::Input(1, 3, "");
			temp2->SetAge(static_cast<Age>(CastTemp));
			cout << "修改完成!" << endl;
		}
		else if (temp1 == 3)
		{
			bool temp3 = StudentManage::Input(0, 1, "");
			temp2->SetGender(temp3);
			cout << "修改完成!" << endl;
		}
		else if (temp1 == 4)
		{
			int CastTemp = StudentManage::Input(1, 5, "");
			temp2->SetEnrollmentYear(static_cast<EnrollmentYear>(CastTemp));
			cout << "修改完成!" << endl;
		}
		else if(temp1==5)
		{
			int CastTemp = StudentManage::Input(1, 5, "");
			temp2->SetResearchField(static_cast<ResearchField>(CastTemp));
			cout << "修改完成!" << endl;
		}
		else
		{
			bool temp3 = StudentManage::Input(0, 1, "");
			temp2->SetTeaching(temp3);
			cout << "修改完成!" << endl;
		}
	}
	else
	{
		cout << "未找到学生!" << endl;
	}
}
void DoctorManage::SearchStudent()
{
	int temp1 = StudentManage::Input(1, 6, "请输入选项:(1:姓名,2:年龄,3:性别,4:入学年份,5:研究方向,6:是否参与教学)");
	if (temp1 == 1)
	{
		string Name;
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		cout << "请输入姓名:";
		cin >> Name;
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Name](StudentProperties* Doctor) {return Doctor->GetName() == Name; });
		StudentManage::Print(Result, 3);
	}
	else if (temp1 == 2)
	{
		cout << "请输入年龄:";
		int CastTemp = StudentManage::Input(1, 3, "");
		Age TempAge = TempAge = static_cast<Age>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempAge](StudentProperties* Doctor) {return Doctor->GetAge() == TempAge; });
		StudentManage::Print(Result, 3);
	}
	else if (temp1 == 3)
	{
		cout << "请输入性别:";
		bool Gender = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Gender](StudentProperties* Doctor) {return Doctor->GetGender() == Gender; });
		StudentManage::Print(Result, 3);
	}
	else if (temp1 == 4)
	{
		cout << "请输入入学年份:";
		int CastTemp = StudentManage::Input(1, 5, "");
		EnrollmentYear TempEnrollmentYear = static_cast<EnrollmentYear>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempEnrollmentYear](StudentProperties* Doctor) {return Doctor->GetEnrollmentYear() == TempEnrollmentYear; });
		StudentManage::Print(Result, 3);
	}
	else if (temp1 == 5)
	{
		cout << "请输入研究方向:";
		int CastTemp = StudentManage::Input(1, 5, "");
		ResearchField TempResearchField = static_cast<ResearchField>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempResearchField](StudentProperties* Doctor) {DoctorProperties* Student = dynamic_cast<DoctorProperties*>(Doctor); return Student && (Student->GetEnrollmentYear() == TempResearchField); });
		StudentManage::Print(Result, 3);
	}
	else
	{
		cout << "请输入是否参与教学:";
		bool TempTeaching = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempTeaching](StudentProperties* Doctor) {DoctorProperties* Student = dynamic_cast<DoctorProperties*>(Doctor); return Student && (Student->GetTeaching() == TempTeaching); });
		StudentManage::Print(Result, 3);
	}
}
void DoctorManage::ShowAllStudent()
{
	for (StudentProperties* Doctor : StudentArray)
	{
		DoctorProperties* temp = dynamic_cast<DoctorProperties*>(Doctor);
		if (temp != nullptr && temp->GetSpecificIdentification()[2] == 1)
		{
			cout << *temp;
		}
	}
}