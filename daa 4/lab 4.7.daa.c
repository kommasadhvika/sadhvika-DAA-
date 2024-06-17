#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void replace(char* s, char a, char b) {
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == a) {
            s[i] = b;
        }
    }
}
int maxDiff(int num) {
    char a[12], b[12];
    sprintf(a, "%d", num);
    strcpy(b, a);
    for (int i = 0; a[i] != '\0'; ++i) {
        if (a[i] != '9') {
            replace(a, a[i], '9');
            break;
        }
    }
    if (b[0] != '1') {
        replace(b, b[0], '1');
    } else {
        for (int i = 1; b[i] != '\0'; ++i) {
            if (b[i] != '0' && b[i] != '1') {
                replace(b, b[i], '0');
                break;
            }
        }
    }
    return atoi(a) - atoi(b);
}
int main() {
    int num = 555;
    printf("Max Difference: %d\n", maxDiff(num));
    return 0;
}
