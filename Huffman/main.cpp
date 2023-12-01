#include <iostream>
#include <string>
#include "HuffmanTree.hpp"

int main()
{
    HuffmanTree myTree;
    std::string text{"this is my code"};
    myTree.buildTree(text);
    myTree.printTree();

    return 0;
}