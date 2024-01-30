#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>

// Assuming TreeNode and PointData classes are defined in their respective headers
#include "TreeNode.h"
#include "PointData.h"

class DataAnalyzer {
public:
    DataAnalyzer(const std::vector<PointData>& points) {
        root = new TreeNode("root");
        build_tree(points);
    }

    ~DataAnalyzer() {
        delete root;
    }

    void build_tree(const std::vector<PointData>& points) {
        for (const auto& point : points) {
            std::vector<std::string> date_parts = split(point.date_time, " ");
            TreeNode* year_node = root->get_child(date_parts[0]);
            if (!year_node) {
                year_node = new TreeNode(date_parts[0]);
                root->add_child(date_parts[0], year_node);
            }
            TreeNode* month_node = year_node->get_child(date_parts[1]);
            if (!month_node) {
                month_node = new TreeNode(date_parts[1]);
                year_node->add_child(date_parts[1], month_node);
            }
            TreeNode* day_node = month_node->get_child(date_parts[2]);
            if (!day_node) {
                day_node = new TreeNode(date_parts[2]);
                month_node->add_child(date_parts[2], day_node);
            }
            std::vector<std::string> quarter_parts = split(date_parts[3], ":");
            std::string quarter_key = quarter_parts[0] + "-" + quarter_parts[1];
            TreeNode* quarter_node = day_node->get_child(quarter_key);
            if (!quarter_node) {
                quarter_node = new TreeNode(quarter_key);
                day_node->add_child(quarter_key, quarter_node);
            }
            quarter_node->add_child(point.date_time, new TreeNode(point));
        }
    }

    double sum_autokonsumpcja(const std::string& start_date, const std::string& end_date) {
        double total_sum = 0.0;
        TreeNode* start_node = find_node_by_date(start_date);
        TreeNode* end_node = find_node_by_date(end_date);
        if (start_node && end_node) {
            for (auto node : iterate_nodes_in_range(start_node, end_node)) {
                total_sum += node->value.autokonsumpcja;
            }
        }
        std::cout << "Suma autokonsumpcji od " << start_date << " do " << end_date << ": " << total_sum << std::endl;
        return total_sum;
    }

    // Other sum and average methods would be similar to sum_autokonsumpcja

    // Other compare methods would be implemented here

    // Other methods like search_records, print_data_in_range would be implemented here

private:
    TreeNode* root;

    TreeNode* find_node_by_date(const std::string& date) {
        std::vector<std::string> date_parts = split(date, " ");
        TreeNode* year_node = root->get_child(date_parts[0]);
        if (!year_node) {
            return nullptr;
        }
        TreeNode* month_node = year_node->get_child(date_parts[1]);
        if (!month_node) {
            return nullptr;
        }
        TreeNode* day_node = month_node->get_child(date_parts[2]);
        if (!day_node) {
            return nullptr;
        }
        std::vector<std::string> quarter_parts = split(date_parts[3], ":");
        std::string quarter_key = quarter_parts[0] + "-" + quarter_parts[1];
        TreeNode* quarter_node = day_node->get_child(quarter_key);
        if (!quarter_node) {
            return nullptr;
        }
        return quarter_node;
    }

    std::vector<TreeNode*> iterate_nodes_in_range(TreeNode* start_node, TreeNode* end_node) {
        std::vector<TreeNode*> nodes;
        std::stack<TreeNode*> stack;
        stack.push(start_node);
        while (!stack.empty()) {
            TreeNode* current_node = stack.top();
            stack.pop();
            nodes.push_back(current_node);
            std::unordered_map<std::string, TreeNode*> children = current_node->get_children();
            for (auto& child : children) {
                stack.push(child.second);
            }
            if (current_node == end_node) {
                break;
            }
        }
        return nodes;
    }

    std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
        std::vector<std::string> tokens;
        size_t start = 0;
        size_t end = str.find(delimiter);
        while (end != std::string::npos) {
            tokens.push_back(str.substr(start, end - start));
            start = end + delimiter.length();
            end = str.find(delimiter, start);
        }
        tokens.push_back(str.substr(start, end));
        return tokens;
    }
};


