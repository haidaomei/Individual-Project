#pragma once
#include"MasterAndDoctorProperties.h"
#include<string>
#include"Enum.h"
#include<vector>
using namespace std;
class MasterProperties :public MasterAndDoctorProperties
{
	//属性
private:
	bool StudentProfessionalAndAcademic;
	vector<bool> StudentSpecificIdentification = { 0,1,0 };
	//属性
	//构造析构
public:
	MasterProperties(string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear, ResearchField ResearchField,bool ProfessionalAndAcademic);
	virtual ~MasterProperties()override = default;
	//构造析构
	//get
	bool GetProfessionalAndAcademic()const;
	vector<bool> GetSpecificIdentification()const;
	//get
	//set
	void SetProfessionalAndAcademic(bool ProfessionalAndAcademic);
	//set
	//重载
	friend ostream& operator<<(ostream& out, const MasterProperties& Master);
	//重载
};