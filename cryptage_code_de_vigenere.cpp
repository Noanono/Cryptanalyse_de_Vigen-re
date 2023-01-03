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
        index++;
    }
    if(index == tp){
        index = -1;
    }

    return index;
}

void Crypt_Vigenere(string adresse_decry, char key[], string adresse_cry){
    ofstream txt_cry_Flux(adresse_cry);
    if(!txt_cry_Flux){
        cerr << "cry file didn't opened !" << endl;
        exit(1);
    }

    ifstream txt_decry_Flux(adresse_decry);
    if(!txt_decry_Flux) {
        cerr << "decry file didn't opened !" << endl;
        exit(1);
    }

    char alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                         'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                         'r','s','t','u','v','w','x','y','z'};
    char alphabet_maj[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                         'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                         'R','S','T','U','V','W','X','Y','Z'};

    //Recherche de la fin du texte
    int end;
    txt_decry_Flux.seekg (0, txt_decry_Flux.end);
    end = txt_decry_Flux.tellg() ;
    txt_decry_Flux.seekg (0, txt_decry_Flux.beg);
    end--;

    int place_in_txt = 0;

    char leter;
    char cry_leter;
    int i = 0;
    while(place_in_txt < end){
        if(key[i] == '\0'){
            i = 0;
        }

        //Cryptage du caractère
        //Recupération du caractère
        txt_decry_Flux >> leter;

        if(leter == '_'){
            cry_leter = leter;
        }else{
            int index_leter, index_cry_leter, index_key;

            index_leter = Index_Of(leter, alphabet, 26);
            if(index_leter == -1){
                index_leter = Index_Of(leter, alphabet_maj, 26);
            }
            index_key = Index_Of(key[i], alphabet, 26);
            if(index_key == -1){
                index_key = Index_Of(key[i], alphabet_maj, 26);
            }

            index_cry_leter = index_leter + index_key;

            if(index_cry_leter >= 26){
                index_cry_leter -= 26;
            }

            cry_leter = alphabet[index_cry_leter];
        }

        //Envoie du caractère crypté sur le fichier cible
        txt_cry_Flux << cry_leter;

        i++;
        place_in_txt++;
    }
}

void Decrypt_Vigenere(string adresse_decry, char key[], string adresse_cry){

}