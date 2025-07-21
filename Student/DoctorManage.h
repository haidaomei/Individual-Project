#pragma once
#include"MasterAndDoctorManage.h"
#include"DoctorProperties.h"
#include<vector>
using namespace std;
class DoctorManage :public MasterAndDoctorManage
{
public:
	DoctorManage() = default;
	virtual ~DoctorManage()override = default;
	virtual void AddStudent()override;
	virtual void DeleteStudent()override;
	virtual void ChangeInformation()override;
	virtual void SearchStudent()override;
	virtual void ShowAllStudent()override;
};