#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (end - begin < 0)return false;
	if (end == NULL || begin == NULL)return false;
	int pivot;
	item tmp;
	int i, j;
	j =  (end - begin)-1;
	i = 1;
	tmp = begin[0];
	begin[0] = begin[(end-begin)/2];
	begin[(end - begin) / 2] = tmp;
	pivot = begin[0].key;
	if (end - begin <= 1)
		return true;
	while (1)
	{
		while (begin[j].key > pivot)
			j--;
		while (begin[i].key < pivot)
		{
			i++;
		}
		if (j <= i)
			break;
		tmp = begin[i];
		begin[i] = begin[j];
		begin[j] = tmp;
		j--;
		i++;
	}
	tmp = begin[j];
	begin[j] = begin[0];
	begin[0] = tmp;
	quick_sort(begin, begin+j);
	quick_sort(begin+j+1, end);
	return true;
}
