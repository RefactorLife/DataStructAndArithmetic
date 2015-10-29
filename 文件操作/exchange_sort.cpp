#include "Common.h"
#include "sort.h"

void bubble(int a[])
{
	// 1 2 3 4 5 6 7
	// |_|_|_|_|_|_| �Ӹߵ��� ���αȽϽ�������
	//   |_|_|_|_|_|
	//     |_|_|_|_| ...
	//�ռ临�Ӷȣ�O��1�� ʱ�临�Ӷ�O��n^2��  
	//�ȶ������㷨
	bool isSwaped;
	tag("ð������");
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
//��������
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
	a[low] = privot; // low Ϊ����������λ��
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
	//����ʱ��
	double time=0;
	get_rand_array_int(a,MIN_NUM,MAX_NUM,LIMIT);//����һ���������
	printf("����ǰ����--->\n");
	show_array_int(a,LIMIT);
	time = cal_time(0.0);
	switch(ch)
	{
		case 'a':	
			bubble(a);
			break;
		case 'b':	
			quick_sort(a,0,LIMIT-1);
			tag("��������");
			break;
		default:
			printf("unvalide operation!\n");
	}
	time = cal_time(time);
	printf("���������--->\n");
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
