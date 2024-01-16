# CSVLoader.py
import csv
import pickle
from PointData import PointData
from datetime import datetime

class CSVLoader:
    def __init__(self, filename):
        self.filename = filename
        self.points = []

    def load_data(self):
        try:
            with open(self.filename, 'r') as file:
                reader = csv.reader(file)
                rows = list(reader)

                # Sprawdź, czy pierwszy wiersz to nagłówek
                if not rows or len(rows[0]) < 6 or not all(cell.strip() for cell in rows[0][:6]):
                    print("Brak lub nieprawidłowy nagłówek w pliku CSV. Oczekiwano co najmniej 6 kolumn.")
                    return

                header_mapping = { "time": None, "autokonsumpcja (w)": None, "eksport (w)": None, "import (w)": None, "pobór (w)": None, "produkcja (w)": None }

                for i, cell in enumerate(rows[0]):
                    cell_lower = cell.strip().lower()
                    for key in header_mapping.keys():
                        if key in cell_lower:
                            header_mapping[key] = i

                if None in header_mapping.values():
                    print("Nie udało się zmapować wszystkich kolumn. Sprawdź nagłówek pliku CSV.")
                    return

                for i, row in enumerate(rows[1:], start=2):
                    try:
                        # Pomijanie pustych wierszy
                        if not row or all(cell.strip() == '' for cell in row):
                            print(f"Pusty wiersz w pliku CSV. Linia: {i}. Pomijanie...")
                            continue

                        date_time_str = row[header_mapping["time"]]

                        # Konwersja czasu do formatu RRRR-MM-DD GG:MM
                        try:
                            date_time = datetime.strptime(date_time_str, "%d.%m.%Y %H:%M").strftime("%Y-%m-%d %H:%M")
                        except ValueError:
                            print(f"Błąd w linii {i}: Nieprawidłowy format daty i czasu. Pomijanie...")
                            continue

                        autokonsumpcja = float(row[header_mapping["autokonsumpcja (w)"]])
                        eksport = float(row[header_mapping["eksport (w)"]])
                        import_val = float(row[header_mapping["import (w)"]])
                        pobor = float(row[header_mapping["pobór (w)"]])
                        produkcja = float(row[header_mapping["produkcja (w)"]])

                        # Tworzymy obiekt punktu i dodajemy go do listy
                        point = PointData(date_time, autokonsumpcja, eksport, import_val, pobor, produkcja)
                        self.points.append(point)
                    except (IndexError, ValueError) as e:
                        print(f"Błąd w linii {i}: {e}. Pomijanie...")
                        continue  # Przejdź do następnej linii

                print(f"Wczytano {len(self.points)} rekordów.")

        except Exception as e:
            print(f"Błąd podczas wczytywania danych z pliku CSV: {e}")

    def save_to_binary_file(self, filename):
        try:
            with open(filename, 'wb') as file:
                pickle.dump(self.points, file)
            print(f"Dane zapisano do pliku binarnego: {filename}")
        except Exception as e:
            print(f"Błąd podczas zapisu danych do pliku binarnego: {e}")

    def load_from_binary_file(self, filename):
        try:
            with open(filename, 'rb') as file:
                self.points = pickle.load(file)
            print(f"Dane wczytano z pliku binarnego: {filename}")
        except Exception as e:
            print(f"Błąd podczas wczytywania danych z pliku binarnego: {e}")
