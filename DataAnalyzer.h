#ifndef DATAANALYZER_H
#define DATAANALYZER_H

#include "TreeNode.h"
#include "PointData.h"
#include <vector>
#include <string>

class DataAnalyzer {
public:
    DataAnalyzer(const std::vector<PointData>& points);
    ~DataAnalyzer(); // Dodane, aby zwolnić pamięć

    void buildTree(const std::vector<PointData>& points);
    double sumAutokonsumpcja(const std::string& start_date, const std::string& end_date);

private:
    TreeNode* root;

    TreeNode* findNodeByDate(const std::string& date);
    void iterateNodesInRange(TreeNode* start_node, TreeNode* end_node, std::vector<TreeNode*>& result);
};

#endif  // DATAANALYZER_H
