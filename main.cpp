#include <iostream>
#include <string>
using namespace std;

#include "functions.h"

int main(){

    string adresse_decry_file = "/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/Decry_files/Cryptage_test1.txt";
    string adresse_cry_file = "/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/Cry_files/Cryptage_test1.txt";
    char key[8] = "cochon";

    Crypt_Vigenere(adresse_decry_file, key, adresse_cry_file);

    return 0;
}