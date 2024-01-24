#ifndef CSVLOADER_H
#define CSVLOADER_H

#include "PointData.h"
#include <vector>
#include <string>

class CSVLoader {
public:
    CSVLoader(const std::string& filename);
    ~CSVLoader();

    void load_data();
    void save_to_binary_file(const std::string& filename);
    void load_from_binary_file(const std::string& filename);

    const std::vector<PointData>& get_points() const;

private:
    std::string filename;
    std::vector<PointData> points;

    bool validate_header(const std::vector<std::string>& header);
    void process_row(const std::vector<std::string>& row, int line_number);
};

#endif  // CSVLOADER_H
