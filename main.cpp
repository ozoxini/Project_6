#include <iostream>
#include <string>
#include "CSVLoader.h" // Assuming CSVLoader is a custom class you have to define
#include "DataAnalyzer.h" // Assuming DataAnalyzer is a custom class you have to define

int main() {
    try {
        std::string filename;
        std::cout << "Podaj nazwę pliku CSV: ";
        std::cin >> filename;
        CSVLoader csv_loader(filename);
        csv_loader.load_data();
        DataAnalyzer analyzer(csv_loader.getPoints()); // Assuming getPoints() is a method that returns the loaded data
        int choice;
        do {
            std::cout << "\nMenu:\n";
            std::cout << "1. Suma autokonsumpcji w danym zakresie dat\n";
            std::cout << "2. Suma eksportu w danym zakresie dat\n";
            std::cout << "3. Suma importu w danym zakresie dat\n";
            std::cout << "4. Suma poboru w danym zakresie dat\n";
            std::cout << "5. Suma produkcji w danym zakresie dat\n";
            std::cout << "6. Średnia autokonsumpcji w danym zakresie dat\n";
            std::cout << "7. Średnia eksportu w danym zakresie dat\n";
            std::cout << "8. Średnia importu w danym zakresie dat\n";
            std::cout << "9. Średnia poboru w danym zakresie dat\n";
            std::cout << "10. Średnia produkcji w danym zakresie dat\n";
            std::cout << "11. Porównaj autokonsumpcję w dwóch przedziałach\n";
            std::cout << "12. Porównaj eksport w dwóch przedziałach\n";
            std::cout << "13. Porównaj import w dwóch przedziałach\n";
            std::cout << "14. Porównaj pobór w dwóch przedziałach\n";
            std::cout << "15. Porównaj produkcję w dwóch przedziałach\n";
            std::cout << "16. Wyszukaj rekordy spełniające warunek\n";
            std::cout << "17. Wypisz dane w danym zakresie\n";
            std::cout << "18. Zapisz dane do pliku binarnego\n";
            std::cout << "19. Odczytaj dane z pliku binarnego\n";
            std::cout << "20. Wyjście\n";
            std::cout << "Wybierz opcję (1-20): ";
            std::cin >> choice;
            std::string start_date, end_date;
            switch (choice) {
                case 1:
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.sum_autokonsumpcja(start_date, end_date);
                    break;
                case 2:
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.sum_eksport(start_date, end_date);
                    break;
                case 3:
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.sum_import(start_date, end_date);
                    break;
                case 4:
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.sum_pobor(start_date, end_date);
                    break;
                case 5:
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.sum_produkcja(start_date, end_date);
                    break;
                case 6:
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.average_autokonsumpcja(start_date, end_date);
                    break;
                case 7:
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.average_eksport(start_date, end_date);
                    break;
                case 8:
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.average_import(start_date, end_date);
                    break;
                case 9:
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.average_pobor(start_date, end_date);
                    break;
                case 10:
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.average_produkcja(start_date, end_date);
                    break;
                case 11:
                    std::cout << "Podaj początkową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    std::string start_date2, end_date2;
                    std::cout << "Podaj początkową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date2;
                    std::cout << "Podaj końcową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date2;
                    analyzer.compare_autokonsumpcja(start_date, end_date, start_date2, end_date2);
                    break;
                case 12:
                    std::cout << "Podaj początkową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    std::cout << "Podaj początkową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date2;
                    std::cout << "Podaj końcową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date2;
                    analyzer.compare_eksport(start_date, end_date, start_date2, end_date2);
                    break;
                case 13:
                    std::cout << "Podaj początkową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    std::cout << "Podaj początkową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date2;
                    std::cout << "Podaj końcową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date2;
                    analyzer.compare_import(start_date, end_date, start_date2, end_date2);
                    break;
                case 14:
                    std::cout << "Podaj początkową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    std::cout << "Podaj początkową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date2;
                    std::cout << "Podaj końcową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date2;
                    analyzer.compare_pobor(start_date, end_date, start_date2, end_date2);
                    break;
                case 15:
                    std::cout << "Podaj początkową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę pierwszego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    std::cout << "Podaj początkową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date2;
                    std::cout << "Podaj końcową datę drugiego przedziału (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date2;
                    analyzer.compare_produkcja(start_date, end_date, start_date2, end_date2);
                    break;
                case 16:
                    // Add code for case 16
                     std::string condition;
                    std::cout << "Podaj warunek wyszukiwania: ";
                    std::cin.ignore(); 
                    std::getline(std::cin, condition);
                    analyzer.search_records(condition);
                    break;
                case 17:
                    // Add code for case 17
                    std::string start_date, end_date;
                    std::cout << "Podaj początkową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> start_date;
                    std::cout << "Podaj końcową datę (format: RRRR-MM-DD GG:MM): ";
                    std::cin >> end_date;
                    analyzer.print_data_in_range(start_date, end_date);

                    break;
                case 18:
                    // Add code for case 18
                    std::string binary_filename;
                    std::cout << "Podaj nazwę pliku binarnego do zapisu: ";
                    std::cin >> binary_filename;
                    analyzer.save_to_binary(binary_filename);
                    break;
                case 19:
                    // Add code for case 19
                     std::string binary_filename;
                     std::cout << "Podaj nazwę pliku binarnego do odczytu: ";
                     std::cin >> binary_filename;
                     analyzer.read_from_binary(binary_filename);
                    break;
                case 20:
                    break;
                default:
                    std::cout << "Niepoprawny wybór. Spróbuj ponownie.\n";
                    break;
            }
        } while (choice != 20);
    } catch (const std::exception& e) {
        std::cout << "Wystąpił błąd: " << e.what() << std::endl;
    }
    return 0;
}


