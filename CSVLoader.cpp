#include "CSVLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>

CSVLoader::CSVLoader(const std::string& filename) : filename(filename) {}

CSVLoader::~CSVLoader() {}

void CSVLoader::load_data() {
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Błąd otwarcia pliku CSV: " << filename << std::endl;
            return;
        }

        std::string line;
        std::vector<std::string> header;
        std::getline(file, line);
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            header.push_back(cell);
        }

        if (!validate_header(header)) {
            std::cerr << "Brak lub nieprawidłowy nagłówek w pliku CSV. Oczekiwano co najmniej 6 kolumn." << std::endl;
            return;
        }

        int line_number = 1;

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::vector<std::string> row;
            
            while (std::getline(ss, cell, ',')) {
                row.push_back(cell);
            }

            if (!row.empty()) {
                process_row(row, line_number);
            }

            line_number++;
        }

        std::cout << "Wczytano " << points.size() << " rekordów." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Błąd podczas wczytywania danych z pliku CSV: " << e.what() << std::endl;
    }
}

void CSVLoader::save_to_binary_file(const std::string& filename) {
    try {
        std::ofstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Błąd otwarcia pliku binarnego do zapisu: " << filename << std::endl;
            return;
        }

        file.write(reinterpret_cast<const char*>(points.data()), points.size() * sizeof(PointData));

        std::cout << "Dane zapisano do pliku binarnego: " << filename << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Błąd podczas zapisu danych do pliku binarnego: " << e.what() << std::endl;
    }
}

void CSVLoader::load_from_binary_file(const std::string& filename) {
    try {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Błąd otwarcia pliku binarnego do odczytu: " << filename << std::endl;
            return;
        }

        file.seekg(0, std::ios::end);
        std::streampos size = file.tellg();
        file.seekg(0, std::ios::beg);

        points.resize(size / sizeof(PointData));
        file.read(reinterpret_cast<char*>(points.data()), size);

        std::cout << "Dane wczytano z pliku binarnego: " << filename << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Błąd podczas wczytywania danych z pliku binarnego: " << e.what() << std::endl;
    }
}

const std::vector<PointData>& CSVLoader::get_points() const {
    return points;
}

bool CSVLoader::validate_header(const std::vector<std::string>& header) {
    // Sprawdź, czy nagłówek zawiera co najmniej 6 kolumn
    return header.size() >= 6;
}

void CSVLoader::process_row(const std::vector<std::string>& row, int line_number) {
    try {
        // Pomijanie pustych wierszy
        if (std::all_of(row.begin(), row.end(), [](const std::string& cell) { return cell.empty(); })) {
            std::cout << "Pusty wiersz w pliku CSV. Linia: " << line_number << ". Pomijanie..." << std::endl;
            return;
        }

        std::string date_time_str = row[0];  // Zakładamy, że pierwsza kolumna to data i czas

        // Konwersja czasu do formatu RRRR-MM-DD GG:MM
        std::string formatted_date_time = /* Implementuj konwersję daty i czasu */;
        
        double autokonsumpcja = std::stod(row[1]);
        double eksport = std::stod(row[2]);
        double import_val = std::stod(row[3]);
        double pobor = std::stod(row[4]);
        double produkcja = std::stod(row[5]);

        // Tworzymy obiekt punktu i dodajemy go do listy
        PointData point(formatted_date_time, autokonsumpcja, eksport, import_val, pobor, produkcja);
        points.push_back(point);

    } catch (const std::exception& e) {
        std::cerr << "Błąd w linii " << line_number << ": " << e.what() << ". Pomijanie..." << std::endl;
    }
}
