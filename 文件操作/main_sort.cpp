#include "Common.h"
#include "sort.h"
void sort_main()
{
	char ch;
	while(1)
	{
		tag("sort");
		printf("a.ֱ�Ӳ�������\n");
		printf("b.�۰�����\n");
		printf("c.ϣ������(��������)\n");
		printf("d.ð�����򣨽�������\n");
		printf("e.�������򣨽�������\n");
		while ((ch = getchar())=='\r');
		flushall();//������뻺����
		switch(ch)
		{
			case 'a':
				insert_sort('a');
				break;
			case 'b':
				insert_sort('b');
				break;
			case 'c':
				insert_sort('c');
				break;
			case 'D':
			case 'd':
				exchange_sort('a');//ð������
				break;
			case 'e':
			case 'E':
				exchange_sort('b');//��������
				break;
			default:
				printf("unvalide operation!\n");
		}
		if(!isContinue())
		{
			return;
		}
	}

}