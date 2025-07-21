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
	void ScoreSummmary();//都使用void的原因是不想在其他地方继续处理输入输出,直接一步搞定
	void AverageScore();
};