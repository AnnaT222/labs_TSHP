#include <iostream>

// amenamec yndhanur bazmapatik
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int num1, num2;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int result = gcd(num1, num2);

    std::cout << "amenamec @ndhanur bazmapatiky " << num1 << " ev  " << num2 << " havasar e " << result << std::endl;

    return 0;
}
* /