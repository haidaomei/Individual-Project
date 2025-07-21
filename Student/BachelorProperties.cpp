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
void BachelorProperties::SetCoreCurriculumScore1(double CoreCurriculumScore1)//setֻ��һ����set
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
	out << "ѧ��:" << Bachelor.GetStudentNumber() << endl;
	out << "����:" << Bachelor.GetName() << endl;
	out << "����;" << AgeToString(Bachelor.GetAge()) << endl;
	out << "�Ա�:" << Bachelor.GetGender() << endl;//Ĭ�����1��0û����
	out << "��ѧ���:" << EnrollmentYearToString(Bachelor.GetEnrollmentYear()) << endl;
	out << "רҵ:" << MajorToString(Bachelor.GetMajor()) << endl;
	out << "�༶:" << ClassToString(Bachelor.GetClass()) << endl;
	out << "ʵϰ״̬:" << Bachelor.StudentPracticeCondition << endl;
	out << "C++������Ƴɼ�" << ":" << Bachelor.GetCoreCurriculumScore()[0] << endl;
	out << "��ɢ��ѧ�ɼ�" << ":" << Bachelor.GetCoreCurriculumScore()[1] << endl;
	out << "���ݽṹ�ɼ�" << ":" << Bachelor.GetCoreCurriculumScore()[2] << endl;
	out << "��������ԭ��ɼ�" << ":" << Bachelor.GetCoreCurriculumScore()[3] << endl;
	out << "����ϵͳ�ɼ�" << ":" << Bachelor.GetCoreCurriculumScore()[4] << endl;
	return out;
}
vector<bool> BachelorProperties::GetSpecificIdentification()const
{
	return StudentSpecificIdentification;
}