//
//  pcb.c
//  Process
//
//  Created by qiaoyao on 15/6/9.
//  Copyright (c) 2015年 qiaoyao. All rights reserved.
//

#include "pcb.h"

/////

PCB* initPCB(){
    PCB * pcb = (PCB*)malloc(sizeof(PCB));
    pcb->next = NULL;
    
    return pcb;
}

int getSize(PCB * pcb)
{
    PCB * p = pcb;
    int size = 0;
    while(p->next != NULL){
        p = p->next;
        size++;
    }
    return size;
}

void hello(){
    
}

void insertPCB(PCB * pcb,int __super)
{
    PCB * pr = (PCB*)malloc(sizeof(PCB));
    pr->_super = __super;
    pr->next = NULL;
    
    PCB * p = pcb;
    
    while(p->next != NULL){
        p = p->next;
    }
    
    p->next = pr;
    
 
}

void show(PCB * pcb)
{
    PCB * p = pcb;
    while(p->next != NULL){
        p = p->next;
        printf("%d\n",p->_super);
    }
}