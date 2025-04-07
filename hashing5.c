#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include <math.h>

#define Max_size 11

typedef struct client
{
    int numero;
    char nom[50];
    char prenom[50];
}client;

client tab[Max_size];


void init_tab(){
    for (int i = 0; i < Max_size; i++)
    {
        tab[i].numero=-1;
        strcpy(tab[i].nom,"no mane");
        strcpy(tab[i].prenom,"no mane");
    }
}

int hash_fonction(int numara){

    int tmp,temp1,i=0,numara1;
    float temp3;
    numara1=numara;
    while (numara!=0)
    {
        numara=numara/10;
        i++;
    }
    temp1=numara1*numara1;
    tmp=temp1*(1/pow(10,i));
    temp3=temp1*(1/pow(10,i));
    
 return ((temp3-tmp)*pow(10,4));
}

int hash_fonction_ascii(char *adi){
    int sum=0;
    for (int i = 0; adi[i] !='\0'; i++)
    {
        sum+=adi[i];
    }
    int sum1=sum%10000;
    return sum1;
}

    

void ajouter(int numero,char nom[50], char prenom[50]){
    int hash_index,index;
    hash_index=hash_fonction(numero);
    index=hash_index%Max_size;
    if (tab[index].numero==-1)
    {
       tab[index].numero=numero;
        strcpy(tab[index].nom,nom);
        strcpy(tab[index].prenom,prenom);
    }
    else
    {
        while (tab[index].numero!=-1)
        {
            hash_index=hash_fonction(hash_index);
            index=hash_index%Max_size;
        }
        tab[index].numero=numero;
        strcpy(tab[index].nom,nom);
        strcpy(tab[index].prenom,prenom);
    }
}

void print(){
    for (int i = 0; i < Max_size; i++)
    {
        if (tab[i].numero==-1)
        {
            printf("[no Data,0]");
        }
        else
        {
            printf("[%d  , %s , %s]",tab[i].numero,tab[i].nom,tab[i].prenom);
        }
        printf("\n");
    }
}


char* arama(int numero){
    int hash_index,index;
    hash_index=hash_fonction(numero);
    index=hash_index%Max_size;
    if (tab[index].numero!=-1)
    {
        return tab[index].nom;
    }
    return "l'element recherche ne se trouve pas dans la ttable";
}




int main(){
    int n,i,number,numero;
    char nom[20];  
    char prenom[20];  
    init_tab();
    printf("Entrer le nombre de client: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Entrer le nom: ");
        scanf("%s",nom);
        printf("Entrer le prnom: ");
        scanf("%s",prenom);
        printf("Entrer le numero: ");
        scanf("%d",&number);
        ajouter(number,nom,prenom);
    }
    print();

    printf("Enter the number you are looking for:");
    scanf("%d",&numero);
    printf("The enter number corresponds to %s \n",arama(numero));
    
    
    printf("%d",hash_fonction_ascii("aaaa"));


    

return 0;
}




