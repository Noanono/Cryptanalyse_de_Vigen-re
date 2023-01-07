//
// Created by noah on 25/12/22.
//
#include <iostream>
#include <fstream>
using namespace std;

#include "vars.h"
#include "functions.h"

int Index_Of(char k, const char tab[], int tp){
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

    //Recherche de la fin du texte
    int end;
    txt_decry_Flux.seekg (0, txt_decry_Flux.end);
    end = txt_decry_Flux.tellg() ;
    txt_decry_Flux.seekg (0, txt_decry_Flux.beg);

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
            int index_leter, index_key;

            index_leter = Index_Of(leter, alphabet, 26);
            index_key = Index_Of(key[i], alphabet, 26);

            cry_leter = alphab_tab[index_key][index_leter];
        }

        //Envoie du caractère crypté sur le fichier cible
        txt_cry_Flux << cry_leter;

        i++;
        place_in_txt++;
    }
}

void Decrypt_Vigenere(string adresse_decry, char key[], string adresse_cry){

    ofstream Flux_decry_txt(adresse_decry);
    if(!Flux_decry_txt){
        cerr << "decry not open !" << endl;
        exit(1);
    }

    ifstream Flux_cry_txt(adresse_cry);
    if(!Flux_cry_txt){
        cerr << "cry not open !" << endl;
        exit(1);
    }

    //fin du texte crypté
    int end;
    Flux_cry_txt.seekg (0, Flux_cry_txt.end);
    end = Flux_cry_txt.tellg() ;
    Flux_cry_txt.seekg (0, Flux_cry_txt.beg);

    int place_in_txt = 0;

    char leter;
    char decry_leter;
    int i = 0;
    while(place_in_txt < end){
        if(key[i] == '\0'){
            i = 0;
        }

        //Cryptage du caractère
        //Recupération du caractère
        Flux_cry_txt >> leter;

        if(leter ==  '_') {
            decry_leter = leter;
        }else{
            int index_leter, index_key;

            index_leter = Index_Of(leter, alphabet, 26);
            index_key = Index_Of(key[i], alphabet, 26);

            if(index_key == 0){
                decry_leter = leter;
            }else{
                decry_leter = alphab_tab[26 - index_key][index_leter];
            }
        }


        //Envoie du caractère crypté sur le fichier cible
        Flux_decry_txt << decry_leter;

        i++;
        place_in_txt++;
    }



}