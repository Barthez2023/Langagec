#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Yboyut 100

typedef struct kuyruklar
{
    int son_indis;
    int element[Yboyut];
} kuyruklar;

kuyruklar yeni_kuyruk;

int kuyruk_dolu(){
    if (yeni_kuyruk.son_indis>=Yboyut-1)

        return -1;
    else
        return 1;
}

int kuyruk_dolu2(kuyruklar *kuyruk1){
    if (kuyruk1->son_indis>=Yboyut-1)

        return -1;
    else
        return 1;
}


int kuyruk_bos(){
    if (yeni_kuyruk.son_indis==-1)

        return -1;
    else
        return 1;
}

int kuyruk_bos2(kuyruklar *kuyruk1){
    if (kuyruk1->son_indis==-1)

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
        yeni_kuyruk.son_indis++;
        yeni_kuyruk.element[yeni_kuyruk.son_indis]=sayi;
    }
}

void kuyruk_ekle2(kuyruklar *kuyruk1,int sayi){
    if (kuyruk_dolu2(kuyruk1)==-1)
    {
        printf("kuyruk dolu element eklemezsiniz\n");
    }
    else
    {
        kuyruk1->son_indis++;
        kuyruk1->element[kuyruk1->son_indis]=sayi;
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
        sayi=yeni_kuyruk.element[0];
        for (int i = 1; i <=yeni_kuyruk.son_indis; i++)
        {
            yeni_kuyruk.element[i-1]=yeni_kuyruk.element[i];
        }
        yeni_kuyruk.son_indis--;
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
        sayi=kuyruk1->element[0];
        for (int i = 1; i<=kuyruk1->son_indis; i++)
        {
            kuyruk1->element[i-1]=kuyruk1->element[i];
        }
        kuyruk1->son_indis--;
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
        for (int i = 0; i <= yeni_kuyruk.son_indis; i++)
        {
            printf("\n: %d",yeni_kuyruk.element[i]);
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
        for (int i = 0; i <= kuyruk1->son_indis; i++)
        {
            printf("\n: %d",kuyruk1->element[i]);
        }
        
    }
}


int main(){
    int i;
    char secim;
    int numara;
    yeni_kuyruk.son_indis=-1;
    kuyruklar *kuyruk;
    kuyruk->son_indis=-1;
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
                //listeleme();
                listeleme2(kuyruk);
                break;
            case 'c':
                exit(0);
            }
        }
    return 0;
}