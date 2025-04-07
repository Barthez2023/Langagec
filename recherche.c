#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Liste
{
   int sayi;
   struct Liste *next;
}Liste;

Liste* Ekleme(Liste *li,int sayi1){
    Liste *ilk, *son,*gecici;
    gecici=(Liste*)malloc(sizeof(Liste));
    if (gecici==NULL)
    {
        printf("Dinamik tahsis hatasi\n");
        exit(1);
    }
    ilk=li;
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
    son=gecici;
    return ilk;
}

void print(Liste *li){
    Liste *gecici;
    gecici=li;
    while (gecici!=NULL)
    {
        printf("[%d]->",gecici->sayi);
        gecici=gecici->next;
    }
    printf("NULL");
}

Liste* Delete(Liste *li,int sayi1){
    Liste *gecici,*ilk,*son;
    if (li==NULL)
    {
        printf("Liste bos\n");
        return NULL;
    }
    
    ilk=son=li;
    if (ilk->sayi==sayi1)
    {
        ilk=li->next;
        free(li);
        return ilk;
    }
    while (son!=NULL&&son->sayi!=sayi1)
    {
        gecici=son;
        son=son->next;
        
    }
    if (son==NULL)
    {
        printf("Element bulamadik");
        return ilk;
    }
    else
    {
        gecici->next=son->next;
        free(son);
        return ilk;
    }
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
    while (gecici!=NULL &&gecici->sayi!=sayi1)
    {
        gecici=gecici->next;
    }
    if (gecici==NULL)
    {
        return NULL;
    }
    else
    {
        return gecici;
    }
    
}

int sirali_Arama(Liste *li,int sayi1){
    Liste *gecici;
    gecici=li;
    while (gecici!=NULL)
    {
        if (gecici->sayi==sayi1)
        {
            return 1;
        }
        gecici=gecici->next;
    }
    return -1;
}

int ikili_Arama(Liste *li,int sayi1){
    Liste *gecici;
    int deb=0,fin=0;
    gecici=li;
    while (gecici!=NULL)
    {
        if (gecici->sayi==sayi1)
        {
            return 1;
        }
        gecici=gecici->next;
    }
    return -1;
}

int max_Liste(Liste *li){
    Liste *ilk,*gecici;
    int max;
    ilk=li;
    gecici=li->next;
    max=ilk->sayi;
    while (gecici!=NULL)
    {
        if(gecici->sayi>max)
        max=gecici->sayi;
        gecici=gecici->next;
    }
    return max;
    
}

int sum_Liste(Liste *li){
    Liste *gecici;
    int sum=0;
    gecici=li;
    while (gecici!=NULL)
    {
        sum+=gecici->sayi;
        gecici=gecici->next;
    }
    return sum;
    
}

bool asal_sayi(int sayi){
    if (sayi==0||sayi==1)
    {
        return false;
    }
    for (int i= 2; i < sayi; i++)
    {
        if (sayi%i==0)
        {
           return false;
        }
    }
    return true;
}

void inverse_liste(Liste *li){
    Liste *son,*gecici,*ptr;
    son=li;
    int cmp;
    while (son->next!=NULL)
    {
        son=son->next;
    }
    ptr=li;
    while (ptr!=son)
    {
        gecici=ptr;
        while (gecici!=son)
        {
            cmp=gecici->sayi;
            gecici->sayi=son->sayi;
            son->sayi=cmp;
            gecici=gecici->next;
        }
        ptr=ptr->next;
    }
}




int main(){
 Liste *li=NULL;
  Liste *gecici=NULL;
    int sayi,max,sum,cmp;
    char secim;
    while (1)
    {
        printf("\nEkleme='e'\nListeleme='l'\nArama='a'\nSilme='s'\nMax='m'\nToplam='t'\ninverse='i'\nCikis='c'\'siraliarama='r'\n");
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
        case 'r':
            printf("Bir sayi girin:");
            scanf("%d",&sayi);
            cmp=sirali_Arama(li,sayi);
            if (cmp==1)
            {
                printf("Aradiginiz sayi listeye bulduk\n");
            }
            else
            {
                printf("Aradiginiz sayi listeye bulamadik");
            }
            break; 

        case 'm':
            max=max_Liste(li);
            printf("Bu listede maximun element bu:%d\n",max);
            break;
        case 't':
            sum=sum_Liste(li);
            printf("Bu listede toplam element bu:%d\n",sum);
            break;

        case 'i':
            inverse_liste(li);
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