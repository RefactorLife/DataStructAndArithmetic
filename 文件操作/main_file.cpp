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
			flushall();//������뻺����
			switch(ch)
			{
				case 'a':
				case 'A':
					readFile();//˳���ȡָ���ļ�
					break;
				case 'b':
				case 'B':
					writFile();//����д���ļ���
					break;		
				case 'c':
				case 'C':
					copyFile();//�ļ�copy
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