#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

LinkedList* createLinkedList()
{
	LinkedList* pReturn = NULL;
	int i = 0;

	pReturn = (LinkedList*)malloc(sizeof(LinkedList));
	if (pReturn != NULL)
		memset(pReturn, 0, sizeof(LinkedList));
	else
	{
		printf("오류, 메모리할당 createLinkedList()\n");
		return NULL;
	}

	return pReturn;
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	int ret = FALSE;
	int i = 0;
	ListNode* pPreNode = NULL;
	ListNode* pNewNode = NULL;
	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			pNewNode = (ListNode*)malloc(sizeof(ListNode));
			if (pNewNode != NULL)
			{
				*pNewNode = element;
				pNewNode->pLink = NULL;
				
				pPreNode = &(pList->headerNode);
				for (i = 0; i < position; i++)
					pPreNode = pPreNode->pLink;

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;

				pList->currentElementCount++;
				
				ret = TRUE;
			}
			else
			{
				printf("오류, 메모리 할당 addLLElement()\n");
				return ret;
			}
		}
		else
			printf("오류, 위치 인덱스-[%d], addLLElement()\n", position);
	}

	return ret;
}