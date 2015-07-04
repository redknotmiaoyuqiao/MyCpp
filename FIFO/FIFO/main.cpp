//
//  main.cpp
//  FIFO
//
//  Created by qiaoyao on 15/7/4.
//  Copyright (c) 2015年 qiaoyao. All rights reserved.
//

#define MAXSIZE    20
#include <iostream>

using namespace std;

int main()
{
    int label=0;                        //标记此页是否已经装入内存
    int input=0;                        //用于输入作业号
    int worknum=0;                      //记录作业个数
    int storesize=0;                    //系统分配的存储块数
    int interrupt=0;                    //中断次数
    int quence[MAXSIZE];                //队列，FIFO算法的主要数据结构
    int workstep[MAXSIZE];              //用于记录作业走向
    /*初始化*/
    for(int i=0;i<MAXSIZE;i++)
    {
        quence[i]=0;
        workstep[i]=0;
    }
    cout<<"请输入存储区块数：";
    cin>>storesize;
    cout<<"请输入作业走向（输入0结束）：\n";
    for(int j=0;j<MAXSIZE;j++)
    {
        cout<<"页面号："<<j+1;
        cin>>input;
        workstep[j]=input;
        if(input==0)
        {
            cout<<"输入结束！\n";
            break;
        }
        
        worknum++;
    }
    if(workstep[0]==0)
    {
        cout<<"未输入任何作业，系统将退出！\n";
        return 0;
    }
    cout<<"置换情况如下：\n";
    for(int k=0;k<worknum;k++)
    {
        label=0;
        /*看队列中是否有相等的页号或空位置*/
        for(int l=0;l<storesize;l++)
        {
            /*是否有相等的页号*/
            if(quence[l]==workstep[k])
            {
                cout<<"内存中有"<<workstep[k]<<"号页面，无须中断！\n";
                label=1;                                                //标记此页面已装入内存
                break;
            }
            /*是否有空位置*/
            if(quence[l]==0)
            {
                quence[l]=workstep[k];
                cout<<"发生中断,但内存中有空闲区，"<<workstep[k]<<"号页面直接调入！\n";
                interrupt++;
                label=1;
                break;
            }
        }
        /*上述情况都不成立则调出对首，将调入页面插入对尾*/
        if(label==0)
        {
            cout<<"发生中断，将"<<quence[0]<<"号页面调出，"<<workstep[k]<<"号装入！\n";
            interrupt++;
            for(int m=0;m<storesize;m++)
            {
                quence[m]=quence[m+1];
            }
            quence[storesize-1]=workstep[k];
        }
    }
    cout<<"作业"<<worknum<<"个，"<<"中断"<<interrupt<<"次，"<<"缺页率："<<float(interrupt)/float(worknum)*100<<"%\n";
}
