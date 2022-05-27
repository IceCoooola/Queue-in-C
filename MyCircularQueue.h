#define CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int* queue;
    int front;
    int rear;
    int size;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);

bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);

bool myCircularQueueDeQueue(MyCircularQueue* obj);

int myCircularQueueFront(MyCircularQueue* obj);

int myCircularQueueRear(MyCircularQueue* obj);

void myCircularQueueFree(MyCircularQueue* obj);

