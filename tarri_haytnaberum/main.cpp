// matrici tari haytnaberum
#include <iostream>

using namespace std;

void findAndInsertMissingNumber(int sortedArray[], int n)
{
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        actualSum += sortedArray[i];
    }

    int missingNumber = expectedSum - actualSum;

    int insertPosition = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (sortedArray[i] < missingNumber)
        {
            insertPosition = i + 1;
        }
        else
        {
            break;
        }
    }

    for (int i = n - 2; i >= insertPosition; --i)
    {
        sortedArray[i + 1] = sortedArray[i];
    }

    sortedArray[insertPosition] = missingNumber;
}

int main()
{
    int n = 6;
    int sortedArray[6] = {1, 2, 3, 4, 6};

    cout << "skzbnakan zangvac" << endl;
    for (int i = 0; i < n - 1; ++i)
    {
        cout << sortedArray[i] << " ";
    }
    cout << endl;

    findAndInsertMissingNumber(sortedArray, n);