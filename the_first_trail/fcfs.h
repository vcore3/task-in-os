#pragma once
#include "proc.h"
#include "crqe.h"

void FCFS(){
    if(head == NULL){
        printf("当前没有进程在运行\n");
    }
    struct PCB *front = NULL;
    printf("**********************************************\n");
    printf("进程id 到达时间 等待时间 运行时间 完成时间\n");
    while(head != NULL){
        if(front == NULL){
            head->start_time = head->arrive_time;
        }
        else{
            head->start_time = head->arrive_time < front->complete_time ? front->complete_time : head->arrive_time;
        }
        head->complete_time = head->start_time + head->bust_time;
        head->waite_time = head->start_time - head->arrive_time;
        head->id > 9 ? printf("  %d   ",head->id) : printf("  %d    ",head->id);
        head->arrive_time > 9 ? printf("   %d    ",head->arrive_time) : printf("   %d     ",head->arrive_time);
        head->waite_time > 9 ? printf("   %d    ",head->waite_time) : printf("   %d     ",head->waite_time);
        head->bust_time > 9 ? printf("   %d    ",head->bust_time) : printf("   %d     ",head->bust_time);
        printf("   %d\n",head->complete_time);
        if(front != NULL)free(front);
        front = head;
        head = head->next;
    }
    if(front != NULL)free(front);
    printf("**********************************************\n");
}

