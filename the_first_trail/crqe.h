#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "proc.h"
struct PCB *head,*fear;
void creat_process_queue(){
    head = fear = NULL;
    int n = rand() % 5 + 1;
    int front_arrive_time = 0;
    for(int i = 1; i<=n; ++i){
        if(i == 1)head= fear = (struct PCB*)malloc(sizeof(struct PCB)),head->count_time = 0;
        else{
            fear->next = (struct PCB*)malloc(sizeof(struct PCB));
            fear = fear->next;
            fear->count_time = 0;
        }
        fear->next = NULL;
        fear->id = i; fear->pri = rand(); fear->bust_time = rand() % 5 + 1; fear->arrive_time = front_arrive_time + rand() % 3 + 1;
        front_arrive_time = fear->arrive_time + 1;
    }
}