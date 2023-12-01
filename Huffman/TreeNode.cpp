#include "TreeNode.hpp"

TreeNode::TreeNode(char symbol, int freq) : m_symbol{symbol}, m_frequency{freq}, m_left{nullptr}, m_right{nullptr} {}

char TreeNode::getSymbol() const
{
    return m_symbol;
}

int TreeNode::getFrequency() const
{
    return m_frequency;
}