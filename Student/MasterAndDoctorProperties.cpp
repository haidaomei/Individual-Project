#include"MasterAndDoctorProperties.h"
#include"Enum.h"
#include"StudentProperties.h"
#include<string>
using namespace std;
extern int StudentNumberCountingSymbol;
MasterAndDoctorProperties::MasterAndDoctorProperties(string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear, ResearchField ResearchField) :StudentProperties(StudentNumberCountingSymbol, Name, Age, Gender, EnrollmentYear), StudentResearchField(ResearchField)
{
}
void MasterAndDoctorProperties::SetResearchField(ResearchField ResearchField)
{
	StudentResearchField = ResearchField;
}
ResearchField MasterAndDoctorProperties::GetResearchField()const
{
	return StudentResearchField;
}