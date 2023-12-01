#include <iostream>
#include <string>

using namespace std;

string vigenereCipher(const string &input, const string &key, bool encrypt)
{
    string result;
    int keyLength = key.length();

    for (size_t i = 0; i < input.length(); i++)
    {
        char inputChar = input[i];
        char keyChar = key[i % keyLength];

        keyChar = keyChar % 256;

        char resultChar;

        if (encrypt)
        {
            resultChar = (inputChar + keyChar) % 256;
        }
        else
        {
            resultChar = (inputChar - keyChar + 256) % 256;
        }

        result += resultChar;
    }

    return result;
}

int main()
{
    string plaintext = "Hello, World!";
    string key = "SECRETVERBFORKEY";
    // coding
    string ciphertext = vigenereCipher(plaintext, key, true);
    cout << "coded: " << ciphertext << endl;
    // decoding
    string decryptedText = vigenereCipher(ciphertext, key, false);
    cout << "decoded: " << decryptedText << endl;

    return 0;
}