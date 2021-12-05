#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end == NULL)  return false;
	
	if (end < begin)  return false;

	int left = 0;
	int right = (end - begin) - 1;

	if (left == right)  return true;

	while (1)
	{
		int pivot = begin[(left + right) / 2].key;
		int i = left;
		int j = right;

		while (1)
		{
			while (begin[i].key < pivot)  i++;
			while (pivot < begin[j].key)  j--;

			if (i >= j)  break;

			item tmp = begin[i];
			begin[i] = begin[j];
			begin[j] = tmp;
			i++;
			j--;
		}

		if (left < i - 1)  right = i - 1;

		else if (j + 1 < right)  left = j + 1;

		else  break;
	}

	return true;
}
