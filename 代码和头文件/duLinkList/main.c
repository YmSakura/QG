#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	DuLinkedList pHead = NULL;		//����ͷ���
	DuLNode* p, * q;
	Status status;
	int num = 0, pos;
	char menu[] = {
	   "QGѵ��Ӫ��һ�ݴ���ҵ��˫������\n"
	};
	for (int i = 0; menu[i] != '\0'; i++) {
		Sleep(30);
		printf("%c", menu[i]);
	}
	while (num != OVERFLOW)
	{
		printf("��������ʹ����Ӧ���ܡ������ȳ�ʼ������\n");
		printf("-1.�˳�ϵͳ\n");
		printf("1:��ʼ������\n");
		printf("2:ǰ�������\n");
		printf("3.��巨������\n");
		printf("4.ɾ�����\n");
		printf("5.��������\n");
		printf("6.�ݻ�����\n");

		scanf("%d", &num);
		switch (num)
		{
		case 1:status = InitList_DuL(&pHead);
			printf("%d\n", status);
			break;
		case 2: {
			printf("�������������(��ע�⣺ͷ�ڵ������Ϊ0��������ͷ���ǰ������)�������ڸý��ǰ������");
			scanf("%d", &pos);
			p = (DuLNode*)malloc(sizeof(DuLNode));
			p = FindNode(pHead, pos);
			if (p == NULL)
			{
				printf("��������Ч�����������룡\n");
				break;
			}
			q = (DuLNode*)malloc(sizeof(DuLNode));
			q->next = NULL;
			ElemType data;
			printf("�������½���data:");
			scanf("%d", &data);
			q->data = data;
			status = InsertBeforeList_DuL(p, q);
			printf("%d\n", status);
			break;
		}
		case 3: {
			printf("��������������������ڸý��������");
			scanf("%d", &pos);
			p = (DuLNode*)malloc(sizeof(DuLNode));
			p = FindNode(pHead, pos);
			if (p == NULL)
			{
				printf("��������Ч�����������룡\n");
				free(p);
				break;
			}
			q = (DuLNode*)malloc(sizeof(DuLNode));
			q->next = NULL;
			ElemType data;
			printf("�������½���data:");
			scanf("%d", &data);
			q->data = data;
			status = InsertAfterList_DuL(p, q);
			printf("%d\n", status);
			break;
		}
		case 4: {
			printf("��������Ҫɾ������������");
			scanf("%d", &pos);
			p = (DuLNode*)malloc(sizeof(DuLNode));
			p = FindNode(pHead, pos - 1);
			if (p == NULL)
			{
				printf("��������Ч�����������룡\n");
				free(p);
				break;
			}
			ElemType e;
			status = DeleteList_DuL(p, &e);
			printf("%d\n", status);
			printf("ɾ���Ľ��dataΪ%d\n", e);
			break;
		}
		case 5: {
			void (*pFun)(ElemType e) = NULL;		
			pFun = visit;			
			TraverseList_DuL(pHead, pFun);
			break;
		}
		case 6: 
			DestroyList_DuL(&pHead);
			break;
		default:break;
		}
	}
	return 0;
}