#include"MasterManage.h"
#include"Enum.h"
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
void MasterManage::AddStudent()
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
	Temp6 = StudentManage::Input(0, 1, "类型(0:专业硕士,2:学术硕士):");
	//
	StudentProperties* temp = new MasterProperties(Temp1, Temp2, Temp3, Temp4, Temp5, Temp6);
	StudentArray.push_back(temp);
	cout << "学生已添加!" << endl;
}
void MasterManage::DeleteStudent()
{
	int StudentNumber = StudentManage::Input2("请输入学号:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Master) {return Master->GetStudentNumber() == StudentNumber; });
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
void MasterManage::ChangeInformation()
{
	int StudentNumber = StudentManage::Input2("请输入学号:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Master) {return Master->GetStudentNumber() == StudentNumber; });
	if (it != StudentArray.end())
	{
		MasterProperties* temp2 = dynamic_cast<MasterProperties*>(*it);
		int temp1 = StudentManage::Input(1, 12, "请输入选项:(1:姓名,2:年龄,3:性别,4:入学年份,5:研究方向,6:类型)");
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
		else if (temp1 == 5)
		{
			int CastTemp = StudentManage::Input(1, 5, "");
			temp2->SetResearchField(static_cast<ResearchField>(CastTemp));
			cout << "修改完成!" << endl;
		}
		else
		{
			bool temp3 = StudentManage::Input(0, 1, "");
			temp2->SetProfessionalAndAcademic(temp3);
			cout << "修改完成!" << endl;
		}
	}
	else
	{
		cout << "未找到学生!" << endl;
	}
}
void MasterManage::SearchStudent()
{
	int temp1 = StudentManage::Input(1, 5, "请输入选项:(1:姓名,2:年龄,3:性别,4:入学年份,5:研究方向,6:类型)");
	if (temp1 == 1)
	{
		string Name;
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		cout << "请输入姓名:";
		cin >> Name;
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Name](StudentProperties* Master) {return Master->GetName() == Name; });
		StudentManage::Print(Result, 2);
	}
	else if (temp1 == 2)
	{
		cout << "请输入年龄:";
		int CastTemp = StudentManage::Input(1, 3, "");
		Age TempAge = TempAge = static_cast<Age>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempAge](StudentProperties* Master) {return Master->GetAge() == TempAge; });
		StudentManage::Print(Result, 2);
	}
	else if (temp1 == 3)
	{
		cout << "请输入性别:";
		bool Gender = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Gender](StudentProperties* Master) {return Master->GetGender() == Gender; });
		StudentManage::Print(Result, 2);
	}
	else if (temp1 == 4)
	{
		cout << "请输入入学年份:";
		int CastTemp = StudentManage::Input(1, 5, "");
		EnrollmentYear TempEnrollmentYear = static_cast<EnrollmentYear>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempEnrollmentYear](StudentProperties* Master) {return Master->GetEnrollmentYear() == TempEnrollmentYear; });
		StudentManage::Print(Result, 2);
	}
	else if (temp1 == 5)
	{
		cout << "请输入研究方向:";
		int CastTemp = StudentManage::Input(1, 5, "");
		ResearchField TempResearchField = static_cast<ResearchField>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempResearchField](StudentProperties* Master) {MasterProperties* Student = dynamic_cast<MasterProperties*>(Master); return Student && (Student->GetEnrollmentYear() == TempResearchField); });
		StudentManage::Print(Result, 2);
	}
	else
	{
		cout << "请输入类型:";
		bool TempProfessionalAndAcademic = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempProfessionalAndAcademic](StudentProperties* Master) {MasterProperties* Student = dynamic_cast<MasterProperties*>(Master); return Student && (Student->GetProfessionalAndAcademic() == TempProfessionalAndAcademic); });
		StudentManage::Print(Result, 2);
	}
}
void MasterManage::ShowAllStudent()
{
	for (StudentProperties* Master : StudentArray)
	{
		MasterProperties* temp = dynamic_cast<MasterProperties*>(Master);
		if (temp != nullptr && temp->GetSpecificIdentification()[1] == 1)//经过控制变量法的调试,发现确实是要加nullptr的,还要放前面,否则确实会有运行时错误,这个错误别人不调试估计很难发现
		{
			cout << *temp;
		}
	}
}