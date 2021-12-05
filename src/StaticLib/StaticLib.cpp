#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
void Swap(item x[], int i, int j) {
	item tempo;

	tempo = x[i];
	x[i] = x[j];
	x[j] = tempo;
}

bool quick_sort(item* begin, const item* end)
{
	int left = 0;
	int right = (end - begin) - 1;

	int i = left;
	int j = right;


	if (end < begin)
		return false;

	if (end == NULL || begin == NULL)
		return false;


		while (1) {

			int pivot = begin[(i + j) / 2].key;

			while (begin[i].key < pivot)
				i++;
			while (pivot < begin[j].key)
				j--;

			if (i >= j)
				break;

			Swap(begin, i, j);
			i++;
			j--;
		}
	return true;
}
