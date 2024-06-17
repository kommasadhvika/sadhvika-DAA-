#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000000
typedef structNode {
    int value;
    struct Node*next;
} Node;
typedef structQueue {
    Node*front;
    Node*rear;
} Queue;
typedef structFirstUnique {
    int count[MAX_NUM];
    Queue queue;
} FirstUnique;
void initQueue(Queue*q) {
    q->front=q->rear=NULL;
}
void enqueue(Queue*q,int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->value=value;
    newNode->next=NULL;
    if (q->rear==NULL) {
        q->front=q->rear=newNode;
        return;
    }
    q->rear->next=newNode;
    q->rear=newNode;
}
void dequeue(Queue*q) {
    if (q->front==NULL) return;
    Node*temp=q->front;
    q->front=q->front->next;
    if (q->front==NULL)q->rear=NULL;
    free(temp);
}
    if (q->front==NULL) 
	return -1;
    return q->front->value;
}
int isQueueEmpty(Queue* q) {
    return q->front==NULL;
}
FirstUnique* firstUniqueCreate(int* nums,int numsSize) {
    FirstUnique*obj=(FirstUnique*)malloc(sizeof(FirstUnique));
    for (int i=0;i<MAX_NUM;i++)obj->count[i]=0;
    initQueue(&obj->queue);
    for (int i=0;i<numsSize;i++) {
        obj->count[nums[i]]++;
        enqueue(&obj->queue,nums[i]);
    }
    return obj;
}
int firstUniqueShowFirstUnique(FirstUnique* obj) {
    while (!isQueueEmpty(&obj->queue) && obj->count[front(&obj->queue)] != 1) {
        dequeue(&obj->queue);
    }
    return isQueueEmpty(&obj->queue) ? -1 : front(&obj->queue);
}
void firstUniqueAdd(FirstUnique* obj, int value) {
    obj->count[value]++;
    enqueue(&obj->queue, value);
}
void firstUniqueFree(FirstUnique* obj) {
    while (!isQueueEmpty(&obj->queue)) {
        dequeue(&obj->queue);
    }
    free(obj);
}
int main() {
    int nums[] = {2, 3, 5};
    FirstUnique* obj = firstUniqueCreate(nums, 3);
    printf("%d\n", firstUniqueShowFirstUnique(obj)); 
    firstUniqueAdd(obj, 5);
    printf("%d\n", firstUniqueShowFirstUnique(obj)); 
    firstUniqueAdd(obj, 2);
    printf("%d\n", firstUniqueShowFirstUnique(obj));
    firstUniqueAdd(obj, 3);
    printf("%d\n", firstUniqueShowFirstUnique(obj));
    firstUniqueFree(obj);
    return 0;
}
