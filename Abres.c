#include<stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Tree
{
    int value;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
}Tree;
//creation d'un arbre vide
Tree *new_tree(int x){
    Tree *tr=malloc(sizeof(*tr));
    if(tr==NULL){
        printf("Erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }
    tr->value=x;
    tr->left=NULL;
    tr->right=NULL;
    tr->parent=NULL;
    //identifie les elements creer un a un 
    printf("creation de l'element %d\n",tr->value);
    return tr;
}
//nettoyer un arbre
void clear_tree(Tree *tr){
    if (tr==NULL)
    {
        return;
    }
    printf("suppresion de %d\n",tr->value);
    clear_tree(tr->left);
    clear_tree(tr->right);
    free(tr);
    
} 
//cette fonction permet de joindre les noeuds des arbres
Tree *join(Tree *left, Tree *right,int node){
    Tree *tr=new_tree(node);
    tr->left=left;
    tr->right=right;
    if (left!=NULL)
    {
       left->parent=tr;
    }
    if (right!=NULL)
    {
        right->parent=tr;
    }
    return tr;
}
//afficher les abres: la methode par preffixes consiste a affciher tout les elements en commencant par ceux qui se trouve a la gauche et on remonte l'abre puis on affiche ceux qui se trouve a droite
void print_tree_prefix(Tree *tr){
    if (tr==NULL)
    {
        return;
    }
    if (tr->parent!=NULL)
    {
        printf("(%d) -> (%d)\n",tr->parent->value,tr->value);
    }
    else
        printf("(%d)\n",tr->value);
    if (tr->left!=NULL)
    {
        print_tree_prefix(tr->left);
    }
    if (tr->right!=NULL)
    {
        print_tree_prefix(tr->right);
    }
    
}

int count_tree_node(Tree *tr){
    if (tr==NULL)
    {
        return 0;
    }
    return(count_tree_node(tr->left)+count_tree_node(tr->right)+1);
     
    
}

int main(void){
    //Tree *arbre=new_tree(2);
    Tree *arbre=join(join(new_tree(8),join(new_tree(1),new_tree(5),3),2),new_tree(4),6);
    printf("\n*******************************************\n");
    print_tree_prefix(arbre);
    printf("Le nombre d'element contenu dans l'abre est %d\n",count_tree_node(arbre));

    printf("\n*******************************************\n");

    clear_tree(arbre);
















return 0;
}