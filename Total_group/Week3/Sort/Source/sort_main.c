#include"sort.h"
int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	while (1)
	{
		Load_Data(head);//读取文档中保存的数据
		MainMenu_print();
		int o = _getch();
		switch (o)
		{
		case'0':
			printf("已退出\n");
			return;

		case'1'://生成数据
			printf("请输入要生成的数据量（10000，50000，200000）：\n");
			int num;
			scanf_s("%d", &num);
			Create_Save_data(num, 1, 999, head);

			system("pause");
			system("cls");
			break;

		case'2'://各种排序
		{
			int data_size ;
			printf("请输入要进行操作的数据量（10000，50000，200000）：\n");
			scanf_s("%d", &data_size);
	
			if (Judge_dataSize(data_size,head))
			{
				int data_size = Create_Save_data(num,  1, 999,head);//读取文档中保存的数据,并记录数据量大小
				int* S_data = (int*)malloc(data_size * sizeof(int));
				Ways_of_sort(S_data,head);
				free(S_data);
				
			}

			system("pause");
			system("cls");
			break;
		}

		case'3'://清空数据
			Clear_data(head);

			system("pause");
			system("cls");
			break;
		default:
			printf("请输入0-3间的数字！\n");

			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");//暂停

	return 0;
}