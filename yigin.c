#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*definition des piles en utilisant les tableaux*/
/*#define N 100
int yigin[N];
int indis=-1;

void yigin_ekle(int sayi){
    if (indis>=N-1)
    {
        printf("Yigin dolu  element eklemezsiniz\n");
    }
    else
    {
        indis++;
        yigin[indis]=sayi;
    }
}

int yigin_cikar(){
    int sayi;
    if (indis==-1)
    {
        return  -1;
    }
    else
    {
        sayi=yigin[indis];
        indis--;
        return  sayi;
    }
}
void listeleme(){
    if (indis==-1)
    {
        printf("Yigin bos  element yok\n");
    }
    for (int i =indis; i>=0; i--)
    {
        printf("\n %d",yigin[i]);
    }
}*/



/*definition des piles en utilisant les structures pour les nombres*/

#define YBoyut 100

typedef struct Yigin
{ 
    int indis;
    int eleman[YBoyut];
}Yiginlar;

Yiginlar Yeni_Yigin;
//Yeni_Yigin.indis=-1;
int yigin_dolu(){
    if (Yeni_Yigin.indis>=YBoyut-1)
    {
       return -1;
    }
    return  1;
}

int yigin_bos(){
    if (Yeni_Yigin.indis==-1)
    {
       return -1;
    }
    return  1;
}

void yigin_ekle(int sayi){
    if (yigin_dolu()==-1)
    {
       printf("yigin dolu element eklemezsiniz`\n");
    }
    else
    {
        Yeni_Yigin.indis++;
        Yeni_Yigin.eleman[Yeni_Yigin.indis]=sayi;
    }
}

int yigin_cikar(){
    if (yigin_bos()==-1)
    {
       printf("yigin bos element cikarmazsiniz\n");
       return -1;
    }
    else
    {
        int sayi=Yeni_Yigin.eleman[Yeni_Yigin.indis];
        Yeni_Yigin.indis--;
        return sayi;
    }
}


void listeleme(){
    if (Yeni_Yigin.indis==-1)
    {
        printf("Yigin bos  element yok\n");
    }
    for (int i =Yeni_Yigin.indis; i>=0; i--)
    {
        printf("[%d]\n",Yeni_Yigin.eleman[i]);
    }

}


/*void cevir_binary(int sayi){
    int digit;
    while (sayi>0)
    {
       digit=sayi%2;
       yigin_ekle(digit);
       sayi=sayi/2;
    }
    //listeleme1(binary_yigin);
    while (Yeni_Yigin.indis>=0)
    {   digit=yigin_cikar();
        printf("%d",digit);
    }
}*/

int main(){
    /*utilisation des yigin avec les sayi*/
    char secim;
    int numara;
    Yeni_Yigin.indis=-1;
    while(1==1)
    {
         printf("\ne = Ekleme\ns = Cikarma\nl = Listeleme\nc = Cikis\nSecim? ");
         scanf(" %c",&secim);
        switch (secim)
        {
        case 'e':
            printf("bir sayi girin:");
            scanf("%d",&numara);
            yigin_ekle(numara);
            break;
        case 's':
            if (Yeni_Yigin.indis==-1)
            {
               printf("Yigin bos  element cikarmazsiniz\n");
            }
            else
                printf("aldigimiz element bu:%d\n",yigin_cikar());
            break;
        case 'l':
            listeleme();
            break;
        case 'c':
            exit(0);
        default:
            break;
        }
    }
  

    return 0;
}