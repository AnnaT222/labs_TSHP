#include "HuffmanTree.hpp"
#include <queue>
#include <iostream>
#include <iomanip>

HuffmanTree::FrequencyTable HuffmanTree::createFrequencyTable(const std::string &txt) const
{
    FrequencyTable table;
    for (char c : txt)
    {
        table[c] += 1;
    }
    return table;
}

void HuffmanTree::buildTree(const std::string &txt)
{
    FrequencyTable fTable = createFrequencyTable(txt);
    std::priority_queue<TreeNode *, std::vector<TreeNode *>, GreaterFrequency> pq;

    for (auto pair : fTable)
    {
        pq.push(new TreeNode(pair.first, pair.second));
    }

    while (pq.size() > 1)
    {
        TreeNode *left = pq.top();
        pq.pop();
        TreeNode *right = pq.top();
        pq.pop();

        TreeNode *newNode = new TreeNode('#', left->getFrequency() + right->getFrequency());
        newNode->m_left = left;
        newNode->m_right = right;
        pq.push(newNode);
    }

    if (!pq.empty())
    {
        m_root = pq.top();
    }
}

void HuffmanTree::printTree() const
{
    printTreeNode(m_root, 0);
}

void HuffmanTree::printTreeNode(TreeNode *root, int spaces) const
{
    if (root == nullptr)
        return;
    spaces += 10;

    printTreeNode(root->m_right, spaces);

    std::cout << '\n';
    std::cout << std::setw(spaces) << std::right << root->getSymbol() << ':' << root->getFrequency() << '\n';

    printTreeNode(root->m_left, spaces);
}

HuffmanTree::~HuffmanTree()
{
    destroyTree(m_root);
}

void HuffmanTree::destroyTree(TreeNode *root)
{
    if (root != nullptr)
    {
        destroyTree(root->m_left);
        destroyTree(root->m_right);
        delete root;
    }
}