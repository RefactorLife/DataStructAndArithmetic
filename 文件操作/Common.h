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
void Common_main_test();//����Common�к����Ĳ���
void color(const unsigned short color1);
void show_time_cost(double time);
double cal_time(double time);//���ڼ���һ���㷨����ʱ��

/*��ɫ��Ӧֵ�� 
����0=��ɫ                8=��ɫ����
  ��1=��ɫ                9=����ɫ                ����                        
����2=��ɫ                10=����ɫ        0xa        ����
����3=����ɫ		      11=��ǳ��ɫ      0xb��
����4=��ɫ                12=����ɫ        0xc����
����5=��ɫ                13=����ɫ        0xd        ����
����6=��ɫ                14=����ɫ        0xe        ����
����7=��ɫ                15=����ɫ        0xf 
����Ҳ���԰���Щֵ���óɳ�����
*/