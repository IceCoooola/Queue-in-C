#include"quene.h"

//typedef struct QueneNode
//{
//	QueueDataType data;
//	struct QueneNode* next;
//}QueneNode;
//
//typedef struct Quene
//{
//	QueneNode* head;
//	QueneNode* tail;
//}Q;


void initQueue(Q* q)
{
	assert(q);
	//initiate quene to size of element. 
	q->head = NULL;
	q->tail = NULL;
}

bool isEmptyQueue(Q* q)
{
	assert(q);
	//return true if quene is empty, return false if quene is not empty.
	return q->head == NULL;
}

void enQueue(Q* q, QueueDataType x)
{
	assert(q);
	//add one element to the back of quene
	if (isEmptyQueue(q))
	{
		q->head = (QueueNode*)malloc(sizeof(QueueNode));
		if (q->head == NULL)
		{
			exit(-1);
		}
		q->head->data = x;
		q->head->next = NULL;
		q->tail = q->head;
	}
	else
	{
		q->tail->next = (QueueNode*)malloc(sizeof(QueueNode));
		if (q->tail->next == NULL)
		{
			exit(-1);
		}
		q->tail->next->data = x;
		q->tail->next->next = NULL;
		q->tail = q->tail->next;
	}

}
void deQueue(Q* q)
{
	//delete one element from the front of quene
	assert(q);
	if (isEmptyQueue(q))
	{
		printf("list empty!\n");
		return;
	}
	if (q->head->next == NULL)
	{
		free(q->head);
		q->head = q->tail = NULL;
	}
	else
	{
		QueueNode* temp = q->head;
		q->head = q->head->next;
		free(temp);
	}
}
QueueDataType getFrontQueue(Q* q)
{
	assert(q);
	if (isEmptyQueue(q))
	{
		printf("list empty!\n");
		return -1;
	}
	return q->head->data;
}
QueueDataType getBackQueue(Q* q)
{
	assert(q);
	if (isEmptyQueue(q))
	{
		printf("list empty!\n");
		return -1;
	}
	return q->tail->data;
}
void destroyQueue(Q* q)
{
	//delete all elements in quene
	while (q->head)
	{
		QueueNode* temp = q->head;
		q->head = q->head->next;
		free(temp);
	}
	q->tail = NULL;
}

int getQueueLength(Q* q)
{
	int size = 0;
	QueueNode* cur = q->head;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
