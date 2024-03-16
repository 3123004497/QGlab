#include"Linklist_head.h"
int main()
{
	Node* head =malloc(sizeof(Node));
	head->next = NULL;
	D_Node* d_head = malloc(sizeof(D_Node));
	d_head->next = NULL;
	
	while (1)
	{
		//Load_Data(head);//读取文档中保存的数据
		MainMenu_print();
		int o = _getch();
		switch (o)
		{
		case'0':
			printf("已退出\n");
			return;
		case'1'://单链表
			Single_Linklist(head);
			break;
		case'2'://双链表
			Double_Linklist(d_head);
			break;
		default:
			printf("请输入0-2间的数字！\n");
			break;
		}
	}
	system("pause");//暂停
	return 0;
}