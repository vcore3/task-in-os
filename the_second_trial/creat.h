#pragma once
#include<stdlib.h>
#include<stdio.h>

void creat(int* addr){
    int i = 0;
    while(1){
        int m = rand() % 320;
        if(m > 318)m = 318;
        addr[i++] = m + 1;
        if(i == 320)return;
        int m_ = rand() % (m+2);
        if(m_ > 317)m_ = 317;
        addr[i++] = m_;
        if(i == 320)return;
        addr[i++] = m_ + 1;
        if(i == 320)return;
        addr[i++] = rand() % (319 - (m_ + 2) + 1) + (m_ + 2);
        if(i == 320)return;
    }
}