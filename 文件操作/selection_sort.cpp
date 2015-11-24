#include "Common.h"
#include "sort.h"

void simple_selection_sort(int a[])
{
	//123 6974869
	// |  |  |->   1.�ұ�Ϊû�����������
	// |->|        2.���Ϊ�Ѿ�����С���������źã������Ѿ�������λ����
	//    |->      3.��6��ʼ�����ұ飬��ѡ���ұ���С�����֣��롰a[3]=6������λ��	
	//   4.Ȼ���ٴ�9��ʼѡ���ұ���С����9����λ�ã�ֱ����ɡ�
	//ʱ�临�Ӷ�O(n^2) �ռ临�Ӷ�O(1) 
	//���ȶ� �� {2 3 1} -> {1 3 2} -> {1 2 3} ��Ȼ 2 3 ��λ�÷�����Ա仯 
	int min;
	tag("�򵥲�������");
	for(int i=0;i<LIMIT-1;i++)
	{
		min = i;
		for(int j=i+1;j<LIMIT;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		swap_int(&a[i],&a[min]);
	}
}
//������
//O(nlog2(n))  O(1)
void heap_sort(int a[])
{
	void build_max_heap(int a[]);
	void adjust_down(int a[],int k);
	build_max_heap(a);
	for(int i=LIMIT-1;i>1;i--)//for(int i=LIMIT;i>1;i--) �����д�
	{
		swap_int(&a[i],&a[1]);
		adjust_down(a,1);
	}
}
void adjust_down(int a[],int k)
{
	a[0]=a[k];
	for(int i =2*k;i<LIMIT;i*=2)//for(int i =2*k;i<=LIMIT;i*=2)
	{
		if(i<LIMIT&&a[i]<a[i+1])
			i++;
		if(a[0]>=a[i]) break;
		else
		{
			a[k]=a[i];
			k=i;
		}
	}
	a[k]=a[0];
}
void build_max_heap(int a[])
{
	for(int i=LIMIT/2;i>0;i--)
	{
		adjust_down(a,i);
	}
}




void selection_sort(char ch,int a[])
{
	switch(ch)
	{
		case 'a':	
			simple_selection_sort(a);
			break;
		case 'b':	
			heap_sort(a);
			break;
		default:
			printf("unvalide operation!\n");
	}
}