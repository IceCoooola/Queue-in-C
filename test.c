#pragma once
#include"quene.h"
/*
bool isEmpty(Q*);
void initQuene(Q*);
void enQuene(Q*, QueneDataType x);
void deQuene(Q*);
QueneDataType getFront(Q*);
QueneDataType getBack(Q*);
void destroyQuene(Q*);
*/
int main()
{
	Q* quene = (Q*)malloc(sizeof(Q));
	initQueue(quene);
	enQueue(quene, 1);
	enQueue(quene, 2);
	enQueue(quene, 3);
	enQueue(quene, 4);
	enQueue(quene, 5);
	while (!(isEmptyQueue(quene)))
	{
		printf("%d ", getFrontQueue(quene));
		deQueue(quene);
	}
	free(quene);
	quene = NULL;
	return 0;
}
