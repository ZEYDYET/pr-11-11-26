#include <stdio.h>
#include <windows.h>

int matrixSize();
void inputMatrix(int M, int matrix[M][M]);
void mainDiag(int M, int matrix[M][M]);
void sumSecDiag(int M, int matrix[M][M]);
void findMaxMin(int M, int matrix[M][M]);

void printMatrix(int M, int matrix[M][M]);

int main() {
    SetConsoleOutputCP(65001);

    // 2. В заданій квадратній матриці розміру M  M:
    // a) вивести елементи головної діагоналі (по діагоналі).
    // b) знайти суму елементів, які знаходяться над побічною діагоналлю,
    // враховуючи елементи на самій діагоналі.
    // c) знайти елемент, що є максимальним у своєму рядку та
    // мінімальним у своєму стовпці. Якщо такий елемент відсутній,
    // вивести 0.
    // Для цієї задачі написати функції введення та виведення матриці, та
    // функції, які виконують вказані дії.


    int m = matrixSize();
    if (m > 0) {
        int matrix[m][m];
        inputMatrix(m, matrix);

        mainDiag(m, matrix);
        sumSecDiag(m, matrix);
        findMaxMin(m, matrix);

        printMatrix(m, matrix);
    } else {
        printf("Некоректний розмір матриці\n");
    }

    return 0;
}

int matrixSize() {
    printf("Введіть розмір матриці: ");
    int m;
    scanf("%d", &m);

    return m;
}

void inputMatrix(int M, int matrix[M][M]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            printf("Введіть елемент матриці для %d рядка та %d стовбця: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void mainDiag(int M, int matrix[M][M]) {
    printf("Елементи головної діагоналі: \n");
    for (int i = 0; i < M; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

void sumSecDiag(int M, int matrix[M][M]) {
    int sum = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (i + j <= M - 1) {
                sum += matrix[i][j];
            }
        }
    }
    printf("Сума елементів над побічною діагоналлю: %d\n", sum);
}

void findMaxMin(int M, int matrix[M][M]) {
    int result = 0;
    for (int i = 0; i < M; i++) {
        int maxInRow = matrix[i][0];
        int minInCol = matrix[0][0];

        for (int j = 1; j < M; j++) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
            }
        }

        for (int j = 0; j < M; j++) {
            if (matrix[j][i] < minInCol) {
                minInCol = matrix[j][i];
            }
        }

        if (maxInRow == minInCol) {
            result = maxInRow;
            break;
        }
    }

    printf("Елемент, що є максимальним у своєму рядку та мінімальним у своєму стовпці: %d\n", result);
}

void printMatrix(int M, int matrix[M][M]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            printf("Число %d рядка %d стовбця: ", i + 1, j + 1);
            printf("%d \n", matrix[i][j]);
        }
        printf("\n");
    }
}
