#include"Linklist_head.h"
int main()
{
	Node* head =malloc(sizeof(Node));
	head->next = NULL;
	D_Node* d_head = malloc(sizeof(D_Node));
	d_head->next = NULL;
	
	while (1)
	{
		//Load_Data(head);//��ȡ�ĵ��б��������
		MainMenu_print();
		int o = _getch();
		switch (o)
		{
		case'0':
			printf("���˳�\n");
			return;
		case'1'://������
			Single_Linklist(head);
			break;
		case'2'://˫����
			Double_Linklist(d_head);
			break;
		default:
			printf("������0-2������֣�\n");
			break;
		}
	}
	system("pause");//��ͣ
	return 0;
}