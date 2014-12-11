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
    int *firstArray2 = new int[n1];
    int *firstArray3 = new int[n1];
    int *secondArray = new int[n2];
    int *secondArray2 = new int[n2];
    int *secondArray3 = new int[n2];
    int *thirdArray = new int[n3];
    int *thirdArray2 = new int[n3];
    int *thirdArray3 = new int[n3];
    for (int i=0;i<n1;i++)
        firstArray3[i]=0;
    for(int i=0;i<n2;i++)
        secondArray3[i]=0;
    for (int i=0;i<n3;i++)
        thirdArray3[i] = 0;
    double *arr1 = new double[5];
    double *arr2 = new double[5];
    double *arr3 = new double[5];
    srand(time(NULL));
    createArray(firstArray, n1);
    createArray(secondArray, n2);
    createArray(thirdArray, n3);
    copyArray(firstArray, n1, firstArray2);
    copyArray(secondArray, n2, secondArray2);
    copyArray(thirdArray, n3, thirdArray2);
    std::cout<<"Три массива заданы. Выберите сортировку."<<std::endl;
    int t = 0;
    while (t!=4)
    {
        std::cout<<"1)quickSort"<<std::endl;
        std::cout<<"2)bubbleSort"<<std::endl;
        std::cout<<"3)Сортировка с предварительным выбором"<<std::endl;
        std::cout<<"Выход"<<std::endl;
        std::cin>>t;
        switch (t) {
            case 1:
                copyArray(thirdArray2, n3, thirdArray);
                copyArray(secondArray2, n2, secondArray);
                copyArray(firstArray2, n1, firstArray);
                quickSort(firstArray, 0, n1, arr1);
                quickSort(secondArray, 0, n2, arr2);
                quickSort(thirdArray, 0, n3, arr3);
                std::cout<<"Количество сравнений в первом массиве: "<<arr1[0]<<std::endl;
                std::cout<<"Количество сравнений вo втором массиве: "<<arr2[0]<<std::endl;
                std::cout<<"Количество сравнений в третьем массиве: "<<arr3[0]<<std::endl;
                arr1[0]=0;
                arr2[0]=0;
                arr3[0]=0;
                break;
            case 2:
                copyArray(firstArray2, n1, firstArray);
                copyArray(secondArray2, n2, secondArray);
                copyArray(thirdArray2, n3, thirdArray);
                bubbleSort(firstArray, arr1, n1);
                bubbleSort(secondArray, arr2, n2);
                bubbleSort(thirdArray, arr3, n3);
                std::cout<<"Количество сравнений в первом массиве: "<<arr1[0]<<std::endl;
                std::cout<<"Количество сравнений вo втором массиве: "<<arr2[0]<<std::endl;
                std::cout<<"Количество сравнений в третьем массиве: "<<arr3[0]<<std::endl;
                arr1[0]=0;
                arr2[0]=0;
                arr3[0]=0;
                break;
            case 3:
                copyArray(firstArray2, n1, firstArray);
                copyArray(secondArray2, n2, secondArray);
                copyArray(thirdArray, n3, thirdArray);
                wtfSort(firstArray, n1, firstArray3, arr1);
                std::cout<<"Количество сравнений в первом массиве: "<<arr1[0]<<std::endl;
                wtfSort(secondArray, n2, secondArray3, arr2);
                std::cout<<"Количество сравнений вo втором массиве: "<<arr2[0]<<std::endl;
                wtfSort(thirdArray, n3, thirdArray3, arr3);
                std::cout<<"Количество сравнений в третьем массиве: "<<arr3[0]<<std::endl;
                arr1[0]=0;
                arr2[0]=0;
                arr3[0]=0;
                break;
            default:
                break;
        }
        
    }
    return 0;
}
