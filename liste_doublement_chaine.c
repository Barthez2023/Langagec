#include<stdio.h>
#include<stdlib.h>
typedef struct Liste
{
   int sayi;
   struct Liste *next;
   struct Liste *before;
}Liste;

Liste* Ekleme(Liste *li,int sayi1){
    Liste *ilk, *son,*gecici,*once;
    gecici=(Liste*)malloc(sizeof(Liste));
    if (gecici==NULL)
    {
        printf("Dinamik tahsis hatasi\n");
        exit(1);
    }
    ilk=li;
    gecici->sayi=sayi1;
    gecici->next=NULL;
    gecici->before=NULL;
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
    son=gecici;
    return ilk;
}

void print(Liste *li){
    Liste *gecici;
    gecici=li;
    if (li==NULL)
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

Liste* Delete(Liste *li,int sayi1){
    Liste *gecici=NULL,*ilk,*son;
    if (li==NULL)
    {
        printf("Liste bos\n");
        return NULL;
    }
    // Cas où le premier élément est celui à supprimer.
    ilk=li;
    if (ilk->sayi==sayi1)
    {
        if (ilk->next!=NULL)        // Si ce n'est pas le seul élément.
        {
            ilk=li->next;
            ilk->before=NULL;
            li->next=NULL;
            free(li);       // Libération de l'ancien premier élément.
            return ilk;
        }
        else        // Si c'est le seul élément dans la liste.
        {
            free(li);
            return NULL;        // La liste est maintenant vide.
        }   
    }

    son=ilk;
    // Parcours pour trouver l'élément à supprimer.
    while (son!=NULL&&son->sayi!=sayi1)
    {
        gecici=son;
        son=son->next;
    }
    // Si l'élément n'a pas été trouvé.
    if (son==NULL)
    {
        printf("Element bulamadik");
        return ilk;
    }
    // Si l'élément trouvé est le dernier.
    if (son->next==NULL)
    {
        gecici->next=NULL;
        son->before=NULL;
        free(son);
        return ilk;
    }
    // Si l'élément est un nœud intermédiaire.
    gecici->next=son->next;
    son->next->before=gecici;
    son->next=NULL;
    son->before=NULL;
    free(son);
    return ilk;
}

/*void Arama(Liste *li,int sayi1){
    Liste *gecici;
    int cmp=1;
    gecici=li;
    while (gecici!=NULL &&gecici->sayi!=sayi1)
    {
        gecici=gecici->next;
        cmp++;
    }
    if (gecici==NULL)
    {
        printf("Aradiginiz sayi bulmadik\n");
    }
    else
    {
        printf("Aradiginiz sayi %d pozisyonu bulduk\n",cmp);
    }
    
}*/

Liste* Arama(Liste *li,int sayi1){
    Liste *gecici;
    gecici=li;
    if (li==NULL)
    {
        printf("Liste bos\n");
        return NULL;
    }
    while (gecici!=NULL &&gecici->sayi!=sayi1)
    {
        gecici=gecici->next;
    }
    return gecici;
    
}




int main(){
  Liste *li=NULL;
  Liste *gecici=NULL;
    int sayi;
    char secim;
    while (1)
    {
        printf("\nEkleme='e'\nListeleme='l'\nArama='a'\nSilme='s'\nCikis='c'\n");
        printf("Istediginiz islem secin:");
        scanf(" %c",&secim);
        switch (secim)
        {
        case 'e':
            printf("Bir sayi girin:");
            scanf("%d",&sayi);
            li=Ekleme(li,sayi);
            break;

        case 's':
            printf("Bir sayi girin:");
            scanf("%d",&sayi);
            li=Delete(li,sayi);
            break;
        
        case 'l':
            print(li);
            break;

        case 'a':
            printf("Bir sayi girin:");
            scanf("%d",&sayi);
            gecici=Arama(li,sayi);
            if (gecici==NULL)
            {
                printf("Aradiginiz sayi bulmadik\n");
            }
            else
            {
                printf("Aradiginiz sayi %p adress bulduk\n",gecici);
            }
            break;    

        case 'c':
            exit(0);
            break;        
        default:
            break;
        }

    }






   /*Liste *li=NULL;
    int sayi,sayi2,sayi3;
    char cevap;
    do
    {   printf("Bir sayi girin:");
        scanf("%d",&sayi);
        li=Ekleme(li,sayi);
        printf("Bir daha sayi girmek ister misin:e=evet h=hayir:");
        scanf(" %c",&cevap);
    } while (cevap== 'e');
    print(li);

    printf("\n\n");
    printf("Bir sayi girin:");
    scanf("%d",&sayi2);

    li=Delete(li,sayi2);
    printf("\n\n");
    print(li);

    printf("Bir sayi girin:");
    scanf("%d",&sayi3);
    Arama(li,sayi3);
    */






    return 0;
}