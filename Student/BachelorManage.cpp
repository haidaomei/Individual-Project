#include"BachelorManage.h"
#include"BachelorProperties.h"
#include"Enum.h"
#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
#include<string>
#include"StudentManage.h"
using namespace std;
void BachelorManage::AddStudent()
{
	string Temp1;
	Age Temp2;
	bool Temp3;
	EnrollmentYear Temp4;
	Major Temp5;
	Class Temp6;
	double Temp7, Temp8, Temp9, Temp10, Temp11;
	bool Temp12;
	cout << "������ѧ����Ϣ:" << endl;
	//
	cout << "����:";
	cin >> Temp1;
	//
	int CastTemp1=StudentManage::Input(0,2, "����(0:18��,1:19��,2:20��):");
	Temp2 = static_cast<Age>(CastTemp1);
	//
	Temp3 = StudentManage::Input(0, 1, "�Ա�(0:Ů,1:��): ");
	//
	int CastTemp2 = StudentManage::Input(0, 4, "��ѧ���(0:��һ��,1:�ڶ���,2:������,3:������,4:������):");
	Temp4 = static_cast<EnrollmentYear>(CastTemp2);
	//
	int CastTemp3 = StudentManage::Input(0, 4, "רҵ(0:�������ѧ,1:�������,2:���繤��,3:���簲ȫ,4:����������):");
	Temp5 = static_cast<Major>(CastTemp3);
	//
	int CastTemp4=StudentManage::Input(0,4, "�༶(0:01��,1:02��,2:03��,3:04��,4:05��):");
	Temp6 = static_cast<Class>(CastTemp4);
	//
	Temp7 = StudentManage::Input(0, 1, "ʵϰ״̬(0:δʵϰ,1:��ʵϰ):");
	//
	Temp8 = StudentManage::Input2("C++������Ƴɼ�:");
	Temp9 = StudentManage::Input2("��ɢ��ѧ�ɼ�:");
	Temp10 = StudentManage::Input2("���ݽṹ�ɼ�:");
	Temp11 = StudentManage::Input2("��������ԭ��ɼ�:");
	Temp12 = StudentManage::Input2("����ϵͳ�ɼ�:");
	//
	StudentProperties* temp = new BachelorProperties(Temp1, Temp2, Temp3, Temp4, Temp5, Temp6, Temp7, Temp8, Temp9, Temp10, Temp11, Temp12);
	StudentArray.push_back(temp);
	cout << "ѧ�������!" << endl;
}
void BachelorManage::DeleteStudent()
{
	int StudentNumber=StudentManage::Input2("������ѧ��:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Bachelor) {return Bachelor->GetStudentNumber() == StudentNumber; });
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
void BachelorManage::ChangeInformation()
{
	int StudentNumber = StudentManage::Input2("������ѧ��:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Bachelor) {return Bachelor->GetStudentNumber() == StudentNumber; });
	if (it != StudentArray.end())
	{
		BachelorProperties* temp2 = dynamic_cast<BachelorProperties*>(*it);//ǿ��ת���ȽϷ���,����������һ����ʵ�����ݵ�function
		int temp1 = StudentManage::Input(1, 12, "������ѡ��:(1:����,2:����,3:�Ա�,4:��ѧ���,5:רҵ,6:�༶,7:ʵϰ״̬,8:C++������Ƴɼ�,9:��ɢ��ѧ�ɼ�,10:���ݽṹ�ɼ�,11:��������ԭ��ɼ�,12:����ϵͳ�ɼ�)");
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
			temp2->SetMajor(static_cast<Major>(CastTemp));
			cout << "�޸����!" << endl;
		}
		else if (temp1 == 6)
		{
			int CastTemp = StudentManage::Input(1, 5, "");
			temp2->SetClass(static_cast<Class>(CastTemp));
			cout << "�޸����!" << endl;
		}
		else if (temp1 == 7)
		{
			bool temp3 = StudentManage::Input(0, 1, "");
			temp2->SetPracticeCondition(temp3);
			cout << "�޸����!" << endl;
		}
		else if (temp1 == 8)
		{
			double temp3 = StudentManage::Input2("");
			temp2->SetCoreCurriculumScore1(temp3);
			cout << "�޸����!" << endl;
		}
		else if (temp1 == 9)
		{
			double temp3 = StudentManage::Input2("");
			temp2->SetCoreCurriculumScore2(temp3);
			cout << "�޸����!" << endl;
		}
		else if (temp1 == 10)
		{
			double temp3 = StudentManage::Input2("");
			temp2->SetCoreCurriculumScore3(temp3);
			cout << "�޸����!" << endl;

		}
		else if (temp1 == 11)
		{
			double temp3 = StudentManage::Input2("");
			temp2->SetCoreCurriculumScore4(temp3);
			cout << "�޸����!" << endl;
		}
		else
		{
			double temp3 = StudentManage::Input2("");
			temp2->SetCoreCurriculumScore5(temp3);
			cout << "�޸����!" << endl;
		}
	}
	else
	{
		cout << "δ�ҵ�ѧ��!" << endl;
	}
}
void BachelorManage::SearchStudent()//���ڿ�ʼ��д��������,�����и���ѧ��,��������,��������,�����Ա�,������ѧ���,����רҵ,���ݰ༶,����ʵϰ״̬
{
	int temp1 = StudentManage::Input(1, 8, "������ѡ��:(1:����,2:����,3:�Ա�,4:��ѧ���,5:רҵ,6:�༶,7:ʵϰ״̬)");
	if (temp1 == 1)//���ڼ����������Եõ��Ľ������Ψһ��,����stl�ͻ��ڷ�Χ�����������ַ���,Ϊʹ���Ƚ������ִ�cppѡ��stl(���ʹ��copyif������ƶ���ǳ���� �ڴ濪��û�����еĴ�)
	{
		string Name;
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());//Ԥ����һ��,ע��reverse����reserve,ͬʱreserve֮����Ȼ�ǿյ�,������ֻ���Ż���
		cout << "����������:";
		cin >> Name;//ע��copyif����algorithm�ﲻ�Ƿ���numeric�ͬʱע��copyif�ĵ�����������������������������
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Name](StudentProperties* Bachelor) {return Bachelor->GetName() == Name; });//���&&��Ŀ���Ǽ��Student�ǲ���nullptr(dynamiccastת��ʧ�ܵ��µ�,�Ͼ��������˶��)
		StudentManage::Print(Result, 1);
	}
	else if (temp1 == 2)
	{
		cout << "����������:";
		int CastTemp = StudentManage::Input(1, 3, "");
		Age TempAge= TempAge = static_cast<Age>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempAge](StudentProperties* Bachelor) {return Bachelor->GetAge() == TempAge; });
		StudentManage::Print(Result, 1);
	}
	else if (temp1 == 3)
	{
		cout << "�������Ա�:";
		bool Gender = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Gender](StudentProperties* Bachelor) {return Bachelor->GetGender() == Gender; });
		StudentManage::Print(Result, 1);
	}
	else if (temp1 == 4)
	{
		cout << "��������ѧ���:";
		int CastTemp = StudentManage::Input(1, 5, "");
		EnrollmentYear TempEnrollmentYear = static_cast<EnrollmentYear>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempEnrollmentYear](StudentProperties* Bachelor) {return Bachelor->GetEnrollmentYear() == TempEnrollmentYear; });
		StudentManage::Print(Result, 1);
	}
	else if (temp1 == 5)
	{
		cout << "������רҵ:";
		int CastTemp = StudentManage::Input(1, 5, "");
		Major TempMajor = static_cast<Major>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempMajor](StudentProperties* Bachelor) {BachelorProperties* Student = dynamic_cast<BachelorProperties*>(Bachelor); return Student && (Student->GetMajor() == TempMajor); });
		StudentManage::Print(Result, 1);
	}
	else if (temp1 == 6)
	{
		cout << "������༶:";
		int CastTemp=StudentManage::Input(1,5,"");
		Class TempClass = static_cast<Class>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempClass](StudentProperties* Bachelor) {BachelorProperties* Student = dynamic_cast<BachelorProperties*>(Bachelor); return Student && (Student->GetClass() == TempClass); });
		StudentManage::Print(Result, 1);
	}
	else
	{
		cout << "������ʵϰ״̬:";
		bool PracticeCondition = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&PracticeCondition](StudentProperties* Bachelor) {BachelorProperties* Student = dynamic_cast<BachelorProperties*>(Bachelor); return Student && (Student->GetPracticeCondition() == PracticeCondition); });
		StudentManage::Print(Result, 1);
	}
}
void BachelorManage::ShowAllStudent()
{
	for (StudentProperties* Bachelor : StudentArray)
	{
		BachelorProperties* temp = dynamic_cast<BachelorProperties*>(Bachelor);//���ܻ��ʵ�Ϊʲôcast����if����λ��,�����ᵼ��Bachelorû��SpecificIdentification
		if (temp != nullptr && temp->GetSpecificIdentification()[0] == 1)//ע���·��ֵ����(����˵�����ж��������,�󲻳���ֱ�ӽ���),����Ѻ�������ǰ�������tempΪnullptr��ָ���Ա���ܳ�������ʱ����
		{
			cout << *temp;//ͬ��������һ��������
		}
	}
}
void BachelorManage::ScoreSummmary()
{
	int StudentNumber;
	cout << "������ѧ��:";
	cin >> StudentNumber;
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](StudentProperties* Bachelor) {StudentProperties* Student = dynamic_cast<StudentProperties*>(Bachelor); return Student && (Bachelor->GetStudentNumber() == StudentNumber); });
	if (it != StudentArray.end())
	{
		BachelorProperties* temp = dynamic_cast<BachelorProperties*>(*it);
		double Summary = accumulate(temp->GetCoreCurriculumScore().begin(), temp->GetCoreCurriculumScore().end(), 0);
		cout << "�ܳɼ�:" << Summary << endl;
	}
	else
	{
		cout << "δ�ҵ�ѧ��!" << endl;
	}
}
void BachelorManage::AverageScore()
{
	unsigned int temp1;
	cout << "�������Ŀ:";
	cin >> temp1;
	double temp2 = 0;
	int temp3 = 0;
	for (StudentProperties* Bachelor : StudentArray)
	{
		BachelorProperties* temp = dynamic_cast<BachelorProperties*>(Bachelor);
		if (temp != nullptr && temp->GetSpecificIdentification()[0] == 1)//ȷ���Ǳ���
		{
			temp2 = temp2 + temp->GetCoreCurriculumScore()[temp1 - 1];
			temp3 = temp3 + 1;
		}
	}
	cout << "ƽ���ɼ�Ϊ:" << temp2 / temp3 << endl;
}