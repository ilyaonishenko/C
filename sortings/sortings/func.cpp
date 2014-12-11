//
//  func.cpp
//  sortings
//
//  Created by Ilya Onishenko on 10.12.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#include "func.h"
void showArray(int arr[], int n)
{
    for (int i=0;i<n;i++)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}
void createArray(int arr[],int n)
{
    for (int i=0;i<n;i++)
        arr[i]=rand()%100;
}
void copyArray(int arr[],int n,int arr2[])
{
    for (int i=0;i<n;i++)
        arr2[i]=arr[i];
}
void quickSort(int arr[], int left, int right,double arr2[]) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
            arr2[0]++;
        }
    };
    /* recursion */
    if (left < j)
        quickSort(arr, left, j,arr2);
    if (i < right)
        quickSort(arr, i, right,arr2);
    
}
void bubbleSort(int arr[],double arr2[],int n)
{
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
        {
            if (arr[j]<arr[i])
            {
                int tmp = 0;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j]=tmp;
                arr2[0]++;
            }
        }
}
void wtfSort(int arr[],int n,int arr1[],double arr2[])
{
    int count=0;
    int i1=0;
    int i2=0;
    int i11=0;
    int i22=0;
    int len = 0;
    for (int i=1;i<n;i++)
    {
        if (arr[i-1]<arr[i])
        {
            if (count==0)
                i1=i-1;
            count++;
            arr2[0]++;
        }
        else
        {
            if (count!=0)
            {
                i2 = i;
                if (len<i2-i1)
                {
                    i11=i1;
                    i22=i2;
                    len = i2-i1;
                    arr2[0]++;
                }
            }
            count = 0;
        }
    }
    for (int i=i1;i<i2;i++)
    {
        arr1[i] = arr[i];
        arr[i] = -1;
        
    }
    // метод погружения
    for (int i=0;i<n;i++)
    {
        if (arr[i]==-1)
            continue;
        for (int j=0;j<n;j++)
        {
            if (arr[i]>arr1[j])
            {
                if (arr1[j]==0)
                {
                    arr1[j]=arr[i];
                    arr2[0]++;
                    break;
                }
                else continue;
            }
        }
        for (int j=0;j<n;j++)
        {
            for (int j1=j+1;j1<n;j1++)
            {
                if (arr1[j1]<arr1[j])
                {
                    int tmp = 0;
                    tmp = arr1[j];
                    arr1[j] = arr1[j1];
                    arr1[j1]=tmp;
                    arr2[0]++;
                }
            }

        }
    }
}

