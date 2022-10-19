#pragma once
#include "data.h"
#include<stdio.h>

void print(){
    puts("----------------------------------------------------------");
    puts("|                                                        |");
    puts("|                  Hit Rate Comparison                   |");
    puts("|                                                        |");
    puts("----------------------------------------------------------");
    puts("|    Mem_size/KB    |    Algorithm    |    Hit Rate/%    |");
    puts("----------------------------------------------------------");
    for(int i = 4; i<=32; ++i){
        printf("|                   |      FIFO       |      %.2f       |\n",rate_fifo[i]);
        if(i < 10)printf("|         %d         ",i);
        else printf("|         %d        ",i);
        puts("--------------------------------------");
        printf("|                   |      LUR        |      %.2f        |\n",rate_lur[i]);
        puts("----------------------------------------------------------");

    }
}