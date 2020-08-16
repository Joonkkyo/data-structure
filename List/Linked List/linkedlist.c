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
		printf("����, �޸��Ҵ� createLinkedList()\n");
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
				printf("����, �޸� �Ҵ� addLLElement()\n");
				return ret;
			}
		}
		else
			printf("����, ��ġ �ε���-[%d], addLLElement()\n", position);
	}

	return ret;
}