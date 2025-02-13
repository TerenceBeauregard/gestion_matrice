#include <stdio.h>
#include <stdlib.h>
#include "../include/matrice_float.h"
struct matrice_t {
    int n; // nombre de lignes
    int m; // nombre de colonnes
    int **tab;
};

typedef struct matrice_t matrice_t;

matrice_t* allouer_matrice(int n, int m){
    matrice_t* mat = (matrice_t*) malloc(sizeof(matrice_t));
    mat->n = n;
    mat->m = m;
    mat->tab = (int**) malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        mat->tab[i] = (int*) malloc(m * sizeof(int));
    }
    return mat;
}

void saisir_coefficient(matrice_t* mat){
    if(mat == NULL){
        printf("Erreur : matrice non allouée\n");
        return;
    }
    for(int i = 0; i < mat->n; i++){
        for(int j = 0; j < mat->m; j++){
            printf("Saisir le coefficient (%d, %d) : ", i, j);
            scanf("%d", &mat->tab[i][j]);
        }
    }   
}

void afficher_matrice(matrice_t* mat){
    if(mat == NULL){
        printf("Erreur : matrice non allouée\n");
        return;
    }
    for(int i = 0; i < mat->n; i++){
        for(int j = 0; j < mat->m; j++){
            printf("\t%d ", mat->tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

matrice_t* produit_matrice(matrice_t* mat1, matrice_t* mat2){
    if(mat1 == NULL){
        printf("Erreur : Matrice 1 non allouée\n");
        return NULL;
    }
    if(mat2 == NULL){
        printf("Erreur : Matrice 2 non allouée\n");
        return NULL;
    }
    if(mat1->m != mat2->n){
        printf("Impossible de multiplier les matrices\n");
        return NULL;
    }
    matrice_t* res = allouer_matrice(mat1->n, mat2->m);
    for(int i = 0; i < mat1->n; i++){
        for(int j = 0; j < mat2->m; j++){
            res->tab[i][j] = 0;
            for(int k = 0; k < mat1->m; k++){
                res->tab[i][j] += mat1->tab[i][k] * mat2->tab[k][j];
            }
        }
    }
    return res;
}

void liberer_matrice(matrice_t** mat){
    if(mat == NULL){
        printf("Erreur : Matrice non allouee\n");
        return;
    }
    for(int i =0; i < (*mat)-> n; i++){
        free((*mat)->tab[i]);
    }
    free((*mat)->tab);
    free(mat);
    (*mat) = NULL;
}
