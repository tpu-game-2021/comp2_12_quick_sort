#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void Swap(int x[], int i, int j)
{
	int temp;

	temp = x[i];
	x[i] = x[j];
	x[j] = temp;
}


// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください

	
	int* MiddleNumber;
	int *left, *right;

	left = begin->key;

	right = end->key;

	MiddleNumber = begin[(left + right) / 2].key;

	while (1)
	{
		while (begin[left].key < MiddleNumber)left++;

		while (MiddleNumber < begin[left].key)
			right--;
		if (left >= right)break;


		Swap(begin[left].key, left, right);
		left++;
		right--;


		
	}

	if (left < left - 1)
		quick_sort(left, left - 1);
	if (right + 1 < right)
		quick_sort(right + 1, right);

	return false;
}
