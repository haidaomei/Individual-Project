#pragma once
#include"StudentManage.h"
#include"BachelorProperties.h"
class BachelorManage :public StudentManage
{
public:
	BachelorManage() = default;
	virtual ~BachelorManage()override = default;
	virtual void AddStudent()override;
	virtual void DeleteStudent()override;
	virtual void ChangeInformation()override;
	virtual void SearchStudent()override;
	virtual void ShowAllStudent()override;
	void ScoreSummmary();//��ʹ��void��ԭ���ǲ����������ط����������������,ֱ��һ���㶨
	void AverageScore();
};