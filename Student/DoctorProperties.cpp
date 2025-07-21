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
	out << "ѧ��:" << Doctor.GetStudentNumber() << endl;
	out << "����:" << Doctor.GetName() << endl;
	out << "����;" << AgeToString(Doctor.GetAge()) << endl;
	out << "�Ա�:" << Doctor.GetGender() << endl;
	out << "��ѧ���:" << EnrollmentYearToString(Doctor.GetEnrollmentYear()) << endl;
	out << "�о�����:" << ResearchFieldToString(Doctor.GetResearchField()) << endl;
	out << "�Ƿ�����ѧ:" << Doctor.GetTeaching() << endl;
	return out;
}