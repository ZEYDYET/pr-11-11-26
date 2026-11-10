#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

void scanfVar(int*, int*, int*);
bool checkInterval(int, int);
void scanfTraff(int M, int N, int traffic[M][N]);
void findMaxTraff(int K, int M, int N, int traffic[M][N], int* maxTraffic);

int main() {
    SetConsoleOutputCP(65001);

    // 1. Системний маршрутизатор дата-центру фіксує обсяги трафіку у
    // вигляді матриці розміром M х N, де M – часові інтервали (рядки), а N
    // – мережеві порти (стовпці). Інженер мережі проводить аудит
    // конкретного часового інтервалу K (1 < K < M).
    // Написати функцію, яка перевіряє коректність введеного інтервалу K,
    // виводить у консоль усі показники трафіку для K-го рядка та знаходить
    // максимальний обсяг трафіку на цьому інтервалі.

    int m, n, k;
    scanfVar(&m, &n, &k);

     if (checkInterval(k, m) && m > 0 && n > 0) {
        int traffic[m][n];
        scanfTraff(m, n, traffic);

        int maxTraffic = traffic[k - 1][0];
        findMaxTraff(k, m, n, traffic, &maxTraffic);
    } else {
        printf("Некоректний інтервал K\n");
    }

    return 0;
}

void scanfVar(int* M, int* N, int* K) {
    printf("Введіть кількість часових інтервалів: ");
    scanf("%d", M);
    printf("Введіть кількість мережевих портів: ");
    scanf("%d", N);
    printf("Введіть інтервал K (1 < K < %d): ", *M);
    scanf("%d", K);
}

bool checkInterval(int K, int M) {
    return K > 1 && K < M;
}

void scanfTraff(int M, int N, int traffic[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("Введіть обсяг трафіку для інтервалу %d та порту %d: ", i + 1, j + 1);
            scanf("%d", &traffic[i][j]);
        }
        printf("\n");
    }
}

void findMaxTraff(int K, int M, int N, int traffic[M][N], int* maxTraffic) {
    *maxTraffic = traffic[K - 1][0];
    for (int j = 0; j < N; j++) {
        printf("Показник %d: %d\n", j + 1, traffic[K - 1][j]);
        if (traffic[K - 1][j] > *maxTraffic) {
            *maxTraffic = traffic[K - 1][j];
        }
    }

    printf("Максимальний обсяг трафіку на інтервалі %d: %d\n", K, *maxTraffic);
}