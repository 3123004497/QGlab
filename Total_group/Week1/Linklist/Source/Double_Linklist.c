#include"Linklist_head.h"
//˫����
void Double_Linklist(D_Node* d_head)
{
	


	while (1)
	{
		
		DoubleLinklist_print();
		int o = _getch();
		switch (o)
		{
		case'0':
			printf("�ѷ������˵�\n");
			return;
		case'1'://��ӡ����
			Doublelinklist_Print( d_head);
			break;
		case'2'://�������
			Doublelinklist_Input(d_head);
			break;
		default:
			printf("������0-2������֣�\n");
			break;
		}
	}
	
}

void Doublelinklist_Input(D_Node* d_head)//��������Ԫ��
{
	D_Node* head1 = malloc(sizeof(D_Node));
	head1->next = NULL;
	printf("����������(ÿ��ֻ������һ��)��\n");
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

void Doublelinklist_Print(D_Node* d_head)//��ӡ����
{
	printf("����Ϊ��\n");
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
