#include <stdio.h>
#include <stdlib.h>
#include "../include/matrice_float.h"

int main(int argc, char const *argv[])
{
    matrice_t* mat1;
    matrice_t* mat2;
    matrice_t* res;
    saisir_coefficient(mat1);
    afficher_matrice(mat1);
    produit_matrice(mat1, mat2);
    liberer_matrice(mat1);
    return 0;
}
