#include <iostream>
#include <string>
using namespace std;

#include "cryptanalyse.h"

int main(){
    int lengthkey;
    char key[100];

    /*----------------------------------------------------------------------*/

    lengthkey = findkeylenght(1, 100);
    cout << "La longueur de la cle est : " << lengthkey << " lettres" << endl;
    for (int t = 0; t < lengthkey; t++) {
        key[t] = find_oneletter_key(lengthkey, t);
    }
    key[lengthkey] = '\0';
    cout <<"La cle est : "<< key << endl;
    decodefichier(key, lengthkey);
    return 0;
}