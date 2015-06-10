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
    int len;
    int h = 0;
    
    char ch;
    
    input(p,ready);
    
    len = space();
    
    printf("%d",len);
    
    while((len != 0) && (ready != NULL)){
        ch = getchar();
        h++;
        printf("\n The Execute Number : %d \n",h);
        
        p = ready;
        ready = p->link;
        
        p->link = NULL;
        p->state = 'R';
        
        p_check(p,ready);
        
        running(p ,ready);
        
        printf("press any key conuine");
        
        ch = getchar();
    }
    
    printf("mission complete!!");
    ch = getchar();
    
    return 0;
}
