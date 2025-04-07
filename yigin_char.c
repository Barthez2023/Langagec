#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*definition des piles en utilisant les structures pour les caracteres*/

#define YBoyut 100
typedef struct yigin
{
    int indis;
    char element[YBoyut];
}yiginlar;

yiginlar New_yigin;
int yigin_bos(){
    if (New_yigin.indis==-1)
    {
        return -1;
    }
    else
        return 1;
    
}

int yigin_dolu(){
    if (New_yigin.indis>=YBoyut-1)
    {
        return -1;
    }
    else
        return 1;
    
}

void yigin_ekle(char a){
    if (yigin_dolu()==-1)
    {
        printf("yigin dolu element eklemezsiniz");
    }
   else
   {
        New_yigin.indis++;
        New_yigin.element[New_yigin.indis]=a;
   }
}

char yigin_cikar(){
    char c;
    if (yigin_bos()==-1)
    {
        printf("yigin bos element cikarmazsiniz");
        return '\0';
    }
    else
    {
        c=New_yigin.element[New_yigin.indis];
        New_yigin.indis--;
        return c;
    }
}

void listeleme(){
    if (yigin_bos()==-1)
    {
        printf("yigin bos element yok");
    }
    for (int i = New_yigin.indis; i>=0; i--)
    {
        printf("[%c]\n",New_yigin.element[i]);
    }
    
}


int paranteze_control_islem(char *islem){

    for (int i = 0; i < strlen(islem); i++)
    {
        if (islem[i]=='(')
        {
            yigin_ekle(islem[i]);
        }
        else
        {
            if (islem[i]==')')
            {
                if (yigin_bos()==-1)
                {
                    return -1;
                }
                else
                {
                    yigin_cikar();
                }
            }
            
        }
    }

    if (yigin_bos()==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




int main(){
   
   /*utilisation des yigin avec les caracteres*/
    /*char secim;
    char caractere;
    New_yigin.indis=-1;
    while(1==1)
    {
         printf("\ne = Ekleme\ns = Cikarma\nl = Listeleme\nc = Cikis\nSecim? ");
         scanf(" %c",&secim);
        switch (secim)
        {
        case 'e':
            printf("bir caractere girin:");
            scanf(" %c",&caractere);
            //getchar();
            yigin_ekle(caractere);
            break;
        case 's':
            if (yigin_bos()==-1)      //   New_yigin.indis==-1
            {
               printf("Yigin bos  element cikarmazsiniz\n");
            }
            else
                printf("aldigimiz element bu:%c\n",yigin_cikar());
            break;
        case 'l':
            listeleme();
            break;
        case 'c':
            exit(0);
        default:
            break;
        }
    }*/

    New_yigin.indis=-1;
    int i;
    char islem[50];        //exemple="(3+4)/5)";
    printf("Kontrol istediginiz islem girsiniz:");
    scanf("%s",islem);
    i=paranteze_control_islem(islem);
    switch(i)
    {
    case -1:
        printf("Hata: Acma Parantezi Eksik"); // HATA 1 => 6*(5-3))
        break;
    case 0:
        printf("Hata: Kapama parantezi Eksik"); // HATA 2 => 6*(5-3
        break;
    case 1:
        printf("Parantez Hatasi Yok"); // DOĞRU => 6*(5-3)
        break;
    default:
        break;
    }
    return 0;
}