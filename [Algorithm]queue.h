#pragma once

typedef struct QueueNode {
    char data[50];
    struct QueueNode* link;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initializeQueue(Queue* queue);

int isQueueEmpty(const Queue* queue);

void enqueue(Queue* queue, const char* node);


char* dequeue(Queue* queue);

char* showNode(Queue* queue);

void freeQueue(Queue* queue);