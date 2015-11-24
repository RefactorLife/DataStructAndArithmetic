#include "Common.h"
#include "sort.h"

void direct_insert_sort(int a[])
{
	//ֱ�Ӳ�������
	//�ռ临�Ӷ�O(1)
	//ʱ�临�Ӷȣ����:O(n)  ƽ����O(n^2)
	//�ȶ�
	int i,j;
	tag("ֱ�Ӳ�������(a[0]����)");
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
}

void half_insert_sort(int a[])
{
	//�۰��������
	//ʱ�临�Ӷ� O(n^2) �ռ�O(1)
	//�ȶ�
	int i,j,low,high,mid;
	//�����㷨
	tag("�۰��������(a[0]����)");
	for(i=2;i<LIMIT;i++)
	{
		a[0]=a[i];//��������
		high=i-1;
		low=1;
		while(high>=low)//@@@�ҵ�����λ��
		{
			mid = (high+low)/2;
			if(a[0]<a[mid])
			{
				high = mid-1;
			}else
			{
				low = mid+1;
			}
		}
		//�������ǵõ���@@@��high+1��Ϊ����λ��
		//����
		for(j=i-1;j>=(high+1);j--)
		{
			a[j+1]=a[j];
		}
		a[high+1]=a[0];
	}
}

void hill_insert_sort(int a[])
{
	int i,j;
	//���������Ա�˳��洢ʱ
	//����O(n^2) ĳЩ���O(n^1.3)
	//���ȶ�
	tag("ϣ������(a[0]����)");
	//1 4 7 2 5 8 3 6 9
	//| | | | | | | | |
	//d1| |d1 | |d1 | |
	// d2 |  d2 |  d2 |
	//   d3    d3    d3
	//������ LIMIT/2��ʼһ�α��ԭ����1/2 ��������
 	for(int dk=LIMIT/2;dk>=1;dk=dk/2)//�����仯
	{
		for(i = dk+1;i<LIMIT;i++)//����ÿһ��������
		{
			//�������н���ֱ�Ӳ�������
			if(a[i]<a[i-dk])//�����������Ҫ����
			{
				a[0]=a[i];//��Ҫ�����Ԫ�ش����a[0]��
				for(j = i-dk;(j>=1)&&(a[j]>a[0]);j-=dk)//�����Ųλ��
				{
					a[j+dk]=a[j];
				}
				//j+dkΪ����Ų������λ��
				a[j+dk]=a[0];//@@ע���д��a[j+1]
			}
		}
	}
}

void insert_sort(char ch,int a[])
{
	
	switch(ch)
	{
		case 'a':	
			direct_insert_sort(a);
			break;
		case 'b':	
			half_insert_sort(a);
			break;
		case 'c':	
			hill_insert_sort(a);
			break;
		default:
			printf("unvalide operation!\n");
	}
}















//insert sort 
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
//half insert sort
//for(i=2;i<LIMIT;i++)//����p271�� i<=LIMIT
	//{
	//	a[0]=a[i];
	//	low=1;
	//	high=i-1;

	//	/*if(a[i-1]>a[i])//Ӱ�첻�� ���ü�
	//	{*/
	//		while(low<=high)//�۰뷨�ҵ�����λ��Ϊhigh+1
	//		{
	//			mid = (low+high)/2;
	//			if(a[0]<a[mid])
	//				high=mid-1;
	//			else
	//				low=mid+1;
	//		}
	//		for(j=i-1;j>=high+1;--j)//��high+1��ʼ�����������ƣ��Ḳ��a[i]��
	//		{
	//			a[j+1]=a[j];
	//		}
	//		a[high+1]=a[0];//��high+1��������������
	//	//}
	//}
//HILL SORT P271
	//for(int dk=LIMIT/2;dk>=1;dk=dk/2)
	//{
	//	for(i=dk+1;i<LIMIT;++i)//�޸�i<=LIMIT
	//		if(a[i]<a[i-dk])
	//		{
	//			a[0]=a[i];
	//			for(j=i-dk;j>0&&a[0]<a[j];j-=dk)
	//			{
	//				a[j+dk]=a[j];
	//			}
	//			a[j+dk]=a[0];
	//		}
	//}