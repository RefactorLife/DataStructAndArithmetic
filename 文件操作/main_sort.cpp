#include "Common.h"
#include "sort.h"
void sort_main()
{
	char ch;
	while(1)
	{
		tag("sort");
		printf("a.÷±Ω”≤Â»Î≈≈–Ú\n");
		printf("b.’€∞Î≈≈–Ú\n");
		while ((ch = getchar())=='\r');
		flushall();//«Âø’ ‰»Îª∫≥Â«¯
		switch(ch)
		{
			case 'a':
				direct_insert_sort();
				break;
			case 'b':
				half_insert_sort();
				break;
			case 'B':
			case 'c':
			case 'C':
			case 'D':
			case 'd':
			case 'e':
			case 'E':
			default:
				printf("unvalide operation!\n");
		}
		if(!isContinue())
		{
			return;
		}
	}

}