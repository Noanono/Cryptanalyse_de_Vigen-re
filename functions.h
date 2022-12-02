//
// Created by noah on 25/12/22.
//

#ifndef INFO1_PROJETVIGENERE_FUNCTIONS_H
#define INFO1_PROJETVIGENERE_FUNCTIONS_H

/*
 * R: Crypter un fichier texte avec une clé et la taille de la clé
 * E: 1 tab de char : l'adresse du fichier a crypter, 1 tab char : la clé, 1 entier : la taille de la clé, 1 tab char : l'adresse du fichier qui recoit le cryptage
 * S: vide
 */
void Crypt_Vigenere(char adresse_decry[], char key[], unsigned int key_size, char adresse_cry[]);

#endif //INFO1_PROJETVIGENERE_FUNCTIONS_H
