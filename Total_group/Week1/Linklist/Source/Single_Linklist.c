#include"Linklist_head.h"
void Single_Linklist(Node* head)
{
	while (1)
	{
		Load_Data(head);//读取文档中保存的数据
		SingleLinklistMenu_print();
		int o = _getch();
		switch (o)
		{
		case'0':
			printf("已返回主菜单\n");
			return;
		case'1'://打印链表 
			Print_Linklist(head);
			system("pause");
			system("cls");
			break;
		case'2'://.添加数据
			Input_Data(head);
			break;
		case'3'://奇偶调换
			Odd_Even_change(head);
			
			break;
		case'4'://找链表中点
			findMiddle(head);
			system("pause");
			system("cls");
			break;
		case'5'://判断链表是否成环
			Judge_ring(head);
			system("pause");
			system("cls");
			break;
		case'6'://反转链表
			Reversal_linklist(head);
			system("pause");
			system("cls");
			break;
		default:
			printf("请输入0-2间的数字！\n");
			system("pause");//暂停
			system("cls");//清空
			break;

		}
	}

}

//奇偶调换
Node* Odd_Even_change(Node*head)
{
	//
	//Print_Linklist(head);
	//Node* Temp;
	//Node* head2 = malloc(sizeof(Node));
	//head2 = head;//将文档内的链表接入
	//Node* move = head2->next;//move在1
	////假设链表为 1，2，3，4，5，6，7
	//Node* slow = head2->next;
	//Node* fast = head2->next->next;//经过这两部后slow在1，fast在2
	//while (fast->next != NULL||slow->next!=NULL)
	//{
	//	Temp = move;//Temp在1
	//	move = fast;//2放到1
	//	move->next = slow;//1放到2
	//	slow = slow->next->next;
	//	fast = fast->next->next;//奇（偶）数加2还是奇（偶）数
	//	move = Temp->next->next;//move从1移到3
	//}
	//printf("转化后链表为：\n");
	//Print_Linklist(head2);

	system("cls");//清空
	printf("该功能为付费功能，仅VIP用户可使用！    V我50解锁(QAQ)\n");
	system("pause");//暂停
	system("cls");//清空
	printf("好吧，真相是我太菜了，写不出来（ToT）（ToT）（ToT）\n");
	system("pause");//暂停
	system("cls");//清空
}

//查找链表中点
void findMiddle(Node* head)
{
	
	Print_Linklist(head);
	Node* slow = head;
	Node* fast = head;
	while (slow->next!=NULL)
	{//假设链表为 1，2，3，4，5，6，7
		slow = slow->next;
		fast = fast->next->next;//经过这两部后slow在1，fast在2

		if (fast->next != NULL && fast->next->next == NULL)//当fast在6时，slow在3，此时6的下一个是7，不是空(fast->next != NULL)，且6的下一个的下一个是空（fast->next->next == NULL）
		{
			printf("链表的中点为：%d\n", slow->next->data);
			break;
		}
		if (fast != NULL && fast->next == NULL)//若链表只有1到6，则fast在6时，6不是空（fast != NULL），6的下一个是空（fast->next == NULL）
		{
			printf("链表是偶链表，无中点。\n");
		}
	}
}

//判断链表是否成环
void Judge_ring(Node* head)
{
	
	Print_Linklist(head);
	Node* slow = head;
	Node* fast = head->next;

	while (fast!=NULL&&fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow==fast)//相遇说明成环
		{
			printf("链表成环\n");
			return;
		}
	}
	printf("链表不成环\n");
}

//反转链表
void Reversal_linklist(Node* head)
{
	Print_Linklist(head);//先打印原来的链表
	printf("转化后链表为：\n");
	Node* head2 = malloc(sizeof(Node));
	head2 = head;//将文档内的链表接入
	
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