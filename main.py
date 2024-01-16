# main.py
from CSVLoader import CSVLoader

def main():
    filename = input("Podaj nazwę pliku CSV: ")
    csv_loader = CSVLoader(filename)
    csv_loader.load_data()

    # Poniżej znajduje się przykładowe użycie funkcji z DataAnalyzer
    analyzer = DataAnalyzer(csv_loader.points)
    analyzer.sum_autokonsumpcja("2023-10-03 10:15", "2023-10-03 16:45")

    # Pozostałe operacje zgodnie z wymaganiami
    # ...

if __name__ == "__main__":
    main()
