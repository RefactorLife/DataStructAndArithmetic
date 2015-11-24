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
	//�˺��������ҳ�a[low] �ڷ�Χ�ڵ�λ�ã������� ����С��a[low]�������� ���ڵ�����
	//  5 1 2 4 6 7 8 2
	//  |->			  |�ҵ���һ���ڴ������е��м�ֵ
	//    |          �����ұ߿�ʼ�ҵ�С�� 5 �Ķ���a[low]����high--��
	//	  |->Ȼ��������ҵ����� 5 �� ����a[high]��(low++)
	//��˷��� ֱ�� when(low>high) a[low] = 5
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
		pivot = partition(a,low,high);//�ҵ�a[low]�����е�λ��
		quick_sort(a,low,pivot-1);//�Դ�λ��Ϊ�е㣬��߼�������
		quick_sort(a,pivot+1,high);//�ұ�Ҳ��������
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
