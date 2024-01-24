#include "DataAnalyzer.h"

DataAnalyzer::DataAnalyzer(const std::vector<PointData>& points) : root(nullptr) {
    buildTree(points);
}

DataAnalyzer::~DataAnalyzer() {
    delete root;
}

void DataAnalyzer::buildTree(const std::vector<PointData>& points) {
    root = new TreeNode("root");

    for (const auto& point : points) {
        std::vector<std::string> date_parts;
        // Rozdziel datę i czas
        // ...

        TreeNode* year_node = root->getChild(date_parts[0]);
        if (!year_node) {
            year_node = new TreeNode(date_parts[0]);
            root->addChild(date_parts[0], year_node);
        }

        TreeNode* month_node = year_node->getChild(date_parts[1]);
        // Implementuj resztę budowy drzewa

        // ...

        TreeNode* quarter_node = day_node->getChild(quarter_key);
        // Implementuj resztę budowy drzewa
    }
}

double DataAnalyzer::sumAutokonsumpcja(const std::string& start_date, const std::string& end_date) {
    double total_sum = 0.0;
    TreeNode* start_node = findNodeByDate(start_date);
    TreeNode* end_node = findNodeByDate(end_date);

    if (start_node && end_node) {
        std::vector<TreeNode*> nodesInRange;
        iterateNodesInRange(start_node, end_node, nodesInRange);

        for (const auto& node : nodesInRange) {
            // Dodaj odpowiednie sumowanie autokonsumpcji
            // total_sum += node->value.autokonsumpcja;
        }
    }

    return total_sum;
}

// Implementuj pozostałe funkcje według potrzeb

TreeNode* DataAnalyzer::findNodeByDate(const std::string& date) {
    // Implementuj funkcję znajdującą węzeł po dacie
    return nullptr;
}

void DataAnalyzer::iterateNodesInRange(TreeNode* start_node, TreeNode* end_node, std::vector<TreeNode*>& result) {
    // Implementuj funkcję iterującą po węzłach w określonym zakresie
}
