#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void copyMatrix(int **src, int **dest, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

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

int **matrixDeg(int **matrix, int size, int power) {
    if (power == 0) {
        int **result = (int **)malloc(size * sizeof(int *));
        for (int i = 0; i < size; i++) {
            result[i] = (int *)malloc(size * sizeof(int));
            for (int j = 0; j < size; j++) {
                result[i][j] = (i == j) ? 1 : 0;
            }
        }
        return result;
    } else if (power % 2 == 0) {
        int **temp = matrixDeg(matrix, size, power / 2);
        int **result = matrixMultiply(temp, temp, size);
        freeMatrix(temp, size);
        return result;
    } else {
        int **temp = matrixDeg(matrix, size, power - 1);
        int **result = matrixMultiply(matrix, temp, size);
        freeMatrix(temp, size);
        return result;
    }
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main() {
    int size = 3;
    int deg = 5445;

    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = i * size + j + 1;
        }
    }

    printf("Исходная матрица:\n");
    printMatrix(matrix, size);

    int **result = matrixDeg(matrix, size, deg);

    printf("\nМатрица после возведения в степень %d:\n", deg);
    printMatrix(result, size);

    freeMatrix(matrix, size);
    freeMatrix(result, size);

    return 0;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

static PyObject* foreign_matrix_power(PyObject* self, PyObject* args) {
    PyObject *py_matrix;
    PyObject *py_deg;
    if (!PyArg_ParseTuple(args, "OO", &py_matrix, &py_deg)) {
        return NULL;
    }

    int degree = (int)PyLong_AsLong(py_deg);
    int matrix_size = (int)PyObject_Length(py_matrix);

    int **matrix = (int **)malloc(matrix_size * sizeof(int *));
    for (int i = 0; i < matrix_size; i++) {
        matrix[i] = (int *)malloc(matrix_size * sizeof(int));
        for (int j = 0; j < matrix_size; j++) {
            matrix[i][j] = (int)PyLong_AsLong(PyList_GetItem(PyList_GetItem(py_matrix, i), j));
        }
    }

    printf("Исходная матрица:\n");
    printMatrix(matrix, matrix_size);

    printf("deg:%d\n", degree);
    int **result = matrixDeg(matrix, matrix_size, degree);

    PyObject *result_py = PyList_New(matrix_size);
    for (int i = 0; i < matrix_size; i++) {
        PyObject *sublist = PyList_New(matrix_size);
        for (int j = 0; j < matrix_size; j++) {
            PyList_SetItem(sublist, j, PyLong_FromLong(result[i][j]));
        }
        PyList_SetItem(result_py, i, sublist);
        free(matrix[i]);
    }
    freeMatrix(matrix, size);
    freeMatrix(result, size);


    return result_py;
}


static PyMethodDef ForeignMethods[] = {
    {"foreign_matrix_power",
    foreign_matrix_power,
    METH_VARARGS,
    ""
    },
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef foreignmodule = {
    PyModuleDef_HEAD_INIT,
    "foreign",
    NULL,
    -1,
    ForeignMethods
};


PyMODINIT_FUNC PyInit_foreign(void) {
    return PyModule_Create(&foreignmodule);
}