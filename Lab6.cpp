#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

void readMatricesFromFile(std::string fileName, int (&matrix1)[MAX_SIZE][MAX_SIZE], int (&matrix2)[MAX_SIZE][MAX_SIZE], int &matrixSize);
void printMatrix(int(&matrix)[MAX_SIZE][MAX_SIZE], int matrixSize);
void addMatrices(int(&matrix1)[MAX_SIZE][MAX_SIZE], int(&matrix2)[MAX_SIZE][MAX_SIZE], int(&result)[MAX_SIZE][MAX_SIZE], int matrixSize);
void multiplyMatrices(int(&matrix1)[MAX_SIZE][MAX_SIZE], int(&matrix2)[MAX_SIZE][MAX_SIZE], int(&result)[MAX_SIZE][MAX_SIZE], int matrixSize);
void subtractMatrices(int(&matrix1)[MAX_SIZE][MAX_SIZE], int(&matrix2)[MAX_SIZE][MAX_SIZE], int(&result)[MAX_SIZE][MAX_SIZE], int matrixSize);

int main() {
    std::cout << "Asa Maker" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];
    int resultMatrix[MAX_SIZE][MAX_SIZE];
    int matrixSize;

    readMatricesFromFile("matrix_input.txt", matrix1, matrix2, matrixSize);

    std::cout << "Matrix A:\n";
    printMatrix(matrix1, matrixSize);
    std::cout << "Matrix B:\n";
    printMatrix(matrix2, matrixSize);

    std::cout << "Matrix Sum (A + B):\n";
    addMatrices(matrix1, matrix2, resultMatrix, matrixSize);

    std::cout << "Matrix Product (A * B):\n";
    multiplyMatrices(matrix1, matrix2, resultMatrix, matrixSize);

    std::cout << "Matrix Difference (A - B):\n";
    subtractMatrices(matrix1, matrix2, resultMatrix, matrixSize);

    return 0;
}

void readMatricesFromFile(std::string fileName, int (&matrix1)[MAX_SIZE][MAX_SIZE], int (&matrix2)[MAX_SIZE][MAX_SIZE], int &matrixSize) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "File couldn't be opened." << std::endl;
        exit(1);
    }

    file >> matrixSize;
    for(int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            file >> matrix1[i][j];
        }
    }
    for(int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            file >> matrix2[i][j];
        }
    }
}

void printMatrix(int(&matrix)[MAX_SIZE][MAX_SIZE], int matrixSize) {
    for(int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void addMatrices(int(&matrix1)[MAX_SIZE][MAX_SIZE], int(&matrix2)[MAX_SIZE][MAX_SIZE], int(&result)[MAX_SIZE][MAX_SIZE], int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printMatrix(result, matrixSize);
}

void multiplyMatrices(int(&matrix1)[MAX_SIZE][MAX_SIZE], int(&matrix2)[MAX_SIZE][MAX_SIZE], int(&result)[MAX_SIZE][MAX_SIZE], int matrixSize){
    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            result[i][j] = 0;
            for (int k = 0; k < matrixSize; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printMatrix(result, matrixSize);
}

void subtractMatrices(int(&matrix1)[MAX_SIZE][MAX_SIZE], int(&matrix2)[MAX_SIZE][MAX_SIZE], int(&result)[MAX_SIZE][MAX_SIZE], int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printMatrix(result, matrixSize);
}
