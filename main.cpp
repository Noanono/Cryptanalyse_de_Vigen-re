#include <iostream>
#include <string>
using namespace std;

#include "functions.h"

int main(){

    string adresse_decry_file1 = "/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/Decry_files/Cryptage_test1.txt";
    string adresse_cry_file1 = "/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/Cry_files/Cryptage_test1.txt";
    string adresse_decry_file2 = "/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/Decry_files/Decryptage_test1.txt";
    string adresse_cry_file2 = "/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/Cry_files/Decryptage_test1.txt";
    char key[8] = "a";

    Crypt_Vigenere(adresse_decry_file1, key, adresse_cry_file1);
    Decrypt_Vigenere(adresse_decry_file2, key, adresse_cry_file1);
    Crypt_Vigenere(adresse_decry_file2, key, adresse_cry_file2);

    return 0;
}