#include <iostream>
using namespace std;

#include "functions.h"

int main(){

    char adresse_decry_file[100];
    char adresse_cry_file[100];
    char key[50] = "cochon";

    adresse_decry_file = "./decry_files/Cryptage_test1.txt";
    adresse_cry_file = "./cry_files/Cryptage_test1.txt";

    Crypt_Vigenere(adresse_decry_file, key, adresse_cry_file);

    return 0;
}