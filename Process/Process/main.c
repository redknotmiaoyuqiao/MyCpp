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
    
    insertPCB(pcb ,6);
    insertPCB(pcb ,1);
    insertPCB(pcb ,2);
    insertPCB(pcb ,5);
    
    show(pcb);
    
    puts("hahah");

    
    //int size = getSize(pcb);
    
    //getPCB(pcb,3);
    
    //printf("%d" ,a->_super);
   
    int w = 1;
    while(w<=10){
        w++;
        for(int i=0;i<getSize(pcb);i++){
            PCB* p = _getPCB(pcb,i);
 /*
            p->_rtime++;
            
            if(p->_rtime==p->_ntime){
                freePCB(pcb ,p);
            }
            
            p->_super--;*/
        }
    }
    
}
