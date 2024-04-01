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
			printf("�ѷ������˵�\n");
			return;
		case'1'://��������
			InserSort(S_data);
			system("pause");
			system("cls");
			break;
		case'2'://�鲢���� 
			MergeSort(S_data);
			system("pause");
			system("cls");
			break;
		case'3'://��������
			QuickSort(S_data);
			system("pause");
			system("cls");
			break;
		case'4'://��������
			CountSort(S_data);
			system("pause");
			system("cls");
			break;
		case'5'://������������
			RadixCountSort(S_data);
			system("pause");
			system("cls");
			break;
		default:
			printf("������0-5������֣�\n");
			system("pause");//��ͣ
			system("cls");//���
			break;

		}
	}
}


//��������
void InserSort(int* S_data)
{
	//
	//

	int n = sizeof(S_data) / sizeof(S_data[0]);//��ȡ���鳤��

	//
	for (int i = 1; i < n; i++)
	{
		int temp = S_data[i];
		int j = i - 1;//����S_data[j]����S_data[i]��ǰһ��
		while (j >= 0 && S_data[j] >temp)//�Ƚϣ���ǰһ����ں�һ��
		{
			S_data[j + 1] = S_data[j];//��ǰһ���ֵ������һ�ԭ��һ���ֵǰ�������temp�У����±����ǣ�
			j--;
		}
		S_data[j + 1] = temp;//����temp��ԭ����һ���ֵ����ԭ����ǰһ���Ϊ����j--�ˣ�����Ҫ���j+1��
	}
	//
	//
	printf("�����������!" );
}
//�鲢����1
void msort(int* S_data,int tempA[],int left,int right )
{
	if (left < right)//����˵��������������
	{
		int mid = (left + right) / 2;//�����е�
		msort(S_data, tempA, left, mid);
		msort(S_data, tempA, mid+1,right);//�ݹ黮��
		merge(S_data, tempA, left, mid,right);
	}
	
}
//�鲢����2
void merge(int* S_data, int tempA[], int left, int mid, int right)
{
	int left_p = left;//��һ
	int right_p = mid+1;//��һ
	int tempA_p = left;//��ʱ�����±�
	//�ϲ�
	while (left_p<=mid&&right_p<=right)
	{
		if (S_data[left_p] < S_data[right_p])//��һ����һС
		{
			tempA[tempA_p++] = S_data[left_p++];//����һ������ʱ���飨����ʱ�����һ��λ�ÿ�ʼ�ӣ���Ϊleftһ��ʼ����0��
		}
		else
		{
			tempA[tempA_p++] = S_data[right_p++];//������һ������ʱ����
		}
	}
	while (left_p <= mid)//�ж�������Ƿ���ʣ��
	{
		tempA[tempA_p++] = S_data[left_p++];//�о�ֱ�ӽ�����ʱ����
	}
	while (right_p <= right)//�ж��Ұ����Ƿ���ʣ��
	{
		tempA[tempA_p++] = S_data[right_p++];
	}
	while (left < +right)
	{
		S_data = tempA[left];//���ź���������´���ԭ����������
		left++;
	}
}

//�鲢���� 
void MergeSort(int* S_data)
{
	//
	//

	int n = sizeof(S_data) / sizeof(S_data[0]);//��ȡ���鳤��
	int* tempA = (int*)malloc(n * sizeof(int));//������ʱ����
	if (tempA)//�ж��Ƿ񴴽��ɹ�
	{
		//
		msort(S_data, tempA, 0, n - 1);
		//
		//
		printf("�鲢�������!" );
		free(tempA);
	}
	else
	{
		printf("������ʱ����ʧ�ܣ������ԣ�\n");
	}

}
int QuickSort_Divide(int* S_data, int low, int high)//�����õ��Ļ���
{
	int std_mark = S_data[high];//����׼ѡΪ�������һ����
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (S_data[j] < std_mark)
		{
			swap(&S_data[j], &S_data[i++]);//�ѱȻ�׼С�Ķ��ŵ���׼ǰ��
		}
	}
	swap(&S_data[high], &S_data[i]);//��Ϊ�����Ȼ�׼С����i�ͻ���ǰ�ƣ��������Ȼ�׼���������ǰ�ƣ�����ѭ��ͣʱiָ�����һ��>=��׼
	return i;
}
void swap(int* a, int* b)//��������
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

//��������
void QuickSort(int* S_data)
{
	//
	//

	int n = sizeof(S_data) / sizeof(S_data[0]);//��ȡ���鳤��

	//
	Qsort(S_data, 0, n - 1);
	//
	//
	printf("�����������!" );
}

//��������
void CountSort(int* S_data)
{
	//
	//

	int n = sizeof(S_data) / sizeof(S_data[0]);//��ȡ���鳤��
	//
	int max = S_data[0];
	for (int i = 0; i < n; i++)
	{
		if (S_data[i] > max)
		{
			max = S_data[i];//�ҳ�������
		}
	}
	int* tempC = (int*)malloc(sizeof(int) * (max + 1));
	memset(tempC, 0, sizeof(int) * (max + 1));//��memset��������ʱ����ȫ��Ԫ�ر�Ϊ0

	for (int i = 0; i < n; i++)
	{
		tempC[S_data[i]]++;//����ʱ��������¼ÿ�����ֳ��ֵĴ���
	}
	for (int i = 1; i < max + 1; i++)
	{
		tempC[i] += tempC[i - 1];//�������λ��Ҫ����ǰһ�������ֵĴ�������ȷ��
	}
	int* finalS = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		finalS[tempC[S_data[i]] - 1] = S_data[i];//����
		tempC[S_data[i]]--;
	}

	for (int i = 0; i < n; i++)
	{
		S_data[i] = finalS[i];
	}
	//
	//
	printf("�����������!" );
}
//������������
void RadixCountSort(int* S_data)
{
	////
	////

	//int n = sizeof(S_data) / sizeof(S_data[0]);//��ȡ���鳤��
	//int* RC_one = (int*)malloc(sizeof(int) * n);
	printf("��δ������\n");
}