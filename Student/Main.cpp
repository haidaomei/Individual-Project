#include<iostream>
#include <conio.h>//������������
#include <cstdlib>//������
#include"StudentManage.h"
using namespace std;
void Clear();
int main(void)
{
	while (true)
	{
		StudentManage temp;
		int temp1 = StudentManage::Input(1, 8, "��ӭʹ��ѧ������ϵͳ!\n������ѡ��:\n1:���ѧ��\n2:ɾ��ѧ��\n3:�޸���Ϣ\n4:����ѧ��\n5:��ʾ����ѧ��\n6:д�ļ�\n7:���ļ�\n8:�˳�ϵͳ\n");
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
			cout << "�������ļ�·��:";
			cin >> filename;
			temp.SaveData(filename);
			Clear();
		}
		else if (temp1 == 7)
		{
			string filename;
			cout << "�������ļ�·��:";
			cin >> filename;
			temp.ReadData(filename);
			Clear();
		}
		else
		{
			break;
		}
	}
	cout << "�ټ�!" << endl;
	return 0;
}
void Clear()
{
	char temp;//������temp��Ϊ��ȥ������ֵ�����Եľ���(��Ȼ�Ǹ�����ȷʵûʲô��)
	std::cout << "�����������...";
	temp=_getch();
	system("cls");
}