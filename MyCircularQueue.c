


typedef struct {
    int* queue;
    int front;
    int rear;
    int size;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->front == obj->rear);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (((obj->rear+1) % (obj->size+1)) == obj->front)
        return true;
    else 
        return false;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* newQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (!newQueue)
    {
        exit(-1);
    }
    newQueue->queue = (int*)malloc(sizeof(int) * (k+1));
    if (!(newQueue->queue))
    {
        exit(-1);
    }
    newQueue->front = 0;
    newQueue->rear = 0;
    newQueue->size = k;
    return newQueue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    if (obj->rear == obj->size)
    {
        obj->queue[obj->rear] = value;
        obj->rear = 0;
    }
    else
    {
        obj->queue[obj->rear] = value;
        obj->rear++;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    else
    {
        obj->front = (obj->front +1 ) % (obj->size+1);
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->queue[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    if (obj->rear)
        return obj->queue[obj->rear - 1];
    else
        return obj->queue[obj->size];
}


void myCircularQueueFree(MyCircularQueue* obj) {
 free(obj->queue);
    free(obj);
} 
