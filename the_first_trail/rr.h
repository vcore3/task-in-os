#pragma once 
#include<stdlib.h>
#include<stdio.h>
#include "proc.h"
#include "crqe.h"

int turn_of_time = 2;

struct PCB *front;
void rr(){
    if(head == NULL)return;
    printf("*************************************************\n");
    printf("进程id 到达时间 服务时间 分配时间片 完成时间\n");
    int front_leave_time = head->arrive_time;
    while(head != NULL){
        if((head->count_time + 1) * turn_of_time >= head->bust_time){
            head->complete_time = front_leave_time + head->bust_time - (head->count_time * turn_of_time);
            head->count_time += 1;
            front_leave_time = head->complete_time;
            front = head;
            head = head->next;
            //printf("%p\n",head);
            printf("   %d       %d        %d       %d        %d   \n",front->id,front->arrive_time,front->bust_time,front->count_time,front->complete_time);
            free(front);
        }
        else{
            front_leave_time += turn_of_time;
            head->count_time += 1;
            if(head == fear)continue;
            fear->next = head;
            fear = fear->next;
            head = head->next;
            fear->next = NULL;
        }
    }
    printf("*************************************************\n");
}