#include"sort.h"
int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	while (1)
	{
		Load_Data(head);//��ȡ�ĵ��б��������
		MainMenu_print();
		int o = _getch();
		switch (o)
		{
		case'0':
			printf("���˳�\n");
			return;

		case'1'://��������
			printf("������Ҫ���ɵ���������10000��50000��200000����\n");
			int num;
			scanf_s("%d", &num);
			Create_Save_data(num, 1, 999, head);

			system("pause");
			system("cls");
			break;

		case'2'://��������
		{
			int data_size ;
			printf("������Ҫ���в�������������10000��50000��200000����\n");
			scanf_s("%d", &data_size);
	
			if (Judge_dataSize(data_size,head))
			{
				int data_size = Create_Save_data(num,  1, 999,head);//��ȡ�ĵ��б��������,����¼��������С
				int* S_data = (int*)malloc(data_size * sizeof(int));
				Ways_of_sort(S_data,head);
				free(S_data);
				
			}

			system("pause");
			system("cls");
			break;
		}

		case'3'://�������
			Clear_data(head);

			system("pause");
			system("cls");
			break;
		default:
			printf("������0-3������֣�\n");

			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");//��ͣ

	return 0;
}