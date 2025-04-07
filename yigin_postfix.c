#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
int hesaplama(int sayi1,char car,int sayi2){
    if (car=='*')
    {
        return sayi1*sayi2;
    }
    else
    {
        if (car=='+')
        {
            return sayi1+sayi2;
        }
        else
        {
            if (car=='/')
            {
                return sayi1/sayi2;
            }
            else
            {
                if (car=='-')
                {
                   return sayi1-sayi2;
                
            }
        } 
    }

    }
}

int postfix_deger(char *islem){
    int i=strlen(islem);
    int index=0;
    while (index<i)
    {

        // Ignore les espaces
        if (islem[index] == ' ') {
            index++;
            continue;
        }

        if (islem[index]>='0' && islem[index]<='9')
        {
            yigin_ekle(islem[index]-'0');       // Convertit le caractère en entier
        }
        else
        {
            int operand2=yigin_cikar();
            int operand1=yigin_cikar();
            char operator=islem[index];
            int deger=hesaplama(operand1,operator,operand2);
            yigin_ekle(deger);
        }
        index++;
    }
    return yigin_cikar();
}



int main(){
    /*utilisation des yigin avec les sayi*/
    char secim;
    char element[]= "6 2 3 + - 3 8 2 / + * 2 ^ 3";
    Yeni_Yigin.indis=-1;
    printf("%d",postfix_deger(element));
    

    return 0;
}