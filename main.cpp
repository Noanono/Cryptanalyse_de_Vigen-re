#include <iostream>
using namespace std;

#include "functions.h"

int main(){

    char adresse_decry_file[100] = "./decry_files/Cryptage_test1.txt";
    char adresse_cry_file[100] = "./cry_files/Cryptage_test1.txt";
    char key[50] = "cochon";

    Crypt_Vigenere(adresse_decry_file, key, adresse_cry_file);

    return 0;
}