/**************************************************************************************
 * ASR => 4R2.04																	  *
 **************************************************************************************
 * 																					  *
 * N° de Sujet : 3																	  *
 *  																				  *
 **************************************************************************************
 * 																					  *
 * Intitulé : 	Chiffrement de messages												  *
 *  																				  *
 **************************************************************************************
 * 																					  *
 * Nom-prénom1 : Ferran Lucille														  *
 * 																					  *
 * Nom-prénom2 : Nguyen Phuong Thao													  *
 * 																					  *
 * Nom-prénom3 : Elallouf Fantin													  *
 * 																					  *
 **************************************************************************************
 * 																					  *
 * Nom du fichier : main.c															  *
 *  																				  *
 *************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "cesar.h"
#include "vigenere.h"

void main(){
    printf("*** CHIFFREMENT ET DECHIFFREMENT ***\n");

    printf("Choisissez une option :\n");
    printf("1 - Chiffrement de Cesar\n");
    printf("2 - Dechiffrement de Cesar\n");
    printf("3 - Chiffrement de Vigenere\n");
    printf("4 - Dechiffrement de Vigenere\n");
    int entree;
    scanf("%d",&entree);

    char* message = NULL;
    size_t taille = 0;
    int nbCharLu = 0;
    nbCharLu = getline(&message, &taille, stdin);
    printf("Saisir votre message : ");
    nbCharLu = getline(&message, &taille, stdin);
    printf("Message lu : %s\n", message);

    if (entree == 1 || entree == 2){
        int clef;
        printf("Entrez votre clef de chiffrement : ");
        scanf("%d",&clef);

        if (entree == 1){
            chiffrementCesar(message,clef);
            printf("\nLe chiffrement de votre message : %s\n",message);
        } else{
            dechiffrementCesar(message,clef);
            printf("\nLe dechiffrement de votre message : %s\n",message);
        }
    } else if (entree == 3 || entree == 4){
        char* clef = NULL;
        size_t tailleCle = 0;
        int nbCharLuCle = 0;
        printf("Entrez votre clef de chiffrement : ");
        nbCharLu = getline(&clef, &tailleCle, stdin);
        printf("Clef lu : %s\n", clef);

        if (entree == 3){
            chiffrementVigenere(message,clef);
            printf("\nLe chiffrement de votre message : %s\n",message);
        } else{
            dechiffrementVigenere(message,clef);
            printf("\nLe dechiffrement de votre message : %s\n",message);
        }
    }
}