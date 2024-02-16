class Matrix:
    def __init__(self, rows, cols):
        self.rows = rows
        self.cols = cols
        self.data = [[0 for _ in range(cols)] for _ in range(rows)]

    def set_element(self, row, col, value):
        self.data[row][col] = value

    def get_element(self, row, col):
        return self.data[row][col]

    def print_matrix(self):
        for row in self.data:
            print(' '.join(map(str, row)))

    def transpose(self):
        self.data = [[self.data[j][i] for j in range(self.rows)] for i in range(self.cols)]
        self.rows, self.cols = self.cols, self.rows

    def swap_rows(self, row1, row2):
        self.data[row1], self.data[row2] = self.data[row2], self.data[row1]


def main():
    matrix = None

    while True:
        command = input("Enter command (init/print/set/get/transpose/swap/exit): ")

        if command == "init":
            rows, cols = map(int, input("Enter number of rows and columns: ").split())
            matrix = Matrix(rows, cols)
            print("Matrix initialized.")
        elif command == "print":
            matrix.print_matrix()
        elif command == "set":
            row, col, value = map(int, input("Enter row, column, and value: ").split())
            matrix.set_element(row, col, value)
        elif command == "get":
            row, col = map(int, input("Enter row and column: ").split())
            print("Value at ({}, {}): {}".format(row, col, matrix.get_element(row, col)))
        elif command == "transpose":
            matrix.transpose()
            print("Matrix transposed.")
        elif command == "swap":
            row1, row2 = map(int, input("Enter rows to swap: ").split())
            matrix.swap_rows(row1, row2)
            print("Rows swapped.")
        elif command == "exit":
            break
        else:
            print("Invalid command. Please try again.")


if __name__ == "__main__":
    main()
