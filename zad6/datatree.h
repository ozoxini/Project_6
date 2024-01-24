#ifndef DATATREE_H
#define DATATREE_H

#include <vector>
#include "measurement.h"

class DataTree {
public:
    int year;
    std::vector<DataTree*> months;
    std::vector<Measurement> measurements;

    DataTree(int y);
    ~DataTree();

    void addMeasurement(const Measurement& measurement);
};

#endif