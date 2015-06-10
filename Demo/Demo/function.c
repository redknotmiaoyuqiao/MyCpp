//
//  function.c
//  Demo
//
//  Created by qiaoyao on 15/6/8.
//  Copyright (c) 2015年 qiaoyao. All rights reserved.
//

#include "function.h"

int space(PCB * ready){
    int l = 0;
    PCB * pr = ready;
    
    while (pr != NULL) {
        l++;
        pr = pr->link;
    }
    return l;
}

void input(PCB * p,PCB *ready){
    int num;
    printf("请输入进程数\n");
    
    scanf("%d",&num);
    
    for(int i=0;i<num;i++){
        printf("\n 进程号：%d \n",i);
        p = (PCB*)malloc(sizeof(PCB));
        printf("\n 进程名 \n");
        scanf("%s",p->name);
        
        printf("\n 优先级 \n");
        scanf("%d",&(p->super));
        
        printf("\n 运行时间 \n");
        scanf("%d",&(p->ntime));
        
        p->rtime = 0;
        p->state = 'w';
        p->link = NULL;
        
        sort(ready, p);
    }
}

void p_check(PCB * p,PCB * ready){
    
    printf("\n 正在运行的进程是 %s",p->name);
    disp(p);

    printf("\n 当前就绪队列状态是：\n");
    
    PCB * pr;
    pr = ready;
    
    while (pr != NULL) {
        disp(pr);
        pr = pr->link;
    }
}

void disp(PCB * pr){
    printf("\n qname \t state \t super \t ndtime \t runtime \n");
    printf("|%s\t",pr->name);
    printf("|%c\t",pr->state);
    printf("|%d\t",pr->super);
    printf("|%d\t",pr->ntime);
    printf("|%d\t",pr->rtime);
    printf("\n");
}

void sort(PCB * ready,PCB * p){
    PCB * first, * second;
    int insert = 0;
    
    if((ready == NULL)||((p->super)>(ready->super))){
        p->link = ready;
        ready = p;
    }else{
        first = ready;
        second = first->link;
        
        while(second != NULL){
            if((p->super)>(second->super)){
                p->link = second;
                first->link = p;
                second = NULL;
                insert = 1;
            }else{
                first = first->link;
                second = second->link;
            }
        }
        
        if(insert == 0){
            first->link = p;
        }
    }
}

void running(PCB * p ,PCB * ready){
    (p->rtime)++;
    if((p->rtime) == (p->ntime)){
        destroy(p);
    }else{
        (p->super)++;
        p->state = 'w';
        sort(ready,p);
    }
}

void destroy(PCB * p){
    printf("\n 进程 %s 已完成。\n",p->name);
    free(p);
}

