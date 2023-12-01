#ifndef TREENODE_H
#define TREENODE_H

class TreeNode
{
public:
    TreeNode(char symbol, int frequency);
    char getSymbol() const;
    int getFrequency() const;

private:
    char m_symbol;
    int m_frequency;
    TreeNode *m_left;
    TreeNode *m_right;

    friend class HuffmanTree;
};

#endif