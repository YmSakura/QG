#include "duLinkedList.h"
#include <stdio.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if (*L == NULL)
		return ERROR;
	(*L)->next = NULL;
	(*L)->prior = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	if (*L == NULL)
	{
		printf("����δ���������ȴ�������\n");
		return;
	}
	DuLNode* p = *L;
	while (p) {
		p = p->next;
		free(*L);
		*L = p;
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if (p == NULL)
		return ERROR;

	p->prior->next = q;			//q��ǰ�����Ĺҽ�
	q->prior = p->prior;

	q->next = p;				//q���̽�㼴p�Ĺҽ�
	p->prior = q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if (p == NULL)
		return ERROR;
	if (p->next)					//��pΪβ��㣬������к�̽�������
	{
		p->next->prior = q;			//q���̽��Ĺҽ�
		q->next = p->next;
	}
	p->next = q;					//q��ǰ����㼴p�Ĺҽ�
	q->prior = p;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if (p == NULL || p->next == NULL)
		return ERROR;
	DuLNode* q = p->next;
	*e = q->data;
	if (q->next)		//���q����β��㣬��Ҫ����p��q֮���һ�����Ĺҽ�
	{
		q->next->prior = p;
	}
	p->next = q->next;
	free(q);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	if (L == NULL)
	{
		printf("����δ���������ȴ�������\n");
		return;
	}
	DuLNode* p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}

void visit(ElemType e)
{
	printf("%d\t", e);
}

/**
 *  @name        : LNode* FindNode(LinkedList* L,int val)
 *	@description : find the appointed node in the linked list
 *	@param		 : L(the head node),pos
 *	@return		 : LNode
 *  @notice      : my additional function
 */
DuLNode* FindNode(DuLinkedList L, int pos) {
	if (L == NULL)
	{
		printf("����δ���������ȴ�������");
		return NULL;
	}
	DuLNode* p = L;
	int cnt = 0;
	while (p)
	{
		p = p->next;
		cnt++;
	}
	if (pos == OVERFLOW || pos > (cnt + 1))
	{
		printf("���������������������\n");
		return NULL;
	}

	p = L;
	for (int i = 0; p; i++)
	{
		if (i == pos)
		{
			return p;
		}
		p = p->next;
	}

}