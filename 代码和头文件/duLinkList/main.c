#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	DuLinkedList pHead = NULL;		//创建头结点
	DuLNode* p, * q;
	Status status;
	int num = 0, pos;
	char menu[] = {
	   "QG训练营第一份大作业：双向链表\n"
	};
	for (int i = 0; menu[i] != '\0'; i++) {
		Sleep(30);
		printf("%c", menu[i]);
	}
	while (num != OVERFLOW)
	{
		printf("输入数字使用相应功能。建议先初始化链表\n");
		printf("-1.退出系统\n");
		printf("1:初始化链表\n");
		printf("2:前插结插入点\n");
		printf("3.后插法插入结点\n");
		printf("4.删除结点\n");
		printf("5.遍历链表\n");
		printf("6.摧毁链表\n");

		scanf("%d", &num);
		switch (num)
		{
		case 1:status = InitList_DuL(&pHead);
			printf("%d\n", status);
			break;
		case 2: {
			printf("请输入结点的索引(请注意：头节点的索引为0，请勿在头结点前插入结点)，您将在该结点前插入结点");
			scanf("%d", &pos);
			p = (DuLNode*)malloc(sizeof(DuLNode));
			p = FindNode(pHead, pos);
			if (p == NULL)
			{
				printf("该索引无效，请重新输入！\n");
				break;
			}
			q = (DuLNode*)malloc(sizeof(DuLNode));
			q->next = NULL;
			ElemType data;
			printf("请输入新结点的data:");
			scanf("%d", &data);
			q->data = data;
			status = InsertBeforeList_DuL(p, q);
			printf("%d\n", status);
			break;
		}
		case 3: {
			printf("请输入结点的索引，您将在该结点后插入结点");
			scanf("%d", &pos);
			p = (DuLNode*)malloc(sizeof(DuLNode));
			p = FindNode(pHead, pos);
			if (p == NULL)
			{
				printf("该索引无效，请重新输入！\n");
				free(p);
				break;
			}
			q = (DuLNode*)malloc(sizeof(DuLNode));
			q->next = NULL;
			ElemType data;
			printf("请输入新结点的data:");
			scanf("%d", &data);
			q->data = data;
			status = InsertAfterList_DuL(p, q);
			printf("%d\n", status);
			break;
		}
		case 4: {
			printf("请输入想要删除结点的索引：");
			scanf("%d", &pos);
			p = (DuLNode*)malloc(sizeof(DuLNode));
			p = FindNode(pHead, pos - 1);
			if (p == NULL)
			{
				printf("该索引无效，请重新输入！\n");
				free(p);
				break;
			}
			ElemType e;
			status = DeleteList_DuL(p, &e);
			printf("%d\n", status);
			printf("删除的结点data为%d\n", e);
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