#pragma once
#include"StudentProperties.h"
#include"Enum.h"
class MasterAndDoctorProperties :public StudentProperties
{
private:
	//����
	ResearchField StudentResearchField;
	//����
public:
	//��������
	MasterAndDoctorProperties(string Name,Age Age,bool Gender,EnrollmentYear EnrollmentYear,ResearchField ResearchField);
	virtual ~MasterAndDoctorProperties()override = default;
	//��������
	//Set
	void SetResearchField(ResearchField ResearchField);
	//Set
	//Get
	ResearchField GetResearchField()const;
	//Get
};