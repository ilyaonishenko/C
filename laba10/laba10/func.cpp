//
//  func.cpp
//  laba10
//
//  Created by Ilya Onishenko on 19.12.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#include "func.h"
using namespace std;
Drugstore* adding(Drugstore* Obj, const int amount)
{
    if (amount==0)
    {
        Obj = new Drugstore[1];// выделяем память для первой структуры
    }
    else
    {
        Drugstore* tempObj = new Drugstore[amount+1];
        for (int i=0;i<amount;i++)
        {
            tempObj[i] = Obj[i];
        }
        delete [] Obj;
        Obj = tempObj;
    }
    return Obj;
}
void setDrugstore(Drugstore* Obj, const int amount)
{
    cout<<"ID:"<<endl;
    cin>>Obj[amount].ident;
    cout<<"Название"<<endl;
    cin>>Obj[amount].name;
    cout<<"День доставки:"<<endl;
    cin>>Obj[amount].postDay;
    cout<<"Месяц доставки:"<<endl;
    cin>>Obj[amount].postMonth;
    cout<<"Количество лекарства сейчас"<<endl;
    cin>>Obj[amount].numbers;
    cout<<"Нужен ли рецепт?"<<endl;
    cin>>Obj[amount].receipt;
    cout<<"Цена"<<endl;
    cin>>Obj[amount].price;
    cout<<"Есть ли сейчас в наличии"<<endl;
    cin>>Obj[amount].isIt;
    cout<<"Возможен ли предзаказ"<<endl;
    cin>>Obj[amount].preOrder;
    cout<<"Сколько человек предзаказали"<<endl;
    cin>>Obj[amount].preCustomers;
}
void showDrugstore(Drugstore* Obj, const int amount)
{
    for (int i=0;i<amount;i++)
    {
        cout<<"ID:"<<" "<<Obj[i].ident<<endl;
        cout<<"Название"<<" "<<Obj[i].name<<endl;
        cout<<"День доставки:"<<" "<<Obj[i].postDay<<endl;
        cout<<"Месяц доставки:"<<" "<<Obj[i].postMonth<<endl;
        cout<<"Количество лекарства сейчас"<<" "<<Obj[i].numbers<<endl;
        cout<<"Нужен ли рецепт?"<<" "<<Obj[i].receipt<<endl;
        cout<<"Цена"<<" "<<Obj[i].price<<endl;
        cout<<"Есть ли сейчас в наличии"<<" "<<Obj[i].isIt<<endl;
        cout<<"Возможен ли предзаказ"<<" "<<Obj[i].preOrder<<endl;
        cout<<"Сколько человек предзаказали"<<" "<<Obj[i].preCustomers<<endl;
    }
}
void writeInFile(Drugstore* Obj,const int amount)
{
    ofstream fout("inputoutput.txt");
    for (int i=0;i<amount;i++)
    {
        fout<<"ID:"<<" "<<Obj[i].ident<<endl;
        fout<<"Название"<<" "<<Obj[i].name<<endl;
        fout<<"День доставки:"<<" "<<Obj[i].postDay<<endl;
        fout<<"Месяц доставки:"<<" "<<Obj[i].postMonth<<endl;
        fout<<"Количество лекарства сейчас"<<" "<<Obj[i].numbers<<endl;
        fout<<"Нужен ли рецепт?"<<" "<<Obj[i].receipt<<endl;
        fout<<"Цена"<<" "<<Obj[i].price<<endl;
        fout<<"Есть ли сейчас в наличии"<<" "<<Obj[i].isIt<<endl;
        fout<<"Возможен ли предзаказ"<<" "<<Obj[i].preOrder<<endl;
        fout<<"Сколько человек предзаказали"<<" "<<Obj[i].preCustomers<<endl;
        fout.close();
    }

}
void readFromFile(Drugstore* Obj,const int amount)
{
    ifstream fin("inputoutput.txt");
    char buff[100];
    char extrabuff[100];
    for (int i=0;i<amount;i++)
    {
        fin.getline(buff, 100);
        Obj[i].ident = charToInt(buff,3);
        fin.getline(buff, 80);
        strcpy(Obj[i].name, &buff[17]);
        fin.getline(buff,100);
        Obj[i].postDay = charToInt(buff, 27);
        fin.getline(buff,100);
        Obj[i].postMonth = charToInt(buff, 29);
        fin.getline(buff, 100);
        Obj[i].numbers = charToInt(buff, 53);
        fin.getline(buff,100);
        Obj[i].receipt = charToInt(buff, 30);
        fin.getline(extrabuff, 100);
        Obj[i].price = charToDouble(extrabuff, 8);
        fin.getline(extrabuff,100);
        Obj[i].isIt = charToInt(extrabuff, 45);
        fin.getline(buff,100);
        Obj[i].preOrder = charToInt(buff, 41);
        fin.getline(buff, 100);
        Obj[i].preCustomers = charToInt(buff, 55);
    }
}
int charToInt(char* buff,int num)
{
    char buff2[100];
    strcpy(buff2, &buff[num]);
    int intVar = atoi(buff2);
    return intVar;
}
double charToDouble(char* buff,int num)
{
    char buff2[100];
    strcpy(buff2,&buff[num]);
    double doubleVar = atof(buff2);
    return doubleVar;
}




















