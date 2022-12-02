#include <iostream>
#include<fstream>

using namespace std;

int main(){
    //Cryptage d'un texte en utilisant la méthode de Vigenere
    char alphabet_majuscule[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char tab_vigenere_majuscule[27][27] = {  "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                                             "BCDEFGHIJKLMNOPQRSTUVWXYZA",
                                             "CDEFGHIJKLMNOPQRSTUVWXYZAB",
                                             "DEFGHIJKLMNOPQRSTUVWXYZABC",
                                             "EFGHIJKLMNOPQRSTUVWXYZABCD",
                                             "FGHIJKLMNOPQRSTUVWXYZABCDE",
                                             "GHIJKLMNOPQRSTUVWXYZABCDEF",
                                             "HIJKLMNOPQRSTUVWXYZABCDEFG",
                                             "IJKLMNOPQRSTUVWXYZABCDEFGH",
                                             "JKLMNOPQRSTUVWXYZABCDEFGHI",
                                             "KLMNOPQRSTUVWXYZABCDEFGHIJ",
                                             "LMNOPQRSTUVWXYZABCDEFGHIJK",
                                             "MNOPQRSTUVWXYZABCDEFGHIJKL",
                                             "NOPQRSTUVWXYZABCDEFGHIJKLM",
                                             "OPQRSTUVWXYZABCDEFGHIJKLMN",
                                             "PQRSTUVWXYZABCDEFGHIJKLMNO",
                                             "QRSTUVWXYZABCDEFGHIJKLMNOP",
                                             "RSTUVWXYZABCDEFGHIJKLMNOPQ",
                                             "STUVWXYZABCDEFGHIJKLMNOPQR",
                                             "TUVWXYZABCDEFGHIJKLMNOPQRS",
                                             "UVWXYZABCDEFGHIJKLMNOPQRST",
                                             "VWXYZABCDEFGHIJKLMNOPQRSTU",
                                             "WXYZABCDEFGHIJKLMNOPQRSTUV",
                                             "XYZABCDEFGHIJKLMNOPQRSTUVW",
                                             "YZABCDEFGHIJKLMNOPQRSTUVWX",
                                             "ZABCDEFGHIJKLMNOPQRSTUVWXY",};
    int i=0;
    int j=0;

    const char fichier_cle[50] = "C:/Documents/Telecom_SE/INFO1_Projet1/key.txt";
    const char fichier_txt_crypte[80] = "C:/Documents/Telecom_SE/INFO1_Projet1/message_cry.txt";
    const char fichier_txt_decrypte[80] = "C:/Documents/Telecom_SE/INFO1_Projet1/message_cry_decry.txt";

    ifstream cryptFlux(fichier_txt_crypte);

    if (cryptFlux){
        ofstream decryptFlux(fichier_txt_decrypte, ios::app);

        if (decryptFlux){
            ofstream cleFlux(fichier_cle, ios::app);

            if (cleFlux){

                //code here when all oppening are possible

            }else{
                cout << "Ouverture de \"key\" impossible !" << endl;
            }
        }else{
            cout << "Ouverture de \"message_cry_decry\" impossible !" << endl;
        }
    }else{
        cout << "Ouverture de \"message_cry\" impossible !" << endl;
    }

    return 0;
}