#pragma once
#include<stdlib.h>
#include<stdio.h>

void creat(int* addr){
    int i = 0;
    int m = rand() % 320;
    addr[i++] = m;
    addr[i] = addr[0] + 1;
    while(1){
        /*
        int m = rand() % 320;
        if(m > 318)continue;
        addr[i++] = m;
        if(i == 320)return;
        */
        i++;
        int m_ = rand() % (addr[i - 2] - 1);
        addr[i++] = m_;
        addr[i++] = m_ + 1;
        int m2 = (rand() % (319 - (m_ + 2)) + (m_ + 2));
        addr[i++] = m2;
        addr[i++] = m2 + 1;
        if(i >= 320)return;
    }
}