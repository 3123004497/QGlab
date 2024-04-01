#include"sort.h"

void Ways_of_sort(int* S_data, Node* head)
{
	while (1)
	{
		
		Sort_Menu_print();
		int o = _getch();
		switch (o)
		{
		case'0':
			printf("已返回主菜单\n");
			return;
		case'1'://插入排序
			InserSort(S_data);
			system("pause");
			system("cls");
			break;
		case'2'://归并排序 
			MergeSort(S_data);
			system("pause");
			system("cls");
			break;
		case'3'://快速排序
			QuickSort(S_data);
			system("pause");
			system("cls");
			break;
		case'4'://计数排序
			CountSort(S_data);
			system("pause");
			system("cls");
			break;
		case'5'://基数计数排序
			RadixCountSort(S_data);
			system("pause");
			system("cls");
			break;
		default:
			printf("请输入0-5间的数字！\n");
			system("pause");//暂停
			system("cls");//清空
			break;

		}
	}
}


//插入排序
void InserSort(int* S_data)
{
	//
	//

	int n = sizeof(S_data) / sizeof(S_data[0]);//获取数组长度

	//
	for (int i = 1; i < n; i++)
	{
		int temp = S_data[i];
		int j = i - 1;//所以S_data[j]就是S_data[i]的前一项
		while (j >= 0 && S_data[j] >temp)//比较，若前一项大于后一项
		{
			S_data[j + 1] = S_data[j];//则将前一项的值赋给后一项（原后一项的值前面存在了temp中，不怕被覆盖）
			j--;
		}
		S_data[j + 1] = temp;//利用temp将原来后一项的值付给原来的前一项（因为上面j--了，所以要变成j+1）
	}
	//
	//
	printf("插入排序完成!" );
}
//归并排序1
void msort(int* S_data,int tempA[],int left,int right )
{
	if (left < right)//成立说明至少有两个数
	{
		int mid = (left + right) / 2;//数组中点
		msort(S_data, tempA, left, mid);
		msort(S_data, tempA, mid+1,right);//递归划分
		merge(S_data, tempA, left, mid,right);
	}
	
}
//归并排序2
void merge(int* S_data, int tempA[], int left, int mid, int right)
{
	int left_p = left;//左一
	int right_p = mid+1;//右一
	int tempA_p = left;//临时数组下标
	//合并
	while (left_p<=mid&&right_p<=right)
	{
		if (S_data[left_p] < S_data[right_p])//左一比右一小
		{
			tempA[tempA_p++] = S_data[left_p++];//将左一接在临时数组（从临时数组第一个位置开始接，因为left一开始等于0）
		}
		else
		{
			tempA[tempA_p++] = S_data[right_p++];//否则将右一接在临时数组
		}
	}
	while (left_p <= mid)//判断左半区是否有剩余
	{
		tempA[tempA_p++] = S_data[left_p++];//有就直接接在临时数组
	}
	while (right_p <= right)//判断右半区是否有剩余
	{
		tempA[tempA_p++] = S_data[right_p++];
	}
	while (left < +right)
	{
		S_data = tempA[left];//将排好序的数重新存在原来的数组中
		left++;
	}
}

//归并排序 
void MergeSort(int* S_data)
{
	//
	//

	int n = sizeof(S_data) / sizeof(S_data[0]);//获取数组长度
	int* tempA = (int*)malloc(n * sizeof(int));//创建临时数组
	if (tempA)//判断是否创建成功
	{
		//
		msort(S_data, tempA, 0, n - 1);
		//
		//
		printf("归并排序完成!" );
		free(tempA);
	}
	else
	{
		printf("创建临时数组失败，请重试！\n");
	}

}
int QuickSort_Divide(int* S_data, int low, int high)//快排用到的划分
{
	int std_mark = S_data[high];//将基准选为数组最后一个数
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (S_data[j] < std_mark)
		{
			swap(&S_data[j], &S_data[i++]);//把比基准小的都放到基准前面
		}
	}
	swap(&S_data[high], &S_data[i]);//因为遇到比基准小的数i就会往前移，而遇到比基准大的数不会前移，所以循环停时i指向的数一定>=基准
	return i;
}
void swap(int* a, int* b)//交换函数
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Qsort(int* S_data, int low, int high)
{
	if (low < high)
	{
		int mid = QuickSort_Divide(S_data, low, high);
		Qsort(S_data, low, mid - 1);
		Qsort(S_data, mid +1,high);
	}
}

//快速排序
void QuickSort(int* S_data)
{
	//
	//

	int n = sizeof(S_data) / sizeof(S_data[0]);//获取数组长度

	//
	Qsort(S_data, 0, n - 1);
	//
	//
	printf("快速排序完成!" );
}

//计数排序
void CountSort(int* S_data)
{
	//
	//

	int n = sizeof(S_data) / sizeof(S_data[0]);//获取数组长度
	//
	int max = S_data[0];
	for (int i = 0; i < n; i++)
	{
		if (S_data[i] > max)
		{
			max = S_data[i];//找出最大的数
		}
	}
	int* tempC = (int*)malloc(sizeof(int) * (max + 1));
	memset(tempC, 0, sizeof(int) * (max + 1));//用memset函数将临时数组全部元素变为0

	for (int i = 0; i < n; i++)
	{
		tempC[S_data[i]]++;//用临时数组来记录每个数字出现的次数
	}
	for (int i = 1; i < max + 1; i++)
	{
		tempC[i] += tempC[i - 1];//这个数的位置要加上前一个数出现的次数才能确定
	}
	int* finalS = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		finalS[tempC[S_data[i]] - 1] = S_data[i];//排序
		tempC[S_data[i]]--;
	}

	for (int i = 0; i < n; i++)
	{
		S_data[i] = finalS[i];
	}
	//
	//
	printf("计数排序完成!" );
}
//基数计数排序
void RadixCountSort(int* S_data)
{
	////
	////

	//int n = sizeof(S_data) / sizeof(S_data[0]);//获取数组长度
	//int* RC_one = (int*)malloc(sizeof(int) * n);
	printf("暂未开发！\n");
}