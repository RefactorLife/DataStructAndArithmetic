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
		while ((ch = getchar())=='\r');
		flushall();//������뻺����
		switch(ch)
		{
			case 'a':
				direct_insert_sort();
				break;
			case 'b':
				half_insert_sort();
				break;
			case 'c':
				hill_insert_sort();
				break;
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