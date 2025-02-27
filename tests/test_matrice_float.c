#include <stdio.h>
#include <stdlib.h>
#include "../include/matrice_float.h"

int main(int argc, char const *argv[])
{
    // test sans alocations
    matrice_t* mat1 = NULL;
    matrice_t* mat2 = NULL;
    matrice_t* res = NULL;
    saisir_coefficient(mat1);
    afficher_matrice(mat1);
    res = produit_matrice(mat1, mat2);

    // test avec allocations
    mat1 = allouer_matrice(2, 2);
    mat2 = allouer_matrice(2, 2);
    saisir_coefficient(mat1);
    saisir_coefficient(mat2);
    afficher_matrice(mat1);
    afficher_matrice(mat2);
    res = produit_matrice(mat1, mat2);
    afficher_matrice(res);
    printf("sortie affiche matrice\n");
   
    
    // test liberation
    printf("Désallocation matrice 1...\n");

    liberer_matrice(&mat1);
    /*printf("Fin Désallocation matrice 1...\n");
    printf("Désallocation matrice 2...\n");
    liberer_matrice(&mat2);
    printf("Fin Désallocation matrice 2...\n");
    printf("Désallocation matrice res...\n");
    liberer_matrice(&res);
    printf("Fin Désallocation matrice res...\n");*/
    if(mat1 == NULL){
        printf("désallocation correcte");
    }else{
        printf("désallocation false");
    }
    return 0;
}
