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
    double sumEksport(const std::string& start_date, const std::string& end_date);
    double sumImport(const std::string& start_date, const std::string& end_date);
    double sumPobor(const std::string& start_date, const std::string& end_date);
    double sumProdukcja(const std::string& start_date, const std::string& end_date);
    double averageAutokonsumpcja(const std::string& start_date, const std::string& end_date);
    double averageEksport(const std::string& start_date, const std::string& end_date);
    double averageImport(const std::string& start_date, const std::string& end_date);
    double averagePobor(const std::string& start_date, const std::string& end_date);
    double averageProdukcja(const std::string& start_date, const std::string& end_date);
    void compareAutokonsumpcja(const std::string& start_date1, const std::string& end_date1, const std::string& start_date2, const std::string& end_date2);
    void compareEksport(const std::string& start_date1, const std::string& end_date1, const std::string& start_date2, const std::string& end_date2);
    void compareImport(const std::string& start_date1, const std::string& end_date1, const std::string& start_date2, const std::string& end_date2);
    void comparePobor(const std::string& start_date1, const std::string& end_date1, const std::string& start_date2, const std::string& end_date2);
    void compareProdukcja(const std::string& start_date1, const std::string& end_date1, const std::string& start_date2, const std::string& end_date2);
    void searchRecords(const std::string& condition);
    void printDataInRange(const std::string& start_date, const std::string& end_date);
    void saveToBinary(const std::string& filename);
    void readFromBinary(const std::string& filename);

private:
    TreeNode* root;

    TreeNode* findNodeByDate(const std::string& date);
    void iterateNodesInRange(TreeNode* start_node, TreeNode* end_node, std::vector<TreeNode*>& result);
};

#endif  // DATAANALYZER_H