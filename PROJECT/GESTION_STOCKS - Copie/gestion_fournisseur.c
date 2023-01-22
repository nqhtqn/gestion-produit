#include "gestion_fournisseur.h"

int menu_debut() //affichage du menu de départ
{
    int choix;
    do
    {
        printf("Introduire un choix :\n");
        printf("- %d - Saisir une liste de fournisseur\n", SAISIR_LISTE_FOURNISSEUR);
        printf("- %d - Chargement de la liste a partir d un fichier\n", CHARGEMENT_FOUNISSEUR_FICHIER);
        printf("- %d - Chargement de la liste a partir d une base de donnees\n", CHARGEMENT_FOURNISSEUR_BD);
        printf("- %d - Quitter\n", QUITTER_DEBUT);
        scanf("%d",&choix);
    }
    while (choix < SAISIR_LISTE_FOURNISSEUR || choix > QUITTER_DEBUT );
    return choix;
}

int menu_fournisseur() //affichage du menu fournisseur
{
    int choix;
    do
    {
        printf("\nIntroduire un choix :\n");
        printf("- %d - Ajouter un nouveau fournisseur\n", NOUVEAU_FOURNISSEUR);
        printf("- %d - Rechercher un fournisseur\n", RECHERCHE_FOURNISSEUR);
        printf("- %d - Supprimer un fournisseur\n", SUPPRIMER_FOURNISSEUR);
        printf("- %d - Afficher la liste des fournisseurs\n", AFFICHE_LISTE_FOURNISSEUR);
        printf("- %d - Trier les fournisseurs par code\n", TRI_CODE_LISTE_FOURNISSEUR);
        printf("- %d - Trier les fournisseurs par tel\n", TRI_TEL_LISTE_FOURNISSEUR);
        printf("- %d - Gerer un fournisseur\n", GERER_FOURNISSEUR);
        printf("- %d - Exporter la liste de fournisseurs dans un fichier\n", ENREGISTRER_FOURNISSEUR_FICHIER);
        printf("- %d - Exporter la liste de fournisseurs dans une base de donnees\n", ENREGISTRER_FOURNISSEUR_BD);
        printf("- %d - Quitter (pensez a enregistrer)\n", QUITTER);
        scanf("%d",&choix);
    }
    while (choix < NOUVEAU_FOURNISSEUR || choix > QUITTER);
    return choix;
}

ADR saisir_adresse() //saisie de l'adresse du fournisseur
{
    ADR adrtmp; //variable temporaire
    printf("Saisie de l'adresse du fournisseur\n");

    printf("Saisir le numero de rue : ");
    scanf("%d",&adrtmp.numero); //saisie du numero de la rue

    printf("Saisir le nom de la rue : ");
    scanf("%s",&adrtmp.nomRue); //saisie du nom de la rue
    adrtmp.nomRue[29] = '\0';
    fflush(stdin);

    printf("Saisir le nom de la ville : ");
    scanf("%s",&adrtmp.nomVille); //saisie du nom de la ville
    adrtmp.nomVille[29] = '\0';
    fflush(stdin);

    printf("Saisir le code postal : ");
    scanf("%s",&adrtmp.codePostal); //saisie du code postal
    fflush(stdin);

    printf("Saisir le pays : ");
    scanf("%s",&adrtmp.pays); //saisie du pays
    adrtmp.pays[29] = '\0';
    fflush(stdin);

    return adrtmp; //renvoie de l'adresse créée dans la saisie d'un fournisseur
}

FOURNI saisir_fournisseur() //fonction de saisie de fournisseur
{
    FOURNI frntmp; //variable temporaire
    printf("Saisir le code du fournisseur : ");
    scanf("%d", &frntmp.code);//saisie du code du fournisseur

    frntmp.adresse = saisir_adresse(); //appel du programme pour la saisie de l'adresse

    printf("Saisir le numero de telephone du fournisseur : ");
    scanf("%d", &frntmp.tel); //saisie du telephone

    printf("Saisir le nombre de produit(s) du fournisseur : ");
    scanf("%d", &frntmp.nbProd); //saisie du nombre de produis du fournisseur

    printf("Saisir la liste des produits du fournisseur");
    saisir_liste_produit(frntmp.tabListProduit, frntmp.nbProd); //saisie des produits du fournisseur

    return(frntmp); //renvoie du fournisseur créé dans le tableau des fournisseurs
}

void affiche_fournisseur(FOURNI frn) //affiche un fournisseur
{
    printf("%d | %ld | %d %s %s %s %s | %d\n", frn.code, frn.tel, frn.adresse.numero, frn.adresse.nomRue, frn.adresse.nomVille, frn.adresse.codePostal, frn.adresse.pays, frn.nbProd);
}

void tri_liste_code(FOURNI* tab_fourn, int nb) //tri des fournisseurs par code
{
    int i; //variables
    int j;
    int positionMax;
    int type_tri;
    FOURNI tmp;

    do
    {
        printf("Introduire le choix Croissant %d - Decroissant %d\n", TRI_CROISSANT, TRI_DECROISSANT); //choix du type de tri
        scanf("%d", &type_tri);
    }
    while(type_tri !=TRI_CROISSANT && type_tri!=TRI_DECROISSANT);

    for (i = 0; i < nb-1; i++)
    {
        for (j = i+1, positionMax = i; j < nb; j++)
        {
            if(type_tri == TRI_DECROISSANT)
            {
                if (tab_fourn[positionMax].code < tab_fourn[j].code) //check si valeur max courante < prochaine valeur
                {
                    positionMax = j;
                }
            }
            else
            {
                if (tab_fourn[positionMax].code > tab_fourn[j].code) //check si valeur max courante > prochaine valeur
                {
                    positionMax = j;
                }
            }
        }

        if(positionMax != i) //permutation des valeurs
        {
            tmp = tab_fourn[i];
            tab_fourn[i] = tab_fourn[positionMax];
            tab_fourn[positionMax] = tmp;
        }
    }
}

void tri_liste_tel(FOURNI* tab_fourn, int nb) //tri des fournisseurs par tel
{
    int i; //variables
    int j;
    int positionMax;
    int type_tri;
    FOURNI tmp;
    do
    {
        printf("Introduire le choix Croissant %d - Decroissant %d\n", TRI_CROISSANT, TRI_DECROISSANT); //choix du type de tri
        scanf("%d", &type_tri);
    }
    while(type_tri !=TRI_CROISSANT && type_tri!=TRI_DECROISSANT);

    for (i = 0; i < nb-1; i++)
    {
        for (j = i+1, positionMax = i; j < nb; j++)
        {
            if (type_tri == TRI_DECROISSANT)
            {
                if (tab_fourn[positionMax].tel < tab_fourn[j].tel) //check si valeur max courante < prochaine valeur
                {
                    positionMax = j;
                }
            }
            else
            {
                if (tab_fourn[positionMax].tel > tab_fourn[j].tel) //check si valeur max courante > prochaine valeur
                {
                    positionMax = j;
                }
            }
        }

        if(positionMax != i) //permutation des valeurs
        {
            tmp = tab_fourn[i];
            tab_fourn[i] = tab_fourn[positionMax];
            tab_fourn[positionMax] = tmp;
        }
    }
}

void saisir_liste_fournisseur(FOURNI* tab_fourn, int nb) //saisie de la liste de fournisseurs
{
    int i;
    for(i = 0; i < nb; i++)
    {
        FOURNI tmp = saisir_fournisseur();
        tab_fourn[i] = tmp;
    }
}

void charg_fournisseur_fichier(FOURNI* tab_fourn, char* PATH, int *nb) //charger un fournisseur a partir d'un fichier
{
    char ligne[200]; //variable pour rentrer un fournisseur
    char nom_file_prod_fourn[100]; //nom du fichier
    int i = 0;
    FILE* fp_fourn_read = fopen(PATH, "r"); //ouverture du fichier en mode écriture
    if(!fp_fourn_read) //erreur
    {
        printf("Erreur de l'ouverture du fichier");
        exit(-1);
    }
    while(fgets(ligne, 200, fp_fourn_read))
    {
        sscanf("%d | %ld | %d %s %s %s %s | %d\n", tab_fourn[i].code, tab_fourn[i].tel, tab_fourn[i].adresse.numero, tab_fourn[i].adresse.nomRue, tab_fourn[i].adresse.nomVille, tab_fourn[i].adresse.codePostal, tab_fourn[i].adresse.pays, tab_fourn[i].nbProd);
        i++;
    }
    *nb = i; //nb dans le main prend la valeur du nombre de fournisseurs dans la liste
    printf("Chargement reussi.\n");
    fclose(fp_fourn_read);
}

void charg_fourn_bd(int* nb,FOURNI* listefournisseur, char* ip_adresss, char* user, char* password, char* db_name )
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    if(mysql_real_connect(&mysql,ip_adresss,user,password,db_name,0,NULL,0)) //connexion à la base de données
    {
        mysql_query(&mysql, "SELECT fournisseur.id, adresse.num_rue, adresse.nom_rue, adresse.ville, adresse.code_postal, adresse.pays, fournisseur.telephone FROM Fournisseur, adresse WHERE fournisseur.id = adresse.Fournisseur_id"); //requête de recherche des fournisseurs
        MYSQL_RES *result = NULL; //déclaration des pointeurs de structure
        MYSQL_ROW row;
        unsigned int i = 0;
        unsigned int num_champs = 0;
        int j =0;

        result = mysql_use_result(&mysql); //on met le jeu de resultat dans le pointeur result
        num_champs = mysql_num_fields(result); //on recupere le nombre de champs
        while ((row = mysql_fetch_row(result))) //on stock les valeurs de la ligne choisie
        {
            unsigned long *lengths;
            lengths = mysql_fetch_lengths(result); //stock de la taille
            listefournisseur[j].code = atoi(row[0]); //ajoute les différentes variables dans le tableau du programme
            listefournisseur[j].adresse.numero = atoi(row[1]);
            strcpy(listefournisseur[j].adresse.nomRue,row[2]);
            strcpy(listefournisseur[j].adresse.nomVille,row[3]);
            listefournisseur[j].adresse.codePostal = atoi(row[4]);
            strcpy(listefournisseur[j].adresse.pays,row[5]);
            listefournisseur[j].tel = atoi(row[6]);
            j++;
        }
        *nb = j; //nb dans le main prend la valeur du nombre de fournisseurs dans la liste
        mysql_free_result(result); //libération du jeu du résultat
        printf("Chargement reussi.\n");
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion a la BDD: %s", mysql_error(&mysql)); //erreur de connexion à la base de données
    }
}

void nouveau_fournisseur(FOURNI* tab_fourn, FOURNI new_fourni, int nb) //ajouter un fournisseur
{
    tab_fourn[nb] = new_fourni; //ajout d'un case avec le nouveau fournisseur dans la liste
    nb++;
    tri_liste_code(tab_fourn, nb); //tri par code
}

void recherche_fournisseur(FOURNI* tab_fourn, int nb, int code_fourni) //recherche un fournisseur dans la liste
{
    int i;
    for (i = 0; i < nb; i++)
    {
        if(tab_fourn[i].code == code_fourni) //si le code correspond à un code dans la liste
        {
            printf("Le fournisseur recherche :\n");
            affiche_fournisseur(tab_fourn[i]);
        }
    }
}

void supprimer_fournisseur(FOURNI* tab_fourn, int nb, int code_fourni) //suppression d'un fournisseur dans la liste
{
    int i;
    for (i = 0; i < nb; i++)
    {
        if(tab_fourn[i].code == code_fourni) //si le code correspond à un code dans la liste
        {
            free(&(tab_fourn[i])); //supprime le fournisseur
            printf("Fournisseur supprime");
        }
    }
}

void afficher_liste_fournisseur(FOURNI* tab_fourn, int nb) //afficher la liste des fournisseurs
{
    int i;
    printf("La liste des fournisseurs : \n");
    for(i = 0; i < nb; i++)
    {
        affiche_fournisseur(tab_fourn[i]);
    }
}

int menu_gerer() //afficher le menu pour gerer un fournisseur
{
    int choix;
    do
    {
        printf("Introduire un choix :\n");
        printf("- %d - Modifier un fournisseur\n", MODIFIER_FOURNISSEUR);
        printf("- %d - Ajouter un produit au fournisseur\n", AJOUTER_PRODUIT_FOURNISSEUR);
        printf("- %d - Supprimer un produit du fournisseur\n", SUPPRIMER_PRODUIT_FOURNISSEUR);
        printf("- %d - Afficher la liste des produits du fournisseur\n", AFFICHER_PRODUIT_FOURNISSEUR);
        printf("- %d - Revenir au menu principal\n", RETOUR_MENU);
        scanf("%d",&choix);
    }
    while (choix < MODIFIER_FOURNISSEUR || choix > RETOUR_MENU );

    return choix;
}


void exporter_fournisseur_fichier(FOURNI* tab_fourn, char* PATH, int nb) //export de la liste de fournisseur dans un fichier
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
        fprintf(fp_prod_write,"%d | %ld | %d %s %s %s %s | %d\n", tab_fourn[i].code, tab_fourn[i].tel, tab_fourn[i].adresse.numero, tab_fourn[i].adresse.nomRue, tab_fourn[i].adresse.nomVille, tab_fourn[i].adresse.codePostal, tab_fourn[i].adresse.pays, tab_fourn[i].nbProd);
    }
    printf("Enregistrement reussi.\n");
    fclose(fp_prod_write);
}

void exporter_fournisseur_BD(int* nb, FOURNI* tab_fourn, char* ip_adresss, char* user, char* password, char* db_name ) //export de la liste de fournisseur dans une bdd
{
    int i;
    char nomfourni[50];
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_OPT_WRITE_TIMEOUT,"option");
    char sql_statement[2048];
    if(mysql_real_connect(&mysql,ip_adresss,user,password,db_name,0,NULL,0))
    {
        for (i = 0; i < nb; i++)
        {
            affiche_fournisseur(tab_fourn[i]);
            printf("Donnez un nom à ce fournisseur\n");
            scanf("%s",nomfourni);
            fflush(stdin);
            sprintf(sql_statement, "INSERT INTO FOURNISSEUR(id,nom,telephone) VALUES('%d',%s,'%ld')", tab_fourn[i].code, nomfourni, tab_fourn[i].tel);
            if(mysql_query(&mysql, sql_statement) !=0)
            {
                printf("Query failed  with the following message:\n");
                printf("%s\n", mysql_error(&mysql));
                exit(1);
            }
            printf("Fournisseur %s a bien ete ajoute\n", nomfourni);
            //Fermeture de MySQL
            mysql_close(&mysql);
        }
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD: %s", mysql_error(&mysql));
    }

    return 0;
}

bool rechercher_prod_fournisseur(FOURNI fournisseur, PROD prod_recherche) //recherche d'un produit chez le fournisseur
{
    int i;
    bool retrouve = false;
    for (i = 0; retrouve == false && i < fournisseur.nbProd; i++)
    {
        if (strcmp(fournisseur.tabListProduit[i].designation, prod_recherche.designation) == 0
                &&
                strcmp(fournisseur.tabListProduit[i].nom, prod_recherche.nom) == 0
                &&
                fournisseur.tabListProduit[i].prix == prod_recherche.prix)
        {
            retrouve = true;
        }
    }
    return retrouve;
}

int modif_fournisseur() //modifier un fournisseur
{
    int choix; //choix du champ à modifier
    do
    {
        printf("- %d - Modifier le code\n", MODIF_CODE);
        printf("- %d - Modifier le tel\n", MODIF_TEL);
        printf("- %d - Modifier le numero de rue\n", MODIF_NUM_RUE);
        printf("- %d - Modifier le nom de la rue\n", MODIF_NOM_RUE);
        printf("- %d - Modifier la ville\n", MODIF_VILLE);
        printf("- %d - Modifier le code postal\n", MODIF_POSTAL);
        printf("- %d - Modifier le pays\n", MODIF_PAYS);
        printf("- %d - Retour au menu de gestion\n", RETOUR_GESTION);
        scanf("%d",&choix);
    }
    while (choix < MODIF_CODE || choix > RETOUR_GESTION );
}

FOURNI ajout_prod_fourn(FOURNI frn) //ajouter un produit au fournisseur
{
    PROD tmp = saisir_produit();
    if(rechercher_prod_fournisseur(frn, tmp) == false)
    {
        frn.nbProd++;
        frn.tabListProduit[frn.nbProd] = tmp;
    }
}

void supp_prod_fourn(FOURNI frn) //supprimer un produit de la liste prod du fournisseur
{
    int i;
    char nomprod;
    printf("Saisir le nom du produit a supprimer : ");
    scanf("%s", &nomprod); //demande le nom du produit à supprimer
    fflush(stdin);

    for (i=0;i<frn.nbProd;i++)
    if(nomprod == frn.tabListProduit[i].nom) //si le nom correspond à un nom dans la liste des produits
        {
            free(&(frn.tabListProduit[i])); //supprime le produit
            printf("Produit supprime");
        }
}

void affiche_prod_fourn(FOURNI frn) //affichage de la liste produit du fournisseur
{
    int i;
    for (i=0;i<frn.nbProd;i++)
    {
        affiche_produit(frn.tabListProduit[i]);
    }
}
