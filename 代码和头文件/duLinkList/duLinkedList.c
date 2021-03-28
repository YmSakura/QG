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
		printf("链表未创建，请先创建链表！\n");
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

	p->prior->next = q;			//q与前驱结点的挂接
	q->prior = p->prior;

	q->next = p;				//q与后继结点即p的挂接
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
	if (p->next)					//若p为尾结点，无需进行后继结点的连接
	{
		p->next->prior = q;			//q与后继结点的挂接
		q->next = p->next;
	}
	p->next = q;					//q与前驱结点即p的挂接
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
	if (q->next)		//如果q不是尾结点，需要进行p和q之后第一个结点的挂接
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
		printf("链表未创建，请先创建链表！\n");
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
		printf("链表未创建！请先创建链表");
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
		printf("索引输入错误！请重新输入\n");
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