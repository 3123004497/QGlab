#include"Linklist_head.h"

//��ȡ����
void Load_Data(Node*head)
{
	FILE* file = fopen("Linklist_data.text", "r");//���ļ�
	if (file == NULL)//�����Ƿ��ʧ��
	{
		printf("����ʷ���ݣ�\n");
		return;
	}

	Node* head1 = malloc(sizeof(Node));
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

//�������ݵ��ļ�
void Save_Data(Node* head)
{

	FILE* file = fopen("Linklist_data.text", "w+");//���ļ�
	
	if (file == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
	}
	Node* move = head->next;
	while (move != NULL)
	{
		fwrite(&move->data, sizeof(int), 1, file);
		
		move = move->next;
	}
	fclose(file);
	
}