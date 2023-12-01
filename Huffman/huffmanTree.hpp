#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "TreeNode.hpp"
#include <string>
#include <unordered_map>

class HuffmanTree
{
public:
    using FrequencyTable = std::unordered_map<char, int>;
    ~HuffmanTree();

    void buildTree(const std::string &);
    void printTree() const;

private:
    TreeNode *m_root{nullptr};
    FrequencyTable createFrequencyTable(const std::string &) const;
    void destroyTree(TreeNode *);
    void printTreeNode(TreeNode *root, int spaces) const;

    struct GreaterFrequency
    {
        bool operator()(TreeNode *lhs, TreeNode *rhs) const
        {
            return (lhs->getFrequency() > rhs->getFrequency());
        }
    };
};

#endif