#include<iostream>
#include <conio.h>//读任意输入用
#include <cstdlib>//清屏用
#include"StudentManage.h"
using namespace std;
void Clear();
int main(void)
{
	while (true)
	{
		StudentManage temp;
		int temp1 = StudentManage::Input(1, 8, "欢迎使用学生管理系统!\n请输入选项:\n1:添加学生\n2:删除学生\n3:修改信息\n4:查找学生\n5:显示所有学生\n6:写文件\n7:读文件\n8:退出系统\n");
		if (temp1 == 1)
		{
			temp.AddStudent();
			Clear();
		}
		else if (temp1 == 2)
		{
			temp.DeleteStudent();
			Clear();
		}
		else if (temp1 == 3)
		{
			temp.ChangeInformation();
			Clear();
		}
		else if (temp1 == 4)
		{
			temp.SearchStudent();
			Clear();
		}
		else if (temp1 == 5)
		{
			temp.ShowAllStudent();
			Clear();
		}
		else if (temp1 == 6)
		{
			string filename;
			cout << "请输入文件路径:";
			cin >> filename;
			temp.SaveData(filename);
			Clear();
		}
		else if (temp1 == 7)
		{
			string filename;
			cout << "请输入文件路径:";
			cin >> filename;
			temp.ReadData(filename);
			Clear();
		}
		else
		{
			break;
		}
	}
	cout << "再见!" << endl;
	return 0;
}
void Clear()
{
	char temp;//添加这个temp是为了去除返回值被忽略的警告(虽然那个警告确实没什么用)
	std::cout << "按任意键继续...";
	temp=_getch();
	system("cls");
}