#include <stdio.h>
#include <stdlib.h>
#include "myFile.h"
#include "Common.h"
#include<time.h>
#include <windows.h>
/*颜色对应值： 
　　0=黑色                8=灰色　　
  　 1=蓝色                9=淡蓝色                　　                        
　　2=绿色                10=淡绿色       0xa        　　
　　3=湖蓝色          11=淡浅绿色        0xb　
　　4=红色                12=淡红色        0xc　　
　　5=紫色                13=淡紫色        0xd        　　
　　6=黄色                14=淡黄色        0xe        　　
　　7=白色                15=亮白色        0xf 
　　也可以吧这些值设置成常量。
*/
void color(const unsigned short color1)
{        /*仅限改变0-15的颜色;如果在0-15那么实现他的颜色   因为如果超过15后面的改变的是文本背景色。*/
        if(color1>=0&&color1<=15)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
        /*如果不在0-15的范围颜色，那么改为默认的颜色白色；*/
    else
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

bool isContinue()
{
	//询问是否继续 输入 y/n 或者输入字符串开口是 y/n 有效
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
	//标记
	printf("\n===========%s==========\n",str);
}
//显示长度为n的数组全部
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
	//得到int型随机数的数组 从min到max产生n个
	if(min>max)
	{
		swamp_int(&min,&max);
	}
	srand(time(0));//随机数种子
	for(int i=0;i<n;i++)
	{
		a[i]= get_random_int(min,max);
	}
}
//用于计算时间
//使用方法，在函数开始和结束的时候分别调动此函数即可
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
