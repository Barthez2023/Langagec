/*ici on va implelmenter les abres binaires basee sur une logique differentes les elements sernt ajouter d efacon trier dans l' abre
le premier elmement sera ajouter ensuite avant d'ajouter le second element on vas faire le controle si l'element a inserrer est plus 
garnd que la racinne alors on l'ajoute a droite si non on l'ajoute a gauche et ainsi de suite */
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct arbre
{
    int value;
    struct arbre *left;
    struct arbre *right;
}arbre;
int sum=0;

//creation d'un arbre vide
arbre *new_tree(int x){
    arbre *tr=malloc(sizeof(*tr));
    if(tr==NULL){
        printf("Erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }
    tr->value=x;
    tr->left=NULL;
    tr->right=NULL;
    return tr;
}

void insertion(arbre **racine,int value){
    arbre *tr,*cmp;
    tr=new_tree(value);
    if (*racine==NULL)
    {
        *racine=tr;
        return;
    }
    cmp=*racine;
    while (1)
    {
        if (tr->value>cmp->value)
        {
           if (cmp->right==NULL)
           {
                cmp->right=tr;
                break;
           }
           else
                cmp=cmp->right;
        }
        else
        {
            if (cmp->left==NULL)
            {
                cmp->left=tr;
                break;
            }
            else
                cmp=cmp->left;
        }
    }
}





/*on definie les ofnction on_cikar arka_ekle on_ekle pour implementer la file a partie de la liste chaine
on_cikar=retirer dans la file arka_ekle ajouter dans la file  pour la file
on_cikar=retirer dans la pile on_ekle ajouter dans la pile  pour la pile*/ 
typedef struct YKliste_chainee                  
{
    arbre *data;
    struct YKliste_chainee *next;
}YKliste_chainee;  

arbre * on_cikar(YKliste_chainee **liste){
    arbre *cmp;
    if (*liste==NULL)
    {
        /*printf("veriden hic element yoktur\n");*/
        return NULL;
    }
    YKliste_chainee *gecici=*liste;
    cmp=gecici->data;
    *liste=gecici->next;
    free(gecici);
    return cmp;
}

void arka_ekle(YKliste_chainee **liste, arbre *cmp){
    YKliste_chainee *gecici,*ilk,*son;
    gecici=(YKliste_chainee*)malloc(sizeof(YKliste_chainee));
    if (gecici==NULL)
    {
        printf("Dynamik tahsis hatasi\n");
        exit(1);
    }
    gecici->data=cmp;
    gecici->next=NULL;
    if (*liste==NULL)
    {
        *liste=gecici;
    }
    else
    {
        son=*liste;
        while (son->next!=NULL)
        {
        son=son->next;
        }
        son->next=gecici;
    }
}

void *on_ekle(YKliste_chainee **liste, arbre *cmp){
    YKliste_chainee *gecici;
    gecici=(YKliste_chainee*)malloc(sizeof(YKliste_chainee));
    if (gecici==NULL)
    {
        printf("Dynamik tahsis hatasi\n");
        exit(1);
    }
    gecici->data=cmp;
    gecici->next=NULL;
    if (*liste==NULL)
    {
        *liste=gecici;
    }
    else
    {
        gecici->next=*liste;
        *liste=gecici;
    }
}
/*la suite du programme de l'abre binare*/


void print_arbre(arbre *racine){           //Breadth First Traversal:c'est une methode qui consiste a afficher les elements par niveau
    YKliste_chainee *file=NULL;
    arbre *tr=NULL;
    tr=racine;
    while (tr!=NULL)
    {

        if (tr->left!=NULL)
           arka_ekle(&file,tr->left);
        if (tr->right!=NULL)
           arka_ekle(&file,tr->right);

        printf("%d",tr->value);
        tr=on_cikar(&file);
        printf(" ");
    }

    printf("\n");
}


void Preorder_tarama(arbre *racine){           
    YKliste_chainee *pile=NULL;
    arbre *tr;
    tr=racine;
    while (tr!=NULL)
    {
        if (tr->right!=NULL)
           on_ekle(&pile,tr->right);
        if (tr->left!=NULL)
           on_ekle(&pile,tr->left);
        printf("%d",tr->value);
        tr=on_cikar(&pile);
        printf(" ");
    }

    printf("\n");
}

void Inorder_tarama(arbre *racine){           
    if (racine==NULL)
    {
        return;
    }
    Inorder_tarama(racine->left);
    printf("%d ",racine->value);
    Inorder_tarama(racine->right);
}


void postorder_tarama(arbre *racine){           
    if (racine==NULL)
    {
        return;
    }
    postorder_tarama(racine->left);
    postorder_tarama(racine->right);
    printf("%d ",racine->value);

}

void Preorder_tarama_recu(arbre *racine){           
    if (racine==NULL)
    {
        return;
    }
    printf("%d ",racine->value);
    Preorder_tarama_recu(racine->left);
    Preorder_tarama_recu(racine->right);
}

void postorder_tarama_ite(arbre *racine){           
    arbre *ptr;
    arbre *last=NULL;
    YKliste_chainee *pile=NULL;
    ptr=racine;
    while (pile!=NULL || ptr!=NULL)
    {
        while (ptr!=NULL)
        {
            on_ekle(&pile,ptr);
            ptr=ptr->left;
        }
        ptr=pile->data;
        if (ptr->right!=NULL && ptr->right!=last)
        {
            ptr=ptr->right;
        }
        else
        {
            printf("%d ", ptr->value);
            last=ptr;  
            on_cikar(&pile);
            ptr=NULL;
        }
    
    }
    printf("\n");
}

void ineorder_tarama_ite(arbre *racine){           
    arbre *ptr;
    arbre *last=NULL;
    YKliste_chainee *pile=NULL;
    ptr=racine;
    while (pile!=NULL || ptr!=NULL)
    {
        while (ptr!=NULL)
        {
            on_ekle(&pile,ptr);
            ptr=ptr->left;

        }
        ptr=on_cikar(&pile);
        printf("%d ", ptr->value);
        if (ptr->right!=NULL && ptr->right!=last)
        {
            ptr=ptr->right;
        }
        else
        {
            last=ptr;  
            ptr=NULL;
        }
    
    }
    printf("\n");
}

int somme_rec(arbre *racine){
    arbre *ptr=racine;
    if (ptr==NULL)
    {
        return 0;
    }
    return ptr->value+somme_rec(ptr->left)+somme_rec(ptr->right);
}

int somme_ite(arbre *racine){          
    YKliste_chainee *file=NULL;
    arbre *tr=NULL;
    tr=racine;
    int som=0;
    while (tr!=NULL)
    {

        if (tr->left!=NULL)
           arka_ekle(&file,tr->left);
        if (tr->right!=NULL)
           arka_ekle(&file,tr->right);

        som+=tr->value;
        tr=on_cikar(&file);
    }
    return som;
    printf("\n");
}

int min_arbre(arbre *racine){
    arbre *tr=racine;
    while (tr->left!=NULL)
    {
        tr=tr->left;
    }
    return tr->value;
}

int max_arbre (arbre *racine){
    arbre *tr=racine;
    while (tr->right!=NULL)
    {
        tr=tr->right;
    }
    return tr->value;
}


int min_arbre_rec(arbre *racine){
    arbre *tr=racine;
    if (tr==NULL)
    {
        exit;
    }
    if (tr->left==NULL)
    {
        return tr->value;
    }
    else
    {
       min_arbre_rec(tr->left);
    }
}

int max_arbre_rec(arbre *racine){
    arbre *tr=racine;
    if (tr==NULL)
    {
        exit;
    }
    if (tr->right==NULL)
    {
        return tr->value;
    }
    else
    {
       min_arbre_rec(tr->right);
    }
}

//dans  cette fonction on affiche le 1 ou -1 si l'elemnent a ete trouver ou pas
int recherche(arbre *racine ,int val){
    arbre *ptr;
    ptr=racine;
    if (ptr==NULL)
    {
        return -1;
    }
    if (ptr->value==val)
    {
        return 1;
    }
    if (ptr->value>val)
    {
        return  recherche(ptr->left,val);
    }
    else
    {
        return  recherche(ptr->right,val);
    }
}

//dans  cette fonction on affiche le nombre de noued parcourru ^pour trouver l'element recherche
/*int recherche_noeud(arbre *racine ,int val){
    arbre *ptr;
    ptr=racine;
    if (ptr==NULL)
    {
        return -1;
    }
    if (ptr->value==val)
    {
        return 1;
    }
    if (ptr->value>val)
    {
        int noeud= recherche_noeud(ptr->left,val);
        if (noeud != -1) {
            return 1 + noeud; // Ajouter le nœud courant
        }
    }
    else
    {
        int noeud=recherche_noeud(ptr->right,val);
        if (noeud != -1) {
            return 1 + noeud; // Ajouter le nœud courant
        }
    }
}*/

//dans  cette fonction on affiche le nombre de noued parcourru ^pour trouver l'element recherche
int recherche_noeud(arbre *racine ,int val){
    arbre *ptr;
    ptr=racine;
    if (ptr==NULL)
    {
        return -1;
    }
    if (ptr->value==val)
    {
        return 1;
    }
    if (ptr->value>val)
    {
        int noeud=recherche_noeud(ptr->left,val);
        if (noeud!=-1)
        {
            return 1+noeud; 
        }
    }
    else
    {
        int noeud=recherche_noeud(ptr->right,val);
        if (noeud!=-1)
        {
            return 1+noeud; 
        }
    }
}

int agac_seviye(arbre *racine){
    arbre *ptr=racine;
    if (ptr==NULL)
    {
        return 0;
    }
    return 1+agac_seviye(ptr->left);
    return 1+agac_seviye(ptr->right);
}

/*int agac_seviye(arbre *racine){
    arbre *ptr=racine;
    if (ptr==NULL)
    {
        return 0;
    }
    int left=agac_seviye(ptr->left);
    int right=agac_seviye(ptr->right);
    if (left>right)
    {
        return 1+left;
    }
    else
    {
        return 1+right;
    }
}*/

int nombre_noeud(arbre *racine){
    if (racine==NULL)
    {
        return 0;
    }
    return (1+nombre_noeud(racine->left)+nombre_noeud(racine->right));
}

void print_arbre_inverse(arbre *racine){ //Breadth First Traversal:c'est une methode qui consiste a afficher les elements par niveau du dernier niveau au premier niveau
    YKliste_chainee *file=NULL;
    YKliste_chainee *pile=NULL;
    arbre *tr=NULL;
    tr=racine;
    while (tr!=NULL)
    {
        if (tr->right!=NULL)
           arka_ekle(&file,tr->right);
        if (tr->left!=NULL)
           arka_ekle(&file,tr->left);

        on_ekle(&pile,tr);
        tr=on_cikar(&file);
    }
    while (pile!=NULL)
    {
        tr=on_cikar(&pile);
       printf("%d ", tr->value);
    }
    printf("\n");
}

arbre * abre_simetrik(arbre *racine){
    arbre *tr=NULL;
    if (racine==NULL)
    {
        return NULL;
    }
    tr=racine->left;
    racine->left=racine->right;
    racine->right=tr;
    abre_simetrik(racine->right);
    abre_simetrik(racine->left);

    return racine;
}

//calcul la somme des noeud qui on un seul enfant
int somme_rec_tek(arbre *racine){
    arbre *ptr=racine;
    if (ptr==NULL)
    {
        return 0;
    }
    if ((ptr->left==NULL && ptr->right!=NULL)|| (ptr->right==NULL && ptr->left!=NULL))
    {
        return ptr->value+somme_rec_tek(ptr->left)+somme_rec_tek(ptr->right);
    }
    return somme_rec_tek(ptr->left) + somme_rec_tek(ptr->right);
}

int somme_seviye(arbre *racine,int seviye){
    arbre *tr;
    tr=racine;
    if (seviye==0)
    {
        return tr->value;
    }
    return somme_seviye(tr->left,seviye-1)+somme_seviye(tr->right,seviye-1);
}

int difference(arbre *racine){

    arbre *gecici=NULL,*gecici1=NULL;
    arbre *ptr=NULL;
    ptr=racine;
    while (ptr!=NULL)
    {
        if (ptr->value<racine->value)
        {
            gecici=ptr;
            ptr=ptr->right;
        }
        else
            ptr=ptr->left;
    }
    
    ptr=racine;
    while (ptr!=NULL)
    {
        if (ptr->value>racine->value)
        {
            gecici1=ptr;
            ptr=ptr->left;
        }
        else
            ptr=ptr->right;
    }

    if (gecici1==NULL || gecici==NULL)
    {
       return -1;
    }
    return gecici1->value-gecici->value;
}



int main(){
    arbre *Arbre=NULL;
    /*insertion(&Arbre,70);
    insertion(&Arbre,77);
    insertion(&Arbre,75);
    insertion(&Arbre,60);
    insertion(&Arbre,45);
    insertion(&Arbre,30);
    insertion(&Arbre,81);
    insertion(&Arbre,64);
    insertion(&Arbre,52);
    insertion(&Arbre,62);*/

    insertion(&Arbre,23);
    insertion(&Arbre,18);
    insertion(&Arbre,44);
    insertion(&Arbre,12);
    insertion(&Arbre,20);
    insertion(&Arbre,35);
    insertion(&Arbre,52);
    insertion(&Arbre,10);


    print_arbre(Arbre);
    printf("\n");
    print_arbre_inverse(Arbre);
    printf("\n");

    Preorder_tarama(Arbre);
    Preorder_tarama_recu(Arbre);
    printf("\n");
    printf("\n");

    Inorder_tarama(Arbre);
    printf("\n");
    ineorder_tarama_ite(Arbre);
    printf("\n");
    
    postorder_tarama(Arbre);
    printf("\n");
    postorder_tarama_ite(Arbre);
    printf("\n");
    printf("La somme est de :%d\n",somme_rec(Arbre));
    printf("La somme est de :%d\n",somme_ite(Arbre));
    printf("Le minunum des elements de cet arbre  est de :%d\n",min_arbre(Arbre));
    printf("Le maximun des elements de cet arbre  est de :%d\n",max_arbre(Arbre));
    printf("Le minunum des elements de cet arbre par reccurcivite est de :%d\n",min_arbre_rec(Arbre));
    printf("Le maximun des elements de cet arbre par reccurcivite  est de :%d\n",max_arbre_rec(Arbre));
    
    int sayi=recherche(Arbre,89);
    if (sayi!=1)
    {
        printf("L'element recherche ne se trouve pas dans l'arbre\n");
    }
    else
        printf("L'element recherche se trouve dans l'arbre\n");

    printf("Le nombre de noued parcourru avant de trouver l'element 20 est de  :%d\n",recherche_noeud(Arbre,20));

    printf("Le niveau de ce graphe est de:%d\n",agac_seviye(Arbre));
    printf("Le nombre de  noeud presend dans ce graphe est de:%d\n",nombre_noeud(Arbre));
    

     arbre *Arbre1=NULL;
     Arbre1=abre_simetrik(Arbre);
     print_arbre(Arbre1);

    arbre *Arbre2=NULL;
    insertion(&Arbre2,23);
    insertion(&Arbre2,10);
    insertion(&Arbre2,30);
    insertion(&Arbre2,12);
    insertion(&Arbre2,11);
    insertion(&Arbre2,20);
    insertion(&Arbre2,40);
    insertion(&Arbre2,50);
    printf("La somme est de :%d\n",somme_rec_tek(Arbre2));


    arbre *Arbre3=NULL;
    insertion(&Arbre3,9);
    insertion(&Arbre3,6);
    insertion(&Arbre3,11);
    insertion(&Arbre3,2);
    insertion(&Arbre3,7);
    insertion(&Arbre3,15);
    printf("La somme est de :%d\n",somme_seviye(Arbre3,2));
    printf("La difference  est de :%d\n",difference(Arbre3));






    return 0;
}

