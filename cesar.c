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
 * Nom du fichier : cesar.c							          						  *
 *  																				  *
 *************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <assert.h>

int verifierAlphanumerique(char* message);

void chiffrementCesar(char message[], int cle);
void dechiffrementCésar(char* message, int cle);

int verifierAlphanumerique(char* message){
    int i = 0;
    while (i < strlen(message)){
        if ((message[i]<'A' && message[i]>'9')||
            (message[i]>'Z' && message[i]<'a')||
            (message[i]>'z')|| (message[i]<'0')
            && (message[i]!=' ' && message[i]!=10 && message[i]!=5))
        {
            return 0;
            break;
        }
        i++;
    }
    return 1;
}

void chiffrementCesar(char message[], int cle){
    /*Asserts :
        - Le message ne doit contenir que des caractères alphanumériques
        - La clé de chiffrement doit être inférieure à 26
        - La clé de chiffrement doit être supérieur ou égale à 0
    */
    assert(verifierAlphanumerique(message)==1);
    assert(cle<=26);
    assert(cle>=0);

    int i = 0;
    int ascii;
    while (i < strlen(message) && message[i]!=10){
        ascii = message[i]+cle;
        if (ascii-cle <= '9' && ascii-cle >='0' && (ascii>'9')){
            message[i]=ascii-10;
        } else if ((ascii > 'z')||(ascii>'Z' && (ascii < 'a') || (ascii-cle<='Z' && ascii>='a'))){
            message[i]=ascii-26;
            } else{
                message[i]=ascii;
            }
        i++;
   }
}

void dechiffrementCesar(char message[], int cle){
    /*Asserts :
        - Le message ne doit contenir que des caractères alphanumériques
        - La clé de chiffrement doit être inférieure à 26
        - La clé de chiffrement doit être supérieur ou égale à 0
    */
    assert(verifierAlphanumerique(message)==1);
    assert(cle<=26);
    assert(cle>=0);

    int i = 0;
    while (i < strlen(message) && message[i]!=10){
        message[i]-=cle;
        if (message[i]+cle <= '9' && message[i]+cle >='0' && (message[i]<'0' || message[i]>'9')){
            message[i]+=10;
        } else if ((message[i] < 'a' && message[i]>'Z')||
            (message[i]<'A' && message[i]>'9')||(message[i]+cle>='a' && message[i]<='Z')){
            message[i]+=26;
        }
        i++;
   }
}