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


int * func(int i){
    int target[10] = {1,2,3,4,5};
    
    int * p = target;
    
    return p;
}

int main(int argc, const char * argv[]) {
    int * p = func(0);
    
    printf("%d",p[1]);
}
