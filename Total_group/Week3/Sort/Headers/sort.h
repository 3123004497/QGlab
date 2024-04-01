#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>

//创建结构体用于将数据存入文件
typedef struct _Node//单链表
{
	int data;
	struct _Node* next;
}Node;

//函数声明
int Create_Save_data(int num, int min, int max, Node* head);
int  Load_Data(Node* head);

void MainMenu_print();//打印主菜单
void Sort_Menu_print();//打印排序方法

//选择文件数据量并判断文件的数据量是否符合用户选择
int Judge_dataSize(Node* head);
void Clear_data(Node* head);//清空数据


void Ways_of_sort(int *S_data,Node* head);
void InserSort(int* S_data);//插入排序
void msort(int* S_data, int tempA[], int left, int right);//归并排序1
void merge(int* S_data, int tempA[], int left, int mid, int right);//归并排序2
void MergeSort(int* S_data);//归并排序 
void QuickSort(int* S_data);//快速排序
int QuickSort_Divide(int* S_data, int low, int high);//快排用到的划分
void Qsort(int* S_data, int low, int high);
void swap(int* a, int* b);//交换函数
void CountSort(int* S_data);//计数排序
void RadixCountSort(int* S_data);//基数计数排序
