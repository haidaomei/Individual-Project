#include"MasterProperties.h"
#include<iostream>
#include<string>
#include"Enum.h"
using namespace std;
MasterProperties::MasterProperties(string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear, ResearchField ResearchField, bool ProfessionalAndAcademic) :MasterAndDoctorProperties(Name, Age, Gender, EnrollmentYear, ResearchField), StudentProfessionalAndAcademic(ProfessionalAndAcademic)
{
}
bool MasterProperties::GetProfessionalAndAcademic()const
{
	return StudentProfessionalAndAcademic;
}
void MasterProperties::SetProfessionalAndAcademic(bool ProfessionalAndAcademic)
{
	StudentProfessionalAndAcademic = ProfessionalAndAcademic;
}
vector<bool> MasterProperties::GetSpecificIdentification()const
{
	return StudentSpecificIdentification;
}
ostream& operator<<(ostream& out, const MasterProperties& Master)
{
	out << "学号:" << Master.GetStudentNumber() << endl;
	out << "姓名:" << Master.GetName() << endl;
	out << "年龄;" << AgeToString(Master.GetAge()) << endl;
	out << "性别:" << Master.GetGender() << endl;
	out << "入学年份:" << EnrollmentYearToString(Master.GetEnrollmentYear()) << endl;
	out << "研究方向:" << ResearchFieldToString(Master.GetResearchField()) << endl;
	out << "类型:" << Master.GetProfessionalAndAcademic() << endl;
	return out;
}