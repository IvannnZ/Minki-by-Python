#include <stdio.h>
#include <stdlib.h>

// Функция для печати матрицы
void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для освобождения памяти, выделенной под матрицу
void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция для копирования содержимого одной матрицы в другую
void copyMatrix(int **src, int **dest, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

// Функция для перемножения двух матриц
int **matrixMultiply(int **mat1, int **mat2, int size) {
    int **result = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        result[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

// Функция для возведения матрицы в степень
int **matrixPower(int **matrix, int size, int power) {
    if (power == 0) {
        int **result = (int **)malloc(size * sizeof(int *));
        for (int i = 0; i < size; i++) {
            result[i] = (int *)malloc(size * sizeof(int));
            for (int j = 0; j < size; j++) {
                result[i][j] = (i == j) ? 1 : 0; // Единичная матрица
            }
        }
        return result;
    } else if (power % 2 == 0) {
        int **temp = matrixPower(matrix, size, power / 2);
        int **result = matrixMultiply(temp, temp, size);
        freeMatrix(temp, size);
        return result;
    } else {
        int **temp = matrixPower(matrix, size, power - 1);
        int **result = matrixMultiply(matrix, temp, size);
        freeMatrix(temp, size);
        return result;
    }
}

int main() {
    // Размер квадратной матрицы
    int size = 3;
    // Степень, в которую нужно возвести матрицу
    int power = 5445;

    // Создание и заполнение матрицы
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = i * size + j + 1;
        }
    }

    printf("Исходная матрица:\n");
    printMatrix(matrix, size);

    // Возводим матрицу в заданную степень
    int **result = matrixPower(matrix, size, power);

    printf("\nМатрица после возведения в степень %d:\n", power);
    printMatrix(result, size);

    // Освобождение памяти
    freeMatrix(matrix, size);
    freeMatrix(result, size);

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

// Функция для печати матрицы
void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для выделения памяти под матрицу и заполнения её значениями
int **createMatrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            // В примере заполним матрицу случайными значениями от 1 до 9
            matrix[i][j] = rand() % 9 + 1;
        }
    }
    return matrix;
}

// Функция для освобождения памяти, выделенной под матрицу
void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция для перемножения двух матриц
int **matrixMultiply(int **mat1, int **mat2, int size) {
    int **result = createMatrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

// Функция для возврата матрицы в заданную степень
int **matrixPower(int **matrix, int size, int power) {
    if (power == 1) {
        return matrix;
    } else if (power % 2 == 0) {
        int **temp = matrixPower(matrix, size, power / 2);
        int **result = matrixMultiply(temp, temp, size);
        freeMatrix(temp, size);
        return result;
    } else {
        int **temp = matrixPower(matrix, size, power - 1);
        int **result = matrixMultiply(matrix, temp, size);
        freeMatrix(temp, size);
        return result;
    }
}

int main() {
    // Размер квадратной матрицы
    int size = 3;
    // Степень, в которую нужно возвести матрицу
    int power = 3;

    // Создание и заполнение матрицы случайными значениями
    int **matrix = createMatrix(size);

    printf("Исходная матрица:\n");
    printMatrix(matrix, size);

    // Возводим матрицу в заданную степень
    int **result = matrixPower(matrix, size, power);

    printf("\nМатрица после возведения в степень %d:\n", power);
    printMatrix(result, size);

    // Освобождение памяти
    freeMatrix(matrix, size);
    freeMatrix(result, size);

    return 0;
}*/