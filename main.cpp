#include <iostream>

using namespace std;

int main(){
    //Cryptage d'un texte en utilisant la méthode de Vigenere
    char texte[100];
    char cle[100];
    char texte_crypte[100];
    char alphabet_majuscule[26] = {'A','B','C','D','E','F','G','H','I','J',
                                   'K','L','M','N','O','P','Q','R','S',
                                   'T','U','V','W','X','Y','Z'};
    char alphabet_minuscule[26] = {'a','b','c','d','e','f','g','h','i','j',
                                   'k','l','m','n','o','p','q','r','s',
                                   't','u','v','w','x','y','z'};

    int i=0;

    cout << "Entrez le texte à crypter : ";
    cin >> texte;

    cout << "Entrez la clé de cryptage : ";
    cin >> cle;

    while(texte[i] != '\0'){
        texte_crypte[i] = ((texte[i] + cle[i]) % 26) + 'A';
        i++;
    }
    texte_crypte[i] = '\0';

    cout << "Texte crypté : " << texte_crypte << endl;

    return 0;
}