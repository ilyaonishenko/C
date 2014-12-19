//
//  func.h
//  laba10
//
//  Created by Ilya Onishenko on 19.12.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#ifndef __laba10__func__
#define __laba10__func__

#include <stdio.h>
#include <iostream>
#include <fstream>
struct Drugstore
{
    int ident;
    char name[80];
    int postDay;
    int postMonth;
    int numbers;
    int receipt;
    double price;
    int isIt;
    int preOrder;
    int preCustomers;
};

Drugstore* adding(Drugstore* Obj, const int amount);
void setDrugstore(Drugstore* Obj, const int amount);
void showDrugstore(Drugstore* Obj, const int amount);
void writeInFile(Drugstore* Obj,const int amount);
void readFromFile(Drugstore* Obj,const int amount);
int charToInt(char* buff,int num);
double charToDouble(char* buff,int num);

#endif /* defined(__laba10__func__) */
