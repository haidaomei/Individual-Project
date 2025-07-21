#pragma once
#include"MasterAndDoctorProperties.h"
#include<string>
#include"Enum.h"
#include<vector>
using namespace std;
class MasterProperties :public MasterAndDoctorProperties
{
	//����
private:
	bool StudentProfessionalAndAcademic;
	vector<bool> StudentSpecificIdentification = { 0,1,0 };
	//����
	//��������
public:
	MasterProperties(string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear, ResearchField ResearchField,bool ProfessionalAndAcademic);
	virtual ~MasterProperties()override = default;
	//��������
	//get
	bool GetProfessionalAndAcademic()const;
	vector<bool> GetSpecificIdentification()const;
	//get
	//set
	void SetProfessionalAndAcademic(bool ProfessionalAndAcademic);
	//set
	//����
	friend ostream& operator<<(ostream& out, const MasterProperties& Master);
	//����
};