#include "gestion_produit.h"
#include "gestion_fournisseur.h"

int main()
{
    /**Variables*/
    int nb; //nombre de cases du tableau
    int i;
    int choix; //numero du choix du menu
    int verif=false; //verifie si le code correspondà un fournisseur

    PROD tab_prod[MAX_SIZE_TAB]; //liste des produits
    PROD tmp; //produit temporaire
    FOURNI tab_fourn[MAX_SIZE_TAB]; //liste des fournisseurs
    FOURNI frntmp; //fournisseur temporaire

    int code_fourni; //code du fournisseur
    char nom_file[100]; //ficher de chargement

    /**1er Traitement : Initialisation de la liste de fournisseurs*/
    choix = menu_debut(); //menu de d�part pour commencer une liste de fournisseur
    switch(choix)
    {
    case (SAISIR_LISTE_FOURNISSEUR): //saisir la liste de fournisseurs
        do
        {
            printf("Introduire le nombre de fournisseur a saisir: ");
            scanf("%d", &nb);
        }
        while(nb<=0||nb>MAX_SIZE_TAB); //v�rifie que le nombre est entre 0 et nombre max
        saisir_liste_fournisseur(tab_fourn, nb);
        break;

    case (CHARGEMENT_FOUNISSEUR_FICHIER):
        printf("Introduire le chemin et le nom du fichier de chargement : ");
        scanf("%s", nom_file); //cherche le nom du fichier
        nom_file[99] = '\0';
        charg_fournisseur_fichier(tab_fourn, nom_file, &nb); //importe la liste depuis le fichier
        break;

    case (CHARGEMENT_FOURNISSEUR_BD):
        charg_fourn_bd(&nb, tab_fourn, "127.0.0.1", "root", "", "gestion_stocks"); //importe la liste depuis une base de donn�es
        break;

    default :
        break;
    }

    /**2eme Traitement : Options sur la liste de fournisseurs*/
    do
    {
        choix = menu_fournisseur(); //affiche le menu fournisseur
        switch(choix)
        {
        case (NOUVEAU_FOURNISSEUR):
            frntmp = saisir_fournisseur(); //saisie d'un nouveau fournisseur
            nouveau_fournisseur(tab_fourn, frntmp, nb); //ajout du nouveau fournisseur dans la liste
            nb++;
            break;

        case (RECHERCHE_FOURNISSEUR):
            printf("Saisir le code du fournisseur a rechercher : ");
            scanf("%d", &code_fourni); //saisie du code du fournisseur
            recherche_fournisseur(tab_fourn, nb, code_fourni); //recherche du fournisseur dans la liste
            break;

        case (SUPPRIMER_FOURNISSEUR):
            printf("Saisir le code du fournisseur a rechercher : ");
            scanf("%d", &code_fourni); //saisie du code du fournisseur
            supprimer_fournisseur(tab_fourn, nb, code_fourni); //suppression du fournisseur
            break;

        case (AFFICHE_LISTE_FOURNISSEUR):
            afficher_liste_fournisseur(tab_fourn, nb); //afficher la liste des fournisseurs
            break;

        case (TRI_CODE_LISTE_FOURNISSEUR):
            tri_liste_code(tab_fourn, nb); //trier les fournisseurs par leur code
            break;

        case (TRI_TEL_LISTE_FOURNISSEUR):
            tri_liste_tel(tab_fourn, nb); //trier les fournisseurs par leur tel
            break;

        case (GERER_FOURNISSEUR):
            printf("Saisissez le code du fournisseur a gerer : ");
            scanf("%d", &code_fourni); //scan le code du fournisseur rentré
            for (i = 0; i < nb; i++)
            {
                if (tab_fourn[i].code == code_fourni) //si le code correspond à un code dans la liste
                {
                    verif = true;
                }
            }
            if (verif==true)
                {
                    do
                    {
                        choix = menu_gerer(code_fourni); //affichage du menu de gestion
                        switch(choix)
                        {
                        case (MODIFIER_FOURNISSEUR):
                            choix = modif_fournisseur(); //choix du champ à modifier
                            switch(choix)
                            {
                            case(MODIF_CODE):
                                printf("Saisir le nouveau code : ");
                                scanf("%d", &tab_fourn[i].code);
                                break;

                            case(MODIF_TEL):
                                printf("Saisir le nouveau tel : ");
                                scanf("%d",&tab_fourn[i].tel);
                                break;

                            case(MODIF_NUM_RUE):

                                printf("Saisir le nouveau numero de rue : ");
                                scanf("%d",&tab_fourn[i].adresse.numero);
                                break;

                            case(MODIF_NOM_RUE):
                                printf("Saisir le nouveau nom de rue : ");
                                scanf("%d",&tab_fourn[i].adresse.nomRue);
                                tab_fourn[i].adresse.nomRue[29] = '\0';
                                fflush(stdin);
                                break;

                            case(MODIF_VILLE):
                                printf("Saisir le nouveau nom de rue : ");
                                scanf("%d",&tab_fourn[i].adresse.nomRue);
                                tab_fourn[i].adresse.nomRue[29] = '\0';
                                fflush(stdin);
                                break;

                            case(MODIF_POSTAL):
                                printf("Saisir le nouveau code postal : ");
                                scanf("%d",&tab_fourn[i].adresse.codePostal);
                                break;

                            case(MODIF_PAYS):
                                printf("Saisir le nouveau pays : ");
                                scanf("%d",&tab_fourn[i].adresse.pays);
                                tab_fourn[i].adresse.nomRue[29] = '\0';
                                fflush(stdin);
                                break;

                            case(RETOUR_GESTION):
                                break;
                            }
                            break;

                        case (AJOUTER_PRODUIT_FOURNISSEUR):
                            ajout_prod_fourn(tab_fourn[i]);
                            break;

                        case (SUPPRIMER_PRODUIT_FOURNISSEUR):
                            supp_prod_fourn(tab_fourn[i]);
                            break;

                        case (AFFICHER_PRODUIT_FOURNISSEUR):
                            affiche_prod_fourn(tab_fourn[i]);
                            break;

                        case (RETOUR_MENU):
                            printf("Retour vers le MENU GESTION FOURNISSEUR\n");
                            break;

                        default:
                            break;
                        }
                    }
                    while (choix!=RETOUR_MENU);
                }
                else
                {
                    printf("Ce fournisseur n'existe pas.\n");
                }
                break;

        case (ENREGISTRER_FOURNISSEUR_FICHIER):
            exporter_fournisseur_fichier(tab_fourn, "fichier_fourni.txt", nb);
            break;

        case (ENREGISTRER_FOURNISSEUR_BD):
            exporter_fournisseur_BD(&nb, tab_fourn, "127.0.0.1", "root", "", "gestion_stocks");
            break;

        case (QUITTER):
            printf("Au revoir !\n");
            break;

        default :
            break;
        }
    }
    while (choix!=QUITTER);

    return 0;
}

/**
    do //menu produit
    {
        choix = menu_produit();
        switch (choix)
        {
            case (SAISIR_LISTE_PRODUIT):
                do
                {
                    printf("Introduire le nombre de produit à saisir: ");
                    scanf("%d", &nb);
                }
                while (nb<=0 || nb>MAX_SIZE_TAB);
                saisir_liste_produit(tab_prod, nb);
                break;

            case (AFFICHE_LISTE_PRODUIT):
                affiche_liste_produit(tab_prod, nb);
                break;

            case (TRI_PRIX_LISTE_PRODUIT):
                tri_liste_produit_prix(tab_prod, nb);
                break;

            case (TRI_NOM_LISTE_PRODUIT):
                tri_liste_produit_nom(tab_prod, nb);
                break;

            case (TRI_DESIGNATION_LISTE_PRODUIT):
                tri_liste_produit_designation(tab_prod, nb);
                break;

            case (INSERTION_NOUVEAU_PRODUIT):
                tmp = saisir_produit();
                inserer_un_produit(tab_prod, tmp, nb);
                nb++;
                break;

            case(ENREGISTRER_FICHIER_EXTERNE):
                enregistrement_liste_produit_in_file(tab_prod, "fichier_produit.txt", nb);
                break;

            case(CHARGEMENT_FICHIER_EXTERNE):
                printf("Introduire le chemin et le nom du fichier de chargement : ");
                scanf("%s", nom_file);
                nom_file[99] = '\0';
                chargement_liste_produit_from_file(tab_prod, nom_file, &nb);
                break;

            case (QUITTER):
                printf("Vous quittez le menu produit...\n");
                break;

            default :
                break;
        }
    }while(choix!=QUITTER);
*/
