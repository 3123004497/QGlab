#include"Linklist_head.h"
void Single_Linklist(Node* head)
{
	while (1)
	{
		Load_Data(head);//��ȡ�ĵ��б��������
		SingleLinklistMenu_print();
		int o = _getch();
		switch (o)
		{
		case'0':
			printf("�ѷ������˵�\n");
			return;
		case'1'://��ӡ���� 
			Print_Linklist(head);
			system("pause");
			system("cls");
			break;
		case'2'://.�������
			Input_Data(head);
			break;
		case'3'://��ż����
			Odd_Even_change(head);
			
			break;
		case'4'://�������е�
			findMiddle(head);
			system("pause");
			system("cls");
			break;
		case'5'://�ж������Ƿ�ɻ�
			Judge_ring(head);
			system("pause");
			system("cls");
			break;
		case'6'://��ת����
			Reversal_linklist(head);
			system("pause");
			system("cls");
			break;
		default:
			printf("������0-2������֣�\n");
			system("pause");//��ͣ
			system("cls");//���
			break;

		}
	}

}

//��ż����
Node* Odd_Even_change(Node*head)
{
	//
	//Print_Linklist(head);
	//Node* Temp;
	//Node* head2 = malloc(sizeof(Node));
	//head2 = head;//���ĵ��ڵ��������
	//Node* move = head2->next;//move��1
	////��������Ϊ 1��2��3��4��5��6��7
	//Node* slow = head2->next;
	//Node* fast = head2->next->next;//������������slow��1��fast��2
	//while (fast->next != NULL||slow->next!=NULL)
	//{
	//	Temp = move;//Temp��1
	//	move = fast;//2�ŵ�1
	//	move->next = slow;//1�ŵ�2
	//	slow = slow->next->next;
	//	fast = fast->next->next;//�棨ż������2�����棨ż����
	//	move = Temp->next->next;//move��1�Ƶ�3
	//}
	//printf("ת��������Ϊ��\n");
	//Print_Linklist(head2);

	system("cls");//���
	printf("�ù���Ϊ���ѹ��ܣ���VIP�û���ʹ�ã�    V��50����(QAQ)\n");
	system("pause");//��ͣ
	system("cls");//���
	printf("�ðɣ���������̫���ˣ�д��������ToT����ToT����ToT��\n");
	system("pause");//��ͣ
	system("cls");//���
}

//���������е�
void findMiddle(Node* head)
{
	
	Print_Linklist(head);
	Node* slow = head;
	Node* fast = head;
	while (slow->next!=NULL)
	{//��������Ϊ 1��2��3��4��5��6��7
		slow = slow->next;
		fast = fast->next->next;//������������slow��1��fast��2

		if (fast->next != NULL && fast->next->next == NULL)//��fast��6ʱ��slow��3����ʱ6����һ����7�����ǿ�(fast->next != NULL)����6����һ������һ���ǿգ�fast->next->next == NULL��
		{
			printf("������е�Ϊ��%d\n", slow->next->data);
			break;
		}
		if (fast != NULL && fast->next == NULL)//������ֻ��1��6����fast��6ʱ��6���ǿգ�fast != NULL����6����һ���ǿգ�fast->next == NULL��
		{
			printf("������ż�������е㡣\n");
		}
	}
}

//�ж������Ƿ�ɻ�
void Judge_ring(Node* head)
{
	
	Print_Linklist(head);
	Node* slow = head;
	Node* fast = head->next;

	while (fast!=NULL&&fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow==fast)//����˵���ɻ�
		{
			printf("����ɻ�\n");
			return;
		}
	}
	printf("�����ɻ�\n");
}

//��ת����
void Reversal_linklist(Node* head)
{
	Print_Linklist(head);//�ȴ�ӡԭ��������
	printf("ת��������Ϊ��\n");
	Node* head2 = malloc(sizeof(Node));
	head2 = head;//���ĵ��ڵ��������
	
	Node* move = head2->next;
	Node* p = head2->next->next;
	while (p!= NULL)
	{
		move->next = p->next;
		p->next = head2->next;
		head2->next = p;
		p = move->next;
	}
	Print_Linklist(head2);
}