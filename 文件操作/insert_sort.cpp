#include <stdio.h>
#include "Common.h"
#include "sort.h"
void direct_insert_sort()
{
	//直接插入排序
	//空间复杂度O(1)
	//时间复杂度：最好:O(n)  平均：O(n^2)
	int i,j;
	int a[LIMIT];
	//计算时间
	double time=0;
	time = cal_time(time);

	get_rand_array_int(a,MIN_NUM,MAX_NUM,LIMIT);//产生一个随机数组
	tag("直接插入排序(a[0]不用)");
	printf("排序前数组--->\n");
	show_array_int(a,LIMIT);
	//13456   2   840376
	//  |     |     |
	//有序数列|  待插入序列
	//    找到的插入值
 	////////////排序算法////////////
	for(i=2;i<LIMIT;i++)//遍历整个数组
	{
		if(a[i]<a[i-1])//找到需要插入的值
		{
			a[0]=a[i];//哨兵 因为要腾出位置向后移动
			for(j=i-1;a[j]>a[0];j--)//向后移动
			{
				a[j+1]=a[j];
			}
			a[j+1]=a[0];//放到腾出来的位置上
		}
	}
	printf("\n排序后数组--->\n");
	show_array_int(a,LIMIT);
	//显示时间
	cal_time(time);
	//from book p270
	//for(i=2;i<=LIMIT;i++)
	//	if(a[i-1]>a[i])//找到下一下需要插入的值
	//	{
	//		a[0]=a[i];
	//		for(j=i-1;a[0]<a[j];--j)//在有序队列中找到要插入的位置
	//		{
	//			a[j+1]=a[j];
	//		}
	//		a[j+1]=a[0];
	//	}

}

void half_insert_sort()
{
	//折半插入排序
	int i,j,low,high,mid;
	int a[LIMIT];
	//计算时间
	double time=0;
	time = cal_time(time);

	get_rand_array_int(a,MIN_NUM,MAX_NUM,LIMIT);//产生一个随机数组
	tag("折半插入排序(a[0]不用)");
	printf("排序前数组--->\n");
	show_array_int(a,LIMIT);
	//排序算法
	for(i=2;i<LIMIT;i++)//书中p271是 i<=LIMIT
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

	printf("\n排序后数组--->\n");
	show_array_int(a,LIMIT);
	//显示时间
	cal_time(time);
}
