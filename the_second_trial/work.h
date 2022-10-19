#pragma once
#include<stdio.h>
#include<stdlib.h>
#include "data.h"


void fifo(){
    head = mx = 0;
    memset(mis, 0, sizeof(mis));
    memset(inq, 0, sizeof(inq));
    inq[addr[0] % 32]= 1; mis[addr[0] % 32] += 1; mx += 1; que[0] = addr[0] % 32;
    for(int i = 1; i < 320; i++){
        int cur = addr[i] % 32;
        if(inq[cur])continue;
        mis[cur] += 1;
        if(mx < cap){
            que[mx++] = cur;
            inq[cur] = 1;
        }
        else{
            inq[que[head]] = 0;
            que[head] = cur;
            inq[cur] = 1;
            head = (head + 1) % cap;
        }
    }
    int all = 0;
    for(int i = 0; i < 32; i++)all += mis[i];
    rate[cap] = (1.0 - 1.0 * all / 320) * 100.0;
}

