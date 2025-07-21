#pragma once
#include<string>
using namespace std;
enum Age { Eighteen, Nineteen, Twenty };
enum EnrollmentYear { YearOne, YearTwo, YearThree, YearFour, YearFive };
enum Major { ComputerScience, SoftwareEngineering, NetworkEngineering, Cybersecurity1, IoTEngineering };
enum Class { ZeroOne, ZeroTwo, ZeroThree, ZeroFour, ZeroFive };
enum ResearchField { AI, EmbeddedSystems, ComputerGraphics, IoT, Cybersecurity2 };
inline string AgeToString(Age Age)//�����������������ʱ������ֶ�ת��
{
    switch (Age)
    {
    case Eighteen: 
        return "18��";
    case Nineteen: 
        return "19��";
    case Twenty:   
        return "20��";
    }
}
inline string EnrollmentYearToString(EnrollmentYear EnrollmentYear)
{
    switch (EnrollmentYear)
    {
    case YearOne:
        return "��1��";
    case YearTwo:
        return "��2��";
    case YearThree:
        return "��3��";
    case YearFour:
        return "��4��";
    case YearFive:
        return "��5��";
    }
}
inline string MajorToString(Major Major)
{
    switch (Major)
    {
    case ComputerScience:
        return "�������ѧ�뼼��";
    case SoftwareEngineering:
        return "�������";
    case NetworkEngineering:
        return "���繤��";
    case Cybersecurity1:
        return "��Ϣ��ȫ";
    case IoTEngineering:
        return "����������";
    }
}
inline string ClassToString(Class Class)
{
    switch (Class)
    {
    case ZeroOne:
        return "01��";
    case ZeroTwo:
        return "02��";
    case ZeroThree:
        return "03��";
    case ZeroFour:
        return "04��";
    case ZeroFive:
        return "05��";
    }
}
inline string ResearchFieldToString(ResearchField ResearchField)
{
    switch (ResearchField)
    {
    case AI:
        return "�˹�����";
    case EmbeddedSystems:
        return "Ƕ��ʽ";
    case ComputerGraphics:
        return "�����ͼ��ѧ";
    case IoT:
        return "������";
    case Cybersecurity2:
        return "���簲ȫ";
    }
}//��˵Ҫinline�Ҿͼ���