#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void swap(item a[], int i, int j)
{
	item box;
	box = a[i];
	a[i] = a[j];
	a[j] = box;
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end == NULL) return false;
	if (end < begin) return false;
	
	unsigned int Lbox = 0;
	unsigned int Rbox = (end - begin) - 1;
	int average = begin[(Lbox + Rbox) / 2].key;

	while (1)
	{
		while (begin[Lbox].key < average) Lbox++;
		while (begin[Rbox].key > average) Rbox--;
		if (Lbox >= Rbox) break;
		swap(begin, Lbox, Rbox);
		Lbox++;
		Rbox--;
	}
	return true;
}
