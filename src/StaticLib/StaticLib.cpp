#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end == NULL)return false;
	if (end < begin)return false;

	item* it = begin;
	item* it2 = begin;
	int center = (begin->key + end->key) / 2;
	
	for (it2; it2 != end; it2++);

	while (1)
	{
		while (it->key < center)it++;
		while (it2->key > center)it2--;

		if (it->key >= it2->key)break;

		item tmp = *it;
		*it = *it2;
		*it2 = tmp;

		it++;
		it2--;
	}

	if (it->key - begin->key >= 2)
		quick_sort(begin, it - 1);

	if (end->key - it2->key >= 2)
		quick_sort(it2 + 1, end);

	return true;
}
