//
// Created by noah on 25/12/22.
//
#include <iostream>
#include <fstream>
using namespace std;

#include "functions.h"

void Crypt_Vigenere(char adresse_decry[], char key[], unsigned int key_size, char adresse_cry[]){
    ofstream txt_cry_Flux(adresse_cry);
    ifstream txt_decry_Flux(adresse_decry);

    char alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                         'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                         'r','s','t','u','v','w','x','y','z'};

    char leter;
    char cry_leter;
    do{
        //Recupération du caractère
        txt_decry_Flux.get(leter);

        //Cryptage du caractère
        char key_char;
        cry_leter = leter;

        //Envoie du caractère crypté sur le fichier cible
        txt_cry_Flux.put(cry_leter);
    }while(leter != '\0');
}