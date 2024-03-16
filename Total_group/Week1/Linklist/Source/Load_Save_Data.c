#include"Linklist_head.h"

//读取数据
void Load_Data(Node*head)
{
	FILE* file = fopen("Linklist_data.text", "r");//打开文件
	if (file == NULL)//检验是否打开失败
	{
		printf("无历史数据！\n");
		return;
	}

	Node* head1 = malloc(sizeof(Node));
	head1->next = NULL;
	Node* move = head;
	while (fread(&head1->data, sizeof(int), 1, file) == 1)
	{
		move->next = head1;//接入链表
		move = head1;
		head1 = malloc(sizeof(Node));
		head1->next = NULL;
	}
	
	free(head1);//释放最后一个多出来的节点
	fclose(file);
	printf("读取成功！\n");
}

//保存数据到文件
void Save_Data(Node* head)
{

	FILE* file = fopen("Linklist_data.text", "w+");//打开文件
	
	if (file == NULL)
	{
		printf("打开文件失败！\n");
	}
	Node* move = head->next;
	while (move != NULL)
	{
		fwrite(&move->data, sizeof(int), 1, file);
		
		move = move->next;
	}
	fclose(file);
	
}