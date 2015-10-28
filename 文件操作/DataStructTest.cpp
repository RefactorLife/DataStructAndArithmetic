#include <stdio.h>
#include "myDataStruct.h"
void testLineStruct()
{
	CharList L;
	for(int i=0;i<20;i++)
	{
		insertCharList(L,'a'+i);
	}
	showCharList(L);
	insertCharList_1(L,5,'#');
	showCharList(L);
	insertCharList_1(L,-1,'#');
	showCharList(L);
	insertCharList_1(L,50,'#');
	showCharList(L);
}