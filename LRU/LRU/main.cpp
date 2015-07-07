//
//  main.cpp
//  LRU
//
//  Created by qiaoyao on 15/7/4.
//  Copyright (c) 2015年 qiaoyao. All rights reserved.
//

#define MAXSIZE    20
#include <iostream>

using namespace std;

int n;

int main()
{
    int input=0;                                   //用于输入作业号
    int worknum=0;                                 //输入的作业个数
    int storesize=0;                               //系统分配的存储区块数
    int interrupt=0;                               //缺页中断次数
    int stack[MAXSIZE];                            //栈，LRU算法的主要数据结构
    int workstep[MAXSIZE];                         //记录作业走向
    /*初始化*/
    for(int i=0;i<MAXSIZE;i++)
    {
        stack[i]=0;
        workstep[i]=-1;
    }
    cout<<"请输入存储区块数：";
    cin>>storesize;
    cout<<"请输入作业的页面走向（输入-1结束）：\n";
    for(int j=0;j<MAXSIZE;j++)
    {
        cout<<"页面号 "<<j+1;
        cin>>input;
        workstep[j]=input;
        if(input==-1)
        {
            cout<<"输入结束！\n";///
            break;
        }
        worknum++;////////
    }
    if(workstep[0]==0)
    {
        cout<<"未输入任何作业，系统将退出！\n";
        return 03;
    }
    cout<<"置换情况如下：\n";
    for(int k=0;k<worknum;k++)
    {
        /*在栈中找相等的页号或空位置*/
        for(int l=0;l<storesize;l++)
        {
            /*是否有相等的页号*/
            if(stack[l]==workstep[k])
            {
                cout<<"内存中有"<<workstep[k]<<"号页面，无须中断！\n";
                goto step1;
            }
            /*找栈中是否有空位置*/
            if(stack[l]==0)
            {
                stack[l]=workstep[k];
                cout<<"发生中断，但内存中有空闲区，"<<workstep[k]<<"号页面直接调入！\n";
                interrupt++;
                
                n = l;
                
                goto step2;
            }
        }
        /*上述情况都不成立则调出栈顶，将调入页面插入栈顶*/
        cout<<"发生中断，将"<<stack[0]<<"号页面调出，"<<workstep[k]<<"号装入！\n";
        interrupt++;
        /*新掉入的页面放栈顶*/
        
        
    step2:
        if(n>storesize){
            cout<<"error"<<endl;
            return 0;
        }
        for(int m=n;m<storesize;m++){
            stack[m]=stack[m+1];
        }
        stack[storesize-1]=workstep[k];
        cout<<"作业"<<worknum<<"个，"<<"中断"<<interrupt<<"次，"<<"缺页率："<<float(interrupt)/float(worknum)*100<<"%\n";
        
        return 0;
        
    step1:
        for(int m=0;m<storesize;m++)
        {
            
            stack[m]=stack[m+1];
        }
        stack[storesize-1]=workstep[k];
        
    }
    cout<<"作业"<<worknum<<"个，"<<"中断"<<interrupt<<"次，"<<"缺页率："<<float(interrupt)/float(worknum)*100<<"%\n";
}

void ss1(){
    for(){
        
    }
}

