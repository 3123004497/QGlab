#include"sort.h"

//读取数据
int Load_Data(Node* head)
{
	FILE* file = fopen("Sort_data.text", "r");//打开文件
	if (file == NULL)//检验是否打开失败
	{
		printf("无历史数据！\n");
		return;
	}


	Node* head1 = (Node*)malloc(sizeof(Node));
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

//随机生成num个从min到max的整数，并将其保存在文件中
int Create_Save_data(int num, int min, int max, Node* head)
{   //随机生成

	FILE* file = fopen("Sort_data.text", "w+");//打开文件

	if (file == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}
	Node* move = head;

	int sum_num = 0;//用于表示文件的数据量

	for (int i = 0; i < num; i++)
	{
		Node*head1= (Node*)malloc(sizeof(Node));
		head1->data= rand() % (max - min + 1) + min;
		head1->next=move->next;
		move->next = head1;
		move = move->next;
		sum_num++;
	}
	move = head->next;// 重新将move指向头节点的下一个节点
	//保存到文件
	while (move != NULL)
	{
		fwrite(&move->data, sizeof(int), 1, file);
		move = move->next;
	}

	fclose(file);
	printf("随机生成的 %d 个数据已保存到文件中\n",num);
	return sum_num;//用于判断文件数据量
}

//选择文件数据量并判断文件的数据量是否符合用户选择
int Judge_dataSize(int data_size, Node* head)
{
	
	if (data_size == 10000 || data_size == 50000 || data_size == 200000)
	{
		if (data_size == Create_Save_data(data_size, 1, 999, head))
		{
			printf("当前文件的数据量符合，可以继续进行排序操作\n");
			return 1;
		}
		else
		{
			printf("当前文件的数据量不符合，请返回主菜单进行数据清空再生成相应的数据量！\n");
			return 0;
		}
	}
	else
	{
		printf("请输入数字 10000，50000或200000 ！\n");
		return 0;
	}

}

void Clear_data(Node* head)//清空数据
{
	FILE* file = fopen("Sort_data.text", "w");//打开文件
	if (file == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}
	fputc('\0', file);
	fclose(file);
	printf("已清空数据，清返回主菜单生成需要的数据量\n");
}
