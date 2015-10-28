#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include "myFile.h"
void copyFile()
{
	void copyFileByName(char filenameRead[20],char filenameWrite[20]);
	char filenameRead[20],filenameWrite[20];
	printf("Please input the readed file name -->");
	scanf("%s",filenameRead);
	getchar();
	printf("Please input the writed file name -->");
	scanf("%s",filenameWrite);
	getchar();
	copyFileByName(filenameRead,filenameWrite);
}
void copyFileByName(char filenameRead[20],char filenameWrite[20])
{
	FILE *fp_read,*fp_write;
	char ch;
	if( (fp_read = fopen(filenameRead,"r")) == NULL)
	{
		printf("can't open readed file : %s",filenameRead);
		return;
	}
	if( (fp_write = fopen(filenameWrite,"w")) == NULL)
	{
		printf("can't open writed file : %s",filenameWrite);
		fclose(fp_read);
		return;
	}
	printf("===========copy==========\n");
	while ((ch = fgetc(fp_read))!=EOF)
	{
		putchar(ch);
		fputc(ch,fp_write);
	}
	printf("\n===========end==========\n");
	fclose(fp_read);
	fclose(fp_write);
	return;
}