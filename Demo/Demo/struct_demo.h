//
//  struct_demo.h
//  Demo
//
//  Created by qiaoyao on 15/6/8.
//  Copyright (c) 2015年 qiaoyao. All rights reserved.
///Users/qiaoyao/cpp/Demo/Demo/function.c

#ifndef __Demo__struct_demo__
#define __Demo__struct_demo__

#include <stdio.h>

struct pcb{
    char name[10];
    char state;
    int super;
    int ntime;
    int rtime;
    struct pcb * link;
};

typedef struct pcb PCB;

#endif /* defined(__Demo__struct_demo__) */
