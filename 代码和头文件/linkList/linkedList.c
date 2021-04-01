#include "linkedList.h"
#include <malloc.h>
#include <stdio.h>
LNode* RecursionReverse(LNode* head);

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L = (LinkedList)malloc(sizeof(LNode));	//�������ָ��ͷָ���ָ�룬�������ܶ�ͷָ�����޸ģ�����Ϊͷ�������ռ�
	if ( (*L) == NULL ) 
		return ERROR;				//����ڴ治�㼴����ʧ��
	(*L)->next = NULL;								
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	if (*L == NULL)
	{
		printf("����δ���������ȴ�������\n");
		return;
	}
	LinkedList p = *L;
	while (p) {
		p = p->next;
		free(*L);
		*L = p;
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if (p == NULL)
		return ERROR;

	q->next = p->next;	//β������赥������
	p->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if (p==NULL || p->next == NULL)		//���p�����ڻ�����β��㣬����error
		return ERROR;
	LNode* q = p->next;			//qΪҪɾ���Ľ��
	*e = q->data;
	p->next = q->next;			//β������赥������
	free(q);
	q = NULL;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {		//����ָ�� ָ����void visit(ElemType e)
	if (L == NULL)
	{
		printf("����δ���������ȴ�������\n");
		return;
	}
	LNode* p = L->next;
	while(p)
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
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	if (L == NULL)
	{
		printf("����δ���������ȴ�������\n");
		return ERROR;
	}
	LNode* p = L->next;
	while (p)
	{
		if (p->data == e)
			return SUCCESS;
		p = p->next;
	}
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
 //�ݹ�ʵ�ַ�ת
Status RecursionReverseList(LinkedList* L) {
	if ((*L) == NULL || (*L)->next == NULL)
	{
		printf("����δ������������ֻ����ͷ��㣬���ȴ�����������һ��ʵ�ʽ�㣡\n");
		return ERROR;
	}	
	LNode* head = (*L)->next;
	LNode* newHead = RecursionReverse((head));			//������β�����з�ת
	(*L)->next = newHead;
	return SUCCESS;
}
LNode* RecursionReverse(LNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	LNode* newHead = RecursionReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

//����ʵ�ַ�ת
Status ReverseList(LinkedList *L) {
	if ((*L) == NULL || (*L)->next == NULL)
	{
		printf("����δ������������ֻ����ͷ��㣬���ȴ�����������һ��ʵ�ʽ��\n");
		return ERROR;
	}
	LNode* p1, * p2, * p3;
	p1 = (*L)->next;
	p2 = p1->next;
	p3 = NULL;
	p1->next = NULL;
	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;		//��ת����
		p1 = p2;
		p2 = p3;
	}
	(*L)->next = p1;
	return SUCCESS;
}


/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if (L == NULL)
	{
		printf("����δ���������ȴ�������\n");
		return ERROR;
	}
	LNode* pFast, * pSlow;				//����ָ�뷨
	pFast = pSlow = L;
	while (pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
		if (pFast == pSlow)
			return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	if (*L == NULL)
	{
		printf("����δ���������ȴ�������\n");
		return NULL;
	}
	if ((*L)->next == NULL)
	{
		printf("������ֻ��ͷ��㣬�������һ��ʵ�ʽ��\n");
		return *L;
	}
	LNode * p0, * p1, * p2;				//p0,p1,p2 ��˳�����ͬ���
	p0 = *L;							//p0ָ��ͷ���
	p1 = p0->next;						//p1��p2Ϊ��Ҫ�����Ľ��
	
	while (p1 && p1->next) {
		p2 = p1->next;
		if (p2->next && p2->next->next) {			
			p1->next = p2->next;				//ʵ��p1��̽���p2ǰ�����Ĺҽ�
			p0->next = p2;
		}
		else {									//p2->nextΪ����ζ�Ž�����Ϊż������ѭ���ڴ˴ν��������
			p1->next = p2->next;				//p2->next->nextΪ����ζ�Ž�����Ϊ��������ѭ���ڴ˴ν�������
			p0->next = p2;
			p2->next = p1;
			return *L;							//ѭ������
		}
		p2->next = p1;							//ż�����ķ�ת
		p0 = p1;								//p0����ָ�򽻻�֮��λ�ں���Ľ��
		p1 = p0->next;
	}
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	if (*L == NULL)
	{
		printf("����δ���������ȴ�������");
		return NULL;
	}
	LNode* p = *L;
	int cnt = 0;
	while (p)
	{
		p = p->next;
		cnt++;
	}
	p = *L;
	for (int i = 0; i < cnt / 2; i++)
	{
		p = p->next;
	}
	return p; 
}

/**
 *  @name        : LNode* FindNode(LinkedList* L,int val)
 *	@description : find the appointed node in the linked list
 *	@param		 : L(the head node),pos
 *	@return		 : LNode
 *  @notice      : my additional function
 */
LNode* FindNode(LinkedList L,int pos) {
	if (L == NULL)
	{
		printf("����δ���������ȴ�������");
		return NULL;
	}
	LNode* p = L;
	int cnt = 0;
	while (p)
	{
		p = p->next;
		cnt++;
	}
	if (pos <= OVERFLOW || pos > (cnt + 1) )
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



