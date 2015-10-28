#include "Common.h"
#define MAX_NUM 100
#define MIN_NUM 10
void test_get_rand_array_int()
{
	int a[MAX_NUM];
	srand(time(0));//随机数种子
	for (int i =0;i<MAX_NUM;i++)
		a[i] = get_random_int(MIN_NUM,MAX_NUM);
	show_array_int(a,MAX_NUM);
}
void Common_main_test()
{
	char ch;
	while(1)
	{
		tag("Common__test");
		printf("a. test_get_rand_array_int()\n");
		while ((ch = getchar())=='\r');
		flushall();//清空输入缓冲区
		switch(ch)
		{
			case 'a':
				test_get_rand_array_int();
				break;
			case 'A':
			case 'b':
			case 'B':
			case 'c':
			case 'C':
			case 'D':
			case 'd':
			case 'e':
			case 'E':
			default:
				printf("unvalide operation!\n");
		}
		if(!isContinue())
		{
			return;
		}
	}

}