#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define boyut 5

//implementation des plies
/*typedef struct yiginlar
{
    int indice;
    int element[boyut];
}yiginlar;

yiginlar yigin;
yiginlar yigin2;

int yigin_bos(){
    if (yigin.indice==-1)
    {
        return -1;
    }
    return 1;
}

int yigin_bos1(yiginlar *yigin1){
    if (yigin1->indice==-1)
    {
        return -1;
    }
    return 1;
}


int yigin_dolu(){
    if (yigin.indice>=boyut-1)
    {
        return -1;
    }
    return 1;
}

int yigin_dolu1(yiginlar *yigin1){
    if (yigin1->indice>=boyut-1)
    {
        return -1;
    }
     return 1;
}

void ekleme(int sayi){
    if (yigin_dolu()==-1)
    {
        printf("yigin dolu element eklemezsiniz");
    }
    yigin.indice++;
    yigin.element[yigin.indice]=sayi;
}
void ekleme1(yiginlar *yigin1 ,int sayi){
    if (yigin_dolu1(yigin1)==-1)
    {
        printf("yigin dolu element eklemezsiniz");
    }
    yigin1->indice++;
    yigin1->element[yigin1->indice]=sayi;
}

int cikarma(){
    if (yigin_bos()==-1)
    {
        printf("yigin bos element cikarmazsiniz");
        return -1;
    }
    int cmp=yigin.element[yigin.indice];
    yigin.indice--;
    return cmp;
}
int cikarma1(yiginlar *yigin1){
    if (yigin_bos1(yigin1)==-1)
    {
        printf("yigin bos element cikarmazsiniz");
        return -1;
    }
    int cmp=yigin1->element[yigin1->indice];
    yigin1->indice--;
    return cmp;
}

void listemele(){
    if (yigin_bos()==-1)
    {
        printf("yigin bos element yoktur");
    }
    for (int i = yigin.indice; i>=0; i--)
    {
        printf("[%d]\n",yigin.element[i]);
    }
}
void listemele1(yiginlar *yigin1){
    if (yigin_bos1(yigin1)==-1)
    {
        printf("yigin bos element yoktur");
    }
    for (int i = yigin1->indice; i>=0; i--)
    {
        printf("[%d]\n",yigin1->element[i]);
    }
}

void binary_cevri(int sayi){
    while (sayi>0)
    {
        int digit=sayi%2;
        ekleme(digit);
        sayi=sayi/2;
    }
    while (yigin.indice>=0)
    {
        printf("%d",cikarma());
    }
}

void binary_cevri1(int sayi){
    while (sayi>0)
    {
        int digit=sayi%2;
        ekleme1(&yigin2,digit);
        sayi=sayi/2;
    }
    while (yigin2.indice>=0)
    {
        printf("%d",cikarma1(&yigin2));
    }
}
*/



/*//implementation des files
typedef struct kuyruklar
{
    int indice;
    int element[boyut];
}kuyruklar;

kuyruklar kuyruk;

int kuyruk_bos(){
    if (kuyruk.indice==-1)
    {
        return -1;
    }
    return 1;
}

int kuyruk_bos1(kuyruklar *kuyruk1){
    if (kuyruk1->indice==-1)
    {
        return -1;
    }
    return 1;
}


int kuyruk_dolu(){
    if (kuyruk.indice>=boyut-1)
    {
        return -1;
    }
    return 1;
}

int kuyruk_dolu1(kuyruklar *kuyruk1){
    if (kuyruk1->indice>=boyut-1)
    {
        return -1;
    }
     return 1;
}

void ekleme(int sayi){
    if (kuyruk_dolu()==-1)
    {
        printf("kuyruk dolu element eklemezsiniz");
    }
    kuyruk.indice++;
    kuyruk.element[kuyruk.indice]=sayi;
}
void ekleme1(kuyruklar *kuyruk1 ,int sayi){
    if (kuyruk_dolu1(kuyruk1)==-1)
    {
        printf("kuyruk dolu element eklemezsiniz");
    }
    kuyruk1->indice++;
    kuyruk1->element[kuyruk1->indice]=sayi;
}

int cikarma(){
    if (kuyruk_bos()==-1)
    {
        printf("kuyruk bos element cikarmazsiniz");
        return -1;
    }

    int cmp=kuyruk.element[0];
    for (int i = 1; i < kuyruk.indice; i++)
    {
        kuyruk.element[i-1]=kuyruk.element[i];
    }
    kuyruk.indice--;
    return cmp;
}
int cikarma1(kuyruklar *kuyruk1){
    if (kuyruk_bos1(kuyruk1)==-1)
    {
        printf("kuyruk bos element cikarmazsiniz");
        return -1;
    }
    int cmp=kuyruk1->element[0];
    for (int i = 0; i < kuyruk1->indice; i++)
    {
        kuyruk1->element[i]=kuyruk1->element[i+1];
    }
    kuyruk.indice--;
    return cmp;
}

void listemele(){
    if (kuyruk_bos()==-1)
    {
        printf("kuyruk bos element yoktur");
    }
    for (int i = 0; i<=kuyruk.indice; i++)
    {
        printf("[%d] ",kuyruk.element[i]);
    }
     printf("\n");
}
void listemele1(kuyruklar *kuyruk1){
    if (kuyruk_bos1(kuyruk1)==-1)
    {
        printf("kuyruk bos element yoktur");
    }
    for (int i = 0; i<=kuyruk1->indice; i++)
    {
        printf("[%d]\n",kuyruk1->element[i]);
    }
    printf("\n");
}*/





/*//implementation des files circulaire cela nous permet de gerer le probleme de decalage dans la files usuels
typedef struct kuyruklar
{   
    int ilk_indice;
    int son_indice;
    int indice;
    int element[boyut];
}kuyruklar;

kuyruklar kuyruk;

int kuyruk_bos(){
    if (kuyruk.indice==-1)
    {
        return -1;
    }
    return 1;
}

int kuyruk_bos1(kuyruklar *kuyruk1){
    if (kuyruk1->indice==-1)
    {
        return -1;
    }
    return 1;
}


int kuyruk_dolu(){
    if (kuyruk.indice>=boyut-1)
    {
        return -1;
    }
    return 1;
}

int kuyruk_dolu1(kuyruklar *kuyruk1){
    if (kuyruk1->indice>=boyut-1)
    {
        return -1;
    }
     return 1;
}

void ekleme(int sayi){
    if (kuyruk_dolu()==-1)
    {
        printf("kuyruk dolu element eklemezsiniz");
    }
    kuyruk.element[kuyruk.son_indice]=sayi;
    kuyruk.son_indice=(kuyruk.son_indice+1)%boyut;
    kuyruk.indice++;
}
void ekleme1(kuyruklar *kuyruk1 ,int sayi){
    if (kuyruk_dolu1(kuyruk1)==-1)
    {
        printf("kuyruk dolu element eklemezsiniz");
    }
    kuyruk1->element[kuyruk1->son_indice]=sayi;
    kuyruk1->son_indice=(kuyruk1->son_indice+1)%boyut;
    kuyruk1->indice++;
}

int cikarma(){
    if (kuyruk_bos()==-1)
    {
        printf("kuyruk bos element cikarmazsiniz");
        return -1;
    }

    int cmp=kuyruk.element[kuyruk.ilk_indice];
    kuyruk.ilk_indice=(kuyruk.ilk_indice+1)%boyut;
    kuyruk.indice--;
    return cmp;
}
int cikarma1(kuyruklar *kuyruk1){
    if (kuyruk_bos1(kuyruk1)==-1)
    {
        printf("kuyruk bos element cikarmazsiniz");
        return -1;
    }
    int cmp=kuyruk1->element[kuyruk1->ilk_indice];
    kuyruk1->ilk_indice=(kuyruk1->ilk_indice+1)%boyut;
    kuyruk1->indice--;
    return cmp;
}

void listemele(){
    if (kuyruk_bos()==-1)
    {
        printf("kuyruk bos element yoktur");
    }
    for (int i = 0; i<=kuyruk.indice; i++)
    {
        printf("[%d] ",kuyruk.element[(kuyruk.ilk_indice+i)%boyut]);
    }
     printf("\n");
}
void listemele1(kuyruklar *kuyruk1){
    if (kuyruk_bos1(kuyruk1)==-1)
    {
        printf("kuyruk bos element yoktur");
    }
    for (int i = 0; i<=kuyruk1->indice; i++)
    {
        printf("[%d] ",kuyruk1->element[(kuyruk1->ilk_indice+i)%boyut]);
    }
    printf("\n");
}*/

//implementation de la recherche binaire par recursivite
int recherche_binaire(int T[],int debut,int fin,int value){
    if (debut>fin)
    {
        return -1;
    }
    int orta=(debut+fin)/2;
    if (T[orta]==value)
    {
       return 1;
    }
    
    if (value>T[orta])
    {
        return recherche_binaire(T,orta+1,fin,value);
    }
    else
    {
        return recherche_binaire(T,debut,orta-1,value);
    }
}

//implementation de la recherche binaire par iteration
int recherche_binaire_ite(int T[],int value,int debut,int fin){
    while (fin>=debut)
    {
        int orta=(fin+debut)/2;
        if (T[orta]==value)
        {
            return 1;
        }
        if (T[orta]>value)
        {
            fin=orta-1;
        }
        else
        {
            debut=orta+1;
        }
    }
    return -1;
}


int main(){
    /*//implementation des piles
    yigin.indice=-1;
    yigin2.indice=-1;
    binary_cevri(18);
    printf("\n");
    binary_cevri1(18);*/



    /*//implementation des files
    kuyruk.indice=-1;

    ekleme(5);
    ekleme(6);
    ekleme(9);
    ekleme(52);
    ekleme(30);
    ekleme(89);
    ekleme(60);
    listemele();
    printf("%d",cikarma());*/




    /*//implementation des files circulaires
    kuyruk.indice=-1;
    kuyruk.ilk_indice=0;
    kuyruk.son_indice=0;

    ekleme(5);
    ekleme(6);
    ekleme(9);
    ekleme(52);
    ekleme(30);
    listemele();
    printf("%d\n",cikarma());
    ekleme(89);
    listemele();
    printf("%d\n",cikarma());*/

    int T[]={1,2,3,7,8,9,10,12,15,20};
    int cmp ,cmp1;
    cmp=recherche_binaire_ite(T,15,0,10);
    if (cmp==1)
    {
        printf("La valeur recherche a ete trouver dans le tableau\n");
    }
    else{
        printf("La valeur recherche ne se trouve pas dans le tableau\n");
    }

    cmp1=recherche_binaire(T,0,10,15);
    if (cmp1==-1)
    {
        printf("La valeur recherche ne se trouve pas dans le tableau\n");
        
    }
    else
        printf("La valeur recherche a ete trouver dans le tableau\n");


    
}