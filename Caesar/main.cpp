#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    int key;
    cout << "Enter Text   ";
    getline(cin, text);
    cout << "Enter key   ";
    cin >> key;
    key = key % 26;
    if (key < 0)
        key = key * (-1);
    for (int i = 0; i < text.length(); i++)
    {
        text[i] += key;
    }
    cout << text;
}
"