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
    pcb = initPCB();
    
    insertPCB(pcb,7);
    insertPCB(pcb,5);
    insertPCB(pcb,8);
    insertPCB(pcb,1);
    insertPCB(pcb,5);
    
    
    //printf("%d",getSize(pcb));
    show(pcb);
}
