//
//  main.cpp
//  laba10
//
//  Created by Ilya Onishenko on 19.12.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#include <iostream>
#include "func.h"
/*
 ввод с клавиатуры
 считывание из файла
 вывод параметров на экран
 вывод в файл стркутуры
 тестирование:
 если файла нет, то вбивать вручную
 иначе из файла
 вывод массива на экран
 массив в файл
 новый элемент с клавы
 вывести на экран
 вывод в файл
 тестирование без меню
 */
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int t=0;
    Drugstore* myDrugstore = 0;
    int number = 0;
    cout<<"Привет. В Вашей аптеке пусто. Что с ней делать - решать только Вам!"<<endl;
    while (t!=5) {
        cout<<"Меню:\n1)Считать из файла\n2)Ввести вручную\n3)Вывести на экран\n4)Вывести в файл\n5) Выход"<<endl;
        cout<<"Выберите:"<<endl;
        cin>>t;
        switch (t) {
            case 1:
                cout<<"Готовлюсь читать!"<<endl;
                cout<<"Сколько структур считать из файла?"<<endl;
                cin>>number;
                for (int i=0;i<number;i++)
                {
                    myDrugstore = adding(myDrugstore, i);
                    readFromFile(myDrugstore, number);
                }
                cout<<"Готово!"<<endl;
                break;
            case 2:
                cout<<"Вводим вручную"<<endl;
                myDrugstore = adding(myDrugstore, number);
                setDrugstore(myDrugstore, number);
                number++;
                break;
            case 3:
                cout<<"Что получилось?"<<endl;
                showDrugstore(myDrugstore, number);
                break;
            case 4:
                cout<<"Вывожу в файл"<<endl;
                writeInFile(myDrugstore, number);
                cout<<"Готово!"<<endl;
                break;
            case 5:
                cout<<"good bye!"<<endl;
                break;
            default:
                cout<<"Вы промахнулись"<<endl;
                break;
        }
    }
    return 0;
    
}
