//���Ա�
#include "myLineStruct.h"
#include "Common.h"
bool insertCharList_1(CharList &L,int i,char ch)
{
	tag("bool insertCharList_1(CharList &L,int i,char ch)");
	//��Ԫ��ch���뵽���е�i��λ��
	if(i<1||i>L.length+1)
	{		
		printf("����λ�ò��Ϸ�\n");
		return false;
	}
	if(L.length>=LimitSize)
	{
		printf("�洢�ռ�����");
		return false;
	}
	for(int j = L.length-1;j>=i-1;j--)
	{
		L.data[j+1]=L.data[j];
	}
	L.data[i-1]=ch;
	L.length++;
	printf("����ɹ�");
	return true;
}
bool insertCharList(CharList &L,char ch)
{
	//��ʼ��Length
	if(L.length<0||L.length>LimitSize+1)
	{
		L.length = 0;
	}
	if(L.length>=LimitSize)
	{
		printf("�洢�ռ�����");
		return false;
	}
	L.data[L.length]=ch;
	L.length++;
	return true;
}
void showCharList(CharList &L)
{
	tag("void showCharList(CharList &L)");
	for(int i = 0;i<L.length;i++)
	{
		printf(" %d.%c",i,L.data[i]);
	}
	return ;
}