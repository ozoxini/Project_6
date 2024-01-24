#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <map>
#include <vector>

class TreeNode {
public:
    std::string value;
    std::map<std::string, TreeNode*> children;

    TreeNode(std::string value);
    ~TreeNode(); // Dodane, aby zwolnić pamięć
    void addChild(std::string key, TreeNode* child);
    TreeNode* getChild(std::string key);
    std::vector<TreeNode*> getChildren();
};

#endif  // TREENODE_H
