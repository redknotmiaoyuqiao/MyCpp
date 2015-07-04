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
    pcb->last = NULL;
    pcb->_super = -1;
    
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

PCB* _getPCB(PCB * pcb,int i){
    PCB* p = NULL;
    /*
    int j=0;
    while((p->next != NULL) && (j<=i)){
        p = p->next;
        j++;
    }
    
    printf("%d",p->_super);*/
    
    printf("%d",sizeof(pcb));
    return (int)pcb;
    //这里返回指针有问题？？ 
}

void insertPCB(PCB * pcb,int __super)
{
    PCB * pr = (PCB*)malloc(sizeof(PCB));
    pr->_super = __super;
    pr->next = NULL;
    
    PCB * p = pcb;
    
    while(p->next != NULL ){
        
       /* if(p->_super != -1 && p->last != NULL){
            if(((pr->_super)>((p->next)->_super))&&(((pr->_super)<((p->last)->_super)))){
                break;
            }
        }
        */
        p = p->next;
    }
    /*
    (p->last)->next = pr;
    pr->last = p->last;
    
    pr->next = p;
    p->last = pr;*/
    
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

void freePCB(PCB * p,PCB * free_p){
    
}