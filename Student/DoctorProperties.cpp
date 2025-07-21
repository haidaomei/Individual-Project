#include<iostream>
#include"DoctorProperties.h"
using namespace std;
DoctorProperties::DoctorProperties(string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear, ResearchField ResearchField, bool Teaching) :MasterAndDoctorProperties(Name, Age, Gender, EnrollmentYear, ResearchField), StudentTeaching(Teaching)
{
}
bool DoctorProperties::GetTeaching()const
{
	return StudentTeaching;
}
void DoctorProperties::SetTeaching(bool Teaching)
{
	StudentTeaching = Teaching;
}
vector<bool> DoctorProperties::GetSpecificIdentification()const
{
	return StudentSpecificIdentification;
}
ostream& operator<<(ostream& out, const DoctorProperties& Doctor)
{
	out << "学号:" << Doctor.GetStudentNumber() << endl;
	out << "姓名:" << Doctor.GetName() << endl;
	out << "年龄;" << AgeToString(Doctor.GetAge()) << endl;
	out << "性别:" << Doctor.GetGender() << endl;
	out << "入学年份:" << EnrollmentYearToString(Doctor.GetEnrollmentYear()) << endl;
	out << "研究方向:" << ResearchFieldToString(Doctor.GetResearchField()) << endl;
	out << "是否参与教学:" << Doctor.GetTeaching() << endl;
	return out;
}