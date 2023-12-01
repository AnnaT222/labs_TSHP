// parz poxarinum
#include <iostream>
#include <string>

using namespace std;

string encode(const string &message, const string &key)
{
    string encodedMessage = message;

    for (char &ch : encodedMessage)
    {
        if (isalpha(ch))
        {
            char base = (islower(ch)) ? 'a' : 'A';
            ch = key[ch - base];
        }
    }

    return encodedMessage;
}

string decode(const string &encodedMessage, const string &key)
{
    string decodedMessage = encodedMessage;

    for (char &ch : decodedMessage)
    {
        if (isalpha(ch))
        {
            char base = (islower(ch)) ? 'a' : 'A';

            ch = static_cast<char>('A' + key.find(ch));
        }
    }

    return decodedMessage;
}

int main()
{
    string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string message, encodedMessage, decodedMessage;

    cout << "Enter a message to encode: ";
    getline(cin, message);

    encodedMessage = encode(message, key);
    cout << "Encoded message: " << encodedMessage << endl;

    decodedMessage = decode(encodedMessage, key);
    cout << "Decoded message: " << decodedMessage << endl;

    return 0;
}
