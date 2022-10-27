#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
#include "creat.h"
#include "data.h"
#include "work.h"
#include "print.h"


int main(int argc, char* argv[]){
    srand((unsigned)(time(NULL)));
    creat(addr);
    //for(int i = 0;i < 320; ++i)addr[i] = i;
    //for(int i = 0; i < 320; ++i)printf("%d ",addr[i]);
    //puts(" ");
    cap = 4;
    while(cap < 33){
        fifo();
        lru();
        cap++;
    }
    print();
    
    return 0;
}


