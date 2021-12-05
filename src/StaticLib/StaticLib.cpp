#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	if (begin == NULL || end == NULL) 
	{
		return false;
	}
	if (begin > end) 
	{
		return false;
	}
	item* Box;
	item* i;
	item* j;

	int i_flag = 0;
	int j_flag = 0;
	// ToDo: クイックソートで並び替えてください

	return false;
}
