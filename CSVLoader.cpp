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
    CSVLoader(const std::string& filename) : filename(filename) {}

    void load_data() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Cannot open file: " << filename << std::endl;
            return;
        }

        std::string line;
        std::getline(file, line); // Read the header line
        std::istringstream headerStream(line);
        std::string cell;
        std::vector<std::string> headers;
        while (std::getline(headerStream, cell, ',')) {
            headers.push_back(cell);
        }

        if (headers.size() < 6) {
            std::cerr << "Invalid or missing header in CSV file. Expected at least 6 columns." << std::endl;
            return;
        }

        std::map<std::string, int> header_mapping = {
            {"time", -1}, {"autokonsumpcja (w)", -1}, {"eksport (w)", -1},
            {"import (w)", -1}, {"pobór (w)", -1}, {"produkcja (w)", -1}
        };

        for (size_t i = 0; i < headers.size(); ++i) {
            for (auto& kv : header_mapping) {
                if (headers[i].find(kv.first) != std::string::npos) {
                    kv.second = i;
                    break;
                }
            }
        }

        if (std::find_if(header_mapping.begin(), header_mapping.end(),
                         [](const std::pair<std::string, int>& p) { return p.second == -1; }) != header_mapping.end()) {
            std::cerr << "Failed to map all columns. Check the CSV file header." << std::endl;
            return;
        }

        int line_number = 2;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            std::vector<std::string> row;
            while (std::getline(lineStream, cell, ',')) {
                row.push_back(cell);
            }

            if (row.empty() || std::all_of(row.begin(), row.end(), [](const std::string& s) { return s.find_first_not_of(' ') == std::string::npos; })) {
                std::cerr << "Empty row in CSV file. Line: " << line_number << ". Skipping..." << std::endl;
                ++line_number;
                continue;
            }

            try {
                std::tm tm = {};
                std::istringstream dateStream(row[header_mapping["time"]]);
                dateStream >> std::get_time(&tm, "%d.%m.%Y %H:%M");
                if (dateStream.fail()) {
                    std::cerr << "Error on line " << line_number << ": Invalid date and time format. Skipping..." << std::endl;
                    ++line_number;
                    continue;
                }

                PointData point(
                    std::mktime(&tm),
                    std::stof(row[header_mapping["autokonsumpcja (w)"]]),
                    std::stof(row[header_mapping["eksport (w)"]]),
                    std::stof(row[header_mapping["import (w)"]]),
                    std::stof(row[header_mapping["pobór (w)"]]),
                    std::stof(row[header_mapping["produkcja (w)"]])
                );

                points.push_back(point);
            }
            catch (const std::exception& e) {
                std::cerr << "Error on line " << line_number << ": " << e.what() << ". Skipping..." << std::endl;
            }

            ++line_number;
        }

        std::cout << "Loaded " << points.size() << " records." << std::endl;
    }

    void save_to_binary_file(const std::string& filename) {
        std::ofstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Error while saving data to binary file: Cannot open file " << filename << std::endl;
            return;
        }

        // Assuming PointData has a serialize method
        for (const auto& point : points) {
            point.serialize(file);
        }

        std::cout << "Data saved to binary file: " << filename << std::endl;
    }

    void load_from_binary_file(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Error while loading data from binary file: Cannot open file " << filename << std::endl;
            return;
        }

        points.clear();

        // Assuming PointData has a deserialize method
        PointData point;
        while (point.deserialize(file)) {
            points.push_back(point);
        }

        std::cout << "Data loaded from binary file: " << filename << std::endl;
    }
};


