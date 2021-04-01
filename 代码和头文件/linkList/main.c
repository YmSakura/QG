#include "linkedList.h"
#include <stdio.h>
#include <Windows.h>

int main()
{
	LinkedList pHead = NULL;		//创建头结点
	LNode* p,* q;
	Status status;
	int num = 0, pos;
	char menu[] = {
	   "QG训练营第一份大作业：单向链表\n"
	};
	for (int i = 0; menu[i] != '\0'; i++) {
		Sleep(30);
		printf("%c", menu[i]);
	}
	while (num != OVERFLOW)
	{
		Sleep(1000);
		system("cls");
		printf("输入数字使用相应功能。建议先初始化链表\n");
		printf("-1.退出系统\n");
		printf("1:初始化链表\n");
		printf("2:插入结点\n");
		printf("3.删除结点\n");
		printf("4.遍历链表\n");
		printf("5.寻找结点\n");
		printf("6.反转链表\n");
		printf("7.判断链表是否成环\n");
		printf("8.反转链表偶数结点\n");
		printf("9.搜索链表中间结点\n");
		printf("10.摧毁链表\n");
		
		status = scanf("%d", &num);
		while (getchar() != '\n');
		if (status == 0)
		{
			printf("输出有误！请重新输入！\n");
			continue;
		}
		if (num > 10 || num <= OVERFLOW)
		{
			printf("输出有误！请重新输入！\n");
			continue;
		}
        switch (num)
        {
        case 1:status = InitList(&pHead); 
			if (status = 1)
				printf("成功！\n");
			else
				printf("失败！\n");
			break;
		case 2: {
			printf("请输入想要插入结点的索引(请注意：头节点的索引为0)：");
			scanf("%d", &pos);
			p = (LNode*)malloc(sizeof(LNode));
			p = FindNode(pHead, pos - 1);
			if (p == NULL)
			{
				printf("该索引无效，请重新输入！\n");
				free(p);
				break;
			}
			q = (LNode*)malloc(sizeof(LNode));
			q->next = NULL;
			ElemType data;
			printf("请输入新结点的data:");
			scanf("%d", &data);
			q->data = data;
			status = InsertList(p, q);
			if (status = 1)
				printf("成功！\n");
			else
				printf("失败！\n");
			break; 
		}
		case 3: {
			printf("请输入想要删除结点的索引：");
			scanf("%d", &pos);
			p = (LNode*)malloc(sizeof(LNode));
			p = FindNode(pHead, pos - 1);
			if (p == NULL)
			{
				printf("该索引无效，请重新输入！\n");
				free(p);
				break;
			}
			ElemType e;
			status = DeleteList(p, &e);
			if (status = 1)
				printf("成功！\n");
			else
				printf("失败！\n");
			printf("删除的结点data为%d\n", e);
			break;
		}
		case 4: {
			void (*pFun)(ElemType e) = NULL;		//声明一个函数指针
			pFun = visit;							//将函数的地址赋给函数指针
			TraverseList(pHead, pFun);
			break; 
		}
		case 5: {
			printf("请输入想要寻找的元素值：");
			ElemType e;
			scanf("%d", &e);
			status = SearchList(pHead, e);
			if (status = 1)
				printf("成功！\n");
			else
				printf("失败！\n");
			break; 
		}
		case 6: {
			int n;
			printf("提供了两种反转方式，请进行选择：\n");
			printf("1.迭代实现\n2.递归实现\n");
			scanf("%d", &n);
			switch (n)
			{
			case 1:status = ReverseList(&pHead); break;
			case 2:status = RecursionReverseList(&pHead); break;
			dafault:break;
			}
			if (status = 1)
				printf("成功！\n");
			else
				printf("失败！\n");
			break;
		}
		case 7: status = IsLoopList(pHead);
			if (status = 1)
				printf("成功！\n");
			else
				printf("失败！\n");
			break;
        case 8: {
			pHead = ReverseEvenList(&pHead);
			break;
		}
		case 9: { 
			p = (LNode*)malloc(sizeof(LNode));
			p = FindMidNode(&pHead);
			if (p == NULL)
			{
				printf("查找失败！");
				free(p);
				break;
			}
			printf("中间结点的data为：%d\n", p->data);
			break;
		}
		case 10:DestroyList(&pHead);
        default: break;
        }
	}
	return 0;
}
