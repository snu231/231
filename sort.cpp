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
	int min;    /// 최소값 임시저장 변수
	int temp;   /// arr[index] 숫자 임시저장할 변수

	for ( index=0 ; index<num; index++)
	{
		min = arr[index];    /// arr[index] 변수를 min에 저장
		for (b = num-1; b>index; b--)
		{
			if (min > arr[b])
			{
				min = arr[b];    /// b번째 숫자와 기존의 min 중 작은 숫자를 min에 저장하는 식으로, arr[index]~arr[num-1] 중 최소값 구하기
			}
		}
		if (arr[index] > min)    /// index번째가 최소값이면 생략해도 되는 절차
		{
			temp = arr[index];   /// temp에 기존의 arr[index] 숫자 임시저장
			arr[index] = min;    ///  arr[index]에 최소값 할당
			for (b = num - 1; b > index; b--)    //// min이 원래 있던 자리에, 기존의 arr[index] 값이 저장된 temp를 할당
			{
				if (arr[b] == min)
				{
					arr[b] = temp;
					break;           ///// 최소값이 중복일 경우를 방지
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
		  if (arr[c-1] > arr[c])     /// 0번째부터 num-index번째까지 bubble sort
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
		for ( b= index; b>0; b--)     /// b번째 숫자와 b-1번째 숫자 비교부터 시작해서, 바로 왼쪽 숫자와 비교하는 식으로 sort
		{
			if (arr[b] < arr[b-1])
			{
				swap(&arr[b-1], &arr[b]);
			}
			else
			{
				break;      /// 오른쪽 숫자가 더 크면 루프 종료하고 index+1번째로 넘어감
			}
		}
	}
}


void mergeSort(int* arr, int left, int right, int num)    // left: 왼쪽 배열 원소 수, right: 오른쪽 배열 원소 개수, num: 총 원소 수
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

	if (left == 2)       ///   sub array의 원소가 2개면 swap으로 우선 정렬
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
	int* temp = new int[num]();         //// sub array 2개를 합쳐서 정렬한 배열을 임시로 담아둘 그릇

	while (a < left && b < right)   
	{		
		if (arr[a] > arr[left+b])    //// 아직 정렬되지 않은 항 중, left 첫 항이 right 첫 항보다 클 경우
		{
			temp[a + b] = arr[left+b];
			++b;
		}
		else   //// 아직 정렬되지 않은 항 중, left 첫 항보다 right 첫 항이 클 경우
		{
			temp[a + b] = arr[a];
			++a;
		}
	}
	if (a == left)   /// left array는 모두 정렬된 경우, 남아있는 right array 정렬
	{
		while (b < right)
		{
			temp[a + b] = arr[left+b];
			b++;
		}
	}

	else if (b == right)   /// right array는 모두 정렬된 경우, 남아있는 right array 정렬
	{
		while (a < left)
		{
			temp[a + b] = arr[a];
			a++;
		}
	}

	for (int k = 0; k < num; k++) //// arr에 temp 붙여넣기
	{
		arr[k] = temp[k];
	}

	delete[] temp;    /// temp 제거
}




