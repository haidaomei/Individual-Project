#pragma once
#include"MasterAndDoctorProperties.h"
#include<vector>
using namespace std;
class DoctorProperties :public MasterAndDoctorProperties
{
	//����
private:
	bool StudentTeaching;
	vector<bool> StudentSpecificIdentification = { 0,0,1 };//�ض���ʶ,���ڲ���
	//����
	//��������
public:
	DoctorProperties(string Name, Age Age, bool Gender, EnrollmentYear EnrollmentYear, ResearchField ResearchField, bool Teaching);
	virtual ~DoctorProperties()override = default;
	//��������
	//get
	bool GetTeaching()const;
	vector<bool> GetSpecificIdentification()const;
	//get
	//set
	void SetTeaching(bool Teaching);
	//set
	//����
	friend ostream& operator<<(ostream& out, const DoctorProperties& Doctor);
	//����
};