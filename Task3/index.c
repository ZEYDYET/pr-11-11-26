#include <stdio.h>
#include <windows.h>

int matrixSize();
void fillMatr(int N, int matrix[N][N]);
void printMatr(int N, int matrix[N][N]);

int main() {
    SetConsoleOutputCP(65001);

    // 3. Заповнити матрицю

    int n = matrixSize();
    if (n > 0) {
        int matrix[n][n];
        fillMatr(n, matrix);
        printMatr(n, matrix);
    } else {
        printf("Некоректний розмір матриці\n");
    }


    return 0;
}

int matrixSize() {
    printf("Введіть розмір матриці: ");
    int n;
    scanf("%d", &n);

    return n;
}

void fillMatr(int N, int matrix[N][N]) {
   for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        matrix[i][i] = i; 
    }
}

void printMatr(int N, int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}