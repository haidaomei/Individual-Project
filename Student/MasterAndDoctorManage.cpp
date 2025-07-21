#include"MasterAndDoctorManage.h"
#include"MasterManage.h"
#include"DoctorManage.h"
#include<iostream>
#include<algorithm>
using namespace std;
void MasterAndDoctorManage::AddStudent()
{
	int temp1;
	cout << "请输入选项:(1:硕士生,2:博士生)";
	cin >> temp1;
	if (temp1 == 1)
	{
		MasterManage temp;
		temp.AddStudent();
	}
	else if (temp1 == 2)
	{
		DoctorManage temp;
		temp.AddStudent();
	}
	else
	{
		cout << "格式错误,请重新输入!" << endl;
	}
}
void MasterAndDoctorManage::DeleteStudent()
{
	int temp1 = StudentManage::Input(1, 2, "请输入选项:(1:硕士生,2:博士生)");
	if (temp1 == 1)
	{
		MasterManage temp;
		temp.DeleteStudent();
	}
	else
	{
		DoctorManage temp;
		temp.DeleteStudent();
	}
}
void MasterAndDoctorManage::ChangeInformation()
{
	int temp1 = StudentManage::Input(1, 2, "请输入选项:(1:硕士生,2:博士生)");
	if (temp1 == 1)
	{
		MasterManage temp;
		temp.ChangeInformation();
	}
	else
	{
		DoctorManage temp;
		temp.ChangeInformation();
	}
}
void MasterAndDoctorManage::SearchStudent()
{
	int temp1 = StudentManage::Input(1, 7, "请输入选项:(1:姓名,2:年龄,3:性别,4:入学年份,5:研究方向,6:硕士生,7:博士生)");
	if (temp1 == 1)//这里就连名字都考虑可能重复
	{
		string Name;
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		cout << "请输入姓名:";
		cin >> Name;//注意copyif放在algorithm里不是放在numeric里，同时注意copyif的第三个参数不是容器是容器迭代器
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Name](StudentProperties* MasterAndDoctor) {return MasterAndDoctor->GetName() == Name; });
		StudentManage::Print(Result, 4);
	}
	else if (temp1 == 2)
	{
		cout << "请输入年龄:";
		int CastTemp = StudentManage::Input(1, 3, "");
		Age TempAge = TempAge = static_cast<Age>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempAge](StudentProperties* MasterAndDoctor) {return MasterAndDoctor->GetAge() == TempAge; });
		StudentManage::Print(Result, 4);
	}
	else if (temp1 == 3)
	{
		cout << "请输入性别:";
		bool Gender = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Gender](StudentProperties* MasterAndDoctor) {return MasterAndDoctor->GetGender() == Gender; });
		StudentManage::Print(Result, 4);
	}
	else if (temp1 == 4)
	{
		cout << "请输入入学年份:";
		int CastTemp = StudentManage::Input(1, 5, "");
		EnrollmentYear TempEnrollmentYear = static_cast<EnrollmentYear>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempEnrollmentYear](StudentProperties* MasterAndDoctor) {return MasterAndDoctor->GetEnrollmentYear() == TempEnrollmentYear; });
		StudentManage::Print(Result, 4);
	}
	else if (temp1 == 5)
	{
		cout << "请输入研究方向:";
		int CastTemp = StudentManage::Input(1, 5, "");
		ResearchField TempResearchField = static_cast<ResearchField>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempResearchField](StudentProperties* MasterAndDoctor) {MasterAndDoctorProperties* Student = dynamic_cast<MasterAndDoctorProperties*>(MasterAndDoctor); return Student && (Student->GetEnrollmentYear() == TempResearchField); });
		StudentManage::Print(Result, 4);
	}
	else if (temp1 == 6)
	{
		MasterManage temp;
		temp.SearchStudent();
	}
	else
	{
		DoctorManage temp;
		temp.SearchStudent();
	}
}
void MasterAndDoctorManage::ShowAllStudent()
{
	int temp1 = StudentManage::Input(1, 3, "请输入选项:(1:硕士生,2:博士生,3:全体硕博生)");
	if (temp1 == 1)
	{
		MasterManage temp;
		temp.ShowAllStudent();
	}
	else if (temp1 == 2)
	{
		DoctorManage temp;
		temp.ShowAllStudent();
	}
	else
	{
		MasterManage temp2;
		temp2.ShowAllStudent();
		DoctorManage temp3;
		temp3.ShowAllStudent();
	}
}