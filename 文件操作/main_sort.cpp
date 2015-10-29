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
		printf("c.œ£∂˚≈≈–Ú(≤Â»Î≈≈–Ú)\n");
		printf("d.√∞≈›≈≈–Ú£®Ωªªª≈≈–Ú£©\n");
		printf("e.øÏÀŸ≈≈–Ú£®Ωªªª≈≈–Ú£©\n");
		while ((ch = getchar())=='\r');
		flushall();//«Âø’ ‰»Îª∫≥Â«¯
		switch(ch)
		{
			case 'a':
				insert_sort('a');
				break;
			case 'b':
				insert_sort('b');
				break;
			case 'c':
				insert_sort('c');
				break;
			case 'D':
			case 'd':
				exchange_sort('a');//√∞≈›≈≈–Ú
				break;
			case 'e':
			case 'E':
				exchange_sort('b');//øÏÀŸ≈≈–Ú
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