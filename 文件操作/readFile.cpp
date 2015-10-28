#include <stdio.h>
#include <stdlib.h>
#include "myFile.h"
#include "Common.h"
void readFile()
{
	void testFseek(FILE *fp);
	FILE *fp;
	char ch,filename[20];
	while(1)
	{
		printf("Please input a filename\n");
		scanf("%s",filename);
		getchar();//���ջس�
		if( (fp = fopen(filename,"r") )==NULL )
		{
			printf("can't open file \"%s\" \n",filename);
			continue;

		}
		testFseek(fp);
		printf("\n======this is the start of the file.======\n");
		while(!feof(fp))
		{
			ch=fgetc(fp);
			putchar(ch);
		}
		printf("\n======this is the end of the file.======\n");
		fclose(fp);
		if(!isContinue())
		{
			return;
		}
	}
}
//����fseek��������
void testFseek(FILE *fp)
{
	printf("\n________test fseek()_________\n");
	char ch;
	printf("\n===== fseek(fp,-3L,SEEK_END); =====\n");
	fseek(fp,-3L,SEEK_END);
		while(!feof(fp))
		{
			ch=fgetc(fp);
			putchar(ch);
		}
	rewind(fp);
	printf("\n===== fseek(fp,3L,SEEK_SET); =====\n");
	fseek(fp,3L,SEEK_SET);
		while(!feof(fp))
		{
			ch=fgetc(fp);
			putchar(ch);
		}
	rewind(fp);
	printf("\n===== fseek(fp,3L,SEEK_CUR); =====\n");
	fseek(fp,3L,SEEK_CUR);
		while(!feof(fp))
		{
			ch=fgetc(fp);
			putchar(ch);
		}
	rewind(fp);
}