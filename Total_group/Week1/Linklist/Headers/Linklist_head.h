#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

//创建结构体
typedef struct _Node//单链表
{
	int data;
	struct _Node* next;
}Node;

typedef struct Double_Node//双链表
{
	int d_data;
	struct Double_Node* prior;
	struct Double_Node* next;
}D_Node;

//函数声明
void MainMenu_print();//打印主菜单
void SingleLinklistMenu_print();//打印单链表功能单
void DoubleLinklist_print();//打印双链表功能单
void Input_Data(Node* head);//添加数据
void Print_Linklist(Node* head);//打印链表
void Load_Data(Node* head);//读取数据
void Save_Data(Node* head);//保存数据

void Single_Linklist(Node* head);//单链表
Node* Odd_Even_change(Node* head);//奇偶调换
void findMiddle(Node* head);//查找链表中点
void Judge_ring(Node* head);//判断链表是否成环
void Reversal_linklist(Node* head);//反转链表

void Double_Linklist(Node* head);//双链表
void Doublelinklist_Input(D_Node* d_head);//输入链表元素
void Doublelinklist_Print(D_Node* d_head);//打印链表