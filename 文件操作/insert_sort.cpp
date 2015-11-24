#include "Common.h"
#include "sort.h"

void direct_insert_sort(int a[])
{
	//直接插入排序
	//空间复杂度O(1)
	//时间复杂度：最好:O(n)  平均：O(n^2)
	//稳定
	int i,j;
	tag("直接插入排序(a[0]不用)");
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
}

void half_insert_sort(int a[])
{
	//折半插入排序
	//时间复杂度 O(n^2) 空间O(1)
	//稳定
	int i,j,low,high,mid;
	//排序算法
	tag("折半插入排序(a[0]不用)");
	for(i=2;i<LIMIT;i++)
	{
		a[0]=a[i];//待插入数
		high=i-1;
		low=1;
		while(high>=low)//@@@找到插入位置
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
		//现在我们得到了@@@（high+1）为插入位置
		//插入
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
	//适用于线性表顺序存储时
	//最坏情况O(n^2) 某些情况O(n^1.3)
	//不稳定
	tag("希尔排序(a[0]不用)");
	//1 4 7 2 5 8 3 6 9
	//| | | | | | | | |
	//d1| |d1 | |d1 | |
	// d2 |  d2 |  d2 |
	//   d3    d3    d3
	//步长从 LIMIT/2开始一次变成原来的1/2 进行排序
 	for(int dk=LIMIT/2;dk>=1;dk=dk/2)//步长变化
	{
		for(i = dk+1;i<LIMIT;i++)//遍历每一个子序列
		{
			//对子序列进行直接插入排序
			if(a[i]<a[i-dk])//如果此序列需要排序
			{
				a[0]=a[i];//需要插入的元素存放在a[0]中
				for(j = i-dk;(j>=1)&&(a[j]>a[0]);j-=dk)//向后面挪位置
				{
					a[j+dk]=a[j];
				}
				//j+dk为最新挪出来的位置
				a[j+dk]=a[0];//@@注意别写成a[j+1]
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
	//	if(a[i-1]>a[i])//找到下一下需要插入的值
	//	{
	//		a[0]=a[i];
	//		for(j=i-1;a[0]<a[j];--j)//在有序队列中找到要插入的位置
	//		{
	//			a[j+1]=a[j];
	//		}
	//		a[j+1]=a[0];
	//	}
//half insert sort
//for(i=2;i<LIMIT;i++)//书中p271是 i<=LIMIT
	//{
	//	a[0]=a[i];
	//	low=1;
	//	high=i-1;

	//	/*if(a[i-1]>a[i])//影响不大 不用加
	//	{*/
	//		while(low<=high)//折半法找到插入位置为high+1
	//		{
	//			mid = (low+high)/2;
	//			if(a[0]<a[mid])
	//				high=mid-1;
	//			else
	//				low=mid+1;
	//		}
	//		for(j=i-1;j>=high+1;--j)//吧high+1开始的数据向后搬移（会覆盖a[i]）
	//		{
	//			a[j+1]=a[j];
	//		}
	//		a[high+1]=a[0];//在high+1处放入插入的数据
	//	//}
	//}
//HILL SORT P271
	//for(int dk=LIMIT/2;dk>=1;dk=dk/2)
	//{
	//	for(i=dk+1;i<LIMIT;++i)//修改i<=LIMIT
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