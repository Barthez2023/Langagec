#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define Max_size 7
unsigned int hash_index;

unsigned int hash_function(char *name){
    unsigned result=0;
    for (int i = 0; i < strlen(name); i++)
    {
        result+=name[i];
    }
    return result%Max_size;
}
void init_hash_table(char *strings[Max_size]){
    for (int i = 0; i < Max_size; i++)
    {
        strings[i] = (char *)malloc(20 * sizeof(char)); // Allouer de la mémoire pour chaque chaîne
        if (strings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for index %d\n", i);
            exit(EXIT_FAILURE);
        }
        strcpy(strings[i],"No data");
    }
}

void add_student (char *strings[Max_size],char* name){
     hash_index=hash_function(name);
        while (strcmp(strings[hash_index],"No data")!=0)
        {
            hash_index = (hash_index + 1) % Max_size; // Boucle circulaire dans le tableau
        }
        strcpy(strings[hash_index],name);

        
}


void print(char *strings[Max_size]){
    for (int i = 0; i < Max_size; i++)
    {
        if (strcmp(strings[i],"No data")==0)
        {
            printf("[no Data]\n");
        }
        else
        {
            printf("[%s]\n",strings[i]);
        }
        //printf("\n");
    }
}
void arama(char *strings[Max_size],char *name){
    hash_index=hash_function(name);
    int i;
    unsigned int start_index=hash_index;
    while (strcmp(strings[hash_index],"No data")!=0)
    {
       if (strcmp(strings[hash_index],name)==0)
       {
            printf("I found your data %s to the index %d \n",name,hash_index);
            i=1;
       }
       hash_index = (hash_index + 1) % Max_size; // Boucle circulaire dans le tableau

       if (hash_index == start_index) { // Si on revient à l'indice initial
            break;
        }

    }     
    if (i!=1)
    {
        printf("I did not find your data '%s'.\n", name);
    }
     
}
    

int main(){
    int n,i,number;
    char name[20];  
    char name1[20];  
    char *strings[Max_size]; 
    init_hash_table(strings);
    printf("Enter the number of student:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name:");
        scanf("%s",name);
        add_student(strings,name);
    }
    print(strings);

    printf("Enter the name you are looking for:");
    scanf("%s",name1);
    arama(strings,name1);
    
return 0;
}

