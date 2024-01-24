#include "PointData.h"

PointData::PointData(std::string date_time, double autokonsumpcja, double eksport, double import_val, double pobor, double produkcja)
    : date_time(date_time), autokonsumpcja(autokonsumpcja), eksport(eksport), import_val(import_val), pobor(pobor), produkcja(produkcja) {}
