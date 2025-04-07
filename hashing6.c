#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define Max_size 7

typedef struct Student
{
   int index;
   int element[Max_size];
   struct Student *link;
}Student;

typedef struct Tbl
{
    Student satirlar[Max_size];
}Tablo;

Tablo table;

unsigned int hash_function(int sayi){
   return sayi%Max_size;
}

void initialised_Table(Tablo *table)
{
    for (int i = 0; i < Max_size; ++i)
    {
        table->satirlar[i].index=-1;
        table->satirlar[i].link=NULL;
    }
}


void add_student (Tablo *table,int sayi){
    //Student *student=create_new_student(name,number);
    Student *student;
    unsigned int index1=hash_function(sayi);
    if (table->satirlar[index1].index==-1)
    {
        table->satirlar[index1].index=sayi;
    }
    else
    {
        for (int  i = Max_size; i>0; i--)
        {
            if (table->satirlar[i].index==-1)
            {
                table->satirlar[i].index==-1;
                table->satirlar[i].index=sayi;
                table->satirlar[index1].link=&table->satirlar[i];
                break;
            }
            
        }
        
    }
}
