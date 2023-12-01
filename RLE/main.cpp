#include <iostream>
#include <string>

std::string runEncodeLength(const std::string &input)
{
    std::string encoded;
    int count = 1;

    for (int i = 1; i <= input.length(); ++i)
    {
        if (i < input.length() && input[i] == input[i - 1])
        {
            ++count;
        }
        else
        {

            encoded += input[i - 1] + std::to_string(count);
            count = 1;
        }
    }

    return encoded;
}

int main()
{
    std::string input = "aaaabbbcc";
    std::string encoded = runEncodeLength(input);

    std::cout << "Original: " << input << std::endl;
    std::cout << "Encoded: " << encoded << std::endl;

    return 0;
}