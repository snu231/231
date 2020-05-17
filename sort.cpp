#include "sort.h"

void swap(int *a, int *b)
{
  int temp = (*a);
  (*a) = (*b);
  (*b) = temp;
}

void selectionSort(int *arr, int num)
{
	int index;
	int b;
	int min;    /// �ּҰ� �ӽ����� ����
	int temp;   /// arr[index] ���� �ӽ������� ����

	for ( index=0 ; index<num; index++)
	{
		min = arr[index];    /// arr[index] ������ min�� ����
		for (b = num-1; b>index; b--)
		{
			if (min > arr[b])
			{
				min = arr[b];    /// b��° ���ڿ� ������ min �� ���� ���ڸ� min�� �����ϴ� ������, arr[index]~arr[num-1] �� �ּҰ� ���ϱ�
			}
		}
		if (arr[index] > min)    /// index��°�� �ּҰ��̸� �����ص� �Ǵ� ����
		{
			temp = arr[index];   /// temp�� ������ arr[index] ���� �ӽ�����
			arr[index] = min;    ///  arr[index]�� �ּҰ� �Ҵ�
			for (b = num - 1; b > index; b--)    //// min�� ���� �ִ� �ڸ���, ������ arr[index] ���� ����� temp�� �Ҵ�
			{
				if (arr[b] == min)
				{
					arr[b] = temp;
					break;           ///// �ּҰ��� �ߺ��� ��츦 ����
				}
			}
		}
	}
}


void bubbleSort(int *arr, int num)
{
  int index, c;
  for(index=num; index>0; index--)
  {
	  for (c = 1; c < index; c++)  
	  {
		  if (arr[c-1] > arr[c])     /// 0��°���� num-index��°���� bubble sort
		  {
			  swap(&arr[c-1], &arr[c]);
		  }
	  }
  }

}


void insertionSort(int *arr, int num)
{
	int index;
	int b;
	for (index = 0; index < num; index++)
	{
		for ( b= index; b>0; b--)     /// b��° ���ڿ� b-1��° ���� �񱳺��� �����ؼ�, �ٷ� ���� ���ڿ� ���ϴ� ������ sort
		{
			if (arr[b] < arr[b-1])
			{
				swap(&arr[b-1], &arr[b]);
			}
			else
			{
				break;      /// ������ ���ڰ� �� ũ�� ���� �����ϰ� index+1��°�� �Ѿ
			}
		}
	}
}


void mergeSort(int* arr, int left, int right, int num)    // left: ���� �迭 ���� ��, right: ������ �迭 ���� ����, num: �� ���� ��
{
	if (left > 2)
	{
		mergeSort(arr, left / 2, left - left / 2, left);
	}
	if (right > 2)
	{
		mergeSort(arr + left, right / 2, right - right / 2, right);
	}

	if (left == 0 || right==0)
	{
		return;
	}

	if (left == 2)       ///   sub array�� ���Ұ� 2���� swap���� �켱 ����
	{
		if (arr[0] > arr[1])    
		{
			swap(&arr[0], &arr[1] );
		}
	}
	if (right == 2)
	{
		if (arr[left] > arr[left + 1])
		{
			swap(&arr[left], &arr[left + 1]);
		}
	}
	int a = 0;
	int b = 0;
	int* temp = new int[num]();         //// sub array 2���� ���ļ� ������ �迭�� �ӽ÷� ��Ƶ� �׸�

	while (a < left && b < right)   
	{		
		if (arr[a] > arr[left+b])    //// ���� ���ĵ��� ���� �� ��, left ù ���� right ù �׺��� Ŭ ���
		{
			temp[a + b] = arr[left+b];
			++b;
		}
		else   //// ���� ���ĵ��� ���� �� ��, left ù �׺��� right ù ���� Ŭ ���
		{
			temp[a + b] = arr[a];
			++a;
		}
	}
	if (a == left)   /// left array�� ��� ���ĵ� ���, �����ִ� right array ����
	{
		while (b < right)
		{
			temp[a + b] = arr[left+b];
			b++;
		}
	}

	else if (b == right)   /// right array�� ��� ���ĵ� ���, �����ִ� right array ����
	{
		while (a < left)
		{
			temp[a + b] = arr[a];
			a++;
		}
	}

	for (int k = 0; k < num; k++) //// arr�� temp �ٿ��ֱ�
	{
		arr[k] = temp[k];
	}

	delete[] temp;    /// temp ����
}




