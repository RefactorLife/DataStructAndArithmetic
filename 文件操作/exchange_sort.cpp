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
		pivot = partition(a,low,high);
		quick_sort(a,low,pivot-1);
		quick_sort(a,pivot+1,high);
	}
}


double exchange_sort(char ch)
{
	int a[LIMIT];
	//计算时间
	double time=0;
	get_rand_array_int(a,MIN_NUM,MAX_NUM,LIMIT);//产生一个随机数组
	printf("排序前数组--->\n");
	show_array_int(a,LIMIT);
	time = cal_time(0.0);
	switch(ch)
	{
		case 'a':	
			bubble(a);
			break;
		case 'b':	
			quick_sort(a,0,LIMIT-1);
			tag("快速排序");
			break;
		default:
			printf("unvalide operation!\n");
	}
	time = cal_time(time);
	printf("排序后数组--->\n");
	show_array_int(a,LIMIT);
	show_time_cost(time);
	return time;
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
