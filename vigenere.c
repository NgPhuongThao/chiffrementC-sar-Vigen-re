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
 * Nom du fichier : vigenere.c  													  *
 *  																				  *
 *************************************************************************************/
 #include <stdio.h>
#include <string.h>
#include <assert.h>

int verifierAlphabetique(char* message);
void uppercase(char* message);
void chiffrementVigenere(char* message, char* cle);
void dechiffrementVigenere(char* message, char* cle);

int verifierAlphabetique(char* message){
    int i = 0;
    while (i < strlen(message)){
        if ((message[i]<'A' && message[i]!=' ' && message[i]!=10 && message[i]!=5)||
            (message[i]>'Z' && message[i]<'a')||
            (message[i]>'z')
            )
        {
            return 0;
            break;
        }
        i++;
    }
    return 1;
}

void uppercase(char* message){
    int i = 0;
    while (i < strlen(message)){
        if (message[i]>='a' && message[i]<='z')
        {
            message[i]-=32;
        }
        i++;
    }
}

void chiffrementVigenere(char* message, char* cle){
    /*Asserts :
        - Le message ne doit contenir que des caractères alphanumériques
        - La clé n'est composée que de lettres majuscules
    */
    assert(verifierAlphabetique(message)==1);
    assert(verifierAlphabetique(cle)==1);
    uppercase(cle);

    int i = 0;
    int j = 0;
    while (i < strlen(message) && message[i]!=10){
        int ascii=message[i]+cle[j]-'A';
        printf("clef : %c    clair : %c    chiffré : %c\n", cle[j], message[i],ascii);
        if ((ascii > 'z')||(ascii>'Z' && (ascii < 'a') || (ascii-cle[j]+'A'<='Z' && ascii>='a'))){
            message[i]=ascii-26;
        } else{
            message[i]=ascii;
        }
        i++;

        if (j==strlen(cle)-2){
            j = 0;
        }else{
            j++;
        }
    }
}

void dechiffrementVigenere(char* message, char* cle){
    /*Asserts :
        - Le message ne doit contenir que des caractères alphanumériques
        - La clé n'est composée que de lettres majuscules
    */
    assert(verifierAlphabetique(message)==1);
    assert(verifierAlphabetique(cle)==1);
    uppercase(cle);

    int i = 0;
    int j = 0;
    while (i < strlen(message) && message[i]!=10){
        printf("cle : %d    clair : %d  ",cle[j],message[i]);
        message[i]=message[i]-cle[j]+'A';
        printf("chiffre : %d\n",message[i]);
        if ((message[i] < 'a' && message[i]>'Z')||
            (message[i]<'A')||(message[i]+cle[j]-'A'>='a' && message[i]<='Z')){
            message[i]+=26;
        }
        i++;

        if (j==strlen(cle)-2){
            j = 0;
        }else{
            j++;
        }
    }
}