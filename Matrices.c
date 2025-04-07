#include<stdio.h>
#include<stdlib.h>

/*Le but de cette section est de créer une matrice à deux dimensions, où chaque "ligne" est un tableau dynamique, pour permettre à la matrice d'être flexible en termes de taille (nombre de lignes et de colonnes déterminé à l'exécution).

MatB est une matrice (ou tableau 2D) de taille m × p, où :
m représente le nombre de lignes.
p représente le nombre de colonnes.
Cette boucle est nécessaire pour allouer l'espace mémoire pour les p colonnes de chaque ligne de la matrice MatB.*/

int** sumMatrice(int **MatA,int **MatB,int n,int m){
    int **MatC;
    // Allouer la mémoire pour le tableau bidimensionnel MatC
    MatC = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        MatC[i] = (int*)malloc(n * sizeof(int));/*Elle parcourt chaque ligne (indice i) de la matrice MatB.
                                                Pour chaque ligne, elle alloue dynamiquement un tableau de p colonnes (de type int), de sorte que chaque ligne ait l'espace nécessaire pour stocker p entiers.
                                                L'espace mémoire pour la matrice MatC est ainsi totalement alloué après l'exécution de cette boucle, et vous pouvez ensuite y stocker des valeurs dans un tableau 2D.*/
    }
    // Calculer la somme des deux matrices
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            MatC[i][j]=MatA[i][j]+MatB[i][j];
        }
        
    }
    return MatC;
    

}

int** soustractionMatrice(int **MatA,int **MatB,int n,int m){
    int **MatC;
    // Allouer la mémoire pour le tableau bidimensionnel MatC
    MatC = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        MatC[i] = (int*)malloc(n * sizeof(int));
    }
    // Calculer la somme des deux matrices
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            MatC[i][j]=MatA[i][j]-MatB[i][j];
        }
        
    }
    return MatC;
    

}


int** produitMatrice(int **MatA,int **MatB,int n,int m,int l){
    int **MatC;
    // Allouer la mémoire pour le tableau bidimensionnel MatC
    MatC = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        MatC[i] = (int*)malloc(m * sizeof(int));  // m correspond au nombre de colonnes de la matrice résultante
    }
    // Calculer la somme des deux matrices
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            MatC[i][j] = 0;  // Initialiser MatC[i][j] à 0 avant l'accumulation
            for (int k = 0; k < l; k++)
            {
                MatC[i][j]+=MatA[i][k]*MatB[k][j];
            }
        }
        
    }
    return MatC;

}

int** transposeMatrice(int **MatA,int n,int m){
    int **MatC;
    // Allouer la mémoire pour le tableau bidimensionnel MatC
    MatC = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        MatC[i] = (int*)malloc(m * sizeof(int));
    }
    // effectue la transposee
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            MatC[j][i]=MatA[i][j];
        }
        
    }
    return MatC;
}

double determinant_2_Matrice(int **MatA,int n,int m){
    double det;
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j <m; j++)
        {
            det=MatA[0][0]*MatA[1][1]-MatA[1][0]*MatA[0][1];
        }
        
    }
    return det;
}

int determinant_3_Matrice(int **MatA,int n,int m){
    double det;
    int **MatC;
    int k=0,asal_kosegen=0,yedek_kosegen=0;
    // Allouer la mémoire pour le tableau bidimensionnel MatC
    MatC = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        MatC[i] = (int*)malloc((m+2)* sizeof(int));
    }
        // Copier les éléments de MatA dans MatC

    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j <m+2; j++)
        {
            MatC[i][j]=MatA[i][j];
        }
        
    }
    // Ajouter des colonnes (valeurs par défaut ou spécifiées)
        for (int i = 0; i < n; i++) {
        for (int j = m; j < m + 2; j++) {
            MatC[i][j] =  MatA[i][k]; // ou une autre valeur selon le besoin
            k++;
        }
        k=0;
    }
    k=0;
    //on fait la somme des produit des diagonales principales
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j <m+2; j++)
        {
            asal_kosegen+=MatC[i][j]*MatC[k+1][j+1]*MatC[k+2][j+2];
        }
        k++;
        
    }

    return asal_kosegen;
}




void affiche(int **Mat,int n,int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", Mat[i][j]);
        }
        printf("\n");
    }
}

int** TakeMatris(int **Mat,int n,int m){
    for (int i = 0; i <n; i++)
    {
        for (int j= 0; j <m; j++)
        {
            printf("entrer l'elment a(%d,%d) :",i+1,j+1);
            scanf("%d",&Mat[i][j]);
        }
        
    }
    return Mat;
}





int main(){
    int **MatC ,**MatA,**MatB,**MatD,**MatE,**MatF,**MatG;
    int n,l,m,p;
    double det;

    printf("Entrer le nombre de ligne de la matrice1 :");
    scanf("%d",&n);
    printf("Entrer le nombre de colonne de la matrice1 :");
    scanf("%d",&l);
    printf("Entrer le nombre de ligne de la matrice2 :");
    scanf("%d",&m);
    printf("Entrer le nombre de colonne de la matrice2 :");
    scanf("%d",&p);

    MatA = (int**)malloc(n * sizeof(int*));
    MatB = (int**)malloc(m * sizeof(int*));

    for (int i = 0; i < n; i++) {
        MatA[i] = (int*)malloc(l * sizeof(int));        //allouent de la mémoire pour chaque ligne de matrice
    }
    for (int i = 0; i < m; i++) {
        MatB[i] = (int*)malloc(p * sizeof(int));
    }

    printf("Entrons la premire matrice A:\n");
    TakeMatris(MatA,n,l);
    
    /*printf("Matrice A:\n");
    affiche(MatA,n,l);

    printf("Entrons la deuxieme matrice B:\n");
    TakeMatris(MatB,m,p);
    
    printf("Matrice B:\n");
    affiche(MatB,m,p);

    if (n==m&&l==p)
    {
        printf("La somme de A et B est de :\n");
        MatC=sumMatrice(MatB,MatA,n,l);
        affiche(MatC,n,l);

        printf("La difference de A et B est de :\n");
        MatD=soustractionMatrice(MatB,MatA,m,p);
        affiche(MatD,m,p);
    }
    else
    {
        printf("L'operation d'addition et ou de soustraction n'est pas possible pour ces matrices.\n");
    }
    if (l==m)
    {
        printf("le produit de A et B est de :\n");
        MatE=produitMatrice(MatA,MatB,n,p,l);
        affiche(MatE,n,p);
    }
    else
    {
        printf("Le produit n'est pas possible pour ces matrices.\n");
    }
    affiche(MatA,n,l);

    printf("la transpose de A est :\n");
    MatF=transposeMatrice(MatA,n,l);
    affiche(MatF,l,n);*/
    affiche(MatA,n,l);
    if (n==2&&l==2)
    {
        det=determinant_2_Matrice(MatA,n,l);
        printf("Le determinant de a est :%f",det);
    }
    else
        printf("on ne peut pas trouver le determinant\n");
    

    printf("le determinant est:%d",determinant_3_Matrice(MatA,n,l));




    






























    
    for (int i = 0; i < n; i++) {
        free(MatA[i]);
        free(MatB[i]);
        free(MatC[i]);
        free(MatD[i]);
        free(MatE[i]);
    }
    free(MatA);
    free(MatB);
    free(MatC);
    free(MatD);
    free(MatE);
    return 0;
}