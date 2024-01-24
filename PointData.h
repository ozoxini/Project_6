#ifndef POINTDATA_H
#define POINTDATA_H

#include <string>

class PointData {
public:
    std::string date_time;
    double autokonsumpcja;
    double eksport;
    double import_val;
    double pobor;
    double produkcja;

    PointData(std::string date_time, double autokonsumpcja, double eksport, double import_val, double pobor, double produkcja);
};

#endif  // POINTDATA_H
