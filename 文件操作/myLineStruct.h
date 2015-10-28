#define LimitSize 50
typedef struct
{
	char *data;
	int MaxSize,length;
}Str;
typedef struct
{
	char data[LimitSize];
	int length;
}CharList;
void showCharList(CharList &L);
bool insertCharList_1(CharList &L,int i,char ch);
bool insertCharList(CharList &L,char ch);