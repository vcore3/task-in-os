#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "proc.h"
struct PCB *head,*fear;
void creat_process_queue(){
    head = fear = NULL;
    int n;
    printf("请输入就绪对列当中的进程数量\n");
    scanf("%d",&n);
    for(int i = 1; i<=n; ++i){
        if(i == 1)head= fear = (struct PCB*)malloc(sizeof(struct PCB)),head->count_time = 0;
        else{
            fear->next = (struct PCB*)malloc(sizeof(struct PCB));
            fear = fear->next;
            fear->count_time = 0;
        }
        fear->next = NULL;
        printf("请输入第%d个进程的id 优先级 服务时间 到达时间\n",i);
        scanf("%d %d %d %d",&(fear->id),&(fear->pri),&(fear->bust_time),&(fear->arrive_time));
    }
}