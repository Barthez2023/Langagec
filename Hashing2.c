#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define Max_size 7

typedef struct Student
{
   char name[20];
   int number;
   struct Student *next;
}Student;

typedef struct Table{
    Student **tab;
}Table;
    
Table hash_table;

Student *create_new_student(char *name ,int number){
    Student *student=(Student*)malloc(sizeof(Student));
    if (student!=NULL)
    {
        strcpy(student->name,name);
        student->number=number;
        student->next=NULL;
    }
    return student;
}

unsigned int hash_function(char *name){
    unsigned result=0;
    for (int i = 0; i < strlen(name); i++)
    {
        result+=name[i];
    }
    return result%Max_size;
}

/*void init_hash_table(Student **tab){
    for (int i = 0; i < Max_size; i++)
    {
        tab[i]=NULL;
    }
}*/

void initialised_Table(Table *hash_table) {
    // Allouer de la mémoire pour le tableau de pointeurs
    hash_table->tab = (Student **)malloc(Max_size * sizeof(Student *));
    if (hash_table->tab == NULL) {
        fprintf(stderr, "Memory allocation failed for hash table.\n");
        exit(EXIT_FAILURE);
    }

    // Initialiser chaque case à un pointeur valide
    for (int i = 0; i < Max_size; ++i) {
        hash_table->tab[i] = (Student *)malloc(sizeof(Student));
        if (hash_table->tab[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for hash table entry %d.\n", i);
            exit(EXIT_FAILURE);
        }
        // Initialiser les champs de chaque structure
        strcpy(hash_table->tab[i]->name, "No Name");
        hash_table->tab[i]->number = -1;
        hash_table->tab[i]->next = NULL;
    }
}


/*// Initialiser la table de hachage
void initialised_Table(Table *hash_table) {
    hash_table->tab = (Student **)malloc(Max_size * sizeof(Student *));
    for (int i = 0; i < Max_size; ++i) {
        hash_table->tab[i] = NULL; // Marquer toutes les cases comme vides
    }
}*/



void add_student (Table *hash_table,char* name, int number){
    Student *student=create_new_student(name,number);
    unsigned int index=hash_function(name);
    if (hash_table->tab[index]->number==-1) {
        hash_table->tab[index] = student; // Ajouter directement si la case est vide
    }
    else
    {   
        Student *current = hash_table->tab[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = student;
    }
}


void print(Table *hash_table){
    Student *ste;
    for (int i = 0; i < Max_size; i++)
    {
        if (hash_table->tab[i]->number==-1)
        {
            printf("[no Data,0]");
        }
        else
        {
            printf("[%s , %d]",hash_table->tab[i]->name,hash_table->tab[i]->number);
            ste=hash_table->tab[i]->next;
            while(ste!=NULL){ 
                printf("->[%s , %d]",ste->name,ste->number);
                ste= ste->next;
            }
            printf("->NULL");
        }
        printf("\n");
    }
}

int search(Table *hash_table,char *name){
    int hash_index,n,i;
    Student *ste;
    hash_index=hash_function(name);
    if (strcmp(hash_table->tab[hash_index]->name,name)==0)
    {
        return hash_table->tab[hash_index]->number;
    }
    else
    {
        ste=hash_table->tab[hash_index]->next;
        while (ste!=NULL)
        {
            if (strcmp(ste->name,name)==0)
            {
                return ste->number;
            }
            ste=ste->next;
        }
        
    }
    return -1;
}

int main(){
    int n,i,number;
    char name[20];  
    char name1[20]; 
    printf("hello") ;
    initialised_Table(&hash_table);    
    printf("Enter the number of student:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name:");
        scanf("%s",name);
        printf("Enter the number student's number:");
        scanf("%d",&number);
        add_student(&hash_table,name,number);
    }
    print(&hash_table);

    printf("Enter the name you are looking for:");
        scanf("%s",name1);
    printf("The number that corresponds to %s is : %d ",name1,search(&hash_table,name1));
    



}

