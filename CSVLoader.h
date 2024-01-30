#ifndef CSVLOADER_H
#define CSVLOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <stdexcept>
#include <ctime>
#include "PointData.h" // Assuming PointData is a class defined in PointData.h

class CSVLoader {
private:
    std::string filename;
    std::vector<PointData> points;

public:
    CSVLoader(const std::string& filename);

    void load_data();

    void save_to_binary_file(const std::string& filename);

    void load_from_binary_file(const std::string& filename);

    const std::vector<PointData>& get_loaded_data() const;
};

#endif // CSVLOADER_H
