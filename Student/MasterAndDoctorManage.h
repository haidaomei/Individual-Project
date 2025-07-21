#pragma once
#include"StudentManage.h"
class MasterAndDoctorManage :public StudentManage
{
public:
	MasterAndDoctorManage() = default;
	virtual ~MasterAndDoctorManage()override = default;
	virtual void AddStudent()override;
	virtual void DeleteStudent()override;
	virtual void ChangeInformation()override;
	virtual void SearchStudent()override;
	virtual void ShowAllStudent()override;
};