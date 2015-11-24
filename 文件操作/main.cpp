#include <stdio.h>
#include <stdlib.h>
#include "myFile.h"
#include "myDataStruct.h"
#include "Common.h"
#include "sort.h"
void main()
{
	char ch;
	while(1)
	{
		printf(" a.main_file();\n b.testLineStruct();\n");
		printf(" c.sort_main();\n d.Common\n");
		printf("--->");
		while ((ch = getchar())=='\r');
		flushall();//清空输入缓冲区
		switch(ch)
		{
			case 'a':
			case 'A':
				main_file();
				break;
			case 'b':
			case 'B':
				testLineStruct();
				break;
			case 'C':
			case 'c':
				sort_main();
				break;
			case 'D':
			case 'd':
				Common_main_test();
				break;
			default:
				show_warn("输入有误~");
		}
		if(!isContinue())
		{
			system("pause");
			exit(0);
		}
	}
}
