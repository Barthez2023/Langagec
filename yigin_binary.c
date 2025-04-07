#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define YBoyut 100

typedef struct Yigin
{ 
    int indis;
    int eleman[YBoyut];
}Yiginlar;

Yiginlar binary_yigin;
//Yeni_Yigin.indis=-1;
int yigin_dolu(Yiginlar *yigin1){
    if (yigin1->indis>=YBoyut-1)
    {
       return -1;
    }
    return  1;
}

int yigin_bos(Yiginlar *yigin1){
    if (yigin1->indis==-1)
    {
       return -1;
    }
    return  1;
}

void yigin_ekle(int sayi,Yiginlar *yigin1){
    if (yigin_dolu(yigin1)==-1)
    {
       printf("yigin dolu element eklemezsiniz`\n");
    }
    else
    {
        yigin1->indis++;
        yigin1->eleman[yigin1->indis]=sayi;
    }
}

int yigin_cikar(Yiginlar *yigin1){
    if (yigin_bos(yigin1)==-1)
    {
       printf("yigin bos element cikarmazsiniz\n");
       return -1;
    }
    else
    {
        int sayi=yigin1->eleman[yigin1->indis];
        yigin1->indis--;
        return sayi;
    }
}

void listeleme(Yiginlar *yigin1){
    if (yigin1->indis==-1)
    {
        printf("Yigin bos  element yok\n");
    }
    for (int i =yigin1->indis; i>=0; i--)
    {
        printf("[%d]\n",yigin1->eleman[i]);
    }

}

void cevir_binary(int sayi){
    int digit;
    while (sayi>0)
    {
       digit=sayi%2;
       yigin_ekle(digit,&binary_yigin);
       sayi=sayi/2;
    }
    //listeleme1(binary_yigin);
    while (binary_yigin.indis>=0)
    {   digit=yigin_cikar(&binary_yigin);
        printf("%d",digit);
    }
}

int main(){
    binary_yigin.indis=-1;
    cevir_binary(18);

    return 0;
}