//
//  main.c
//  Process
//
//  Created by qiaoyao on 15/6/9.
//  Copyright (c) 2015年 qiaoyao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "pcb.h"

PCB * pcb;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    puts("start");
    
    pcb = initPCB();
    
    insertPCB(pcb,5);
    insertPCB(pcb,1);
    insertPCB(pcb,15);
    insertPCB(pcb,20);
    insertPCB(pcb,4);
    insertPCB(pcb,22);
    
    int size = getSize(pcb);
    show(pcb);
    
    return 0;
}
