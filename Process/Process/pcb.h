//
//  pcb.h
//  Process
//
//  Created by qiaoyao on 15/6/9.
//  Copyright (c) 2015年 qiaoyao. All rights reserved.
//

#ifndef __Process__pcb__
#define __Process__pcb__

#include <stdio.h>
#include <stdlib.h>

struct pcb{
    char _name[10];
    char _state;
    int _super;
    int _ntime;
    int _rtime;
    struct pcb * next;
    struct pcb * last;
};

typedef struct pcb PCB;

PCB* initPCB();
int getSize(PCB * pcb);
void insertPCB(PCB * pcb,int __super);
void show(PCB * pcb);

void freePCB(PCB * p,PCB * free_p);

#endif /* defined(__Process__pcb__) */
