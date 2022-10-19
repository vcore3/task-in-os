#pragma once
#include<stdbool.h>
int addr[335];//指令地址
int mis[35];//页面失效次数
bool inq[35];//页面是否在队列中
int que[35];//页面队列
int head;//要替换的头部
int mx;//队列当前最大值
int cap;//内存容量 
double rate[35];