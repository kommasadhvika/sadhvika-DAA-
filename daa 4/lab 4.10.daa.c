#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    char** set;
    int capacity;
    int size;
} unordered_set;
unordered_set* createSet(int capacity) {
    unordered_set* s = (unordered_set*)malloc(sizeof(unordered_set));
    s->capacity = capacity;
    s->size = 0;
    s->set = (char*)malloc(capacity * sizeof(char));
    return s;
}
bool contains(unordered_set* s, char* str) {
    for (int i = 0; i < s->size; ++i) {
        if (strcmp(s->set[i], str) == 0) {
            return true;
        }
    }
    return false;
}
void insert(unordered_set* s, char* str) {
    if (!contains(s, str)) {
        s->set[s->size] = strdup(str);
        s->size++;
    }
}
char* destCity(char** paths, int pathsSize, int pathsColSize) {
    unordered_set* s = createSet(pathsSize);
    for (int i = 0; i < pathsSize; ++i) {
        insert(s, paths[i][0]);
    }
    for (int i = 0; i < pathsSize; ++i) {
        if (!contains(s, paths[i][1])) {
            return strdup(paths[i][1]);
        }
    }
    return "";
}
int main() {
    char* paths[][2] = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    int pathsSize = sizeof(paths) / sizeof(paths[0]);
    int pathsColSize = sizeof(paths[0]) / sizeof(paths[0][0]);
    char* destination = destCity((char***)paths, pathsSize, &pathsColSize);
    printf("Destination city: %s\n", destination);
    
    return 0;
}
