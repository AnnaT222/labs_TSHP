#include <iostream>
#include <string>

using namespace std;

string encryptVigenere(const string &message, const string &key)
{
    string encryptedMessage = "";
    for (size_t i = 0, j = 0; i < message.length(); i++)
    {
        char messageChar = message[i];

        if (isalpha(messageChar))
        {
            char shift = islower(messageChar) ? 'a' : 'A';
            char keyChar = key[j % key.length()];
            char encryptedChar = (messageChar - shift + keyChar - 'A') % 26 + shift;
            encryptedMessage += encryptedChar;
            j++;
        }
        else
        {
            encryptedMessage += messageChar;
        }
    }
    return encryptedMessage;
}

string decryptVigenere(const string &message, const string &key)
{
    string decryptedMessage = "";
    for (size_t i = 0, j = 0; i < message.length(); i++)
    {
        char messageChar = message[i];

        if (isalpha(messageChar))
        {
            char shift = islower(messageChar) ? 'a' : 'A';
            char keyChar = key[j % key.length()];
            char decryptedChar = (messageChar - shift - (keyChar - 'A') + 26) % 26 + shift;
            decryptedMessage += decryptedChar;
            j++;
        }
        else
        {
            decryptedMessage += messageChar;
        }
    }
    return decryptedMessage;
}

int main()
{
    string message = "Test text";
    string key = "SECRET";

    string encrypted = encryptVigenere(message, key);
    string decrypted = decryptVigenere(encrypted, key);

    cout << "Original Message: " << message << endl;
    cout << "Encrypted Message: " << encrypted << endl;
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}