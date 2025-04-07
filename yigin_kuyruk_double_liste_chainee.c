#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*pour la file on ajoute derriere et on retire devant pour avoir la structure first in first out
dans ce cas on va ajouter en fin de la liste doublement chainee(fin de file) et retirer au debut de la liste(debut de file)
on va implementer les fonctions on_cikar(retire deriere) et arka_ekle(ajouter derierere)*/

/*pour la pile on ajoute devant et on retire devant pour avoir la structure last in first out
dans ce cas on va ajouter en debut de la liste doublement chainee(debut de pile) et retirer au debut de la liste(debut de pile)
on va implementer les fonctions on_ekle(ajoute devant) et on_cikar(retirer devant)*/


typedef struct YKliste_chainee                  //YYliste_chaine:yigin_kuyruk_liste_chainee
{
    int sayi;
    struct YKliste_chainee *next;
    struct YKliste_chainee *before;
}YKliste_chainee;

YKliste_chainee *on_ekle(YKliste_chainee *liste, int sayi1){
    YKliste_chainee *gecici,*ilk;
    gecici=(YKliste_chainee*)malloc(sizeof(YKliste_chainee));
    if (gecici==NULL)
    {
        printf("Dynamik tahsis hatasi\n");
        exit(1);
    }
    gecici->sayi=sayi1;
    gecici->next=NULL;
    gecici->before=NULL;
    ilk=liste;
    if (ilk==NULL)
    {
        ilk=gecici;
        return ilk;
    }
    else
    {
        gecici->next=ilk;
        ilk->before=gecici;
        ilk=gecici;
        return ilk;
    }
}


YKliste_chainee *arka_ekle(YKliste_chainee *liste, int sayi1){
    YKliste_chainee *gecici,*ilk,*son;
    gecici=(YKliste_chainee*)malloc(sizeof(YKliste_chainee));
    if (gecici==NULL)
    {
        printf("Dynamik tahsis hatasi\n");
        exit(1);
    }
    gecici->sayi=sayi1;
    gecici->next=NULL;
    ilk=liste;
    if (ilk==NULL)
    {
        ilk=gecici;
        return gecici;
    }
    son=ilk;
    while (son->next!=NULL)
    {
       son=son->next;
    }
    son->next=gecici;
    gecici->before=son;
    son=gecici;
    return ilk;
}


/*int on_cikar(YKliste_chainee *liste){
    int sayi1;
    YKliste_chainee *gecici,*ilk;
    ilk=liste;
    if (ilk==NULL)
    {
        printf("veriden hic element yoktur\n");
    }

    if (ilk->next==NULL)
    {
        sayi1=ilk->sayi;
        free(ilk);
        return sayi1;
    }
    else
    {
        sayi1=ilk->sayi;
        gecici=ilk->next;
        free(ilk);
        ilk=gecici;
        return sayi1;
    }
}*/



int on_cikar(YKliste_chainee **liste){
    int sayi1;
    if (*liste==NULL)
    {
        printf("veriden hic element yoktur\n");
        return -1;
    }
    YKliste_chainee *gecici=*liste;
    sayi1=gecici->sayi;
    *liste=gecici->next;
    gecici->next=NULL;
    free(gecici);
    return sayi1;
}



void print(YKliste_chainee *liste){
    YKliste_chainee  *gecici;
    gecici=liste;
    while (gecici!=NULL)
    {
        printf("[%d]->",gecici->sayi);
        gecici=gecici->next;
    }
    printf("NULL");
}



//implementation des piles et files
int main(){
   char secim;
    int numara;
    YKliste_chainee *yigin=NULL;
    YKliste_chainee *kuyruk=NULL;
    while(1==1)
    { 
        puts("\ne=Ekleme\ns=Cikarma\nl=Listeleme\nc=Cikis\nSecim?");
        scanf(" %c",&secim);
        switch(secim)
        { 
            case 'e':
                puts("Numarayi giriniz");
                scanf("%d",&numara);
                yigin=on_ekle(yigin,numara);
                kuyruk=arka_ekle(kuyruk, numara);
                break;
            case 's':
                printf("yiginden ilk element bu:%d",on_cikar(&yigin));
                printf("\n");
                printf("kuruktan ilk elementbu:%d",on_cikar(&kuyruk));
                break;
            case 'l':
                print(yigin);
                printf("\n\n");
                print(kuyruk);
                break;
            case 'c':
                exit(0);
            }
        }
    return 0;
}
