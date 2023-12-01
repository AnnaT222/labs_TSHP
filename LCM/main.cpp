#include <iostream>
#include <string>

std::string runLengthEncode(const std::string &input)
{
    std::string encoded;
    int length = input.length();

    for (int i = 0; i < length; i++)
    {
        char current = input[i];
        int count = 1;

        while (i + 1 < length && input[i] == input[i + 1])
        {
            i++;
            count++;
        }

        encoded += current;
        // encoded += std::to_string(count);
        encoded += count;
    }
    std::cout << "\n"
              << encoded.length() << "\t" << encoded[3] << "\n";
    return encoded;
}

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::string encoded = runLengthEncode(input);
    std::cout << "Encoded string: " << encoded << std::endl;

    return 0;
}