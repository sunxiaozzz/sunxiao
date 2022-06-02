#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define N 32

typedef struct DataType
{
    int id;
    char name[24];
    int age;
} DataType;

typedef struct
{
    DataType data[N];
    int length;
} SSlist;

void init_SSlist(SSlist *list)
{
   
    memset(list, 0, sizeof(list));
    list->length = 0;
}
void is_list_full(int length)
{
    if (length == N)
    {
        printf("顺序表空间已满");
        return;
    }
    
}

void is_list_empty(int length)
{
    
    if (length <= 0)
    {
        printf("顺序表为空");
        return;
    }
}

void insert_SSlist(SSlist *list, DataType *element)
{
    is_list_empty(list->length);
    list->data[list->length] = *element;
    list->length++;
    // list->data[list->length++] = element;
    return;
}

void SSlist_show(SSlist *list)
{
    is_list_full(list->length);

    //顺序表遍历
    for (int i = 0; i <list->length; i++)
    {
        printf("id = %d,name = %s,age = %d\n", list->data[i].id, list->data[i].name, list->data[i].age);
    }

    return;
}

int main(void)
{
    int cmd;
    SSlist *list = (SSlist *)malloc(sizeof(list));
    

    //初始化顺序表:
    init_SSlist(list);
    

    //顺序表录入
    while (1)
    {
        DataType *element = (DataType *)malloc(sizeof(element));
       

        printf("please input a id:\n");
        scanf("%d", &element->id);
        printf("please input a name:\n");
        scanf("%s", element->name);
        printf("please input a age:\n");
        scanf("%d", &element->age);
        insert_SSlist(list,element);
        
        printf("继续请输入'1'\n");
        scanf("%d", &cmd);
        if (cmd != 1)
        {
            break;
        }
    }

  
    SSlist_show(list);

    return 0;
}
