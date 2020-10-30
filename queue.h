//
// Created by 44811 on 2020/10/27.
//

#ifndef BIGDATA_LAB3_QUEUE_H
#define BIGDATA_LAB3_QUEUE_H

#define ElementType Node*
#define ERROR NULL //ElementType的特殊值，标志错误
typedef struct _Node {
    ElementType data;
    struct _Node* next;
}QNode;

typedef struct {
    QNode* front; //指向对头节点
    QNode* rear; //指向队尾节点
}Queue;

Queue* CreateQueue();
void AddQ(Queue* q, ElementType item);
int IsEmptyQ(Queue* q);
ElementType DeleteQ(Queue* q);
void PrintQueue(Queue* q);


#endif //BIGDATA_LAB3_QUEUE_H
