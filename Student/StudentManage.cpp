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
void StudentManage::AddStudent()//这里必须分离来写,因为不可能公共变量在这里初始化其他变量在子类初始化 难道说?????
{
	int temp1 = StudentManage::Input(1, 2, "请输入选项:(1:本科生,2:硕博生)");
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
}//这个函数已完成
void StudentManage::DeleteStudent()//这里就不将公共逻辑搬上来了,因为公共逻辑只有一个就是找学号 搬上来了我子类写啥
{
	int temp1 = StudentManage::Input(1, 2, "请输入选项:(1:本科生,2:硕博生)");
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
}//这个函数已完成
void StudentManage::ChangeInformation()//这个可以摆公共逻辑吗?由于修改要求精准定位 而被精准定位的只有学号 所以这个也不行(和delete一样)
{
	int temp1 = StudentManage::Input(1, 2, "请输入选项:(1:本科生,2:硕博生)");
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
}//这个函数已完成
void StudentManage::SearchStudent()//这里倒是可以将公共逻辑摆上来,因为子类还是有其它可以写的
{//如果两个lambda表达式嵌套的话,就能封装更多功能?但是好像copyif会报错,这样就挺可以的了
	int temp1 = StudentManage::Input(1, 7, "请输入选项:(1:学号,2:姓名,3:年龄,4:性别,5:入学年份,6:本科生,7:硕博生)");
	if (temp1 == 1)
	{
		int StudentNumber = StudentManage::Input2("请输入学号:");
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
		cout << "请输入姓名:";
		cin >> Name;
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Name](StudentProperties* Student) {return Student->GetName() == Name; });
		StudentManage::Print(Result, 5);
	}
	else if (temp1 == 3)
	{
		cout << "请输入年龄:";
		int CastTemp = StudentManage::Input(1, 3, "");
		Age TempAge = TempAge = static_cast<Age>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempAge](StudentProperties* Student) {return Student->GetAge() == TempAge; });
		StudentManage::Print(Result, 5);
	}
	else if (temp1 == 4)
	{
		cout << "请输入性别:";
		bool Gender = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Gender](StudentProperties* Student) {return Student->GetGender() == Gender; });
		StudentManage::Print(Result, 5);
	}
	else if (temp1 == 5)
	{
		cout << "请输入入学年份:";
		int CastTemp = StudentManage::Input(1, 5, "");
		EnrollmentYear TempEnrollmentYear = static_cast<EnrollmentYear>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempEnrollmentYear](StudentProperties* Student) {return Student->GetEnrollmentYear() == TempEnrollmentYear; });
		StudentManage::Print(Result, 5);
	}
	else if (temp1 == 6)//我输入result.size是干嘛来着?????print是基于容器范围的所以不用size了
	{
		BachelorManage temp;
		temp.SearchStudent();
	}
	else
	{
		MasterAndDoctorManage temp;
		temp.SearchStudent();
	}
}//这个函数已完成
void StudentManage::ShowAllStudent()
{//想添加五种
	int temp1 = StudentManage::Input(1, 5, "请输入选项:(1:本科生,2:硕士生,3:博士生,4:硕博生,5:全体学生)");
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

//整合型方法
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
	}//这里之前存在一个逻辑错误,比如查找名字的时候输入进来的是1,但是本硕博都有一个叫1的人,这三个人会全部被存在输入进来的Result里(见bachelormanage的searchstudent逻辑)
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
	if (!temp4)//现在想去除这种逻辑,就要给一个temp指定输出什么阶段的学生
	{
		cout << "未找到学生!" << endl;
	}
}
int StudentManage::Input(int Min, int Max, string Sentence)//这个输入判定是我搜网上来的,发现必须要把temp1初始化为0
{
	int temp1 = 0;
	while (true)
	{
		cout << Sentence;
		if (!(cin >> temp1) || temp1 < Min || temp1 > Max)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "格式错误,请重新输入!" << endl;
			continue;
		}
		break;
	}
	return temp1;
}
double StudentManage::Input2(string Sentence)//用于bachelormanage的成绩输入,可以保留小数,也用于delete和change的学号输入,如果输入小数那里会进行去尾
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
			cout << "格式错误,请重新输入!" << endl;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
	}
}//模仿StudentManage再来一遍,这个专门给输入成绩用的,判定的是输入数字,不过经测试这个函数还是允许输入开头为数字的(此时读取开头全部数字),由于纯数字判定比较复杂,这里不写
void StudentManage::SaveData(string filename)
{
	ofstream out(filename);
	if (out)
	{
		out << StudentArray.size() << endl;
		out << StudentNumberCountingSymbol << endl;
		for (auto student : StudentArray)
		{
			int type = -1;//确定学生类型
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
		cout << "写文件" << filename << "完成!" << endl;
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
		cout << "读文件" << filename << "完成!" << endl;
	}
}