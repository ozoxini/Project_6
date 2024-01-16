# main.py
from CSVLoader import CSVLoader
from DataAnalyzer import DataAnalyzer

def main():
    try:
        filename = input("Podaj nazwę pliku CSV: ")
        csv_loader = CSVLoader(filename)
        csv_loader.load_data()

        analyzer = DataAnalyzer(csv_loader.points)

        while True:
            print("\nMenu:")
            print("1. Suma autokonsumpcji w danym zakresie dat")
            print("2. Suma eksportu w danym zakresie dat")
            print("3. Suma importu w danym zakresie dat")
            print("4. Suma poboru w danym zakresie dat")
            print("5. Suma produkcji w danym zakresie dat")
            print("6. Średnia autokonsumpcji w danym zakresie dat")
            print("7. Średnia eksportu w danym zakresie dat")
            print("8. Średnia importu w danym zakresie dat")
            print("9. Średnia poboru w danym zakresie dat")
            print("10. Średnia produkcji w danym zakresie dat")
            print("11. Porównaj autokonsumpcję w dwóch przedziałach")
            print("12. Porównaj eksport w dwóch przedziałach")
            print("13. Porównaj import w dwóch przedziałach")
            print("14. Porównaj pobór w dwóch przedziałach")
            print("15. Porównaj produkcję w dwóch przedziałach")
            print("16. Wyszukaj rekordy spełniające warunek")
            print("17. Wypisz dane w danym zakresie")
            print("18. Zapisz dane do pliku binarnego")
            print("19. Odczytaj dane z pliku binarnego")
            print("20. Wyjście")

            choice = input("Wybierz opcję (1-20): ")

            if choice == "1":
                start_date = input("Podaj początkową datę (format: RRRR-MM-DD GG:MM): ")
                end_date = input("Podaj końcową datę (format: RRRR-MM-DD GG:MM): ")
                analyzer.sum_autokonsumpcja(start_date, end_date)

            elif choice == "2":
                start_date = input("Podaj początkową datę (format: RRRR-MM-DD GG:MM): ")
                end_date = input("Podaj końcową datę (format: RRRR-MM-DD GG:MM): ")
                analyzer.sum_eksport(start_date, end_date)

            elif choice == "3":
                start_date = input("Podaj początkową datę (format: RRRR-MM-DD GG:MM): ")
                end_date = input("Podaj końcową datę (format: RRRR-MM-DD GG:MM): ")
                analyzer.sum_import(start_date, end_date)

            elif choice == "4":
                start_date = input("Podaj początkową datę (format: RRRR-MM-DD GG:MM): ")
                end_date = input("Podaj końcową datę (format: RRRR-MM-DD GG:MM): ")
                analyzer.sum_pobor(start_date, end_date)

            elif choice == "5":
                start_date = input("Podaj początkową datę (format: RRRR-MM-DD GG:MM): ")
                end_date = input("Podaj końcową datę (format: RRRR-MM-DD GG:MM): ")
                analyzer.sum_produkcja(start_date, end_date)

            elif choice == "6":
                start_date = input("Podaj początkową datę (format: RRRR-MM-DD GG:MM): ")
                end_date = input("Podaj końcową datę (format: RRRR-MM-DD GG:MM): ")
                analyzer.average_autokonsumpcja(start_date, end_date)

            elif choice == "7":
                start_date = input("Podaj początkową datę (format: RRRR-MM-DD GG:MM): ")
                end_date = input("Podaj końcową datę (format: RRRR-MM-DD GG:MM): ")
                analyzer.average_eksport(start_date, end_date)

            elif choice == "8":
                start_date = input("Podaj początkową datę (format: RRRR-MM-DD GG:MM): ")
                end_date = input("Podaj końcową datę (format: RRRR-MM-DD GG:MM): ")
                analyzer.average_import(start_date, end_date)

            elif choice == "9":
                start_date = input("Podaj początkową datę (format: RRRR-MM-DD GG:MM): ")
                end_date = input("Podaj końcową datę (format: RRRR-MM-DD GG:MM): ")
                analyzer.average_pobor(start_date, end_date)

            elif choice == "10":
                start_date = input("Podaj początkową datę (format: RRRR-MM-DD GG:MM): ")
                end_date = input("Podaj końcową datę (format: RRRR-MM-DD GG:MM): ")
                analyzer.average_produkcja(start_date, end_date)

            # Dodaj pozostałe opcje zgodnie z numeracją menu

            elif choice == "20":
                break
            else:
                print("Niepoprawny wybór. Spróbuj ponownie.")

    except Exception as e:
        print(f"Wystąpił błąd: {e}")

if __name__ == "__main__":
    main()