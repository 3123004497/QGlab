#include"Linklist_head.h"
//�������
void Input_Data(Node* head)
{
	printf("����������(ÿ��ֻ������һ������)��\n");
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
	system("cls");//��տ���̨
}

//��ӡ����
void Print_Linklist(Node*head)
{
	printf("ԭ����Ϊ��\n");
	Node* move = head->next;
	while (move!= NULL)
	{
		printf("%d ", move->data);
		
		move = move->next;

	}
	printf("\n");
	
}