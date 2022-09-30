//#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include "proc.h"
#include "crqe.h"
#include "fcfs.h"
struct PCB *head,*fear;



int main(){
    srand((unsigned)time(NULL));
    int n = rand() % 4 + 1;
    int i = 1;
    while(i <= n){
        printf("              Testing No.%d                   \n",i);
        creat_process_queue();
        FCFS();
        i++;
        sleep(1);
    }
    return 0;
}