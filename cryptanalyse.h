/*
R : décode 1 lettre en connaissant la valeur de la clé pour cette lettre
E : 2 caractères
S : 1 caractère
*/
char decodelettre(char lettre, char lettrecle);

/*
R : décode le fichier input.txt en connaissant la clé comme chaine de caractères et écrit le texte en clair dans le fichier output.txt
E : 1 tableau de caractères : la clé, 1 entier positif : la taille de la clé
S : vide
*/
void decodefichier(const char cle[], unsigned int tp_cle);

/*
R : trouver la longueur de la clé, le test est réalisé entre 2 bornes minimum et maximum
E : 2 entiers, la borne inférieure de test et la borne supérieure de test
S : 1 entier : la longueur de la clé
*/
int findkeylenght(int min_key_length, int max_key_length);

/*
R : trouve 1 lettre de la clé et la renvoyer
E : 1 entier : la taille de la clé, 1 entier : l'indice de la lettre de la clé souhaitée (si la clé est KEY, 0 permettra de trouver K, 1 pour E et 2 pour Y)
S : 1 caractère, la lettre de la clé correspondant à l'indice demandé
*/
char find_oneletter_key(int taill_cle, int indice_lettre_cle);