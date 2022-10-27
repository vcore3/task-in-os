#pragma once
#include "data.h"
#include<stdio.h>

void print(){
    puts("+--------------------------------------------------------+");
    puts("|                                                        |");
    puts("|                  Hit Rate Comparison                   |");
    puts("|                                                        |");
    puts("+-------------------+-----------------+------------------+");
    puts("|    Mem_size/KB    |    Algorithm    |    Hit Rate/%    |");
    puts("+-------------------+-----------------+------------------+");
    for(int i = 4; i<=32; ++i){
        printf("|                   |      FIFO       |      %.2f",rate_fifo[i]);
        if(rate_fifo[i] >= 10.0)printf("       |\n");
        else printf("        |\n");
        if(i < 10)printf("|         %d         ",i);
        else printf("|         %d        ",i);
        puts("+-----------------+------------------+");
        printf("|                   |      LRU        |      %.2f",rate_lur[i]);
        if(rate_lur[i] >= 10.0)printf("       |\n");
        else printf("        |\n");
        puts("+-------------------+-----------------+------------------+");
    }
}