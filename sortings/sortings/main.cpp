//
//  main.cpp
//  sortings
//
//  Created by Ilya Onishenko on 10.12.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#include <iostream>
#include "func.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int n1=1000;
    int n2=5000;
    int n3=10000;
    int *firstArray = new int[n1];
    int *secondArray = new int[n2];
    int *thirdArray = new int[n3];
    int *exampleArray = new int[10];
    int *exampleArray2 = new int[10];
    int *exampleArray3 = new int[10];
    for (int i=0;i<10;i++)
        exampleArray3[i] = 0;
    int *arr1 = new int[5];
    int *arr2 = new int[5];
    int *arr3 = new int[5];
    srand(time(NULL));
    createArray(exampleArray, 10);
    copyArray(exampleArray, 10, exampleArray2);
    std::cout<<"Исходный массив:"<<std::endl;
    showArray(exampleArray, 10);
    //wtfSort(exampleArray, 10,exampleArray3,arr2);
//    quickSort(exampleArray, 0, 10, arr1);
    /*for (int i=0;i<n1;i++)
        firstArray[i]=rand()%500;
    for (int i=0;i<n2;i++)
        secondArray[i]=rand()%500;
    for (int i=0;i<n3;i++)
        thirdArray[i]=rand()%500;*/
    std::cout<<"Три массива заданы. Выберите сортировку."<<std::endl;
    int t = 0;
    while (t!=4)
    {
        std::cout<<"1)quickSort"<<std::endl;
        std::cout<<"2)bubbleSort"<<std::endl;
        std::cout<<"3)what2Sort"<<std::endl;
        std::cout<<"Выход"<<std::endl;
        std::cin>>t;
        switch (t) {
            case 1:
                arr1[0]=0;
                arr2[0]=0;
                arr3[0]=0;
                copyArray(exampleArray2, 10, exampleArray);
                /*quickSort(firstArray, 0, n1, arr1);
                quickSort(secondArray, 0, n2, arr2);
                quickSort(thirdArray, 0, n3, arr3);
                std::cout<<"Количество сравнений в первом массиве: "<<arr1[0]<<std::endl;
                std::cout<<"Количество сравнений вo втором массиве: "<<arr2[0]<<std::endl;
                std::cout<<"Количество сравнений в третьем массиве: "<<arr3[0]<<std::endl;*/
                std::cout<<"До сортировки"<<std::endl;
                showArray(exampleArray, 10);
                quickSort(exampleArray, 0, 9, arr1);
                std::cout<<"ПОСЛЕ сортировки"<<std::endl;
                showArray(exampleArray, 10);
                std::cout<<"Количество сравнений в третьем массиве: "<<arr1[0]<<std::endl;
                break;
            case 2:
                arr1[0]=0;
                arr2[0]=0;
                arr3[0]=0;
                copyArray(exampleArray2, 10, exampleArray);
                std::cout<<"До сортировки"<<std::endl;
                showArray(exampleArray, 10);
                bubbleSort(exampleArray, arr1, 10);
                std::cout<<"ПОСЛЕ сортировки"<<std::endl;
                showArray(exampleArray, 10);
                std::cout<<"Количество сравнений в третьем массиве: "<<arr1[0]<<std::endl;
                break;
            case 3:
                arr1[0]=0;
                arr2[0]=0;
                arr3[0]=0;
                copyArray(exampleArray2, 10, exampleArray);
                std::cout<<"До сортировки"<<std::endl;
                showArray(exampleArray, 10);
                wtfSort(exampleArray, 10, exampleArray3, arr1);
                std::cout<<"После сортировки"<<std::endl;
                showArray(exampleArray3, 10);
                std::cout<<"Количество сравнений в третьем массиве: "<<arr1[0]<<std::endl;
                break;
            default:
                break;
        }
        
    }
    
    /*for (int i=0;i<10;i++)
        std::cout<<exampleArray[i]<<" ";
    std::cout<<std::endl;
    quickSort(exampleArray, 0, 9,arr2);
    std::cout<<"i'llsort"<<std::endl;
    for (int i=0;i<10;i++)
        std::cout<<exampleArray[i]<<" ";
    std::cout<<std::endl<<arr2[0];*/
    return 0;
}
