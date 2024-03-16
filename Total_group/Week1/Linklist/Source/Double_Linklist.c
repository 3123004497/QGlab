#include"Linklist_head.h"
//双链表
void Double_Linklist(D_Node* d_head)
{
	


	while (1)
	{
		
		DoubleLinklist_print();
		int o = _getch();
		switch (o)
		{
		case'0':
			printf("已返回主菜单\n");
			return;
		case'1'://打印链表
			Doublelinklist_Print( d_head);
			break;
		case'2'://添加数据
			Doublelinklist_Input(d_head);
			break;
		default:
			printf("请输入0-2间的数字！\n");
			break;
		}
	}
	
}

void Doublelinklist_Input(D_Node* d_head)//输入链表元素
{
	D_Node* head1 = malloc(sizeof(D_Node));
	head1->next = NULL;
	printf("请输入数据(每次只能输入一个)：\n");
	scanf_s("%d", &head1->d_data);
	D_Node* move = d_head;
	while (move->next != NULL)
	{
		move = move->next;
	}
	move->next = head1;
	system("pause");
	system("cls");
}

void Doublelinklist_Print(D_Node* d_head)//打印链表
{
	printf("链表为：\n");
	D_Node* move = d_head->next;
	while (move != NULL)
	{
		printf("%d ", move->d_data);

		move = move->next;
	}
	printf("\n");
	system("pause");
	system("cls");
	
}
