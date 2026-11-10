#include <stdio.h>
#include <windows.h>

void matrSize(int*, int*);
void inputMatrix(int M, int N, int matrix[M][N]);
void mirror(int M, int N, int matrix[M][N]);
void printMatrix(int M, int N, int matrix[M][N]);

int main() {
    SetConsoleOutputCP(65001);

    // 4. Камера спостереження передає зображення в буфер пам'яті у вигляді
    // цілочисельної матриці M х N (піксельні дані). Потрібно виконати
    // апаратне горизонтальне дзеркальне відображення кадру.
    // Напишіть функцію, яка переставляє стовпці матриці місцями: 1-й із
    // останнім, 2-й із передостаннім і так далі без використання додаткової
    // проміжної матриці у пам'яті.

    int m, n;
    matrSize(&m, &n);

    if (m > 0 && n > 0) {
        int matrix[m][n];
        
        inputMatrix(m, n, matrix);
        mirror(m, n, matrix);
        printMatrix(m, n, matrix);
    }

    return 0;
}

void matrSize(int* M, int* N) {
    printf("Введіть кількість рядків та стовпців: ");
    scanf("%d %d", M, N);
}

void inputMatrix(int M, int N, int matrix[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("Введіть піксель %d рядка та %d стовбця: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void mirror(int M, int N, int matrix[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][N - 1 - j];
            matrix[i][N - 1 - j] = temp;
        }
    }
}

void printMatrix(int M, int N, int matrix[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}