#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
#include "creat.h"
#include "data.h"
#include "work.h"



int main(int argc, char* argv[]){
    srand((unsigned)(time(NULL)));
    creat(addr);
    printf("%d\n",argc);
    cap = 4;
    for(int i = 0; i< 2; ++i){
        if(i == 0){
            while(cap < 33){
                fifo();
                cap++;
            }
            for(int j = 4; j < 32; ++j)printf("%.2f\n", rate_fifo[j]);
        }
        else{
            //lur;
        }
    }
    return 0;
}


