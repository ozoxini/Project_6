#include "TreeNode.h"

TreeNode::TreeNode(std::string value) : value(value) {}

TreeNode::~TreeNode() {
    // Zwolnij pamięć dla dzieci
    for (auto& pair : children) {
        delete pair.second;
    }
}

void TreeNode::addChild(std::string key, TreeNode* child) {
    children[key] = child;
}

TreeNode* TreeNode::getChild(std::string key) {
    auto it = children.find(key);
    return (it != children.end()) ? it->second : nullptr;
}

std::vector<TreeNode*> TreeNode::getChildren() {
    std::vector<TreeNode*> result;
    for (const auto& pair : children) {
        result.push_back(pair.second);
    }
    return result;
}
