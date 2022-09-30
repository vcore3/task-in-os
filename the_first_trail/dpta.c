#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include "proc.h"
#include "cfdpta.h"
#include "dpta.h"


int main(){
    srand((unsigned)time(NULL));
    int i=1;
    int n = rand() % 5 + 1;
    while(i <= n){
        printf("              Testing No.%d                   \n",i);
        creat_process_queue_for_dpta();
        dpta();
        i+=1;
        sleep(1);
    }
    return 0;
}