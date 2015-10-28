#include "myFile.h"
#include "Common.h"
void main_file()
{
	char ch;
		while(1)
		{
			tag("File_test");
			printf(" a.readFile()\n b.writeFile()\n c.copyFile()\n");
			while ((ch = getchar())=='\r');
			flushall();//清空输入缓冲区
			switch(ch)
			{
				case 'a':
				case 'A':
					readFile();//顺序读取指定文件
					break;
				case 'b':
				case 'B':
					writFile();//逐字写入文件中
					break;		
				case 'c':
				case 'C':
					copyFile();//文件copy
					break;
				default:
					printf("unvalide operation!\n");
			}
			if(!isContinue())
			{
				return;
			}
		}
}