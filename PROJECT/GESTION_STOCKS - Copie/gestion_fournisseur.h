#ifndef GESTION_FOURNISSEUR_H_INCLUDED
#define GESTION_FOURNISSEUR_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "gestion_produit.h"
#include <stdbool.h>
#include <winsock.h>
#include <mysql.h>

#define MAX_SIZE_TAB_PROD_FOURNI 10
#define MAX_SIZE_TAB_FOURNI 100
#define TRI_CROISSANT 1
#define TRI_DECROISSANT 2

#define SAISIR_LISTE_FOURNISSEUR 1
#define CHARGEMENT_FOUNISSEUR_FICHIER 2
#define CHARGEMENT_FOURNISSEUR_BD 3
#define QUITTER_DEBUT 4

#define NOUVEAU_FOURNISSEUR 1
#define RECHERCHE_FOURNISSEUR 2
#define SUPPRIMER_FOURNISSEUR 3
#define AFFICHE_LISTE_FOURNISSEUR 4
#define TRI_CODE_LISTE_FOURNISSEUR 5
#define TRI_TEL_LISTE_FOURNISSEUR 6
#define GERER_FOURNISSEUR 7
#define ENREGISTRER_FOURNISSEUR_FICHIER 8
#define ENREGISTRER_FOURNISSEUR_BD 9
#define QUITTER 10

#define MODIFIER_FOURNISSEUR 1
#define AJOUTER_PRODUIT_FOURNISSEUR 2
#define SUPPRIMER_PRODUIT_FOURNISSEUR 3
#define AFFICHER_PRODUIT_FOURNISSEUR 4
#define RETOUR_MENU 5

#define MODIF_CODE 1
#define MODIF_TEL 2
#define MODIF_NUM_RUE 3
#define MODIF_NOM_RUE 4
#define MODIF_VILLE 5
#define MODIF_POSTAL 6
#define MODIF_PAYS 7
#define RETOUR_GESTION 8

/**Structures*/
struct Adresse  //structure de l'adresse du fournisseur
{
    int numero;
    char nomRue[30];
    char nomVille[30];
    int codePostal;
    char pays[30];
};
typedef struct Adresse ADR;

struct Date  //structure de la date du produit
{
    int jour;
    int mois;
    int annee;
};
typedef struct Date DATE_BIS;

struct Detail_Produit  //structure des details du produit
{
    int code;
    float Prix;
    float QteStock;
    DATE_BIS datelimite;

};
typedef struct Detail_Produit DETPROD;

struct Fournisseur  //structure du fournisseur
{
    int code;
    ADR adresse;
    long tel;
    PROD tabListProduit[MAX_SIZE_TAB_PROD_FOURNI];
    DETPROD tabListDetailProduit[MAX_SIZE_TAB_PROD_FOURNI];
    int nbProd;
};
typedef struct Fournisseur FOURNI;

/**Sous programmes*/
int menu_debut(); //affichage du menu de depart
int menu_fournisseur(); //affichage du menu fournisseur
ADR saisir_adresse(); //saisie de l'adresse du fournisseur
FOURNI saisir_fournisseur(); //saisie du fournisseur
void affiche_fournisseur(FOURNI frn); //affiche un fournisseur
void tri_liste_code(FOURNI* tab_fourn, int nb); //trier la liste par code
void tri_liste_tel(FOURNI* tab_fourn, int nb);//trier la liste par tel

void saisir_liste_fournisseur(FOURNI* tab_fourn, int nb); //saisie de la liste de fournisseurs
void charg_fourn_fichier(FOURNI* tab_fourn, char* PATH, int* nb); //chargement de la liste de fournisseurs depuis un fichier
void charg_fourn_bd(int* nb, FOURNI* listefournisseur, char* ip_adresss, char* user, char* password, char* db_name ); //chargement de la liste de fournisseurs depuis une bd

void nouveau_fournisseur(FOURNI* tab_fourn, FOURNI new_fourni, int nb); //ajouter un fournisseur
void recherche_fournisseur(FOURNI* tab_fourn, int nb, int code_fourni); //recherche un fournisseur dans la liste
void supprimer_fournisseur(FOURNI* tab_fourn, int nb, int code_fourni); //suppression d'un fournisseur dans la liste
void afficher_liste_fournisseur(FOURNI* tab_fourn, int nb); //afficher la liste des fournisseurs
int menu_gerer(); //afficher le menu pour gerer un fournisseur
void exporter_fournisseur_fichier(FOURNI* tab_fourn, char* PATH, int nb); //enregistrer les fournisseurs dans un fichier
void exporter_fournisseur_BD(int* nb, FOURNI* tab_fourn, char* ip_adresss, char* user, char* password, char* db_name ); //enregistrer les fournisseurs dans un BD

bool rechercher_prod_fournisseur(FOURNI fournisseur, PROD prod_recherche); //recherche si un produit appartien au fournisseur
int modif_fournisseur(); //modifier un fournisseur
FOURNI ajout_prod_fourn(FOURNI frn); //ajouter un produit au fournisseur
void supp_prod_fourn(FOURNI frn); //supprimer un produit de la liste prod du fournisseur
void affiche_prod_fourn(FOURNI frn); //affichage de la liste produit du fournisseur

#endif // GESTION_FOURNISSEUR_H_INCLUDED
