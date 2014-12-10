//
//  main.c
//  two_list
//
//  Created by Ilya Onishenko on 29.11.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#include <stdio.h>
#include "func.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    struct lst_List lst_names;
    lst_names = *lst_create();
    struct lst_Link* curr = NULL;
    //lst_init(&lst_names);
    int t=0;
    while (t!=8) {
        printf("Меню:\n1)Заполнить самостоятельно\n2)Сохранить в текстовый файл\n3)Вывести на экран\n4)Считать из файла\n6)Удалить элемент\n7)Удалить список\n8)Выход\n");
        printf("Выберите:\n");
        scanf("%d",&t);
        switch (t) {
            case 1:
                printf("Заполните самостоятельно:\n");
                struct Data datas;
                printf("ID%\n");
                scanf("%d",&datas.ident);
                printf("Наличие. 1 - есть, 2 - нет\n");
                scanf("%d",&datas.isIt);
                printf("Название:\n");
                char wop[80];
                scanf("%s",wop);
                strcpy(datas.name,wop);
                printf("Как много в началии?\n");
                scanf("%d",&datas.numbers);
                printf("В какой день будет доставлено?\n");
                scanf("%d",&datas.postDay);
                printf("В какой месяц будет доставлено?\n");
                scanf("%d",&datas.postMonth);
                printf("Можно ли сделать предзаказ?1 - да, 2 - нет\n");
                scanf("%d",&datas.preOrder);
                printf("Как много людей сделали предзаказ?\n");
                scanf("%d",&datas.preCustomers);
                printf("Продаётся по рецепту или нет? 1 - да, 2 - нет\n");
                scanf("%d",&datas.receipt);
                printf("Сколько стоит?\n");
                scanf("%lf",&datas.price);
                lst_push_back(&lst_names, (struct lst_Link*)make_name(datas));
                break;
            case 2:
                printf("Сохарнить в файл\n");
                FILE* file = fopen("inputoutput.txt", "w");
                int size = lst_names.size;
                curr = lst_names.first;
                for (int i=0;i<size;i++)
                {
                    fprintf(file,"Id: %d\n",((struct lst_Value*)curr)->data.ident);
                    fprintf(file,"Наличие: %d\n",((struct lst_Value*)curr)->data.isIt);
                    fprintf(file,"Name: %s\n",((struct lst_Value*)curr)->data.name);
                    fprintf(file,"How many? %d\n",((struct lst_Value*)curr)->data.numbers);
                    fprintf(file,"when it will be ? (day) %d\n",((struct lst_Value*)curr)->data.postDay);
                    fprintf(file,"when it will be ? (month) %d\n",((struct lst_Value*)curr)->data.postMonth);
                    fprintf(file,"Can you preorder? %d\n",((struct lst_Value*)curr)->data.preOrder);
                    fprintf(file,"How many preCustomers? %d\n",((struct lst_Value*)curr)->data.preCustomers);
                    fprintf(file,"How much? %lf\n",((struct lst_Value*)curr)->data.price);
                    if(curr!=0)
                        curr=curr->next;
                }
                fclose(file);
                break;
            case 3:
                curr = lst_names.first;
                size = lst_names.size;
                printf("Размер списка: %d\n",size);
                for (int i=0;i<size;i++)
                {
                    printf("Id: %d\n",((struct lst_Value*)curr)->data.ident);
                    printf("Наличие: %d\n",((struct lst_Value*)curr)->data.isIt);
                    printf("Название: %s\n",((struct lst_Value*)curr)->data.name);
                    printf("Количество упаковок? %d\n",((struct lst_Value*)curr)->data.numbers);
                    printf("В какой день будет доставлено? %d\n",((struct lst_Value*)curr)->data.postDay);
                    printf("В какой месяц будет доставлено? %d\n",((struct lst_Value*)curr)->data.postMonth);
                    printf("Возможен ли предзаказ? %d\n",((struct lst_Value*)curr)->data.preOrder);
                    printf("Сколько человек предзаказали?%d\n",((struct lst_Value*)curr)->data.preCustomers);
                    printf("Стоймость %lf\n",((struct lst_Value*)curr)->data.price);
                    if(curr!=0)
                        curr=curr->next;
                }
                break;
            case 4:
                curr = lst_names.first;
                lst_clear(&lst_names);
                FILE* files = fopen("inputoutput.txt","r");
                struct Data what;
                curr = lst_names.first;
                int colda=0;
                char ququ[80];
                char qu[30];
                while (!feof(files))
                {
                    if (colda==0)
                    {
                        fgets(ququ, 80, files);
                        strcpy(qu, &ququ[4]);
                        //printf(qu);
                        what.ident =atoi(qu);
                        //printf("%d\n",what.ident);
                        colda++;
                        continue;
                    }
                    if (colda==1)
                    {
                        fgets(ququ, 80, files);
                        strcpy(qu, &ququ[16]);
                        what.isIt = atoi(qu);
                        //printf("%d\n",what.isIt);
                        colda++;
                        continue;
                    }
                    if (colda==2)
                    {
                        fgets(ququ, 80, files);
                        strcpy(what.name, &ququ[6]);
                        //printf(what.name);
                        colda++;
                        continue;
                    }
                    if (colda==3)
                    {
                        fgets(ququ, 80, files);
                        strcpy(qu,&ququ[10]);
                        what.numbers = atoi(qu);
                        //printf("%d\n",what.numbers);
                        colda++;
                        continue;
                    }
                    if (colda==4)
                    {
                        fgets(ququ, 80, files);
                        strcpy(qu, &ququ[24]);
                        what.postDay = atoi(qu);
                        //printf("%d\n",what.postDay);
                        colda++;
                        continue;
                    }
                    if (colda==5)
                    {
                        fgets(ququ, 80, files);
                        strcpy(qu, &ququ[26]);
                        what.postMonth = atoi(qu);
                        //printf("%d\n",what.postMonth);
                        colda++;
                        continue;
                    }
                    if (colda==6) {
                        fgets(ququ, 80, files);
                        strcpy(qu, &ququ[18]);
                        what.preOrder = atoi(qu);
                        //printf("%d\n",what.preOrder);
                        colda++;
                        continue;
                    }
                    if (colda==7)
                    {
                        fgets(ququ, 80, files);
                        strcpy(qu, &ququ[23]);
                        what.preCustomers =atoi(qu);
                        //printf("%d\n",what.preCustomers);
                        colda++;
                        continue;
                    }
                    if (colda==8)
                    {
                        fgets(ququ, 80, files);
                        strcpy(qu, &ququ[10]);
                        what.price = atof(qu);
                        //printf("%lf\n",what.price);
                        colda = 0;
                        lst_push_back(&lst_names, (struct lst_Link*)make_name(what));
                        continue;
                    }
                }
                printf("Все данные считаны из файла!\n");
                fclose(files);
                break;
            case 5:
                printf("Меня нет в меню\n");
                break;
            case 6:
                printf("Введите номер элемента, который нужно удалить (отсчёт с единицы)\n");
                int sizee = lst_names.size;
                printf("Размер списка: %d\n",sizee);
                curr = lst_names.first;
                int d=0;
                scanf("%d",&d);
                lst_erase(&lst_names, lst_get_next(lst_names.first, d));
                break;
            case 7:
                //не работает
                printf(("Полное удаление списка!\n"));
                lst_destroy(&lst_names);
                printf(("Список удалён!\n"));
                break;
            default:
                printf("Вы, вероятно, не туда нажали!\n");
                break;
        }
    }
    return 0;
}