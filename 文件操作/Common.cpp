#include <stdio.h>
#include <stdlib.h>
#include "myFile.h"
#include "Common.h"
#include<time.h>
#include <windows.h>
/*��ɫ��Ӧֵ�� 
����0=��ɫ                8=��ɫ����
  �� 1=��ɫ                9=����ɫ                ����                        
����2=��ɫ                10=����ɫ       0xa        ����
����3=����ɫ          11=��ǳ��ɫ        0xb��
����4=��ɫ                12=����ɫ        0xc����
����5=��ɫ                13=����ɫ        0xd        ����
����6=��ɫ                14=����ɫ        0xe        ����
����7=��ɫ                15=����ɫ        0xf 
����Ҳ���԰���Щֵ���óɳ�����
*/
void color(const unsigned short color1)
{        /*���޸ı�0-15����ɫ;�����0-15��ôʵ��������ɫ   ��Ϊ�������15����ĸı�����ı�����ɫ��*/
        if(color1>=0&&color1<=15)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
        /*�������0-15�ķ�Χ��ɫ����ô��ΪĬ�ϵ���ɫ��ɫ��*/
    else
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

bool isContinue()
{
	//ѯ���Ƿ���� ���� y/n ���������ַ��������� y/n ��Ч
	char ch;
	while(1)
		{
			printf("\nDo you want Continue? y/n --> ");
			ch = getchar();
			while(ch == '\r'|| ch=='\n')
			{
				ch = getchar();
			}
			flushall();
			if(ch=='n'||ch=='N')
			{
				return false;
			}else if(ch=='y' || ch=='Y')
			{
				return true;
			}
		}
	return false;
}
void tag(char str[200])
{
	//���
	printf("\n===========%s==========\n",str);
}
//��ʾ����Ϊn������ȫ��
void show_array_int(int e[],int n)
{
	for(int i=0;i<n;i++)
	{
		color(7);
		printf("%d_",i);
		color(11);
		printf("%d",e[i]);
		color(7);
		printf("|");
	}
}

void swamp_int(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return ;
}
int get_random_int(int min,int max)
{
	if(min>max)
	{
		swamp_int(&min,&max);
	}
	return ( abs(rand())+min )  % max ;
}
void get_rand_array_int(int a[],int min,int max,int n)
{
	//�õ�int������������� ��min��max����n��
	if(min>max)
	{
		swamp_int(&min,&max);
	}
	srand(time(0));//���������
	for(int i=0;i<n;i++)
	{
		a[i]= get_random_int(min,max);
	}
}
//���ڼ���ʱ��
//ʹ�÷������ں�����ʼ�ͽ�����ʱ��ֱ�����˺�������
double cal_time(double time)
{
	if(time < 0.001)//time = 0
	{
		time = clock();
		return clock();
	}else
	{
		color(14);
		printf("\n%f/CPUs\n",clock()-time);
		color(7);
		return clock()-time;
	}
}
