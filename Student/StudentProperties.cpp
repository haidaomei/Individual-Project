#include"StudentProperties.h"
#include<vector>
using namespace std;
int StudentNumberCountingSymbol = 0;//这里两个方案,一个是初始化为1然后后置++那样是先把1赋给第一个学生,第一个学生初始化的时候这个变成2赋给下一个学生;第二个是现在的方案,将0++再第一次赋值;比较细节的是,考虑到前置++运行效率大于后置++,所以采用这种方案
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