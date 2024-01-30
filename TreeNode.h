#ifndef TREENODE_H
#define TREENODE_H

#include <memory>
#include <unordered_map>
#include <vector>

class TreeNode {
public:
    int value;
    std::unordered_map<int, std::shared_ptr<TreeNode>> children;

    TreeNode(int val);

    void add_child(int key, std::shared_ptr<TreeNode> child);

    std::shared_ptr<TreeNode> get_child(int key);

    std::vector<std::shared_ptr<TreeNode>> get_children();
};

#endif // TREENODE_H
