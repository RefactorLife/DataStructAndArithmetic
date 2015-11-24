#include "Common.h"
#include "sort.h"
void sort_main()
{
	double sort(char ch);
	char ch;
	while(1)
	{
		tag("sort");
		printf("a.ֱ�Ӳ�������(��������)\n");
		printf("b.�۰�����(��������)\n");
		printf("c.ϣ������(��������)\n");
		printf("d.ð�����򣨽�������\n");
		printf("e.�������򣨽�������\n");
		printf("f.��ѡ������ѡ������\n");
		printf("g.������ѡ������\n");
		while ((ch = getchar())=='\r');
		flushall();//������뻺����
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
	//����ʱ��
	double time=0;
	get_rand_array_int(a,MIN_NUM,MAX_NUM,LIMIT);//����һ���������
	printf("����ǰ����--->\n");
	if(ch>='Z')//��д����ʾ���� Сд����ʾ
		show_array_int(a,LIMIT);
	time = cal_time(0.0);
	switch(ch)
		{
			case 'a':
			case 'A':
				insert_sort('a',a);//ֱ�Ӳ�������
				break;
			case 'b':
			case 'B':
				insert_sort('b',a);//�۰��������
				break;
			case 'c':
			case 'C':
				insert_sort('c',a);//ϣ������
				break;
			case 'd':
			case 'D':
				exchange_sort('a',a);//ð������
				break;
			case 'e':
			case 'E':
				exchange_sort('b',a);//��������
				break;
			case 'f':
			case 'F':
				selection_sort('a',a);//ѡ������
				break;
			case 'g':
			case 'G':
				selection_sort('b',a);//������
				break;
			default:
				show_warn("�������!\n");
				return -1;
		}
	time = cal_time(time);
	printf("���������--->\n");
	if(ch>='Z')
		show_array_int(a,LIMIT);
	show_time_cost(time);
	return time;
}