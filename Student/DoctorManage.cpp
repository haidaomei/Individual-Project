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
	cout << "������ѧ����Ϣ:" << endl;
	//
	cout << "����:";
	cin >> Temp1;
	//
	int CastTemp1 = StudentManage::Input(0, 2, "����(0:18��,1:19��,2:20��):");
	Temp2 = static_cast<Age>(CastTemp1);
	//
	Temp3 = StudentManage::Input(0, 1, "�Ա�(0:Ů,1:��): ");
	//
	int CastTemp2 = StudentManage::Input(0, 4, "��ѧ���(0:��һ��,1:�ڶ���,2:������,3:������,4:������):");
	Temp4 = static_cast<EnrollmentYear>(CastTemp2);
	//
	int CastTemp3 = StudentManage::Input(0, 4, "�о�����(0:�˹�����,1:Ƕ��ʽ,2:�����ͼ��ѧ,3:������,4:���簲ȫ):");
	Temp5 = static_cast<ResearchField>(CastTemp3);
	//
	Temp6 = StudentManage::Input(0, 1, "�Ƿ�����ѧ(0:��,1:��):");
	//
	StudentProperties* temp = new DoctorProperties(Temp1, Temp2, Temp3, Temp4, Temp5, Temp6);
	StudentArray.push_back(temp);
	cout << "ѧ�������!" << endl;
}
void DoctorManage::DeleteStudent()
{
	int StudentNumber = StudentManage::Input2("������ѧ��:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Doctor) {return Doctor->GetStudentNumber() == StudentNumber; });
	if (it != StudentArray.end())
	{
		StudentArray.erase(it);
		cout << "ɾ�����!" << endl;
	}
	else
	{
		cout << "δ�ҵ�ѧ��!" << endl;
	}
}
void DoctorManage::ChangeInformation()
{
	int StudentNumber = StudentManage::Input2("������ѧ��:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Doctor) {return Doctor->GetStudentNumber() == StudentNumber; });
	if (it != StudentArray.end())
	{
		DoctorProperties* temp2 = dynamic_cast<DoctorProperties*>(*it);
		int temp1 = StudentManage::Input(1, 6, "������ѡ��:(1:����,2:����,3:�Ա�,4:��ѧ���,5:�о�����,6:�Ƿ�����ѧ)");
		if (temp1 == 1)
		{
			string temp3;
			cin >> temp3;
			temp2->SetName(temp3);
			cout << "�޸����!" << endl;
		}
		else if (temp1 == 2)
		{
			int CastTemp = StudentManage::Input(1, 3, "");
			temp2->SetAge(static_cast<Age>(CastTemp));
			cout << "�޸����!" << endl;
		}
		else if (temp1 == 3)
		{
			bool temp3 = StudentManage::Input(0, 1, "");
			temp2->SetGender(temp3);
			cout << "�޸����!" << endl;
		}
		else if (temp1 == 4)
		{
			int CastTemp = StudentManage::Input(1, 5, "");
			temp2->SetEnrollmentYear(static_cast<EnrollmentYear>(CastTemp));
			cout << "�޸����!" << endl;
		}
		else if(temp1==5)
		{
			int CastTemp = StudentManage::Input(1, 5, "");
			temp2->SetResearchField(static_cast<ResearchField>(CastTemp));
			cout << "�޸����!" << endl;
		}
		else
		{
			bool temp3 = StudentManage::Input(0, 1, "");
			temp2->SetTeaching(temp3);
			cout << "�޸����!" << endl;
		}
	}
	else
	{
		cout << "δ�ҵ�ѧ��!" << endl;
	}
}
void DoctorManage::SearchStudent()
{
	int temp1 = StudentManage::Input(1, 6, "������ѡ��:(1:����,2:����,3:�Ա�,4:��ѧ���,5:�о�����,6:�Ƿ�����ѧ)");
	if (temp1 == 1)
	{
		string Name;
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		cout << "����������:";
		cin >> Name;
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Name](StudentProperties* Doctor) {return Doctor->GetName() == Name; });
		StudentManage::Print(Result, 3);
	}
	else if (temp1 == 2)
	{
		cout << "����������:";
		int CastTemp = StudentManage::Input(1, 3, "");
		Age TempAge = TempAge = static_cast<Age>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempAge](StudentProperties* Doctor) {return Doctor->GetAge() == TempAge; });
		StudentManage::Print(Result, 3);
	}
	else if (temp1 == 3)
	{
		cout << "�������Ա�:";
		bool Gender = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Gender](StudentProperties* Doctor) {return Doctor->GetGender() == Gender; });
		StudentManage::Print(Result, 3);
	}
	else if (temp1 == 4)
	{
		cout << "��������ѧ���:";
		int CastTemp = StudentManage::Input(1, 5, "");
		EnrollmentYear TempEnrollmentYear = static_cast<EnrollmentYear>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempEnrollmentYear](StudentProperties* Doctor) {return Doctor->GetEnrollmentYear() == TempEnrollmentYear; });
		StudentManage::Print(Result, 3);
	}
	else if (temp1 == 5)
	{
		cout << "�������о�����:";
		int CastTemp = StudentManage::Input(1, 5, "");
		ResearchField TempResearchField = static_cast<ResearchField>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempResearchField](StudentProperties* Doctor) {DoctorProperties* Student = dynamic_cast<DoctorProperties*>(Doctor); return Student && (Student->GetEnrollmentYear() == TempResearchField); });
		StudentManage::Print(Result, 3);
	}
	else
	{
		cout << "�������Ƿ�����ѧ:";
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