#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "proc.h"
struct PCB *head,*fear;
void creat_process_queue_for_dpta(){
    head = fear = NULL;
    int n = rand() % 5 + 1;
    int front_arrive_time = 0;
    for(int i = 1; i<=n; ++i){
        if(i == 1){head= fear = (struct PCB*)malloc(sizeof(struct PCB)),head->count_time = 0,fear->next = NULL;
            fear->id = i; fear->pri = rand() % 99 + 1; fear->bust_time = rand() % 5 + 1; fear->arrive_time = front_arrive_time + rand() % 3 + 1;
            front_arrive_time = fear->arrive_time;
            continue;
        }
        else{
            fear->next = (struct PCB*)malloc(sizeof(struct PCB));
            //fear = fear->next;
            fear->next->count_time = 0;
        }
        //fear->next = NULL;
        fear->next->id = i; fear->next->pri = rand() %99 + 1; fear->next->bust_time = rand() % 5 + 1; fear->next->arrive_time = front_arrive_time + rand() % 3 + 1;
        front_arrive_time = fear->next->arrive_time;
        if(i == 1){continue;}
        fear->next->next = NULL;
        if(fear->next->pri > head->pri){fear->next->next = head; head = fear->next; fear->next = NULL; continue;}
        struct PCB *look = head;
        while(look->next != NULL && look->next->pri >= fear->next->pri)look = look->next;
        if(look == fear->next){
            fear = look;
            continue;
        }
        fear->next->next = look->next;
        look->next = fear->next;
        fear->next = NULL;
    }
}