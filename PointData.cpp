#include <string>

class PointData {
public:
    std::string date_time;
    double autokonsumpcja;
    double eksport;
    double import_val;
    double pobor;
    double produkcja;

    PointData(std::string dt, double autocons, double exp, double imp, double demand, double prod)
        : date_time(dt), autokonsumpcja(autocons), eksport(exp), import_val(imp), pobor(demand), produkcja(prod) {}
};


