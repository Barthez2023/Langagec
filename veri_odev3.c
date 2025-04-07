#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define YBoyut 100

typedef struct Liste
{
    int sayi;
    struct Liste *sonraki;
}Liste;

typedef struct Yigin
{
    int indis;
    int eleman[YBoyut];
}Yigin;

Liste *ekle_liste(Liste *ilk,int sayi1){
    Liste *gecici;
    Liste *son;
    gecici=(Liste*)malloc(sizeof(Liste));
    if(gecici==NULL){
        printf("dinamik tahsis hatasi\n");
        exit(0);
    }
    gecici->sayi=sayi1;
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


Liste *cikar_liste(Liste *ilk){
    Liste *gecici;
    if (ilk==NULL)
    {
        printf("liste bos eleman yok\n");
        return ilk;
    }
    else
    {
        gecici=ilk;
        ilk=ilk->sonraki;
        free(gecici);
        return ilk;
    }
    
}

int bos_yigin(Yigin *yigin1){
    if (yigin1->indis==-1)
    {
        return -1;
    }
    else
        return 1;
}

int dolu_yigin(Yigin *yigin1){
    if (yigin1->indis>=YBoyut-1)
    {
        return -1;
    }
    else
        return 1;
}

void ekle_yigin(Yigin *yigin1 , int sayi){
    if (dolu_yigin(yigin1)==-1)
    {
        printf("yigin dolu element eklemezsiniz\n");
    }
    yigin1->indis++;
    yigin1->eleman[yigin1->indis]=sayi;
}

void listeme_yigin(Yigin *yigin1){
    if (bos_yigin(yigin1)==-1)
    {
        printf("yigin bos element yok\n");
    }
    for (int i = yigin1->indis; i >=0; i--)
    {
        printf("%d ",yigin1->eleman[i]);
    }
}

void print(Liste *li){
    Liste *gecici;
    gecici=li;
    while (gecici!=NULL)
    {
        printf("[%d]->",gecici->sayi);
        gecici=gecici->sonraki;
    }
    printf("NULL");
    printf("\n");
}

int main(){
    Liste *liste=NULL;
    Liste *gecici;
    Yigin *yigin;
    yigin->indis=-1;
    liste=ekle_liste(liste,5);
    liste=ekle_liste(liste,10);
    liste=ekle_liste(liste,15);
    gecici=liste;
    print(liste);
    while (gecici!=NULL)
    {
        ekle_yigin(yigin,gecici->sayi);
        gecici=gecici->sonraki;
    }
    listeme_yigin(yigin);
    
    return 0;
}