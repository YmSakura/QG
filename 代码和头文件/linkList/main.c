#include "linkedList.h"
#include <stdio.h>
#include <Windows.h>

int main()
{
	LinkedList pHead;		//����ͷ���
	LNode* p,* q;
	Status status;
	int num = 0, pos;
	char menu[] = {
	   "QGѵ��Ӫ��һ�ݴ���ҵ����������\n"
	};
	for (int i = 0; menu[i] != '\0'; i++) {
		Sleep(30);
		printf("%c", menu[i]);
	}
	while (num != OVERFLOW)
	{
		printf("��������ʹ����Ӧ���ܡ������ȳ�ʼ������,����ʼ������bug�Ų�����\n");
		printf("-1.�˳�ϵͳ\n");
		printf("1:��ʼ������\n");
		printf("2:������\n");
		printf("3.ɾ�����\n");
		printf("4.��������\n");
		printf("5.Ѱ�ҽ��\n");
		printf("6.��ת����\n");
		printf("7.�ж������Ƿ�ɻ�\n");
		printf("8.��ת����ż�����\n");
		printf("9.���������м���\n");
		printf("10.�ݻ�����\n");
		
		scanf("%d", &num);
        switch (num)
        {
        case 1:status = InitList(&pHead); 
			printf("%d\n",status);
			break;
		case 2: {
			printf("��������Ҫ�����������(��ע�⣺ͷ�ڵ������Ϊ0)��");
			scanf("%d", &pos);
			p = (LNode*)malloc(sizeof(LNode));
			p = FindNode(pHead, pos - 1);
			if (p == NULL)
			{
				printf("��������Ч�����������룡\n");
				break;
			}
			q = (LNode*)malloc(sizeof(LNode));
			q->next = NULL;
			ElemType data;
			printf("�������½���data:");
			scanf("%d", &data);
			q->data = data;
			status = InsertList(p, q);
			printf("%d\n", status);
			break; 
		}
		case 3: {
			printf("��������Ҫɾ������������");
			scanf("%d", &pos);
			p = (LNode*)malloc(sizeof(LNode));
			p = FindNode(pHead, pos - 1);
			if (p == NULL)
			{
				printf("��������Ч�����������룡\n");
				break;
			}
			ElemType e;
			status = DeleteList(p, &e);
			printf("%d\n", status);
			printf("ɾ���Ľ��dataΪ%d\n", e);
			break;
		}
		case 4: {
			void (*pFun)(ElemType e) = NULL;		//����һ������ָ��
			pFun = visit;							//�������ĵ�ַ��������ָ��
			TraverseList(pHead, pFun);
			break; 
		}
		case 5: {
			printf("��������ҪѰ�ҵ�Ԫ��ֵ��");
			ElemType e;
			scanf("%d", &e);
			status = SearchList(pHead, e);
			printf("%d\n", status);
			break; 
		}
		case 6: {
			int n;
			printf("�ṩ�����ַ�ת��ʽ�������ѡ��\n");
			printf("1.����ʵ��\n2.�ݹ�ʵ��\n");
			scanf("%d", &n);
			switch (n)
			{
			case 1:status = ReverseList(&pHead); break;
			case 2:status = RecursionReverseList(&pHead); break;
			dafault:break;
			}
			printf("%d\n", status);
			break;
		}
		case 7: status = IsLoopList(pHead);
			printf("%d\n", status);
			break;
        case 8: {
			pHead = ReverseEvenList(&pHead);
			break;
		}
		case 9: { 
			p = (LNode*)malloc(sizeof(LNode));
			p = FindMidNode(&pHead);
			printf("�м����dataΪ��%d\n", p->data);
			break;
		}
		case 10:DestroyList(&pHead);
        default:break;
        }
	}
	return 0;
}
