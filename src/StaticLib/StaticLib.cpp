#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	item;
	// ToDo: クイックソートで並び替えてください

	
		
		if (begin->key > end->key)
		{
			return 1;
		}
		else if (begin->key < end->key)
		{
			return -1; 
		}
		if (begin->key == NULL && end->key == NULL)
		{
			return false;
		}
		else
		{
			return false;
		}
	
}
