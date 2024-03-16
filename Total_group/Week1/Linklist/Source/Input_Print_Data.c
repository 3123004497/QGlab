#include"Linklist_head.h"
//添加数据
void Input_Data(Node* head)
{
	printf("请输入数据(每次只能输入一个数据)：\n");
	Node* head1 = malloc(sizeof(Node));
	head1->next = NULL;
	
	scanf_s("%d", &head1->data);
	Node* move = head;
	while (move->next != NULL)
	{
		move = move->next;
	}
	move->next = head1;

	Save_Data(head);
	system("pause");
	system("cls");//清空控制台
}

//打印链表
void Print_Linklist(Node*head)
{
	printf("原链表为：\n");
	Node* move = head->next;
	while (move!= NULL)
	{
		printf("%d ", move->data);
		
		move = move->next;

	}
	printf("\n");
	
}