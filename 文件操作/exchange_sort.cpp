#include "Common.h"
#include "sort.h"

void bubble(int a[])
{
	// 1 2 3 4 5 6 7
	// |_|_|_|_|_|_| 从高到底 依次比较交换次序
	//   |_|_|_|_|_|
	//     |_|_|_|_| ...
	//空间复杂度：O（1） 时间复杂度O（n^2）  
	//稳定排序算法
	bool isSwaped;
	tag("冒泡排序");
	for(int i =0;i<LIMIT-1;i++)
	{
		isSwaped = false;
		for(int j=LIMIT-1;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				swap_int(&a[j],&a[j-1]);
				isSwaped = true;
			}
		}
		if(!isSwaped)
		{
			return ;
		}
	
	}
}
//插入排序
int partition(int a[],int low,int high)
{
	//此函数功能找出a[low] 在范围内的位置，并插入 并把小于a[low]的向左扔 大于的向右
	//  5 1 2 4 6 7 8 2
	//  |->			  |找到第一个在此序列中的中间值
	//    |          从最右边开始找到小于 5 的丢到a[low]处（high--）
	//	  |->然后在左边找到大于 5 的 丢到a[high]处(low++)
	//如此反复 直到 when(low>high) a[low] = 5
	int privot = a[low];
	while(low<high)
	{
		while(low<high&&privot<=a[high]) high--;
		a[low] = a[high];
		while(low<high&&privot>=a[low]) low++;
		a[high] = a[low];
	}
	a[low] = privot; // low 为此数字最终位置
	return low;
}
void quick_sort(int a[],int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot = partition(a,low,high);//找到a[low]序列中的位置
		quick_sort(a,low,pivot-1);//以此位置为中点，左边继续排序
		quick_sort(a,pivot+1,high);//右边也继续排序
	}
}


void exchange_sort(char ch,int a[])
{
	switch(ch)
	{
		case 'a':	
			bubble(a);
			break;
		case 'b':	
			quick_sort(a,0,LIMIT-1);
			break;
		default:
			printf("unvalide operation!\n");
	}
}


//int partition(int a[],int low,int high)
//{
//	int pivot = a[low];
//	while(low<high)
//	{
//		while(low<high&&a[high]>=pivot) --high;
//		a[low] = a[high];
//		while(low<high&&a[low]<=pivot) ++low;
//		a[high]=a[low];
//	}
//	a[low]=pivot;
//	return low;
//}
//void quick_sort(int a[],int low,int high)
//{
//	if(low<high)
//	{
//		int privotpos = partition(a,low,high);
//		quick_sort(a,low,privotpos-1);
//		quick_sort(a,privotpos+1,high);
//	}
//}
