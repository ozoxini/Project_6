#include "CSVLoader.h"
#include "DataAnalyzer.h"
#include <iostream>

int main() {
    try {
        std::string filename;
        std::cout << "Podaj nazwę pliku CSV: ";
        std::cin >> filename;

        CSVLoader csv_loader(filename);
        csv_loader.load_data();

        DataAnalyzer analyzer(csv_loader.get_points());

        while (true) {
            std::cout << "\nMenu:\n"
                         "1. Suma autokonsumpcji w danym zakresie dat\n"
                         "2. Suma eksportu w danym zakresie dat\n"
                         "3. Suma importu w danym zakresie dat\n"
                         "4. Suma poboru w danym zakresie dat\n"
                         "5. Suma produkcji w danym zakresie dat\n"
                         "6. Średnia autokonsumpcji w danym zakresie dat\n"
                         "7. Średnia eksportu w danym zakresie dat\n"
                         "8. Średnia importu w danym zakresie dat\n"
                         "9. Średnia poboru w danym zakresie dat\n"
                         "10. Średnia produkcji w danym zakresie dat\n"
                         "11. Porównaj autokonsumpcję w dwóch przedziałach\n"
                         "12. Porównaj eksport w dwóch przedziałach\n"
                         "13. Porównaj import w dwóch przedziałach\n"
                         "14. Porównaj pobór w dwóch przedziałach\n"
                         "15. Porównaj produkcję w dwóch przedziałach\n"
                         "16. Wyszukaj rekordy spełniające warunek\n"
                         "17. Wypisz dane w danym zakresie\n"
                         "18. Zapisz dane do pliku binarnego\n"
                         "19. Odczytaj dane z pliku binarnego\n"
                         "20. Wyjście\n";

            std::string choice;
            std::cout << "Wybierz opcję (1-20): ";
            std::cin >> choice;

            if (choice == "1") {
                std::string start_date, end_date;
                std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date;
                std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date;
                analyzer.sum_autokonsumpcja(start_date, end_date);

            } else if (choice == "2") {
                std::string start_date, end_date;
                std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date;
                std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date;
                analyzer.sum_eksport(start_date, end_date);

            } else if (choice == "3") {
                std::string start_date, end_date;
                std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date;
                std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date;
                analyzer.sum_import(start_date, end_date);

            } else if (choice == "4") {
                std::string start_date, end_date;
                std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date;
                std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date;
                analyzer.sum_pobor(start_date, end_date);

            } else if (choice == "5") {
                std::string start_date, end_date;
                std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date;
                std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date;
                analyzer.sum_produkcja(start_date, end_date);

            } else if (choice == "6") {
                std::string start_date, end_date;
                std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date;
                std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date;
                analyzer.average_autokonsumpcja(start_date, end_date);

            } else if (choice == "7") {
                std::string start_date, end_date;
                std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date;
                std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date;
                analyzer.average_eksport(start_date, end_date);

            } else if (choice == "8") {
                std::string start_date, end_date;
                std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date;
                std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date;
                analyzer.average_import(start_date, end_date);

            } else if (choice == "9") {
                std::string start_date, end_date;
                std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date;
                std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date;
                analyzer.average_pobor(start_date, end_date);

            } else if (choice == "10") {
                std::string start_date, end_date;
                std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date;
                std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date;
                analyzer.average_produkcja(start_date, end_date);

            } else if (choice == "11") {
                std::string start_date_1, end_date_1, start_date_2, end_date_2;
                std::cout << "Podaj początkową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date_1;
                std::cout << "Podaj końcową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date_1;
                std::cout << "Podaj początkową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                std::cin >> start_date_2;
                std::cout << "Podaj końcową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                std::cin >> end_date_2;
                analyzer.compare_autokonsumpcja(start_date_1, end_date_1, start_date_2, end_date_2);

            } else if (choice == "12") {
                // Implementacja pozostałych opcji
                // ...

            } else if (choice == "20") {
                break;
            } else {
                std::cout << "Niepoprawny wybór. Spróbuj ponownie." << std::endl;
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Wystąpił błąd: " << e.what() << std::endl;
    }

    return 0;
}
