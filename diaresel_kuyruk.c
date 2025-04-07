#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Yboyut 100

typedef struct kuyruklar
{
    int son_indis;
    int ilk_indis;
    int count;
    int element[Yboyut];
} kuyruklar;

kuyruklar yeni_kuyruk;

int kuyruk_dolu(){
    if (yeni_kuyruk.count==Yboyut)

        return -1;
    else
        return 1;
}

int kuyruk_dolu2(kuyruklar *kuyruk1){
    if (kuyruk1->count==Yboyut)

        return -1;
    else
        return 1;
}


int kuyruk_bos(){
    if (yeni_kuyruk.count==0)

        return -1;
    else
        return 1;
}

int kuyruk_bos2(kuyruklar *kuyruk1){
    if (kuyruk1->count==0)

        return -1;
    else
        return 1;
}


void kuyruk_ekle(int sayi){
    if (kuyruk_dolu()==-1)
    {
        printf("kuyruk dolu element eklemezsiniz\n");
    }
    else
    {
        yeni_kuyruk.element[yeni_kuyruk.son_indis]=sayi;
        yeni_kuyruk.son_indis=(yeni_kuyruk.son_indis+1)%Yboyut;
        yeni_kuyruk.count++;
    }
}

void kuyruk_ekle2(kuyruklar *kuyruk1,int sayi){
    if (kuyruk_dolu2(kuyruk1)==-1)
    {
        printf("kuyruk dolu element eklemezsiniz\n");
    }
    else
    {
        kuyruk1->element[kuyruk1->son_indis]=sayi;
        kuyruk1->son_indis=(kuyruk1->son_indis+1)%Yboyut;
        kuyruk1->count++;
    }
}


int kuyruk_cikar(){
    int sayi;
    if(kuyruk_bos()==-1){
        printf("kuyruk bos element cikarmazsiniz\n");
        return-1;
    }
    else
    {
        sayi=yeni_kuyruk.element[yeni_kuyruk.ilk_indis];
        yeni_kuyruk.ilk_indis=(yeni_kuyruk.ilk_indis+1)%Yboyut;
        yeni_kuyruk.count--;
        return sayi;
    }
}

int kuyruk_cikar2(kuyruklar *kuyruk1){
    int sayi;
    if(kuyruk_bos2(kuyruk1)==-1){
        printf("kuyruk bos element cikarmazsiniz\n");
        return-1;
    }
    else
    {
        sayi=kuyruk1->element[kuyruk1->ilk_indis];
        kuyruk1->ilk_indis=(kuyruk1->ilk_indis+1)%Yboyut;
        kuyruk1->count--;
        return sayi;
    }
}


void listeleme(){
    if (kuyruk_bos()==-1)
    {
        printf("kuyruk bos hic element cikartirmaz\n");
    }
    else
    {
        for (int i = 0; i < yeni_kuyruk.count; i++)
        {
            printf("\n: %d",yeni_kuyruk.element[(yeni_kuyruk.ilk_indis+i)%Yboyut]);
        }
        
    }
}

void listeleme2(kuyruklar *kuyruk1){
    if (kuyruk_bos2(kuyruk1)==-1)
    {
        printf("kuyruk bos hic element cikartirmaz\n");
    }
    else
    {
        for (int i = 0; i < kuyruk1->count; i++)
        {
            printf("\n: %d",kuyruk1->element[(kuyruk1->ilk_indis+i)%Yboyut]);
        }
    }
}


int main(){
    int i;
    char secim;
    int numara;
    yeni_kuyruk.son_indis=0;
    yeni_kuyruk.ilk_indis=0;
    yeni_kuyruk.count=0;
    kuyruklar *kuyruk;
    // Allocation de mémoire pour la file
    kuyruk = (kuyruklar *)malloc(sizeof(kuyruklar));
    if (kuyruk == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return -1;
    }
    kuyruk->son_indis=0;
    kuyruk->ilk_indis=0;
    kuyruk->count=0;
    while(1==1)
    { 
        puts("\ne=Ekleme\ns=Cikarma\nl=Listeleme\nc=Cikis\nSecim?");
        //secim=getchar();
        scanf(" %c",&secim);
        switch(secim)
        { 
            case 'e':
                puts("Numarayi giriniz");
                scanf("%d",&numara);
                //kuyruk_ekle(numara);
                kuyruk_ekle2(kuyruk,numara);
                break;
            case 's':
                //printf("%d",kuyruk_cikar());
                printf("%d",kuyruk_cikar2(kuyruk));
                break;
            case 'l':
                //isteleme();
                listeleme2(kuyruk);
                break;
            case 'c':
                exit(0);
            }
        }
    return 0;
}