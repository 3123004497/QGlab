#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>

//�����ṹ�����ڽ����ݴ����ļ�
typedef struct _Node//������
{
	int data;
	struct _Node* next;
}Node;

//��������
int Create_Save_data(int num, int min, int max, Node* head);
int  Load_Data(Node* head);

void MainMenu_print();//��ӡ���˵�
void Sort_Menu_print();//��ӡ���򷽷�

//ѡ���ļ����������ж��ļ����������Ƿ�����û�ѡ��
int Judge_dataSize(Node* head);
void Clear_data(Node* head);//�������


void Ways_of_sort(int *S_data,Node* head);
void InserSort(int* S_data);//��������
void msort(int* S_data, int tempA[], int left, int right);//�鲢����1
void merge(int* S_data, int tempA[], int left, int mid, int right);//�鲢����2
void MergeSort(int* S_data);//�鲢���� 
void QuickSort(int* S_data);//��������
int QuickSort_Divide(int* S_data, int low, int high);//�����õ��Ļ���
void Qsort(int* S_data, int low, int high);
void swap(int* a, int* b);//��������
void CountSort(int* S_data);//��������
void RadixCountSort(int* S_data);//������������
