#include"BachelorProperties.h"
#include<string>
using namespace std;
extern int StudentNumberCountingSymbol;
BachelorProperties::BachelorProperties(string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear, Major Major, Class Class, bool PracticeCondition, double Score1, double Score2, double Score3, double Score4, double Score5) :StudentProperties(StudentNumberCountingSymbol, Name, Age, Gender, EnrollmentYear), StudentMajor(Major), StudentClass(Class), StudentPracticeCondition(PracticeCondition)
{
	StudentCoreCurriculumScore[0] = Score1;
	StudentCoreCurriculumScore[1] = Score2;
	StudentCoreCurriculumScore[2] = Score3;
	StudentCoreCurriculumScore[3] = Score4;
	StudentCoreCurriculumScore[4] = Score5;
}
void BachelorProperties::SetMajor(Major Major)
{
	StudentMajor = Major;
}
void BachelorProperties::SetClass(Class Class)
{
	StudentClass = Class;
}
void BachelorProperties::SetCoreCurriculumScore1(double CoreCurriculumScore1)//set只能一个个set
{
	StudentCoreCurriculumScore[0] = CoreCurriculumScore1;
}
void BachelorProperties::SetCoreCurriculumScore2(double CoreCurriculumScore2)
{
	StudentCoreCurriculumScore[1] = CoreCurriculumScore2;
}
void BachelorProperties::SetCoreCurriculumScore3(double CoreCurriculumScore3)
{
	StudentCoreCurriculumScore[2] = CoreCurriculumScore3;
}
void BachelorProperties::SetCoreCurriculumScore4(double CoreCurriculumScore4)
{
	StudentCoreCurriculumScore[3] = CoreCurriculumScore4;
}
void BachelorProperties::SetCoreCurriculumScore5(double CoreCurriculumScore5)
{
	StudentCoreCurriculumScore[4] = CoreCurriculumScore5;
}
void BachelorProperties::SetPracticeCondition(bool PracticeCondition)
{
	StudentPracticeCondition = PracticeCondition;
}
Major BachelorProperties::GetMajor()const
{
	return StudentMajor;
}
Class BachelorProperties::GetClass()const
{
	return StudentClass;
}
vector<double> BachelorProperties::GetCoreCurriculumScore()const
{
	return StudentCoreCurriculumScore;
}
bool BachelorProperties::GetPracticeCondition()const
{
	return StudentPracticeCondition;
}
ostream& operator<<(ostream& out, const BachelorProperties& Bachelor)
{
	out << "学号:" << Bachelor.GetStudentNumber() << endl;
	out << "姓名:" << Bachelor.GetName() << endl;
	out << "年龄;" << AgeToString(Bachelor.GetAge()) << endl;
	out << "性别:" << Bachelor.GetGender() << endl;//默认输出1和0没问题
	out << "入学年份:" << EnrollmentYearToString(Bachelor.GetEnrollmentYear()) << endl;
	out << "专业:" << MajorToString(Bachelor.GetMajor()) << endl;
	out << "班级:" << ClassToString(Bachelor.GetClass()) << endl;
	out << "实习状态:" << Bachelor.StudentPracticeCondition << endl;
	out << "C++程序设计成绩" << ":" << Bachelor.GetCoreCurriculumScore()[0] << endl;
	out << "离散数学成绩" << ":" << Bachelor.GetCoreCurriculumScore()[1] << endl;
	out << "数据结构成绩" << ":" << Bachelor.GetCoreCurriculumScore()[2] << endl;
	out << "计算机组成原理成绩" << ":" << Bachelor.GetCoreCurriculumScore()[3] << endl;
	out << "操作系统成绩" << ":" << Bachelor.GetCoreCurriculumScore()[4] << endl;
	return out;
}
vector<bool> BachelorProperties::GetSpecificIdentification()const
{
	return StudentSpecificIdentification;
}