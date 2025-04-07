#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void binary(int sayi){
    if (sayi==0)
    {
        return;
    }
    binary(sayi/2);
    printf("%d ",sayi%2);
    
}

void affiche_tableau(int T[],int n){
    if (n==0)
    {
       printf("%d ",T[0]);
       return;
    }
    affiche_tableau(T,n-1);
    printf("%d ",T[n]);
    
}

void affiche_tableau_inverse(int T[],int n){
    if (n==0)
    {
       printf("%d ",T[0]);
       return;
    }
    printf("%d ",T[n]);
    affiche_tableau_inverse(T,n-1);
    
}

int tableau_max(int T[],int n){
    if (n-1>0)
    {
        if (T[n-1]<tableau_max(T,n-1))
        {
            return tableau_max(T,n-1);
        }
        return T[n-1];
    }
}

int tableau_occurence(int T[],int n,int sayi){

    if (n==0)
    {
        return 0;
    }

    if (T[n-1]==sayi)
    {
        return 1+tableau_occurence(T,n-1,sayi);
    }
    else 
    {
        return tableau_occurence(T,n-1,sayi);
    }
}

int calcul_som(int n){
    if (n==0)
    {
        return 0;
    }
    return n+calcul_som(n-1);
    
}

int calcul_exopsant(int x,int n){
    if (n==0)
    {
        return 1;
    }
    return x*calcul_exopsant(x,n-1);
    
}

int combinaison(int p,int n){
    if (p==n)
    {
        return 1;
    }
    if (p==1)
    {
        return n;
    }
    return combinaison(p-1,n-1)+combinaison(p,n-1);
    
}

int pgcd(int a,int b){
    if (a-b==0)
    {
        return b;
    }
    if (a-b<b)
    {
        return pgcd(b,a-b);
    }
    return pgcd(a-b,b);
}

int pgcd2(int a,int b){
    if (b==0)
    {
        return a;
    }
    return pgcd2(b,a%b);
}

void monte(int n){
    if (n==0)
    {
       return;
    }
    monte(n-1);
    printf("%d ",n);
}

void descendre(int n){
    if (n==0)
    {
       return;
    }
    printf("%d ",n);
    descendre(n-1);
    
}

int somme_element_tableau(int T[],int n){
    if (n==0)
    {
       return 0;
    }
    return T[n-1]+somme_element_tableau(T,n-1);
    
}

int longueur_chaine(char *s ,int i){
    if (s[i]=='\0')
    {
       return 0;
    }
    return 1+longueur_chaine(s,i+1);
    
}
int occurence_caractere(char *s ,int i,char c){
    if (s[i]=='\0')
    {
       return 0;
    }
    if (s[i]==c)
    {
        return 1+occurence_caractere(s,i+1,c);
    }
    else
        return occurence_caractere(s,i+1,c);
}

void inverse_mot(char *s ,int i){
    if (s[i]=='\0')
    {
       return ;
    }
        inverse_mot(s,i+1);
        printf("%c",s[i]);

}
int long_mot(char *mot,int n){
    if (mot[n]=='\0')
    {
        return 0;
    }
    return mot[n]+long_mot(mot,n+1);
}
int tersi_rec(char *string,int debut,int fin){
    if (debut>=fin)
    {
        return 1;
    }

    if (string[debut]!=string[fin])
    {
        return 0;
    }
    return  tersi_rec(string,debut+1,fin-1);
}

//recherche une chaine de caractere dans une autre chaine
int tersi_rec_rech(char *string,char *string1,int debut,int debut1){
    if (string1[debut1]=='\0')
    {
        return 1;
    }

    if (string[debut]=='\0' || string[debut]!=string1[debut1])
    {
        return 0;
    }
        return tersi_rec_rech(string,string1,debut+1,debut1+1);
}





int main(){
   
   binary(20);
    printf("\n");
   int T[]={7,9,87,3,5,12,3,382,3,8,20,1};
   char *s="enfants";
   affiche_tableau(T,11);
    printf("\n");
   affiche_tableau_inverse(T,11);
   printf("\n");
   printf("Max= %d\n",tableau_max(T,12));
   printf("occurence= %d\n",tableau_occurence(T,12,200));
    printf("La somme des nombre allant de 0 a 10 est de: %d\n",calcul_som(10));
    printf("2 puissance 5 es de: %d\n",calcul_exopsant(2,6));
    printf("combinaison de 8 dans 2 est de : %d\n",combinaison(2,8));
    printf("Le pgcd de 15 et de 3 est de : %d\n",pgcd2(21,7));
    monte(5);
    printf("\n");
    descendre(5);
    printf("\n");
    printf("La somme des element du tableau T est de : %d\n",somme_element_tableau(T,12));
    printf("La longueur de la chaine est de : %d\n",longueur_chaine(s,0));
    printf("occurence du caractere 'e' dans la chaine s est de =  %d\n",occurence_caractere(s,0,'e'));
    printf("L'inverse de la chaine s ets de : ");
    inverse_mot(s,0);
    printf("\n");
    printf("La longueur du mot est de: %d\n",long_mot("grace",0));
    printf("%d\n",long_mot("grace",0)%7);
    char *chaine="hello";
    if (tersi_rec(chaine,0,(strlen(chaine)-1))==1)
    {
        printf("ce mot est un polidromme\n");
    }
    else
        printf("ce mot n'est pas un polidromme\n");


    char *chaine1="helo";
    if (tersi_rec_rech(chaine1,"el",0,0)==1)
    {
        printf("Le mot recherche a ete trouver dans la chaine\n");
    }
    else
        printf("Le mot recherche n'a pas ete trouver dans la chaine\n");











    return 0;
    
}