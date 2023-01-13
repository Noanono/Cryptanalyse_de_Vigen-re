#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

#include "cryptanalyse.h"

char decodelettre(char lettre, char cle)
{
    char lettredecode;
    int valeurlettre;
    int valeurcle;
    int valeurdecode;

    /*----------------------------------------------------------------------*/

    // Si le cracatère n'est pas une lettre, retourner le caractère original
    if (!isalpha(lettre))
    {
        lettredecode = lettre;
    }
    else {
        // Convertir la lettre en sa valeur numérique (A=0, B=1, ..., Z=25)
        valeurlettre = toupper(lettre) - 'A';

        // Convertit la lettre de la clé en sa valeur numérique (A=0, B=1, ..., Z=25)
        valeurcle = toupper(cle) - 'A';

        // Soustrait la valeur de la clé à la valeur de la lettre du message et prend le resultat modulo 26
        valeurdecode = (valeurlettre - valeurcle + 26) % 26;

        // Convertir la valeur numérique en lettre (0=A, 1=B, ..., 25=Z)
        lettredecode = valeurdecode + 'A';
    }
    return lettredecode;
}

void decodefichier(const char cle[], unsigned int taille_cle)
{
    char lettre;
    int i;

    ifstream input("/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/message_cry.txt");
    ofstream output_file("/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/message_cry_decry.txt");
    ofstream key_file("/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/key.txt");
    key_file << cle;

    /*----------------------------------------------------------------------*/

    if (input)  // On teste si on peut ouvrir le fichier
    {
        i = 0;
        while (input.get(lettre)) { // On décode le fichier tant qu'il y a des caractères non lus dans le fichier d'input
            if (isalpha(lettre)) { // Pour avoir tolérence aux espaces et à la ponctuation
                // On écrit dans le fichier output le caractère décodé
                output_file << decodelettre(lettre, cle[i]);

                // On affecte à i, sa valeur +1 modulo la longueur de la clé car toutes les longueur_cle lettres, la valeur de la clé est la même
                i = (i + 1) % taille_cle;
            }
            else // si ce n'est pas une lettre on le recopie comme en entrée
            {
                output_file << lettre;
            }
        }
    }
    else {
        cout << "IMPOSSIBLE d'ouvrir le fichier" << endl;
    }
}

int findkeylenght(int min_key_length, int max_key_length)
{
    // Indice de coincidence attedu de la langue francaise 0.0778 = >0.07
    char c;
    int count[26] = { 0 }; // indice 0 compte les A, 1 compte les B
    int total_chars;
    float index;
    double distance = 1; // Distance entre l'indice de coincidence attendu de la langue francaise et celui trouvé
    double distance_opti = 1; // Distance optimisée (la plus faible possible)
    unsigned int length;

    int m;
    int k;

    float ioc[100] = { 0 }; // 100 = maxmimum de taille de la clé
    float index_moy;

    /*----------------------------------------------------------------------*/

    for (int i = min_key_length; i <= max_key_length && distance >= 0.011; i++) {// On teste toutes les longueurs de clé possible entre min_key_length et max_key_length, on s'arrete automatiquement si la distance par rapport à l'IoC attendu est inférieure à 0.01
        // l'indice i represente dans cette boucle la longueur de la clé actuellement testée
        ifstream file("/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/message_cry.txt");

        if (file) {
            for (m = 0; m < i; m++) {
                ifstream file("/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/message_cry.txt");
                // On remet toutes les variables à 0
                for (int j = 0; j < 26; j++) {
                    count[j] = 0;
                }
                index = 0;
                total_chars = 0;
                k = 0;

                file.seekg(0, ios::beg); // On retourne au debut du fichier
                // Lire le fichier caractère par caractère
                while (file.get(c)) {
                    if (isalpha(c)) {
                        if (k%i == m) { // On partage le texte en i parties

                            // m correspond à l'indice de la lettre de la clé

                            count[toupper(c) - 'A']++; // Compte le nombre de chaque lettre de l'alphabet
                            total_chars++; // Compte le nombre total de  caractères
                        }
                        k++;
                    }
                }

                // Calculer l'indice de coincidence pour chaque tranche, il y a autant de tranches que la longueur de la clé actuellement testée
                for (int p = 0; p < 26; p++) {
                    index += (float)(count[p] * (count[p] - 1)) / (total_chars * (total_chars - 1));
                }
                ioc[m] = index;
            }
            // Calcul de la moyenne de l'IoC des différentes parties
            index_moy = 0; // initialisation de la moyenne à 0
            for (int t = 0; t < i; t++) {
                index_moy += ioc[t];
            }
            index_moy = index_moy / (float)i;

            distance = sqrt((0.0778 - index_moy)*(0.0778 - index_moy)); // calcul de la valeur absolue de la distance
            if (distance < distance_opti) {
                distance_opti = distance;
                length = i;
            }
        }
        else
        {
            cout << "IMPOSSIBLE d'ouvrir le fichier" << endl;
        }
    }
    if (distance_opti > 0.01) {
        cout << "POSSIBLE ERREUR, essayer une cle plus grande" << endl; // verification, si la distance optimisée en sortie est trop éloignée de celle attendue, on signale l'utilisateur d'une possible erreur
    }
    return length;
}

char find_oneletter_key(int taill_cle, int indice_lettre_cle)
{
    int key;
    int key_opti = -1;
    double chisquared;
    char test_up;
    double expectedvalue[26];

    // ATTENTION ne jamais mettre 0 dans ce tableau de constantes car sinon division par 0 = ERREURS
    const double expectedpercentage[26] = { 0.0942,0.0102,0.0264,0.0339,0.1587,0.0095,0.0104,0.0077,0.0841,0.0089,0.0001,0.0534,0.0324,0.0715,0.0514,0.0286,0.0106,0.0646,0.0790,0.0726,0.0624,0.0215,0.0001,0.003,0.0024,0.032 };
    int chisquared_opti = 100000;
    int count[26] = { 0 };
    ifstream input("/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/message_cry.txt");
    char c;
    int k, i;
    int total_chars;

    /*----------------------------------------------------------------------*/

    // test de toutes les valeurs de clés possibles (de 0 à 25 = de A à Z)
    for (key = 0; key < 26; key++) {
        ifstream input("/media/noah/Data/Telecom_SE/Cryptanalyse_de_Vigen-re/message_cry.txt");
        // calcul de chi-squared statisic

        // remise à 0 des variables
        for (int j = 0; j < 26; j++) {
            count[j] = 0;
        }
        k = 0;
        total_chars = 0;
        chisquared = 0;
        // On compte chaque lettre
        input.seekg(0, ios::beg); // On retourne au debut du fichier


        while (input.get(c)) { // On teste le fichier tant qu'il y a des caractères non lus dans le fichier d'input
            if (isalpha(c)) {
                if (k%taill_cle == indice_lettre_cle) { // On partage le texte en i parties
                    count[(toupper(c) - 'A' - key+26)%26]++; // on ajoute 1 au tableau count à son indice de la lettre - la clé, car c'est comme si on avait fait le décodage du texte avec la clé testée, ca compte donc le nombre de lettres après avoir décodé avec la clé testée en question
                    // le +26 est la dans le cas ou apres la soustraction, le resultat serait négatif, cela n'influence pas autrement le résultat puisque ce dernier est modulo 26

                    total_chars++; // on compte le nombre total de caractères
                }
                k++;
            }
        }

        chisquared = 0;

        for (int lettre = 0; lettre < 26; lettre++) { // on le fait pour chaque lettre de l'alphabet
            // calcul des valeurs attendues dans le texte
            expectedvalue[lettre] = expectedpercentage[lettre] * total_chars;

            // calcul de l'erreur au carré normalizée pour chaque lettre
            chisquared += ((count[lettre] - expectedvalue[lettre])*(count[lettre] - expectedvalue[lettre])) / expectedvalue[lettre];
        }

        // quelle clé à le chisqured le plus faible
        if (chisquared < chisquared_opti) {
            chisquared_opti = chisquared;
            key_opti = key;
        }
    }
    key_opti = (char)(key_opti + 'A');
    return key_opti;
}