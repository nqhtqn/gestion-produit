#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#include <mysql.h>

int main()
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_OPT_WRITE_TIMEOUT,"option");
    char sql_statement[2048];
    char numeleve[50];
    char nomeleve[50];
    char numchaleve[50];
    int ageeleve ;
    char adresseleve[100];


    if(mysql_real_connect(&mysql,"127.0.0.1","root","root","ecole",0,NULL,0))
    {

        printf("******************* Insertion d'un nouvel élève ***************\n");
        printf("Introduire l'age de l'eleve :");
        scanf("%d",ageeleve);
        fflush(stdin);
        printf("Introduire le numéro de l'eleve : ");
        scanf("%s",numeleve);
        fflush(stdin);
        printf("Introduire numéro de chambre sinon NULL :");
        scanf("%s",numchaleve);
        fflush(stdin);
        printf("Introduire le nom de l'eleve :");
        scanf("%s",nomeleve);
        fflush(stdin);
        printf("Introduire l'adresse de l'eleve :");
        scanf("%s",adresseleve);
        fflush(stdin);

        // Construct the SQL statement
        sprintf(sql_statement, "INSERT INTO ELEVE(NUM,NO,NOM,AGE,ADRESSE) VALUES('%s',%s,'%s','%d','%s')", numeleve, numchaleve,nomeleve,ageeleve,adresseleve);
        if(mysql_query(&mysql, sql_statement) !=0)
        {
            printf("Query failed  with the following message:\n");
            printf("%s\n", mysql_error(&mysql));
            exit(1);
        }
        printf("Eleve %s inserted into the database\n", numeleve);
        //Fermeture de MySQL
        mysql_close(&mysql);
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD: %s", mysql_error(&mysql));
    }

    return 0;
}
