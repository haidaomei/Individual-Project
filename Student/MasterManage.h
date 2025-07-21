#pragma once
#include"MasterAndDoctorManage.h"
#include"MasterProperties.h"
#include<vector>
using namespace std;
class MasterManage :public MasterAndDoctorManage
{
public:
	MasterManage() = default;
	virtual ~MasterManage()override = default;
	virtual void AddStudent()override;
	virtual void DeleteStudent()override;
	virtual void ChangeInformation()override;
	virtual void SearchStudent()override;
	virtual void ShowAllStudent()override;
};