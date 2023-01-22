#ifndef GESTION_PRODUIT_H_INCLUDED
#define GESTION_PRODUIT_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE_TAB 100

#define TRI_CROISSANT 1
#define TRI_DECROISSANT 2
#define SAISIR_LISTE_PRODUIT 3
#define AFFICHE_LISTE_PRODUIT 4
#define TRI_PRIX_LISTE_PRODUIT 5
#define TRI_NOM_LISTE_PRODUIT 6
#define TRI_DESIGNATION_LISTE_PRODUIT 7
#define INSERTION_NOUVEAU_PRODUIT 8
#define ENREGISTRER_FICHIER_EXTERNE 9
#define CHARGEMENT_FICHIER_EXTERNE 10
#define QUITTER_MENU_PROD 11

struct Produit{ //structure du produit
    char nom[40];
    char designation[60];
    float prix;
};typedef struct Produit PROD;

int menu_produit();
PROD saisir_produit(); //saisie de produit
void saisir_liste_produit(PROD* tab_prod, int nb); //saisie de la liste de produits
void affiche_produit(PROD prd);
void affiche_liste_produit(PROD* tab_prod, int nb);
void tri_liste_produit_prix(PROD* tab_prod, int nb);
void tri_liste_produit_nom(PROD* tab_prod, int nb);
void tri_liste_produit_designation(PROD* listeProduit, int nb);
void inserer_un_produit(PROD* tab_prod, PROD new_prod, int nb);
void enregistrement_liste_produit_in_file(PROD* tab_prod, char* PATH, int nb);
void chargement_liste_produit_from_file(PROD* tab_prod, char* PATH, int* nb);

#endif // GESTION_PRODUIT_H_INCLUDED
