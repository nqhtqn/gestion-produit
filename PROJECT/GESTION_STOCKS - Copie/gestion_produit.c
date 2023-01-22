#include "gestion_produit.h"

int menu_produit() //affichage du menu produit
{
    int choix;
    do
    {
        printf("Introduire un choix :\n");
        printf("- %d - SAISIR LISTE PRODUIT\n", SAISIR_LISTE_PRODUIT);
        printf("- %d - AFFICHE LISTE PRODUIT\n", AFFICHE_LISTE_PRODUIT);
        printf("- %d - TRI PRIX LISTE PRODUIT\n", TRI_PRIX_LISTE_PRODUIT);
        printf("- %d - TRI NOM LISTE PRODUIT\n", TRI_NOM_LISTE_PRODUIT);
        printf("- %d - TRI DESIGNATION LISTE PRODUIT\n", TRI_DESIGNATION_LISTE_PRODUIT);
        printf("- %d - SAISIR LISTE PRODUIT\n", SAISIR_LISTE_PRODUIT);
        printf("- %d - INSERTION NOUVEAU PRODUIT\n", INSERTION_NOUVEAU_PRODUIT);
        printf("- %d - ENREGISTREMENT DANS FICHIER\n", ENREGISTRER_FICHIER_EXTERNE);
        printf("- %d - CHARGEMENT A PARIR DE FICHIER\n", CHARGEMENT_FICHIER_EXTERNE);
        printf("- %d - QUITTER\n", QUITTER_MENU_PROD);
        scanf("%d",&choix);
    }
    while(choix < SAISIR_LISTE_PRODUIT || choix > QUITTER_MENU_PROD );

    return choix;
}

PROD saisir_produit() //saisie de produit
{
    PROD prdtmp; //variable temporaire

    printf("Introduire le nom : ");
    scanf("%s",&prdtmp.nom); //saisie du nom
    prdtmp.nom[39] = '\0';
    fflush(stdin);

    printf("Introduire le prix : ");
    scanf("%f",&prdtmp.prix); //saisie du prix
    fflush(stdin);

    printf("Introduire la designation : ");
    scanf("%s",&prdtmp.designation); //saisie de la designation
    prdtmp.designation[59] = '\0';
    fflush(stdin);

    return prdtmp; //retour du produit créé
}

void saisir_liste_produit(PROD* tab_prod, int nb) //saisie de la liste de produits
{
    int i;
    for(i=0; i<nb; i++) //boucle
    {
        PROD prdtmp = saisir_produit(); //ajout d'un produit
        strcpy(tab_prod[i].nom, prdtmp.nom); //copy des variables créé dans le tableau de produits
        strcpy(tab_prod[i].designation, prdtmp.designation);
        tab_prod[i].prix = prdtmp.prix;
    }
}

void affiche_produit(PROD prd) //fonction d'affichage de produit
{
    printf("%s|%s|%f\n",prd.nom, prd.designation, prd.prix);
}


void affiche_liste_produit(PROD* tab_prod, int nb) //affichage de liste des produits
{
    int i;
    printf("La liste des produit : \n");
    for(i = 0; i<nb; i++)
    {
        affiche_produit(tab_prod[i]);
    }
}

void tri_liste_produit_prix(PROD* tab_prod, int nb) //fonction de tri des produits par prix
{
    int i;
    int j;
    int positionMax;
    int type_tri;
    PROD tmp;

    do
    {
        printf("Introduire le choix Croissant %d - Decroissant %d\n", TRI_CROISSANT, TRI_DECROISSANT);
        scanf("%d",&type_tri);
    }
    while(type_tri!=TRI_CROISSANT && type_tri!=TRI_DECROISSANT);

    for (i = 0; i < nb-1; i++)
    {
        for (j = i+1, positionMax = i; j < nb; j++)
        {
            if(type_tri == TRI_DECROISSANT)
            {
                if (tab_prod[positionMax].prix < tab_prod[j].prix) //check si valeur max courante < prochaine valeur
                {
                    positionMax = j;
                }
            }
            else
            {
                if (tab_prod[positionMax].prix > tab_prod[j].prix) //check si valeur max courante > prochaine valeur
                {
                    positionMax = j;
                }
            }
        }
        if (positionMax != i) //permutation des valeurs
        {
            tmp = tab_prod[i];
            tab_prod[i] = tab_prod[positionMax];
            tab_prod[positionMax] = tmp;
        }
    }
}

void tri_liste_produit_nom(PROD* tab_prod, int nb) //fonction de tri de liste produit
{
    int i;
    int j;
    int positionMax;
    int type_tri;
    PROD tmp;

    do
    {
        printf("Introduire le choix Croissant %d - Decroissant %d\n", TRI_CROISSANT, TRI_DECROISSANT);
        scanf("%d",&type_tri);
    }
    while(type_tri!=TRI_CROISSANT && type_tri!=TRI_DECROISSANT);

    for (i = 0; i < nb-1; i++)
    {
        for (j = i+1, positionMax = i; j < nb; j++)
        {
            if(type_tri == TRI_DECROISSANT)
            {
                if (strcmp(tab_prod[positionMax].nom, tab_prod[j].nom) > 0) //check si valeur max courante > prochaine valeur
                {
                    positionMax = j;
                }
            }
            else
            {
                if (strcmp(tab_prod[positionMax].nom, tab_prod[j].nom) < 0) //check si valeur max courante < prochaine valeur
                {
                    positionMax = j;
                }
            }
        }
        if (positionMax != i) //permutation des valeurs
        {
            tmp = tab_prod[i];
            tab_prod[i] = tab_prod[positionMax];
            tab_prod[positionMax] = tmp;
        }
    }
}

void tri_liste_produit_designation(PROD* tab_prod, int nb)
{
    int i;
    int j;
    int positionMax;
    int type_tri;
    PROD tmp;

    do
    {
        printf("Introduire le choix Croissant %d - Decroissant %d\n", TRI_CROISSANT, TRI_DECROISSANT);
        scanf("%d",&type_tri);
    }
    while(type_tri !=TRI_CROISSANT && type_tri!=TRI_DECROISSANT);

    for (i = 0; i < nb-1; i++)
    {
        for (j = i+1, positionMax = i; j < nb; j++)
        {
            if(type_tri == TRI_DECROISSANT)
            {
                if (tab_prod[positionMax].designation < tab_prod[j].designation) //check si valeur max courante < prochaine valeur
                {
                    positionMax = j;
                }
            }
            else
            {
                if (tab_prod[positionMax].designation > tab_prod[j].designation) //check si valeur max courante > prochaine valeur
                {
                    positionMax = j;
                }
            }
        }
        if(positionMax != i) //permutation des valeurs
        {
            tmp = tab_prod[i];
            tab_prod[i] = tab_prod[positionMax];
            tab_prod[positionMax] = tmp;
        }

    }
}

void inserer_un_produit(PROD* tab_prod, PROD new_prod, int nb) //insere nouveau produit
{
    tab_prod[nb] = new_prod;
    nb++;
    tri_liste_produit_nom(nb, tab_prod);
}

void enregistrement_liste_produit_in_file(PROD* tab_prod, char* PATH, int nb) //enregistrement liste produit dans fichier
{
    int i;
    FILE* fp_prod_write= fopen(PATH, "w"); //PATH = lieu d'enregistrement du fichier

    if (!fp_prod_write) //test si fichier ouvert
    {
        printf("Erreur de l'ouverture du fichier");
        exit(-1);
    }

    for (i = 0; i < nb; i++)
    {
        fprintf(fp_prod_write,"%s %s %5.3f\n", tab_prod[i].nom, tab_prod[i].designation, tab_prod[i].prix);
    }
    printf("Enregistrement reussi.\n");
    fclose(fp_prod_write);
}

void chargement_liste_produit_from_file(PROD* tab_prod, char * PATH, int* nb) //import liste produit depuis fichier
{
    char ligne[200];
    int i;
    FILE* fp_prod_read = fopen(PATH, "r");

    if (!fp_prod_read)
    {
        printf("Erreur de l'ouverture du fichier");
        exit(-1);
    }
    i = 0;

    while(fgets(ligne, 200, fp_prod_read))
    {
        sscanf(ligne,"%s %s %f",tab_prod[i].nom, tab_prod[i].designation, &tab_prod[i].prix);
        i++;
    }
    *nb = i;
    printf("chargement reussi.\n");
    fclose(fp_prod_read);
}
