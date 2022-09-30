#pragma once
struct PCB{
    /* data */
    int id;//name of process    **********************************certain in input
    int pri;//priority   **********************************certain in input
    int all_time;//sum of time , a slice time；********calculate
    int bust_time;//runtime，a slice time；*******************certain in input
    int arrive_time;//arrive of process，slice time；***************certain in input
    int start_time;//starting excute；***********************calculate
    int waite_time;//during come into queue to start to excute*************calculate
    int complete_time;//completetime，time point；*********************calculate
    int state;//process of state
    int count_time; //count of slice time;
    struct PCB* next;
    /*  all_time = complete_time - arrive_time;
        waite_time = all_time - bust_time;
        complete_time = start_time + bust_time;
        start_time = if arrive_time > front_complete_time? arrive_time : front_complete_time;
    */
};