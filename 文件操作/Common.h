#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <math.h>
#include<time.h>
#define BLACK 0
#define WHIGHT 7
#define BLUE 1
#define DIM_YELLOW 14
#define DIM_BLUE 9
#define DIM_TINT_GREEN 11
bool isContinue();
void tag(char str[200]);
void show_array_int(int e[],int n);
void get_rand_array_int(int a[],int min,int max,int n);
void swamp_int(int *a,int *b);
void swap_int(int *a,int *b);
int get_random_int(int min,int max);
void Common_main_test();//用于Common中函数的测试
void color(const unsigned short color1);
void show_time_cost(double time);
double cal_time(double time);//用于计算一个算法所用时间

/*颜色对应值： 
　　0=黑色                8=灰色　　
  　1=蓝色                9=淡蓝色                　　                        
　　2=绿色                10=淡绿色        0xa        　　
　　3=湖蓝色		      11=淡浅绿色      0xb　
　　4=红色                12=淡红色        0xc　　
　　5=紫色                13=淡紫色        0xd        　　
　　6=黄色                14=淡黄色        0xe        　　
　　7=白色                15=亮白色        0xf 
　　也可以把这些值设置成常量。
*/