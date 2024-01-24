#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <string>

class Measurement {
public:
    std::string timestamp;
    double autokonsumpcja;
    double eksport;
    double import;
    double pobor;
    double produkcja;
};

#endif