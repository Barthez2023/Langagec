#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct polinom
{ 
    int katsayi;
    int us;
    struct polinom *sonraki;
} Polinomlar;

Polinomlar *Liste_ekle(Polinomlar *ilk,int katsayi1,int us1){

    Polinomlar *gecici,*son;
    gecici=(Polinomlar*)malloc(sizeof(Polinomlar));
    if (gecici==NULL)
    {
        printf("Dinamik tahsis hatasi\n");
        exit(1);
    }
    gecici->katsayi=katsayi1;
    gecici->us=us1;
    gecici->sonraki=NULL;
    if (ilk==NULL)
    {
        ilk=gecici;
        return ilk;
    }
    son=ilk;
    while (son->sonraki!=NULL)
    {
        son=son->sonraki;
    }
    son->sonraki=gecici;
    son=gecici;
    return ilk;
}

void print(Polinomlar *p){

    Polinomlar *gecici;
    gecici=p;
    while (gecici!=NULL)
    {
        printf("[%d][%d]->",gecici->katsayi,gecici->us);
        gecici=gecici->sonraki;
    }
    printf("NULL");
    printf("\n");
}

Polinomlar * Polinom_Topla(Polinomlar * p1, Polinomlar * p2) {
    Polinomlar *p3,*gecici,*gecici1;
    gecici=p1;
    gecici1=p2;
    p3=NULL;
  /*while (gecici!=NULL ||  gecici1!=NULL)
  {
    if (gecici!=NULL &&  (gecici1==NULL  || gecici->us>gecici1->us))
    {
        p3=Liste_ekle(p3,gecici->katsayi,gecici->us);
        gecici=gecici->sonraki;
    }
    else if (gecici1 != NULL && (gecici == NULL || gecici->us < gecici1->us))
    {
        p3=Liste_ekle(p3,gecici1->katsayi,gecici1->us);
        gecici1=gecici1->sonraki;
    }
    else if (gecici != NULL && gecici1 != NULL && gecici->us == gecici1->us)
    {
        p3=Liste_ekle(p3,gecici->katsayi+gecici1->katsayi,gecici->us);
        gecici1=gecici1->sonraki;
        gecici=gecici->sonraki;
    }
  }*/


   
   
    while (gecici!=NULL)
    {
        while (gecici1!=NULL)
        {
            if (gecici->us>gecici1->us)
            {
                p3=Liste_ekle(p3,gecici->katsayi,gecici->us);
                gecici=gecici->sonraki;
                break;
            }

            else if (gecici->us==gecici1->us)
            {
                p3=Liste_ekle(p3,gecici->katsayi+gecici1->katsayi,gecici->us);
                gecici1=gecici1->sonraki;
                gecici=gecici->sonraki;
                break;
            }
            else if (gecici->us<gecici1->us)
            {
                 p3=Liste_ekle(p3,gecici1->katsayi,gecici1->us);
                 gecici1=gecici1->sonraki;
             }
        }
        if (gecici1==NULL)
        {
            p3=Liste_ekle(p3,gecici->katsayi,gecici->us);
            gecici=gecici->sonraki;
        }
    }
    while (gecici==NULL && gecici1!=NULL)
    {
        p3=Liste_ekle(p3,gecici1->katsayi,gecici1->us);
        gecici1=gecici1->sonraki;
    }
    
    
   
    return p3;
}


int main(){
    Polinomlar *P1=NULL;
    Polinomlar *P2=NULL;
    Polinomlar *P3=NULL;
    int katsayi,us;
    char secim;
    printf("************************Birinci polinom aliyoruz**************************\n");
    while (1)
    {
        printf("polinom katsayi ve us girmek ister misin    evet(e):");
        scanf(" %c",&secim);
        if (secim=='e')
        {
            printf("katsayi girin:");
            scanf("%d",&katsayi);
            printf("us girin:");
            scanf("%d",&us);
            P1=Liste_ekle(P1,katsayi,us);
        }
        else
            break;
    }


    printf("************************Ikinci polinom aliyoruz**************************\n");
    while (1)
    {
        printf("polinom katsayi ve us girmek ister misin    evet(e):");
        scanf(" %c",&secim);
        if (secim=='e')
        {
            printf("katsayi girin:");
            scanf("%d",&katsayi);
            printf("us girin:");
            scanf("%d",&us);
            P2=Liste_ekle(P2,katsayi,us);
        }
        else
            break;
    }

    print(P1);
    print(P2);
    P3=Polinom_Topla(P1,P2);
    print(P3);

    return 0;
}