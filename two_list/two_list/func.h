//
//  func.h
//  two_list
//
//  Created by Ilya Onishenko on 29.11.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#ifndef __two_list__func__
#define __two_list__func__

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
typedef int bool;
enum { false, true };

struct lst_List {
    struct lst_Link* first;
    struct lst_Link* last;
    unsigned int size;
};

struct lst_Link {
    struct lst_Link* prev;
    struct lst_Link* next;
};
struct Data {
    int ident;
    char name[80];
    int postDay;
    int postMonth;
    int numbers;
    bool receipt;
    double price;
    bool isIt;
    bool preOrder;
    int preCustomers;
    
};
struct lst_Value {
    struct lst_Link lnk;
    //char* p;
    struct Data data;
};

/* инициализирует lst пустым */
void lst_init(struct lst_List* lst);

/* создает новый пустой список в свободной памяти */
struct lst_List* lst_create();

/* удаляет все элементы списка lst */
void lst_clear(struct lst_List* lst);

/* удаляет все элементы списка lst, а затем удаляет сам lst */
void lst_destroy(struct lst_List* lst);

/* добавляет элемент p в конец списка lst */
void lst_push_back(struct lst_List* lst, struct lst_Link* p);

/* вставляет элемент q перед элементом p в lst */
void lst_insert_before(struct lst_List* lst, struct lst_Link* p, struct lst_Link* q);

/* удаляет элемент p из списка lst
 возвращает указатель на узел, расположенный после узла p */
struct lst_Link* lst_erase(struct lst_List* lst, struct lst_Link* p);

/* возвращает элемент, находящийся через n узлов после узла p */
struct lst_Link* lst_get_next(struct lst_Link* p, int n);

/* возвращает элемент, находящийся до n узлов перед узлом p */
struct lst_Link* lst_get_prev(struct lst_Link* p, int n);

/* выделяем память для значения списка */
struct lst_Value* make_name(struct Data data);
#endif /* defined(__two_list__func__) */
