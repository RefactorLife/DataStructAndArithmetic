#include <stdio.h>
#include <stdlib.h>
#include "myFile.h"
#include "Common.h"
void writFile()
{
	while(1)
	{
		FILE *out;
		char in,filename[20];
		printf("Please input a filename\n");
		scanf("%s",filename);
		getchar();
		if( (out = fopen(filename,"w")) == NULL)
		{
			printf("can't open the file!\n");
			exit(0);
		}
		printf("Please input the str you want to write in to file with(end with #):\n");
		printf("==================================\n");
		while( (in = getchar())!= '#')
		{
			fputc(in,out);
			//putchar(in);
		}
		fclose(out);
		printf("==================================\n");
		if(!isContinue())
		{
			return;
		}
	}
	


}
