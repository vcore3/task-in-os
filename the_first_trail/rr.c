#include<stdio.h>
#include<stdlib.h>
#include "proc.h"
#include "crqe.h"
#include "rr.h"


int main(){
    creat_process_queue();
    rr();
    return 0;
}