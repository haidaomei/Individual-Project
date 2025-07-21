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
	out << "ѧ��:" << Master.GetStudentNumber() << endl;
	out << "����:" << Master.GetName() << endl;
	out << "����;" << AgeToString(Master.GetAge()) << endl;
	out << "�Ա�:" << Master.GetGender() << endl;
	out << "��ѧ���:" << EnrollmentYearToString(Master.GetEnrollmentYear()) << endl;
	out << "�о�����:" << ResearchFieldToString(Master.GetResearchField()) << endl;
	out << "����:" << Master.GetProfessionalAndAcademic() << endl;
	return out;
}