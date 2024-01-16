# DataAnalyzer.py
from TreeNode import TreeNode
from PointData import PointData

class DataAnalyzer:
    def __init__(self, points):
        self.root = TreeNode("root")
        self.build_tree(points)

    def build_tree(self, points):
        for point in points:
            date_parts = point.date_time.split(" ")
            year_node = self.root.get_child(date_parts[0])
            if not year_node:
                year_node = TreeNode(date_parts[0])
                self.root.add_child(date_parts[0], year_node)

            month_node = year_node.get_child(date_parts[1])
            if not month_node:
                month_node = TreeNode(date_parts[1])
                year_node.add_child(date_parts[1], month_node)

            day_node = month_node.get_child(date_parts[2])
            if not day_node:
                day_node = TreeNode(date_parts[2])
                month_node.add_child(date_parts[2], day_node)

            quarter_parts = date_parts[3].split(":")
            quarter_key = f"{quarter_parts[0]}-{quarter_parts[1]}"
            quarter_node = day_node.get_child(quarter_key)
            if not quarter_node:
                quarter_node = TreeNode(quarter_key)
                day_node.add_child(quarter_key, quarter_node)

            quarter_node.add_child(point.date_time, TreeNode(point))

    def sum_autokonsumpcja(self, start_date, end_date):
        total_sum = 0.0
        start_node = self.find_node_by_date(start_date)
        end_node = self.find_node_by_date(end_date)

        if start_node and end_node:
            for node in self.iterate_nodes_in_range(start_node, end_node):
                total_sum += node.value.autokonsumpcja

        print(f"Suma autokonsumpcji od {start_date} do {end_date}: {total_sum}")
        return total_sum

    def sum_eksport(self, start_date, end_date):
        # Implementacja sumy eksportu w określonym zakresie dat
        pass

    def sum_import(self, start_date, end_date):
        # Implementacja sumy importu w określonym zakresie dat
        pass

    def sum_pobor(self, start_date, end_date):
        # Implementacja sumy poboru w określonym zakresie dat
        pass

    def sum_produkcja(self, start_date, end_date):
        # Implementacja sumy produkcji w określonym zakresie dat
        pass

    def average_autokonsumpcja(self, start_date, end_date):
        # Implementacja średniej autokonsumpcji w określonym zakresie dat
        pass

    def average_eksport(self, start_date, end_date):
        # Implementacja średniej eksportu w określonym zakresie dat
        pass

    def average_import(self, start_date, end_date):
        # Implementacja średniej importu w określonym zakresie dat
        pass

    def average_pobor(self, start_date, end_date):
        # Implementacja średniej poboru w określonym zakresie dat
        pass

    def average_produkcja(self, start_date, end_date):
        # Implementacja średniej produkcji w określonym zakresie dat
        pass

    def compare_autokonsumpcja(self, start_date_1, end_date_1, start_date_2, end_date_2):
        # Implementacja porównywania autokonsumpcji w dwóch przedziałach
        pass

    def compare_eksport(self, start_date_1, end_date_1, start_date_2, end_date_2):
        # Implementacja porównywania eksportu w dwóch przedziałach
        pass

    def compare_import(self, start_date_1, end_date_1, start_date_2, end_date_2):
        # Implementacja porównywania importu w dwóch przedziałach
        pass

    def compare_pobor(self, start_date_1, end_date_1, start_date_2, end_date_2):
        # Implementacja porównywania poboru w dwóch przedziałach
        pass

    def compare_produkcja(self, start_date_1, end_date_1, start_date_2, end_date_2):
        # Implementacja porównywania produkcji w dwóch przedziałach
        pass

    def search_records(self, criteria, tolerance, start_date, end_date):
        # Implementacja wyszukiwania i wypisywania rekordów spełniających warunek
        pass

    def print_data_in_range(self, start_date, end_date):
        # Implementacja wypisywania danych w określonym zakresie
        pass

    def find_node_by_date(self, date):
        date_parts = date.split(" ")
        year_node = self.root.get_child(date_parts[0])
        if not year_node:
            return None

        month_node = year_node.get_child(date_parts[1])
        if not month_node:
            return None

        day_node = month_node.get_child(date_parts[2])
        if not day_node:
            return None

        quarter_parts = date_parts[3].split(":")
        quarter_key = f"{quarter_parts[0]}-{quarter_parts[1]}"
        quarter_node = day_node.get_child(quarter_key)
        if not quarter_node:
            return None

        return quarter_node

    def iterate_nodes_in_range(self, start_node, end_node):
        stack = [start_node]
        while stack:
            current_node = stack.pop()
            yield current_node

            children = current_node.get_children()
            stack.extend(children)

            if current_node == end_node:
                break
