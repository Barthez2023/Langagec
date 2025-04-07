#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Yboyut 5
int yigin[Yboyut];
int kuruk[Yboyut];
int indis=-1;

/*int yigin_bos(){
    if (indis==-1)
    {
       return -1;
    }
    else
        return 1;
}

int yigin_dolu(){
    if (indis>=Yboyut-1)
    {
       return -1;
    }
    else
        return 1;
}

void yigin_ekle(int sayi){
    if (yigin_dolu()==-1)
    {
        printf("yigin dolu element yuklemezsin\n");
    }
    else
    {
        indis++;
        yigin[indis]=sayi;
    }
}


int yigin_cikar(){
    int sayi;
    if (yigin_bos()==-1)
    {
        printf("yigin bos element cikarmazsiniz\n");
    }
    else
    {
        sayi=yigin[indis];
        indis--;
    }
    return sayi;
}

void listeleme(){
    if (yigin_bos()==-1)
    {
        printf("yigin bos element cikarmazsiniz\n");
    }
    else
    {
        for (int i = indis; i>=0; i--)
        {
            printf("[%d]\n",yigin[i]);
        }
        
    }

}*/



/*int kuyruk_bos(){
    if (indis==-1)
    {
       return -1;
    }
    else
        return 1;
}

int kuyruk_dolu(){
    if (indis>=Yboyut-1)
    {
       return -1;
    }
    else
        return 1;
}

void kuyruk_ekle(int sayi){
    if (kuyruk_dolu()==-1)
    {
        printf("kuyruk dolu element yuklemezsin\n");
    }
    else
    {
        indis++;
        kuruk[indis]=sayi;
    }
}


int kuyrukn_cikar(){
    int sayi;
    if (kuyruk_bos()==-1)
    {
        printf("kuyruk bos element cikarmazsiniz\n");
    }
    else
    {
        sayi=kuruk[0];
        for (int i = 1; i <=indis; i++)
        {
            kuruk[i-1]=kuruk[i];
        }
        indis--;
    }
    return sayi;
}

void listeleme(){
    if (kuyruk_bos()==-1)
    {
        printf("kuyruk bos element cikarmazsiniz\n");
    }
    else
    {
        for (int i = 0; i<=indis; i++)
        {
            printf("[%d] ",kuruk[i]);
        }
        
    }

}*/

/*typedef struct Liste
{
    int sayi;
    struct Liste *next;
}Liste;

Liste *liste_ekle(Liste *ilk ,int sayi1){
    Liste *gecici,*son;
    gecici=(Liste*)malloc(sizeof(Liste));
    if (gecici==NULL)
    {
        printf("Dinamik tahsis hatasi\n");
        exit(1);
    }
    gecici->sayi=sayi1;
    gecici->next=NULL;
    if (ilk==NULL)
    {
        ilk=gecici;
        return ilk;
    }
    son=ilk;
    while (son->next!=NULL)
    {
        son=son->next;
    }
    son->next=gecici;
    return ilk;
}
void listeme(Liste *ilk){
    Liste *gecici;

    gecici=ilk;
    while (gecici!=NULL)
    {
        printf("[%d]->",gecici->sayi);
        gecici=gecici->next;
    }
    printf("NULL");
    
}

int sayi_karsilip(Liste *ilk){
    Liste *gecici;
    int tek=0,cift=0;
    gecici=ilk;
    while (gecici!=NULL)
    {
        if (gecici->sayi%2==0)
           cift++;
        else
            tek++;
        gecici=gecici->next;
    }
    if (tek==cift)
    {
        return 0;
    }
    else
    {
        if (tek>cift)
        {
            return -1;
        }
        else
            return 1;
    }
}
*/


typedef struct cift_liste
{
    int sayi;
    struct cift_liste *next;
    struct cift_liste *before;
}cift_liste;

cift_liste*ekle(cift_liste *ilk,int sayi1){
    cift_liste *gecici,*son;
    gecici=(cift_liste*)malloc(sizeof(cift_liste));
    if (gecici==NULL)
    {
        printf("Dinamik tahsis hatasi\n");
        exit(1);
    }
    gecici->sayi=sayi1;
    gecici->before=NULL;
    gecici->next=NULL;
    if (ilk==NULL)
    {
        ilk=gecici;
        return ilk;
    }
    son=ilk;
    while (son->next!=NULL)
    {
        son=son->next;
    }
    son->next=gecici;
    gecici->before=son;
    return ilk;
}

void print(cift_liste *ilk){
    cift_liste *gecici;
    gecici=ilk;
    if (gecici==NULL)
    {
       printf("Liste bos\n");
    }
    
    while (gecici!=NULL)
    {
        printf("[%d]->",gecici->sayi);
        gecici=gecici->next;
    }
    printf("NULL");
}

cift_liste *sil(cift_liste *ilk,int sayi1){
    cift_liste *gecici,*son,*once;
    if (ilk==NULL)
    {
       printf("Liste bos elemnt yok\n");
    }
    gecici=ilk;
    if (gecici->sayi==sayi1)
    {
        if (gecici->next==NULL)
        {
            free(gecici);
            return NULL;
        }
        else
        {
            gecici=gecici->next;
            gecici->before=NULL;
            ilk->next=NULL;
            free(ilk);
            return gecici;
        }
    }
    son=gecici;
    while (son!=NULL&&son->sayi!=sayi1)
    {
        once=son;
        son=son->next;
    }
    if (son==NULL)
    {
        printf("element bulamadik\n");
        return gecici;
    }
    
    if (son->next==NULL)
    {
       once->next=NULL;
       son->before=NULL;
       free(son);
       return gecici;
    }

    once->next=son->next;
    son->next->before=once;
    son->before=NULL;
    son->next=NULL;
    free(son);
    return gecici;
}

void en_buyuk_sil(cift_liste *ilk){
    int max;
    cift_liste *gecici;
    max=ilk->sayi;
    gecici=ilk->next;
    while (gecici!=NULL)
    {
        if (gecici->sayi>max)
        {
            max=gecici->sayi;
        }
        gecici=gecici->next;
    }
    ilk=sil(ilk,max);
}


int main(){
    /*utilisation des yigin avec les sayi*/
    /*char secim;
    int numara;
    while(1==1)
    {
         printf("\ne = Ekleme\ns = Cikarma\nl = Listeleme\nc = Cikis\nSecim? ");
         scanf(" %c",&secim);
        switch (secim)
        {
        case 'e':
            printf("bir sayi girin:");
            scanf("%d",&numara);
            kuyruk_ekle(numara);
            break;
        case 's':
            if (indis==-1)
            {
               printf("kuyruk bos  element cikarmazsiniz\n");
            }
            else
                printf("aldigimiz element bu:%d\n",kuyrukn_cikar());
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
   /*Liste *liste=NULL;
   liste=liste_ekle(liste,1);
   liste=liste_ekle(liste,2);
   liste=liste_ekle(liste,3);
   liste=liste_ekle(liste,4);
   liste=liste_ekle(liste,5);
   liste=liste_ekle(liste,6);
   liste=liste_ekle(liste,8);
   listeme(liste);
   printf("\n");
   int nbr=sayi_karsilip(liste);

   if (nbr==0)
   {
        printf("listedeki tek ve cift sayiar esit");
   }
   else
   {
        if (nbr==-1)
            printf("listedeki tek sayiar ciftten daha fazla");
        else
            printf("listedeki cift sayiar tektten daha fazla");
   }
   */

    cift_liste *liste=NULL;
   liste=ekle(liste,1);
   liste=ekle(liste,2);
   liste=ekle(liste,3);
   liste=ekle(liste,9);
   liste=ekle(liste,5);
   liste=ekle(liste,15);
   liste=ekle(liste,6);
   liste=ekle(liste,8);
   liste=ekle(liste,12);
   print(liste);
   printf("\n");
   liste=sil(liste,5);
   print(liste);
   printf("\n");
   en_buyuk_sil(liste);
   print(liste);


    return 0;
}