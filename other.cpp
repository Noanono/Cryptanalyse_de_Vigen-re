//
// Created by noah on 03/01/23.
//

#include <iostream>
#include <string>
#include <vector>

// Function to calculate the coincidence index
double coincidenceIndex(std::string str)
{
    int n = str.length();
    std::vector<int> freq(26, 0);

    // Calculate the frequency of each character
    for (int i = 0; i < n; i++)
        freq[str[i] - 'A']++;

    // Calculate the coincidence index
    double index = 0;
    for (int i = 0; i < 26; i++)
        index += (freq[i] * (freq[i] - 1));
    index = (index * 100) / (n * (n - 1));

    return index;
}

// Function to calculate the key length
int keyLength(std::string str)
{
    std::string s1, s2;
    int n = str.length();
    double maxIndex = 0;
    int keyLen = 0;

    // Try all possible key lengths
    for (int i = 1; i <= n / 2; i++) {

        s1 = "";
        s2 = "";

        // Divide the text into two parts
        for (int j = 0; j < i; j++)
            s1 += str[j];
        for (int j = i; j < n; j++)
            s2 += str[j];

        // Calculate the coincidence index for the two parts
        double index1 = coincidenceIndex(s1);
        double index2 = coincidenceIndex(s2);

        // Take the maximum of the two
        double index = std::max(index1, index2);

        // Update the maximum coincidence index
        if (maxIndex < index) {
            maxIndex = index;
            keyLen = i;
        }
    }

    return keyLen;
}

// Function to decrypt the text
std::string decrypt(std::string str, std::string key)
{
    int n = str.length();
    std::string decrypt = "";

    for (int i = 0; i < n; i++) {
        // convert to lowercase
        char ch = tolower(str[i]);

        // If it is not an alphabet, leave it as it is
        if (!isalpha(ch)) {
            decrypt += ch;
            continue;
        }

        // Encrypt the alphabet using the key
        decrypt += (char)((ch - key[i % key.length()] + 26) % 26 + 'a');
    }

    return decrypt;
}

int main() {
    std::string str = "BFWJQGCDLP";
    std::string key = "SECRET";

    std::cout << "Original Text: " << str << std::endl;
    std::cout << "Key: " << key << std::endl;

    return 0;
}