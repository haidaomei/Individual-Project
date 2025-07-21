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
	Temp6 = StudentManage::Input(0, 1, "����(0:רҵ˶ʿ,2:ѧ��˶ʿ):");
	//
	StudentProperties* temp = new MasterProperties(Temp1, Temp2, Temp3, Temp4, Temp5, Temp6);
	StudentArray.push_back(temp);
	cout << "ѧ�������!" << endl;
}
void MasterManage::DeleteStudent()
{
	int StudentNumber = StudentManage::Input2("������ѧ��:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Master) {return Master->GetStudentNumber() == StudentNumber; });
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
void MasterManage::ChangeInformation()
{
	int StudentNumber = StudentManage::Input2("������ѧ��:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Master) {return Master->GetStudentNumber() == StudentNumber; });
	if (it != StudentArray.end())
	{
		MasterProperties* temp2 = dynamic_cast<MasterProperties*>(*it);
		int temp1 = StudentManage::Input(1, 12, "������ѡ��:(1:����,2:����,3:�Ա�,4:��ѧ���,5:�о�����,6:����)");
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
		else if (temp1 == 5)
		{
			int CastTemp = StudentManage::Input(1, 5, "");
			temp2->SetResearchField(static_cast<ResearchField>(CastTemp));
			cout << "�޸����!" << endl;
		}
		else
		{
			bool temp3 = StudentManage::Input(0, 1, "");
			temp2->SetProfessionalAndAcademic(temp3);
			cout << "�޸����!" << endl;
		}
	}
	else
	{
		cout << "δ�ҵ�ѧ��!" << endl;
	}
}
void MasterManage::SearchStudent()
{
	int temp1 = StudentManage::Input(1, 5, "������ѡ��:(1:����,2:����,3:�Ա�,4:��ѧ���,5:�о�����,6:����)");
	if (temp1 == 1)
	{
		string Name;
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		cout << "����������:";
		cin >> Name;
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Name](StudentProperties* Master) {return Master->GetName() == Name; });
		StudentManage::Print(Result, 2);
	}
	else if (temp1 == 2)
	{
		cout << "����������:";
		int CastTemp = StudentManage::Input(1, 3, "");
		Age TempAge = TempAge = static_cast<Age>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempAge](StudentProperties* Master) {return Master->GetAge() == TempAge; });
		StudentManage::Print(Result, 2);
	}
	else if (temp1 == 3)
	{
		cout << "�������Ա�:";
		bool Gender = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Gender](StudentProperties* Master) {return Master->GetGender() == Gender; });
		StudentManage::Print(Result, 2);
	}
	else if (temp1 == 4)
	{
		cout << "��������ѧ���:";
		int CastTemp = StudentManage::Input(1, 5, "");
		EnrollmentYear TempEnrollmentYear = static_cast<EnrollmentYear>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempEnrollmentYear](StudentProperties* Master) {return Master->GetEnrollmentYear() == TempEnrollmentYear; });
		StudentManage::Print(Result, 2);
	}
	else if (temp1 == 5)
	{
		cout << "�������о�����:";
		int CastTemp = StudentManage::Input(1, 5, "");
		ResearchField TempResearchField = static_cast<ResearchField>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempResearchField](StudentProperties* Master) {MasterProperties* Student = dynamic_cast<MasterProperties*>(Master); return Student && (Student->GetEnrollmentYear() == TempResearchField); });
		StudentManage::Print(Result, 2);
	}
	else
	{
		cout << "����������:";
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
		if (temp != nullptr && temp->GetSpecificIdentification()[1] == 1)//�������Ʊ������ĵ���,����ȷʵ��Ҫ��nullptr��,��Ҫ��ǰ��,����ȷʵ��������ʱ����,���������˲����Թ��ƺ��ѷ���
		{
			cout << *temp;
		}
	}
}