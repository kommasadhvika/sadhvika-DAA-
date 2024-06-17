#include <stdio.h>
#include <stdlib.h>
int* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int* result = (int*)malloc(candiesSize * sizeof(int));
    int max = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (max <= candies[i]) {
            max = candies[i];
        }
    }
    for (int i = 0; i < candiesSize; i++) {
        int sum = candies[i] + extraCandies;
        if (sum >= max) {
            result[i] = 1;
        } else {
            result[i] = 0; 
        }
}
    *returnSize = candiesSize;
    return result;
}
int main() {
    int candies[] = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    int returnSize;
    int candiesSize = sizeof(candies) / sizeof(candies[0]);
    int* result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%s%d", i > 0 ? ", " : "", result[i]);
    }
    printf("]\n");
    free(result);
    return 0;
}
