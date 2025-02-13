#ifndef MATRICE_H
#define MATRICE_H

typedef struct matrice_t matrice_t;

matrice_t* allouer_matrice(int n, int m);
void saisir_coefficient(matrice_t* mat);
void afficher_matrice(matrice_t* mat);
matrice_t* produit_matrice(matrice_t* mat1, matrice_t* mat2);
void liberer_matrice(matrice_t** mat);
#endif