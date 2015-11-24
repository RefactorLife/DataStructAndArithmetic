#include "Common.h"
#include "sort.h"
void sort_main()
{
	double sort(char ch);
	char ch;
	while(1)
	{
		tag("sort");
		printf("a.Ö±½Ó²åÈëÅÅÐò(²åÈëÅÅÐò)\n");
		printf("b.ÕÛ°ëÅÅÐò(²åÈëÅÅÐò)\n");
		printf("c.Ï£¶ûÅÅÐò(²åÈëÅÅÐò)\n");
		printf("d.Ã°ÅÝÅÅÐò£¨½»»»ÅÅÐò£©\n");
		printf("e.¿ìËÙÅÅÐò£¨½»»»ÅÅÐò£©\n");
		printf("f.¼òµ¥Ñ¡ÔñÅÅÐò£¨Ñ¡ÔñÅÅÐò£©\n");
		printf("g.¶ÑÅÅÐò£¨Ñ¡ÔñÅÅÐò£©\n");
		while ((ch = getchar())=='\r');
		flushall();//Çå¿ÕÊäÈë»º³åÇø
		sort(ch);
		if(!isContinue())
		{
			return;
		}
	}

}

double sort(char ch)
{
	int a[LIMIT];
	//¼ÆËãÊ±¼ä
	double time=0;
	get_rand_array_int(a,MIN_NUM,MAX_NUM,LIMIT);//²úÉúÒ»¸öËæ»úÊý×é
	printf("ÅÅÐòÇ°Êý×é--->\n");
	if(ch>='Z')//´óÐ´²»ÏÔÊ¾Êý×é Ð¡Ð´¾ÍÏÔÊ¾
		show_array_int(a,LIMIT);
	time = cal_time(0.0);
	switch(ch)
		{
			case 'a':
			case 'A':
				insert_sort('a',a);//Ö±½Ó²åÈëÅÅÐò
				break;
			case 'b':
			case 'B':
				insert_sort('b',a);//ÕÛ°ë²åÈëÅÅÐò
				break;
			case 'c':
			case 'C':
				insert_sort('c',a);//Ï£¶ûÅÅÐò
				break;
			case 'd':
			case 'D':
				exchange_sort('a',a);//Ã°ÅÝÅÅÐò
				break;
			case 'e':
			case 'E':
				exchange_sort('b',a);//¿ìËÙÅÅÐò
				break;
			case 'f':
			case 'F':
				selection_sort('a',a);//Ñ¡ÔñÅÅÐò
				break;
			case 'g':
			case 'G':
				selection_sort('b',a);//¶ÑÅÅÐò
				break;
			default:
				show_warn("ÊäÈë´íÎó£¡!\n");
				return -1;
		}
	time = cal_time(time);
	printf("ÅÅÐòºóÊý×é--->\n");
	if(ch>='Z')
		show_array_int(a,LIMIT);
	show_time_cost(time);
	return time;
}