#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

//�����ṹ��
typedef struct _Node//������
{
	int data;
	struct _Node* next;
}Node;

typedef struct Double_Node//˫����
{
	int d_data;
	struct Double_Node* prior;
	struct Double_Node* next;
}D_Node;

//��������
void MainMenu_print();//��ӡ���˵�
void SingleLinklistMenu_print();//��ӡ�������ܵ�
void DoubleLinklist_print();//��ӡ˫�����ܵ�
void Input_Data(Node* head);//�������
void Print_Linklist(Node* head);//��ӡ����
void Load_Data(Node* head);//��ȡ����
void Save_Data(Node* head);//��������

void Single_Linklist(Node* head);//������
Node* Odd_Even_change(Node* head);//��ż����
void findMiddle(Node* head);//���������е�
void Judge_ring(Node* head);//�ж������Ƿ�ɻ�
void Reversal_linklist(Node* head);//��ת����

void Double_Linklist(Node* head);//˫����
void Doublelinklist_Input(D_Node* d_head);//��������Ԫ��
void Doublelinklist_Print(D_Node* d_head);//��ӡ����