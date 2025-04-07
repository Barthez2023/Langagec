#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define YBoyut 100

typedef struct Yigin
{ 
    int indis;
    int eleman[YBoyut];
}Yiginlar;

typedef struct Yigin1
{ 
    int indis;
    char* eleman[YBoyut];
}Yiginlar1;



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

void yigin_ekle(Yiginlar *yigin1,int sayi){
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

void yigin_ekle1(Yiginlar1 *yigin1,char *islem){
    if (yigin1->indis>=YBoyut-1)
    {
       printf("yigin dolu element eklemezsiniz`\n");
    }
    else
    {
        yigin1->indis++;
        yigin1->eleman[yigin1->indis]=strdup(islem);  // Utilisation de strdup pour copier la chaîne;
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

char *yigin_cikar1(Yiginlar1 *yigin1){
    char c;
    if (yigin1->indis==-1)
    {
        printf("yigin bos element cikarmazsiniz");
        return NULL;
    }
    else
    {
        return yigin1->eleman[yigin1->indis--];
    }
}


void concat_char(char *chaine, char caractere) {
    int longueur = strlen(chaine);
    chaine[longueur] = caractere;  // Ajouter le caractère à la fin de la chaîne
    chaine[longueur + 1] = '\0';   // Ajouter le caractère de fin de chaîne
}



char *metin_yegin(char *islem){
    //Yiginlar1 *yigin_metin;
    //Yiginlar *yigin_sayi;
    Yiginlar1 *yigin_metin = (Yiginlar1 *)malloc(sizeof(Yiginlar1));
    Yiginlar *yigin_sayi = (Yiginlar *)malloc(sizeof(Yiginlar));
    char metin1[100] = "";
    char metin2[100] = "";
    yigin_sayi->indis=-1;
    yigin_metin->indis=-1;
    for (int i = 0; i < strlen(islem); i++)
    {
        if (islem[i]>'0'&&islem[i]<='9')
        {
            yigin_ekle(yigin_sayi,islem[i]-'0');
        }
        else
        {
            if (islem[i]!=']')
            {
                yigin_ekle1(yigin_metin,&islem[i]);
            }
            else
            {
                int index=yigin_cikar(yigin_sayi);
                while (*yigin_metin->eleman[yigin_metin->indis]!='[')
                {
                    char *c=yigin_cikar1(yigin_metin);
                    //concat_char(metin1,c);
                    strcat(metin1, c);
                }
                yigin_cikar1(yigin_metin);
                while (index>1)
                {
                    for (int i = 0; i < strlen(metin1); i++)
                    {
                        concat_char(metin2,metin1[i]);
                        //strcat(metin2,metin1[i]);
                    }
                    index--;
                    strcpy(metin1, "");  // Réinitialiser metin1 pour le prochain tour
                }
            }
        }
        
        yigin_ekle1(yigin_metin,metin2);
        strcpy(metin2, "");  // Réinitialiser metin2 pour le prochain tour
    }
    char *result = strdup(yigin_cikar1(yigin_metin));  // Copier le résultat final
    return result;
}


int main(){
    char element[]= "2[ab]";
    printf("%s",metin_yegin(element));

    return 0;
}










































































































































































/*void listeleme(Yiginlar *yigin1){
    if (yigin1->indis==-1)
    {
        printf("Yigin bos  element yok\n");
    }
    for (int i =yigin1->indis; i>=0; i--)
    {
        printf("[%d]\n",yigin1->eleman[i]);
    }

}*/





//int main(){
    /*utilisation des yigin avec les sayi*/
    /*char secim;
    int numara;
    Yiginlar *Yeni_Yigin;
    Yeni_Yigin->indis=-1;
    while(1==1)
    {
         printf("\ne = Ekleme\ns = Cikarma\nl = Listeleme\nc = Cikis\nSecim? ");
         scanf(" %c",&secim);
        switch (secim)
        {
        case 'e':
            printf("bir sayi girin:");
            scanf("%d",&numara);
            yigin_ekle(Yeni_Yigin, numara);
            break;
        case 's':
            if (Yeni_Yigin->indis==-1)
            {
               printf("Yigin bos  element cikarmazsiniz\n");
            }
            else
                printf("aldigimiz element bu:%d\n",yigin_cikar(Yeni_Yigin));
            break;
        case 'l':
            listeleme(Yeni_Yigin);
            break;
        case 'c':
            exit(0);
        default:
            break;
        }
    }
  

    return 0;
}*/