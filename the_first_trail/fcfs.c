//#pragma once
#include<stdio.h>
#include<stdlib.h>
#include "proc.h"
#include "crqe.h"
#include "fcfs.h"
struct PCB *head,*fear;



int main(){
    creat_process_queue();
    FCFS();
    return 0;
}