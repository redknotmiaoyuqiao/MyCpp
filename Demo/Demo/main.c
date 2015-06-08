//
//  main.c
//  Demo
//
//  Created by qiaoyao on 15/6/8.
//  Copyright (c) 2015年 qiaoyao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "function.h"
#include "struct_demo.h"

PCB * ready = NULL;
PCB * p;

int main() {
    PCB * pr = malloc(sizeof(PCB));
    
    pr->state = 'c';
    pr->super = 1;
    pr->ntime = 15;
    pr->rtime = 17;
    
    
    disp(pr);
    return 0;
}
