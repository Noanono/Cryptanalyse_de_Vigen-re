#include <iostream>
#include <string>
using namespace std;

#include "functions.h"

int main(){

    string adresse_decry_file = "./decry_files/Cryptage_test1.txt";
    string adresse_cry_file = "./cry_files/Cryptage_test1.txt";
    char key[8] = "cochon";

    Crypt_Vigenere(adresse_decry_file, key, adresse_cry_file);

    return 0;
}