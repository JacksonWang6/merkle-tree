//
// Created by 44811 on 2020/10/27.
//
#ifndef QUEUE
#define QUEUE
#include <stdio.h>
#include <stdlib.h>
#include "mttree.h"
#include "queue.h"

Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("空间不足！\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void AddQ(Queue* q, ElementType item) {
    QNode* qNode = (QNode*)malloc(sizeof(QNode));
    if (!qNode) {
        printf("空间不足！\n");
        return;
    }
    qNode->data = item;
    qNode->next = NULL;
    if (q->front == NULL) {
        q->front = qNode;
    }
    if (q->rear == NULL) {
        q->rear = qNode;
    }
    else {
        q->rear->next = qNode;
        q->rear = qNode;
    }
}

int IsEmptyQ(Queue* q){
    return (q->front == NULL);
}

ElementType DeleteQ(Queue* q) {
    if (IsEmptyQ(q)) {
        printf("空队列\n");
        return NULL;
    }
    QNode* temp = q->front;
    ElementType item;
    if (q->front == q->rear) { //若队列只有一个元素
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }
    item = temp->data;
    free(temp);
    return item;
}

void PrintQueue(Queue* q) {
    if (IsEmptyQ(q)) {
        printf("空队列\n");
        return;
    }
    printf("打印队列数据元素：\n");
    QNode* qNode = q->front;
    while (qNode != NULL) {
        printf("%d " , qNode->data);
        qNode = qNode->next;
    }
    printf("\n");
}
#endif