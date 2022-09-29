#pragma once
struct PCB{
    /* data */
    int id;//进程名    **********************************事先确认
    int pri;//优先级   **********************************事先确认
    int all_time;//完成任务所需要的时间，时间片；********计算
    int bust_time;//服务时间，时间片；*******************事先确认
    int arrive_time;//进程到达时间，时刻；***************事先确认
    int start_time;//开始服务的时间；***********************计算
    int waite_time;//从进队到执行代码的这段等待时间*************计算
    int complete_time;//完成时间，时刻；*********************计算
    int state;//进程状态
    struct PCB* next;
    /*  all_time = complete_time - arrive_time;
        waite_time = all_time - bust_time;
        complete_time = start_time + bust_time;
        start_time = if arrive_time > front_complete_time? arrive_time : front_complete_time;
    */
};