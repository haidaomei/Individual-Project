#include"MasterAndDoctorManage.h"
#include"MasterManage.h"
#include"DoctorManage.h"
#include<iostream>
#include<algorithm>
using namespace std;
void MasterAndDoctorManage::AddStudent()
{
	int temp1;
	cout << "������ѡ��:(1:˶ʿ��,2:��ʿ��)";
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
		cout << "��ʽ����,����������!" << endl;
	}
}
void MasterAndDoctorManage::DeleteStudent()
{
	int temp1 = StudentManage::Input(1, 2, "������ѡ��:(1:˶ʿ��,2:��ʿ��)");
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
	int temp1 = StudentManage::Input(1, 2, "������ѡ��:(1:˶ʿ��,2:��ʿ��)");
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
	int temp1 = StudentManage::Input(1, 7, "������ѡ��:(1:����,2:����,3:�Ա�,4:��ѧ���,5:�о�����,6:˶ʿ��,7:��ʿ��)");
	if (temp1 == 1)//����������ֶ����ǿ����ظ�
	{
		string Name;
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		cout << "����������:";
		cin >> Name;//ע��copyif����algorithm�ﲻ�Ƿ���numeric�ͬʱע��copyif�ĵ�����������������������������
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Name](StudentProperties* MasterAndDoctor) {return MasterAndDoctor->GetName() == Name; });
		StudentManage::Print(Result, 4);
	}
	else if (temp1 == 2)
	{
		cout << "����������:";
		int CastTemp = StudentManage::Input(1, 3, "");
		Age TempAge = TempAge = static_cast<Age>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempAge](StudentProperties* MasterAndDoctor) {return MasterAndDoctor->GetAge() == TempAge; });
		StudentManage::Print(Result, 4);
	}
	else if (temp1 == 3)
	{
		cout << "�������Ա�:";
		bool Gender = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Gender](StudentProperties* MasterAndDoctor) {return MasterAndDoctor->GetGender() == Gender; });
		StudentManage::Print(Result, 4);
	}
	else if (temp1 == 4)
	{
		cout << "��������ѧ���:";
		int CastTemp = StudentManage::Input(1, 5, "");
		EnrollmentYear TempEnrollmentYear = static_cast<EnrollmentYear>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempEnrollmentYear](StudentProperties* MasterAndDoctor) {return MasterAndDoctor->GetEnrollmentYear() == TempEnrollmentYear; });
		StudentManage::Print(Result, 4);
	}
	else if (temp1 == 5)
	{
		cout << "�������о�����:";
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
	int temp1 = StudentManage::Input(1, 3, "������ѡ��:(1:˶ʿ��,2:��ʿ��,3:ȫ��˶����)");
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