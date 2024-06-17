#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maxElement(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void initializeAdjacencyList(int* hats[], int hatsSize, int hatsColSize, int n, int m) {
    for (int i = 0; i < m + 1; ++i) {
        hats[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) {
            hats[i][j] = -1;
        }
    }
}
void addPersonToAdjacencyList(int* hats[], int hatsSize, int hatsColSize, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < hatsColSize; ++j) {
            int hat = hats[i][j];
            if (hat != -1) {
                hats[hat][i] = 1;
            }
        }
    }
}
int numberWays(int* hats[], int hatsSize, int hatsColSize) {
    int n = hatsSize;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        m = maxElement(hats[i], hatsColSize);
    }
    int* g[m + 1];
    initializeAdjacencyList(g, m + 1, n, n, m);

    addPersonToAdjacencyList(hats, n, hatsColSize, n, m);

    const int mod = 1000000007;
    int f[m + 1][1 << n];
    memset(f, 0, sizeof(f));
    f[0][0] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            f[i][j] = f[i - 1][j];
            for (int k = 0; k < n; ++k) {
                if ((j >> k) & 1) {
                    f[i][j] = (f[i][j] + f[i - 1][j ^ (1 << k)]) % mod;
                }
            }
        }
    }

    return f[m][(1 << n) - 1];
}
int main() {
    int hats[][3] = {{3, 4}, {4, 5}, {5}};
    int n = sizeof(hats) / sizeof(hats[0]);
    int* ptr[n];
    for (int i = 0; i < n; ++i) {
        ptr[i] = hats[i];
    }
    int hatsSize = n;
    int hatsColSize = sizeof(hats[0]) / sizeof(hats[0][0]);
    printf("Number of ways: %d\n", numberWays(ptr, hatsSize, hatsColSize));
    return 0;
}
