#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define Max_size 6
unsigned int hash_index;

unsigned int hash_function(int n){
    return n%Max_size;
}
void init_hash_table(int tab[Max_size]){
    for (int i = 0; i < Max_size; i++)
    {
        tab[i]=-1;
    }
}

void add_student (int tab[Max_size],int number){
     hash_index=hash_function(number);
        while (tab[hash_index]!=-1)
        {
            hash_index = (hash_index + 1) % Max_size; // Boucle circulaire dans le tableau
        }
        tab[hash_index]=number;

        
}


void print(int tab[Max_size]){
    for (int i = 0; i < Max_size; i++)
    {
        if (tab[i]==-1)
        {
            printf("[no Data]\n");
        }
        else
        {
            printf("[%d]\n",tab[i]);
        }
        //printf("\n");
    }
}
void arama(int tab[Max_size],int number){
    hash_index=hash_function(number);
    int i=0;
    unsigned int start_index=hash_index;
    while (tab[hash_index]!=-1)
    {
       if (tab[hash_index]==number)
       {
            printf("I found your data %d to the index %d \n",number,hash_index);
            i=1;
            break;
       }
       hash_index = (hash_index + 1) % Max_size; // Boucle circulaire dans le tableau

       if (hash_index == start_index) { // Si on revient à l'indice initial
            break;
        }
    }     
    if (i!=1)
    {
        printf("I did not find your data '%d'.\n", number);
    }
     
}
    

int main(){
    int n,i,number,number1;
   int tab[Max_size];
    init_hash_table(tab);
    printf("Enter the number of student:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number:");
        scanf("%d",&number);
        add_student(tab ,number);
    }
    print(tab);

    printf("Enter the number you are looking for:");
    scanf("%d",&number1);
    arama(tab,number1);
    
return 0;
}

