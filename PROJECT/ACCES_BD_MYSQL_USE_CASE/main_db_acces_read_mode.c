#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>

int main()
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if(mysql_real_connect(&mysql,"127.0.0.1","root","root","bd_gestion_stock",0,NULL,0))
//    if(mysql_real_connect(&mysql,"192.168.43.208","root","","tp1_cinema",0,NULL,0))
    {

        //Requête qui sélectionne tout dans ma table scores
        mysql_query(&mysql, "SELECT * FROM Fournisseur ORDER BY nom_rue");

        //Déclaration des pointeurs de structure
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        unsigned int i = 0;
        unsigned int num_champs = 0;
        int j =1;
        //On met le jeu de résultat dans le pointeur result
        result = mysql_use_result(&mysql);
        //On récupère le nombre de champs
        num_champs = mysql_num_fields(result);
        //on stock les valeurs de la ligne choisie
        while ((row = mysql_fetch_row(result)))
        {
            //On déclare un pointeur long non signé pour y stocker la taille des valeurs
            unsigned long *lengths;
            //On stocke ces tailles dans le pointeur
            lengths = mysql_fetch_lengths(result);
            //On affiche la position du joueur
            printf("%ld- ", j);
            //On fait une boucle pour avoir la valeur de chaque champs
            for(i = 1; i < num_champs; i++)
            {
                //On ecrit toutes les valeurs
                printf("%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
            }
            printf("\n");
            //On incrémente la position du joueur
            j++;
        }
        //Libération du jeu de résultat
        mysql_free_result(result);
        //Fermeture de MySQL
        mysql_close(&mysql);
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD: %s", mysql_error(&mysql));
    }

    return 0;
}
