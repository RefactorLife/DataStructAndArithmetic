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
		printf(" a.main_file();\n d.testLineStruct();\n");
		printf(" y.sort_main();\n z.Common\n");
		printf("--->");
		while ((ch = getchar())=='\r');
		flushall();//«Âø’ ‰»Îª∫≥Â«¯
		switch(ch)
		{
			case 'a':
			case 'A':
				main_file();
				break;
			case 'b':
			case 'B':

			case 'c':
			case 'C':
				
			case 'D':
			case 'd':
				testLineStruct();
				break;
			case 'Y':
			case 'y':
				sort_main();
				break;
			case 'Z':
			case 'z':
				Common_main_test();
				break;
			default:
				printf("unvalide operation!\n");
		}
		if(!isContinue())
		{
			system("pause");
			exit(0);
		}
	}
}
