#include <iostream>
#include <bitset>

uint32_t feistelFunction(uint32_t halfBlock, uint32_t roundKey)
{
    return halfBlock ^ roundKey;
}

void feistelRoundFunction(uint32_t &left, uint32_t &right, uint32_t roundKey)
{
    uint32_t temp = right;
    right = left ^ feistelFunction(right, roundKey);
    left = temp;
}

void feistelNetworkFunction(uint32_t &left, uint32_t &right, uint32_t *collectRoundKeys, int numRounds)
{
    for (int i = 0; i < numRounds; ++i)
    {
        feistelRoundFunction(left, right, roundKeys[i]);
    }
}

int main()
{
    uint32_t left = 0x01234567;
    uint32_t right = 0x89ABCDEF;

    uint32_t collectRoundKeys[] = {0x0F0F0F0F, 0xEFEFEFEF, 0x12345678};

    int numRounds = sizeof(collectRoundKeys) / sizeof(collectRoundKeys[0]);

    feistelNetworkFunction(left, right, collectRoundKeys, numRounds);

    std::cout << "" << std::hex << left << std::endl;
    std::cout << " " << std::hex << right << std::endl;

    return 0;
}