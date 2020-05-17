#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#include "sort.h"

using namespace std;

void generate_rnd_data(int* arr, int num);
void check_result(int* arr, int* ansArr, int num);


int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		cout << " 사용법 : " << argv[0] << " <array 크기>" << endl;
		return 1;
	}

	int numData = stoi(argv[1]);

	int* inArr = new int[numData];
	int* ansArr = new int[numData];

	int* bubbleArr = new int[numData];
	int* selectArr = new int[numData];
	int* insertArr = new int[numData];
	int* mergeArr = new int[numData];


	clock_t bubbleTime;
	clock_t selectTime;
	clock_t insertTime;
	clock_t mergeTime;


	generate_rnd_data(inArr, numData);


	for (int i = 0; i < numData; i++)
	{
		ansArr[i] = inArr[i];
		bubbleArr[i] = inArr[i];
		selectArr[i] = inArr[i];
		insertArr[i] = inArr[i];
		mergeArr[i] = inArr[i];
	}

	// STL Sort (Answer)
	std::sort(ansArr, ansArr + numData);



	// Merge Sort
	cout << "Merge Sort" << endl;
	mergeTime = clock();
	mergeSort(mergeArr, 0, numData, numData);    // 
	mergeTime = clock() - mergeTime;
	check_result(mergeArr, ansArr, numData);
	cout << "  Execution time : " << fixed << setprecision(5) << (float)mergeTime / CLOCKS_PER_SEC << " seconds" << endl << endl;


	delete[] inArr;
	delete[] ansArr;
	delete[] bubbleArr;
	delete[] selectArr;
	delete[] insertArr;
	delete[] mergeArr;

	return 0;
}


void generate_rnd_data(int* arr, int num)
{
	srand(time(NULL));

	for (int i = 0; i < num; i++)
	{
		arr[i] = rand();
	}

}

void check_result(int* arr, int* ansArr, int num)
{
	bool correct = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] != ansArr[i])
		{
			cout << "  Fail at " << i << "th!!" << endl;     //// 실패 시점을 나타냄
			cout << "arr[" << i << "] = " << arr[i] << ", ansArr[" << i << "] = " << ansArr[i] << endl;

			return;
		}
	}
	cout << "  Success !!" << endl;
}

