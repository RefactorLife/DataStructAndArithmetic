#include "Common.h"
#include "sort.h"

void simple_selection_sort(int a[])
{
	//123 6974869
	// |  |  |->   1.右边为没有排序的数据
	// |->|        2.左边为已经按从小到大有序排好，并且已经在最终位置上
	//    |->      3.从6开始，向右遍，历选出右边最小的数字，与“a[3]=6”交换位置	
	//   4.然后再从9开始选出右边最小的与9交换位置，直到完成。
	//时间复杂度O(n^2) 空间复杂度O(1) 
	//不稳定 如 {2 3 1} -> {1 3 2} -> {1 2 3} 显然 2 3 的位置发生相对变化 
	int min;
	tag("简单插入排序");
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
//堆排序
//O(nlog2(n))  O(1)
void heap_sort(int a[])
{
	void build_max_heap(int a[]);
	void adjust_down(int a[],int k);
	build_max_heap(a);
	for(int i=LIMIT-1;i>1;i--)//for(int i=LIMIT;i>1;i--) 书中有错
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