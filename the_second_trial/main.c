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
    cap = 4;
    for(int i = 0; i< 2; ++i){
        if(i == 0){
            while(cap < 33){
                fifo();
                cap++;
            }
        }
        else{
            //lur;
        }
    }
    print();
    return 0;
}


