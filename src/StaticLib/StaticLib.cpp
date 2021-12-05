#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください	
	if (begin == NULL || end == NULL) return false;
	if (end < begin)  return false;

	int left = 0;
	int right = (end - begin)-1;

	while (1)
	{
		int a = left;
		int z = right;
	    int pivot = begin[(a + z) / 2].key; //基準の値を設定する。

		while (begin[a].key < pivot) a++; 
		while (pivot < begin[z].key) z--; 
		if (a >= z) break; 

		item  tmp = begin[a];
		begin[a] = begin[z];
		begin[z] = tmp;
		a++; z--;
	}
	return true;
}
