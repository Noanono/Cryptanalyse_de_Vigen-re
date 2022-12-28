//
// Created by noah on 25/12/22.
//
#include <iostream>
#include <fstream>
using namespace std;

#include "functions.h"

int Index_Of(char k, char tab[], int tp){
    int index = 0;

    while(index < tp && tab[index] != k){
        index++
    }
    if(index == tp){
        index = -1;
    }

    return index;
}

void Crypt_Vigenere(char adresse_decry[], char key[], char adresse_cry[]){
    ofstream txt_cry_Flux(adresse_cry);
    ifstream txt_decry_Flux(adresse_decry);

    char alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                         'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                         'r','s','t','u','v','w','x','y','z'};

    char leter = "";
    char cry_leter;
    int i = 0;
    while(leter != '\0'){
        if(key[i] == '\0'){
            i = 0;
        }

        //Cryptage du caractère
        //Recupération du caractère
        txt_decry_Flux.get(leter);

        int index_leter, index_cry_leter, index_key;

        index_leter = Index_Of(leter, alphabet, 26);
        index_key = Index_Of(key[i], alphabet, 26);

        index_cry_leter = index_leter + index_key;

        if(index_cry_leter >= 26){
            index_cry_leter -= 26;
        }

        cry_leter = alphabet[index_cry_leter];

        //Envoie du caractère crypté sur le fichier cible
        txt_cry_Flux.put(cry_leter);

        i++;
    }
}