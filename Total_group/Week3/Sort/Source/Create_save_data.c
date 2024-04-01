#include"sort.h"

//��ȡ����
int Load_Data(Node* head)
{
	FILE* file = fopen("Sort_data.text", "r");//���ļ�
	if (file == NULL)//�����Ƿ��ʧ��
	{
		printf("����ʷ���ݣ�\n");
		return;
	}


	Node* head1 = (Node*)malloc(sizeof(Node));
	head1->next = NULL;
	Node* move = head;
	
	while (fread(&head1->data, sizeof(int), 1, file) == 1)
	{
		
		move->next = head1;//��������
		move = head1;
		head1 = malloc(sizeof(Node));
		head1->next = NULL;
		
	}
	free(head1);//�ͷ����һ��������Ľڵ�
	fclose(file);
	
	printf("��ȡ�ɹ���\n");

	
}

//�������num����min��max�������������䱣�����ļ���
int Create_Save_data(int num, int min, int max, Node* head)
{   //�������

	FILE* file = fopen("Sort_data.text", "w+");//���ļ�

	if (file == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return;
	}
	Node* move = head;

	int sum_num = 0;//���ڱ�ʾ�ļ���������

	for (int i = 0; i < num; i++)
	{
		Node*head1= (Node*)malloc(sizeof(Node));
		head1->data= rand() % (max - min + 1) + min;
		head1->next=move->next;
		move->next = head1;
		move = move->next;
		sum_num++;
	}
	move = head->next;// ���½�moveָ��ͷ�ڵ����һ���ڵ�
	//���浽�ļ�
	while (move != NULL)
	{
		fwrite(&move->data, sizeof(int), 1, file);
		move = move->next;
	}

	fclose(file);
	printf("������ɵ� %d �������ѱ��浽�ļ���\n",num);
	return sum_num;//�����ж��ļ�������
}

//ѡ���ļ����������ж��ļ����������Ƿ�����û�ѡ��
int Judge_dataSize(int data_size, Node* head)
{
	
	if (data_size == 10000 || data_size == 50000 || data_size == 200000)
	{
		if (data_size == Create_Save_data(data_size, 1, 999, head))
		{
			printf("��ǰ�ļ������������ϣ����Լ��������������\n");
			return 1;
		}
		else
		{
			printf("��ǰ�ļ��������������ϣ��뷵�����˵��������������������Ӧ����������\n");
			return 0;
		}
	}
	else
	{
		printf("���������� 10000��50000��200000 ��\n");
		return 0;
	}

}

void Clear_data(Node* head)//�������
{
	FILE* file = fopen("Sort_data.text", "w");//���ļ�
	if (file == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return;
	}
	fputc('\0', file);
	fclose(file);
	printf("��������ݣ��巵�����˵�������Ҫ��������\n");
}
