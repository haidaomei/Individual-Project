#pragma once
#include"MasterAndDoctorProperties.h"
#include<vector>
using namespace std;
class DoctorProperties :public MasterAndDoctorProperties
{
	//属性
private:
	bool StudentTeaching;
	vector<bool> StudentSpecificIdentification = { 0,0,1 };//特定标识,用于查找
	//属性
	//构造析构
public:
	DoctorProperties(string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear, ResearchField ResearchField, bool Teaching);
	virtual ~DoctorProperties()override = default;
	//构造析构
	//get
	bool GetTeaching()const;
	vector<bool> GetSpecificIdentification()const;
	//get
	//set
	void SetTeaching(bool Teaching);
	//set
	//重载
	friend ostream& operator<<(ostream& out, const DoctorProperties& Doctor);
	//重载
};