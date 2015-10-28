#include <stdio.h>
#include "Common.h"
#include "sort.h"
void direct_insert_sort()
{
	//ֱ�Ӳ�������
	//�ռ临�Ӷ�O(1)
	//ʱ�临�Ӷȣ����:O(n)  ƽ����O(n^2)
	int i,j;
	int a[LIMIT];
	//����ʱ��
	double time=0;
	time = cal_time(time);

	get_rand_array_int(a,MIN_NUM,MAX_NUM,LIMIT);//����һ���������
	tag("ֱ�Ӳ�������(a[0]����)");
	printf("����ǰ����--->\n");
	show_array_int(a,LIMIT);
	//13456   2   840376
	//  |     |     |
	//��������|  ����������
	//    �ҵ��Ĳ���ֵ
 	////////////�����㷨////////////
	for(i=2;i<LIMIT;i++)//������������
	{
		if(a[i]<a[i-1])//�ҵ���Ҫ�����ֵ
		{
			a[0]=a[i];//�ڱ� ��ΪҪ�ڳ�λ������ƶ�
			for(j=i-1;a[j]>a[0];j--)//����ƶ�
			{
				a[j+1]=a[j];
			}
			a[j+1]=a[0];//�ŵ��ڳ�����λ����
		}
	}
	printf("\n���������--->\n");
	show_array_int(a,LIMIT);
	//��ʾʱ��
	cal_time(time);
	//from book p270
	//for(i=2;i<=LIMIT;i++)
	//	if(a[i-1]>a[i])//�ҵ���һ����Ҫ�����ֵ
	//	{
	//		a[0]=a[i];
	//		for(j=i-1;a[0]<a[j];--j)//������������ҵ�Ҫ�����λ��
	//		{
	//			a[j+1]=a[j];
	//		}
	//		a[j+1]=a[0];
	//	}

}

void half_insert_sort()
{
	//�۰��������
	int i,j,low,high,mid;
	int a[LIMIT];
	//����ʱ��
	double time=0;
	time = cal_time(time);

	get_rand_array_int(a,MIN_NUM,MAX_NUM,LIMIT);//����һ���������
	tag("�۰��������(a[0]����)");
	printf("����ǰ����--->\n");
	show_array_int(a,LIMIT);
	//�����㷨
	for(i=2;i<LIMIT;i++)//����p271�� i<=LIMIT
	{
		a[0]=a[i];
		low=1;
		high=i-1;
		while(low<=high)
		{
			mid = (low+high)/2;
			if(a[mid]>a[0])
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=high+1;--j)
		{
			a[j+1]=a[j];
		}
		a[high+1]=a[0];
	}

	printf("\n���������--->\n");
	show_array_int(a,LIMIT);
	//��ʾʱ��
	cal_time(time);
}
