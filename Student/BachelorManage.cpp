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
	cout << "请输入学生信息:" << endl;
	//
	cout << "姓名:";
	cin >> Temp1;
	//
	int CastTemp1=StudentManage::Input(0,2, "年龄(0:18岁,1:19岁,2:20岁):");
	Temp2 = static_cast<Age>(CastTemp1);
	//
	Temp3 = StudentManage::Input(0, 1, "性别(0:女,1:男): ");
	//
	int CastTemp2 = StudentManage::Input(0, 4, "入学年份(0:第一年,1:第二年,2:第三年,3:第四年,4:第五年):");
	Temp4 = static_cast<EnrollmentYear>(CastTemp2);
	//
	int CastTemp3 = StudentManage::Input(0, 4, "专业(0:计算机科学,1:软件工程,2:网络工程,3:网络安全,4:物联网工程):");
	Temp5 = static_cast<Major>(CastTemp3);
	//
	int CastTemp4=StudentManage::Input(0,4, "班级(0:01班,1:02班,2:03班,3:04班,4:05班):");
	Temp6 = static_cast<Class>(CastTemp4);
	//
	Temp7 = StudentManage::Input(0, 1, "实习状态(0:未实习,1:已实习):");
	//
	Temp8 = StudentManage::Input2("C++程序设计成绩:");
	Temp9 = StudentManage::Input2("离散数学成绩:");
	Temp10 = StudentManage::Input2("数据结构成绩:");
	Temp11 = StudentManage::Input2("计算机组成原理成绩:");
	Temp12 = StudentManage::Input2("操作系统成绩:");
	//
	StudentProperties* temp = new BachelorProperties(Temp1, Temp2, Temp3, Temp4, Temp5, Temp6, Temp7, Temp8, Temp9, Temp10, Temp11, Temp12);
	StudentArray.push_back(temp);
	cout << "学生已添加!" << endl;
}
void BachelorManage::DeleteStudent()
{
	int StudentNumber=StudentManage::Input2("请输入学号:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Bachelor) {return Bachelor->GetStudentNumber() == StudentNumber; });
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
void BachelorManage::ChangeInformation()
{
	int StudentNumber = StudentManage::Input2("请输入学号:");
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](const StudentProperties* Bachelor) {return Bachelor->GetStudentNumber() == StudentNumber; });
	if (it != StudentArray.end())
	{
		BachelorProperties* temp2 = dynamic_cast<BachelorProperties*>(*it);//强制转换比较方便,这里声明了一个无实际内容的function
		int temp1 = StudentManage::Input(1, 12, "请输入选项:(1:姓名,2:年龄,3:性别,4:入学年份,5:专业,6:班级,7:实习状态,8:C++程序设计成绩,9:离散数学成绩,10:数据结构成绩,11:计算机组成原理成绩,12:操作系统成绩)");
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
			temp2->SetMajor(static_cast<Major>(CastTemp));
			cout << "修改完成!" << endl;
		}
		else if (temp1 == 6)
		{
			int CastTemp = StudentManage::Input(1, 5, "");
			temp2->SetClass(static_cast<Class>(CastTemp));
			cout << "修改完成!" << endl;
		}
		else if (temp1 == 7)
		{
			bool temp3 = StudentManage::Input(0, 1, "");
			temp2->SetPracticeCondition(temp3);
			cout << "修改完成!" << endl;
		}
		else if (temp1 == 8)
		{
			double temp3 = StudentManage::Input2("");
			temp2->SetCoreCurriculumScore1(temp3);
			cout << "修改完成!" << endl;
		}
		else if (temp1 == 9)
		{
			double temp3 = StudentManage::Input2("");
			temp2->SetCoreCurriculumScore2(temp3);
			cout << "修改完成!" << endl;
		}
		else if (temp1 == 10)
		{
			double temp3 = StudentManage::Input2("");
			temp2->SetCoreCurriculumScore3(temp3);
			cout << "修改完成!" << endl;

		}
		else if (temp1 == 11)
		{
			double temp3 = StudentManage::Input2("");
			temp2->SetCoreCurriculumScore4(temp3);
			cout << "修改完成!" << endl;
		}
		else
		{
			double temp3 = StudentManage::Input2("");
			temp2->SetCoreCurriculumScore5(temp3);
			cout << "修改完成!" << endl;
		}
	}
	else
	{
		cout << "未找到学生!" << endl;
	}
}
void BachelorManage::SearchStudent()//现在开始扩写查找内容,这里有根据学号,根据姓名,根据年龄,根据性别,根据入学年份,根据专业,根据班级,根据实习状态
{
	int temp1 = StudentManage::Input(1, 8, "请输入选项:(1:姓名,2:年龄,3:性别,4:入学年份,5:专业,6:班级,7:实习状态)");
	if (temp1 == 1)//由于检索其他属性得到的结果不是唯一的,考虑stl和基于范围遍历容器两种方案,为使风格比较贴近现代cpp选用stl(如果使用copyif不是深复制而是浅复制 内存开销没想象中的大)
	{
		string Name;
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());//预分配一下,注意reverse不是reserve,同时reserve之后仍然是空的,这玩意只能优化用
		cout << "请输入姓名:";
		cin >> Name;//注意copyif放在algorithm里不是放在numeric里，同时注意copyif的第三个参数不是容器是容器迭代器
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Name](StudentProperties* Bachelor) {return Bachelor->GetName() == Name; });//最后&&的目的是检查Student是不是nullptr(dynamiccast转换失败导致的,毕竟会遍历到硕博)
		StudentManage::Print(Result, 1);
	}
	else if (temp1 == 2)
	{
		cout << "请输入年龄:";
		int CastTemp = StudentManage::Input(1, 3, "");
		Age TempAge= TempAge = static_cast<Age>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempAge](StudentProperties* Bachelor) {return Bachelor->GetAge() == TempAge; });
		StudentManage::Print(Result, 1);
	}
	else if (temp1 == 3)
	{
		cout << "请输入性别:";
		bool Gender = StudentManage::Input(0, 1, "");
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&Gender](StudentProperties* Bachelor) {return Bachelor->GetGender() == Gender; });
		StudentManage::Print(Result, 1);
	}
	else if (temp1 == 4)
	{
		cout << "请输入入学年份:";
		int CastTemp = StudentManage::Input(1, 5, "");
		EnrollmentYear TempEnrollmentYear = static_cast<EnrollmentYear>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempEnrollmentYear](StudentProperties* Bachelor) {return Bachelor->GetEnrollmentYear() == TempEnrollmentYear; });
		StudentManage::Print(Result, 1);
	}
	else if (temp1 == 5)
	{
		cout << "请输入专业:";
		int CastTemp = StudentManage::Input(1, 5, "");
		Major TempMajor = static_cast<Major>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempMajor](StudentProperties* Bachelor) {BachelorProperties* Student = dynamic_cast<BachelorProperties*>(Bachelor); return Student && (Student->GetMajor() == TempMajor); });
		StudentManage::Print(Result, 1);
	}
	else if (temp1 == 6)
	{
		cout << "请输入班级:";
		int CastTemp=StudentManage::Input(1,5,"");
		Class TempClass = static_cast<Class>(CastTemp);
		vector<StudentProperties*> Result;
		Result.resize(StudentArray.size());
		copy_if(StudentArray.begin(), StudentArray.end(), Result.begin(), [&TempClass](StudentProperties* Bachelor) {BachelorProperties* Student = dynamic_cast<BachelorProperties*>(Bachelor); return Student && (Student->GetClass() == TempClass); });
		StudentManage::Print(Result, 1);
	}
	else
	{
		cout << "请输入实习状态:";
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
		BachelorProperties* temp = dynamic_cast<BachelorProperties*>(Bachelor);//可能会问到为什么cast不和if交换位置,那样会导致Bachelor没有SpecificIdentification
		if (temp != nullptr && temp->GetSpecificIdentification()[0] == 1)//注意短路求值特性(简单来说就是判断先左后右,左不成立直接结束),如果把后条件放前面则如果temp为nullptr再指向成员可能出现运行时错误
		{
			cout << *temp;//同样和上面一样解引用
		}
	}
}
void BachelorManage::ScoreSummmary()
{
	int StudentNumber;
	cout << "请输入学号:";
	cin >> StudentNumber;
	auto it = find_if(StudentArray.begin(), StudentArray.end(), [&StudentNumber](StudentProperties* Bachelor) {StudentProperties* Student = dynamic_cast<StudentProperties*>(Bachelor); return Student && (Bachelor->GetStudentNumber() == StudentNumber); });
	if (it != StudentArray.end())
	{
		BachelorProperties* temp = dynamic_cast<BachelorProperties*>(*it);
		double Summary = accumulate(temp->GetCoreCurriculumScore().begin(), temp->GetCoreCurriculumScore().end(), 0);
		cout << "总成绩:" << Summary << endl;
	}
	else
	{
		cout << "未找到学生!" << endl;
	}
}
void BachelorManage::AverageScore()
{
	unsigned int temp1;
	cout << "请输入科目:";
	cin >> temp1;
	double temp2 = 0;
	int temp3 = 0;
	for (StudentProperties* Bachelor : StudentArray)
	{
		BachelorProperties* temp = dynamic_cast<BachelorProperties*>(Bachelor);
		if (temp != nullptr && temp->GetSpecificIdentification()[0] == 1)//确保是本科
		{
			temp2 = temp2 + temp->GetCoreCurriculumScore()[temp1 - 1];
			temp3 = temp3 + 1;
		}
	}
	cout << "平均成绩为:" << temp2 / temp3 << endl;
}