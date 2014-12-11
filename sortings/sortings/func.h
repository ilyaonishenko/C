//
//  func.h
//  sortings
//
//  Created by Ilya Onishenko on 10.12.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#ifndef __sortings__func__
#define __sortings__func__

#include <stdio.h>
#include <IOStream>
void quickSort(int arr[], int left, int right,int arr2[]);
void bubbleSort(int arr[],int arr2[],int n);
void showArray(int arr[],int n);
void createArray(int arr[],int n);
void copyArray (int arr[],int n, int arr2[]);
void wtfSort(int arr[],int n, int arr1[],int arr2[]);
#endif /* defined(__sortings__func__) */
