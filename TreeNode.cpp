#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

class TreeNode {
public:
    int value;
    std::unordered_map<int, std::shared_ptr<TreeNode>> children;

    TreeNode(int val) : value(val) {}

    void add_child(int key, std::shared_ptr<TreeNode> child) {
        children[key] = child;
    }

    std::shared_ptr<TreeNode> get_child(int key) {
        auto it = children.find(key);
        if (it != children.end()) {
            return it->second;
        }
        return nullptr;
    }

    std::vector<std::shared_ptr<TreeNode>> get_children() {
        std::vector<std::shared_ptr<TreeNode>> childList;
        for (auto& pair : children) {
            childList.push_back(pair.second);
        }
        return childList;
    }
};


