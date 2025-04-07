#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Liste
{
   int sayi;
   struct Liste *next;
}Liste;

Liste* Ekleme_son(Liste *li,int sayi1){
    Liste *ilk, *son,*gecici;
    gecici=(Liste*)malloc(sizeof(Liste));
    if (gecici==NULL)
    {
        printf("Dinamik tahsis hatasi\n");
        exit(1);
    }
    ilk=li;
    gecici->sayi=sayi1;
    gecici->next=NULL;
    if (ilk==NULL)
    {
       ilk=gecici;
       return ilk;
    }
    son=ilk;
    while (son->next!=NULL)
    {
        son=son->next;
    }
    son->next=gecici;
    son=gecici;
    return ilk;
}

Liste* Ekleme_orta(Liste *li,int sayi1){
    Liste *ilk, *son,*gecici,*once;
    gecici=(Liste*)malloc(sizeof(Liste));
    if (gecici==NULL)
    {
        printf("Dinamik tahsis hatasi\n");
        exit(1);
    }
    ilk=li;
    gecici->sayi=sayi1;
    gecici->next=NULL;
    if (ilk==NULL  || sayi1<ilk->sayi)
    {
       gecici->next=ilk;
       ilk=gecici;
       return ilk;
    }
    son=ilk;
    once=ilk;
    while (son!=NULL&&sayi1>son->sayi)
    {
        once=son;
        son=son->next;
    }
    once->next=gecici;
    gecici->next=son;
    return ilk;
}

void print(Liste *li){
    Liste *gecici;
    gecici=li;
    while (gecici!=NULL)
    {
        printf("[%d]->",gecici->sayi);
        gecici=gecici->next;
    }
    printf("NULL");
    printf("\n");
}


int liste_var(Liste *ilk,int sayi1){
    int var=0;
    while (ilk!=NULL)
    {
        if (ilk->sayi==sayi1)
        {
            var=1;
        }
        ilk=ilk->next;
    }
    if (var==1)
        return 1;
    else
        return 0;
}

Liste *Birlesme(Liste *L1,Liste *L2){
    Liste *gecici1,*gecici2,*L3;
    L3=NULL;
    gecici1=L1;
    gecici2=L2;

    while (gecici1!=NULL)
    {
        if (liste_var(L3,gecici1->sayi)==0)
        {
            L3=Ekleme_orta(L3,gecici1->sayi);
        }
        gecici1=gecici1->next;
    }

    while (gecici2!=NULL)
    {
        if (liste_var(L3,gecici2->sayi)==0)
        {
            L3=Ekleme_orta(L3,gecici2->sayi);
        }
        gecici2=gecici2->next;
    }
    return L3;
}



int main(){
    Liste *liste1=NULL;
    Liste *liste2=NULL;
    Liste *liste3=NULL;
    Liste *gecici;
    liste1=Ekleme_son(liste1,8);
    liste1=Ekleme_son(liste1,3);
    liste1=Ekleme_son(liste1,6);
    liste1=Ekleme_son(liste1,2);
    liste1=Ekleme_son(liste1,1);
    liste2=Ekleme_son(liste2,6);
    liste2=Ekleme_son(liste2,5);
    liste2=Ekleme_son(liste2,0);
    liste2=Ekleme_son(liste2,20);
    print(liste1);
    print(liste2);
    liste3=Birlesme(liste1,liste2);
    print(liste3);
    
    
    return 0;
}