#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <math.h>
#include<time.h>
bool isContinue();
void tag(char str[200]);
void show_array_int(int e[],int n);
void get_rand_array_int(int a[],int min,int max,int n);
void swamp_int(int *a,int *b);
int get_random_int(int min,int max);
void Common_main_test();//用于Common中函数的测试
void color(const unsigned short color1);
double cal_time(double time);//用于计算一个算法所用时间