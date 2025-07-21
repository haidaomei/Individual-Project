#pragma once
#include<string>
using namespace std;
enum Age { Eighteen, Nineteen, Twenty };
enum EnrollmentYear { YearOne, YearTwo, YearThree, YearFour, YearFive };
enum Major { ComputerScience, SoftwareEngineering, NetworkEngineering, Cybersecurity1, IoTEngineering };
enum Class { ZeroOne, ZeroTwo, ZeroThree, ZeroFour, ZeroFive };
enum ResearchField { AI, EmbeddedSystems, ComputerGraphics, IoT, Cybersecurity2 };
inline string AgeToString(Age Age)//别忘了在重载输出的时候加上手动转换
{
    switch (Age)
    {
    case Eighteen: 
        return "18岁";
    case Nineteen: 
        return "19岁";
    case Twenty:   
        return "20岁";
    }
}
inline string EnrollmentYearToString(EnrollmentYear EnrollmentYear)
{
    switch (EnrollmentYear)
    {
    case YearOne:
        return "第1年";
    case YearTwo:
        return "第2年";
    case YearThree:
        return "第3年";
    case YearFour:
        return "第4年";
    case YearFive:
        return "第5年";
    }
}
inline string MajorToString(Major Major)
{
    switch (Major)
    {
    case ComputerScience:
        return "计算机科学与技术";
    case SoftwareEngineering:
        return "软件工程";
    case NetworkEngineering:
        return "网络工程";
    case Cybersecurity1:
        return "信息安全";
    case IoTEngineering:
        return "物联网工程";
    }
}
inline string ClassToString(Class Class)
{
    switch (Class)
    {
    case ZeroOne:
        return "01班";
    case ZeroTwo:
        return "02班";
    case ZeroThree:
        return "03班";
    case ZeroFour:
        return "04班";
    case ZeroFive:
        return "05班";
    }
}
inline string ResearchFieldToString(ResearchField ResearchField)
{
    switch (ResearchField)
    {
    case AI:
        return "人工智能";
    case EmbeddedSystems:
        return "嵌入式";
    case ComputerGraphics:
        return "计算机图形学";
    case IoT:
        return "物联网";
    case Cybersecurity2:
        return "网络安全";
    }
}//听说要inline我就加了