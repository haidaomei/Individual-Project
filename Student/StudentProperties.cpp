#include"StudentProperties.h"
#include<vector>
using namespace std;
int StudentNumberCountingSymbol = 0;//������������,һ���ǳ�ʼ��Ϊ1Ȼ�����++�������Ȱ�1������һ��ѧ��,��һ��ѧ����ʼ����ʱ��������2������һ��ѧ��;�ڶ��������ڵķ���,��0++�ٵ�һ�θ�ֵ;�Ƚ�ϸ�ڵ���,���ǵ�ǰ��++����Ч�ʴ��ں���++,���Բ������ַ���
StudentProperties::StudentProperties(int StudentNumber, string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear) :StudentNumber(++StudentNumberCountingSymbol), StudentName(Name), StudentAge(Age), StudentGender(Gender), StudentEnrollmentYear(EnrollmentYear)
{
}
void StudentProperties::SetStudentNumber(int StudentNumber)
{
	this->StudentNumber = StudentNumber;
}
void StudentProperties::SetName(string Name)
{
	StudentName = Name;
}
void StudentProperties::SetAge(Age Age)
{
	StudentAge = Age;
}
void StudentProperties::SetGender(bool Gender)
{
	StudentGender = Gender;
}
void StudentProperties::SetEnrollmentYear(EnrollmentYear EnrollmentYear)
{
	StudentEnrollmentYear = EnrollmentYear;
}
int StudentProperties::GetStudentNumber()const
{
	return StudentNumber;
}
string StudentProperties::GetName()const
{
	return StudentName;
}
Age StudentProperties::GetAge()const
{
	return StudentAge;
}
bool StudentProperties::GetGender()const
{
	return StudentAge;
}
EnrollmentYear StudentProperties::GetEnrollmentYear()const
{
	return StudentEnrollmentYear;
}
void StudentProperties::function()const
{
}