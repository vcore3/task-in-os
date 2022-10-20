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
    rate_fifo[cap] = (1.0 - 1.0 * all / 320) * 100.0;
}

void lru(){
    head = mx = 0;
    memset(mis, 0, sizeof(mis));
    memset(inq, 0, sizeof(inq));
    memset(t, 0, sizeof(t));
    inq[addr[0] % 32]= 1; mis[addr[0] % 32] += 1; mx += 1; que[0] = addr[0] % 32;t[que[0]] = 1;
    for(int i = 1; i < 320; i++){
        int cur = addr[i] % 32;
        if(inq[cur]){
            for(int j = 0; j < mx; ++j)t[que[j]] += 1;
            t[cur] = 1;
            for(int j = 0; j < mx; ++j)head = t[que[head]] > t[que[j]] ? head : j;
            continue;
        }
        mis[cur] += 1;
        if(mx < cap){
            que[mx++] = cur;
            inq[cur] = 1;
            for(int j = 0; j < mx; ++j)t[que[j]] += 1; 
        }
        else{
            inq[que[head]] = 0;
            t[que[head]] = 0;
            que[head] = cur;
            inq[cur] = 1;
            for(int j = 0;j < cap; ++j){t[que[j]] += 1; head = t[que[head]] > t[que[j]] ? head : j;}
        }
    }
    int all = 0;
    for(int i = 0; i < 32; i++)all += mis[i];
    rate_lur[cap] = (1.0 - 1.0 * all / 320) * 100.0;
}