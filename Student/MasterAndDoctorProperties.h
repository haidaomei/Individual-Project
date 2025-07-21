#pragma once
#include"StudentProperties.h"
#include"Enum.h"
class MasterAndDoctorProperties :public StudentProperties
{
private:
	//属性
	ResearchField StudentResearchField;
	//属性
public:
	//构造析构
	MasterAndDoctorProperties(string Name,Age Age,bool Gender,EnrollmentYear EnrollmentYear,ResearchField ResearchField);
	virtual ~MasterAndDoctorProperties()override = default;
	//构造析构
	//Set
	void SetResearchField(ResearchField ResearchField);
	//Set
	//Get
	ResearchField GetResearchField()const;
	//Get
};