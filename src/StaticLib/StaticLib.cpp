#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
void swap(item* a, item* b)
{
	item tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (end - begin < 0)return false;
	if (end==NULL||begin==NULL)return false;
	int pivot;
	item tmp;
	int i, j;
	j =  (end - begin)-1;
	i = 1;
	swap(begin, begin+(end - begin) / 2);
	pivot = begin[0].key;
	if (end - begin <= 1)
		return true;
	while (1)
	{
		while (begin[j].key > pivot )
			j--;
		while (begin[i].key < pivot )
			i++;
		if (j <= i)
			break;
		swap(begin + i, begin + j);
		j--;
		i++;
	}
	swap(begin, begin+j);
	quick_sort(begin, begin+j);
	quick_sort(begin+j+1, end);
	return true;
}