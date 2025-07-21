#include"StudentManage.h"
#include"BachelorManage.h"
#include"MasterManage.h"
#include"DoctorManage.h"
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
extern int StudentNumberCountingSymbol;
vector<StudentProperties*> StudentManage::StudentArray;
void StudentManage::AddStudent()//������������д,��Ϊ�����ܹ��������������ʼ�����������������ʼ�� �ѵ�˵?????
{
	int temp1 = StudentManage::Input(1, 2, "������ѡ��:(1:������,2:˶����)");
	if (temp1 == 1)
	{
		BachelorManage temp;
		temp.AddStudent();
	}
	else
	{
		MasterAndDoctorManage temp;
		temp.AddStudent();
	}
}//������������
void StudentManage::DeleteStudent()//����Ͳ��������߼���������,��Ϊ�����߼�ֻ��һ��������ѧ�� ��������������дɶ
{
	int temp1 = StudentManage::Input(1, 2, "������ѡ��:(1:������,2:˶����)");
	if (temp1 == 1)
	{
		BachelorManage temp;
		temp.DeleteStudent();
	}
	else
	{
		MasterAndDoctorManage temp;
		temp.DeleteStudent();
	}
}//������������
void StudentManage::ChangeInformation()//������԰ڹ����߼���?�����޸�Ҫ��׼��λ ������׼��λ��ֻ��ѧ�� �������Ҳ����(��deleteһ��)
{
	int temp1 = StudentManage::Input(1, 2, "������ѡ��:(1:������,2:˶����)");
	if (temp1 == 1)
	{
		BachelorManage temp;
		temp.ChangeInformation();
	}
	else
	{
		MasterAndDoctorManage temp;
		temp.ChangeInformation();
	}
}//������������
void StudentManage::SearchStudent()//���ﵹ�ǿ��Խ������߼�������,��Ϊ���໹������������д��
{//�������lambda���ʽǶ�׵Ļ�,���ܷ�װ���๦��?���Ǻ���copyif�ᱨ��,������ͦ���Ե���
	int temp1 = StudentManage::Input(1, 7, "������ѡ��:(1:ѧ��,2:����,3:����,4:�Ա�,5:��ѧ���,6:������,7:˶����)");
	if (temp1 == 1)
	{
		int StudentNumber = StudentManage::Input2("������ѧ��:");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&StudentNumber](StudentProperties* Student) {return Student->GetStudentNumber() == StudentNumber; });
		StudentManage::Print(Result, 5);
	}
	else if (temp1 == 2)
	{
		string Name;
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		cout << "����������:";
		cin >> Name;
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Name](StudentProperties* Student) {return Student->GetName() == Name; });
		StudentManage::Print(Result, 5);
	}
	else if (temp1 == 3)
	{
		cout << "����������:";
		int CastTemp = StudentManage::Input(1, 3, "");
		Age TempAge = TempAge = static_cast<Age>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempAge](StudentProperties* Student) {return Student->GetAge() == TempAge; });
		StudentManage::Print(Result, 5);
	}
	else if (temp1 == 4)
	{
		cout << "�������Ա�:";
		bool Gender = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Gender](StudentProperties* Student) {return Student->GetGender() == Gender; });
		StudentManage::Print(Result, 5);
	}
	else if (temp1 == 5)
	{
		cout << "��������ѧ���:";
		int CastTemp = StudentManage::Input(1, 5, "");
		EnrollmentYear TempEnrollmentYear = static_cast<EnrollmentYear>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempEnrollmentYear](StudentProperties* Student) {return Student->GetEnrollmentYear() == TempEnrollmentYear; });
		StudentManage::Print(Result, 5);
	}
	else if (temp1 == 6)//������result.size�Ǹ�������?????print�ǻ���������Χ�����Բ���size��
	{
		BachelorManage temp;
		temp.SearchStudent();
	}
	else
	{
		MasterAndDoctorManage temp;
		temp.SearchStudent();
	}
}//������������
void StudentManage::ShowAllStudent()
{//���������
	int temp1 = StudentManage::Input(1, 5, "������ѡ��:(1:������,2:˶ʿ��,3:��ʿ��,4:˶����,5:ȫ��ѧ��)");
	if (temp1 == 1)
	{
		BachelorManage temp;
		temp.ShowAllStudent();
	}
	else if (temp1 == 2)
	{
		MasterManage temp;
		temp.ShowAllStudent();
	}
	else if (temp1 == 3)
	{
		DoctorManage temp;
		temp.ShowAllStudent();
	}
	else if (temp1 == 4)
	{
		MasterAndDoctorManage temp;
		temp.ShowAllStudent();
	}
	else
	{
		BachelorManage temp2;
		temp2.ShowAllStudent();
		MasterManage temp3;
		temp3.ShowAllStudent();
		DoctorManage temp4;
		temp4.ShowAllStudent();
	}
}

//�����ͷ���
void StudentManage::Print(vector<StudentProperties*>& Result, int temp)
{
	int temp4 = 0;
	if (temp == 1)
	{
		for (StudentProperties* Student : Result)
		{
			BachelorProperties* temp1 = dynamic_cast<BachelorProperties*>(Student);
			if (temp1 != nullptr)
			{
				temp4 = 1;
				cout << *temp1;
			}
		}
	}
	else if (temp == 2)
	{
		for (StudentProperties* Student : Result)
		{
			MasterProperties* temp1 = dynamic_cast<MasterProperties*>(Student);
			if (temp1 != nullptr)
			{
				temp4 = 1;
				cout << *temp1;
			}
		}
	}
	else if (temp == 3)
	{
		for (StudentProperties* Student : Result)
		{
			DoctorProperties* temp1 = dynamic_cast<DoctorProperties*>(Student);
			if (temp1 != nullptr)
			{
				temp4 = 1;
				cout << *temp1;
			}
		}
	}//����֮ǰ����һ���߼�����,����������ֵ�ʱ�������������1,���Ǳ�˶������һ����1����,�������˻�ȫ�����������������Result��(��bachelormanage��searchstudent�߼�)
	else if (temp == 4)
	{
		for (StudentProperties* Student : Result)
		{
			MasterProperties* temp1 = dynamic_cast<MasterProperties*>(Student);
			DoctorProperties* temp2 = dynamic_cast<DoctorProperties*>(Student);
			if (temp1 != nullptr)
			{
				temp4 = 1;
				cout << *temp1;
			}
			if (temp2 != nullptr)
			{
				temp4 = 1;
				cout << *temp2;
			}
		}
	}
	else
	{
		for (StudentProperties* Student : Result)
		{
			BachelorProperties* temp1 = dynamic_cast<BachelorProperties*>(Student);
			MasterProperties* temp2 = dynamic_cast<MasterProperties*>(Student);
			DoctorProperties* temp3 = dynamic_cast<DoctorProperties*>(Student);
			if (temp1 != nullptr)
			{
				temp4 = 1;
				cout << *temp1;
			}
			if (temp2 != nullptr)
			{
				temp4 = 1;
				cout << *temp2;
			}
			if (temp3 != nullptr)
			{
				temp4 = 1;
				cout << *temp3;
			}
		}

	}
	if (!temp4)//������ȥ�������߼�,��Ҫ��һ��tempָ�����ʲô�׶ε�ѧ��
	{
		cout << "δ�ҵ�ѧ��!" << endl;
	}
}
int StudentManage::Input(int Min, int Max, string Sentence)//��������ж���������������,���ֱ���Ҫ��temp1��ʼ��Ϊ0
{
	int temp1 = 0;
	while (true)
	{
		cout << Sentence;
		if (!(cin >> temp1) || temp1 < Min || temp1 > Max)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "��ʽ����,����������!" << endl;
			continue;
		}
		break;
	}
	return temp1;
}
double StudentManage::Input2(string Sentence)//����bachelormanage�ĳɼ�����,���Ա���С��,Ҳ����delete��change��ѧ������,�������С����������ȥβ
{
	double value;
	while (true)
	{
		cout << Sentence;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "��ʽ����,����������!" << endl;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
	}
}//ģ��StudentManage����һ��,���ר�Ÿ�����ɼ��õ�,�ж�������������,����������������������������뿪ͷΪ���ֵ�(��ʱ��ȡ��ͷȫ������),���ڴ������ж��Ƚϸ���,���ﲻд
void StudentManage::SaveData(string filename)
{
	ofstream out(filename);
	if (out)
	{
		out << StudentArray.size() << endl;
		out << StudentNumberCountingSymbol << endl;
		for (auto student : StudentArray)
		{
			int type = -1;//ȷ��ѧ������
			if (dynamic_cast<BachelorProperties*>(student))
			{
				type = 0;
			}
			else if (dynamic_cast<MasterProperties*>(student))
			{
				type = 1;
			}
			else if (dynamic_cast<DoctorProperties*>(student))
			{
				type = 2;
			}
			out << type << endl;
			out << student->GetStudentNumber() << endl;
			out << student->GetName() << endl;
			out << static_cast<int>(student->GetAge()) << endl;
			out << student->GetGender() << endl;
			out << static_cast<int>(student->GetEnrollmentYear()) << endl;
			if (type == 0)
			{
				BachelorProperties* bachelor = dynamic_cast<BachelorProperties*>(student);
				out << static_cast<int>(bachelor->GetMajor()) << endl;
				out << static_cast<int>(bachelor->GetClass()) << endl;
				out << bachelor->GetPracticeCondition() << endl;
				auto scores = bachelor->GetCoreCurriculumScore();
				for (double score : scores)
				{
					out << score << endl;
				}
			}
			else if (type == 1)
			{
				MasterProperties* master = dynamic_cast<MasterProperties*>(student);
				out << static_cast<int>(master->GetResearchField()) << endl;
				out << master->GetProfessionalAndAcademic() << endl;
			}
			else if (type == 2)
			{
				DoctorProperties* doctor = dynamic_cast<DoctorProperties*>(student);
				out << static_cast<int>(doctor->GetResearchField()) << endl;
				out << doctor->GetTeaching() << endl;
			}
		}
		out.close();
		cout << "д�ļ�" << filename << "���!" << endl;
	}
}
void StudentManage::ReadData(string filename)
{
	ifstream in(filename);
	if (in)
	{
		size_t size;
		in >> size;
		int nextId;
		in >> nextId;
		StudentNumberCountingSymbol = nextId;
		for (auto student : StudentArray)
		{
			delete student;
		}
		StudentArray.clear();
		for (size_t i = 0; i < size; ++i)
		{
			int type;
			in >> type;
			int studentNumber;
			string name;
			int ageInt, enrollmentYearInt;
			bool gender;
			in >> studentNumber;
			in.ignore();
			getline(in, name);
			in >> ageInt;
			in >> gender;
			in >> enrollmentYearInt;
			Age age = static_cast<Age>(ageInt);
			EnrollmentYear enrollmentYear = static_cast<EnrollmentYear>(enrollmentYearInt);
			StudentProperties* student = nullptr;
			if (type == 0)
			{
				int majorInt, classInt;
				bool practiceCondition;
				vector<double> scores(5);
				in >> majorInt;
				in >> classInt;
				in >> practiceCondition;
				for (int j = 0; j < 5; ++j)
				{
					in >> scores[j];
				}
				Major major = static_cast<Major>(majorInt);
				Class studentClass = static_cast<Class>(classInt);
				student = new BachelorProperties(name, age, gender, enrollmentYear, major, studentClass, practiceCondition, scores[0], scores[1], scores[2], scores[3], scores[4]);
			}
			else if (type == 1)
			{
				int researchFieldInt;
				bool professionalAndAcademic;
				in >> researchFieldInt;
				in >> professionalAndAcademic;
				ResearchField researchField = static_cast<ResearchField>(researchFieldInt);
				student = new MasterProperties(name, age, gender, enrollmentYear, researchField, professionalAndAcademic);
			}
			else if (type == 2)
			{
				int researchFieldInt;
				bool teaching;
				in >> researchFieldInt;
				in >> teaching;
				ResearchField researchField = static_cast<ResearchField>(researchFieldInt);
				student = new DoctorProperties(name, age, gender, enrollmentYear,
					researchField, teaching);
			}
			if (student)
			{
				student->SetStudentNumber(studentNumber);
				StudentArray.push_back(student);
			}
		}
		in.close();
		cout << "���ļ�" << filename << "���!" << endl;
	}
}