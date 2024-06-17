#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int cmpfunc(const void* a, const void* b) {
    return ((char)a - (char)b);
}
bool check(char* s1, char* s2, int length) {
    for (int i = 0; i < length; ++i) {
        if (s1[i] < s2[i]) {
            return false;
        }
    }
    return true;
}
bool checkIfCanBreak(char* s1, char* s2) {
    int length = strlen(s1);
    qsort(s1, length, sizeof(char), cmpfunc);
    qsort(s2, length, sizeof(char), cmpfunc);
    return check(s1, s2, length) || check(s2, s1, length);
}
int main() {
    char s1[] = "abc";
    char s2[] = "xya";
    if (checkIfCanBreak(s1, s2)) {
        printf("One string can break the other\n");
    } else {
        printf("Neither string can break the other\n");
    }
    return 0;
}
