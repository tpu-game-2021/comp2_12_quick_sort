#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void swap(item box[], int i, int j)
{
    item tmp;
    tmp = box[i];
    box[i] = box[j];
    box[j] = tmp;
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end == NULL)
	{
		return false;
	}
	if (end < begin)
	{
		return false;
	}

	item* it = begin;
	item* it2 = it + 1;
    int left = 0;
    int right = (end - begin) - 1;

    while (1) 
    {
        int p = begin[(left + right) / 2].key;
        int i = left;
        int j = right;

        while (begin[i].key < p)
        {
            i++;
        }
        while (p < begin[j].key)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        swap(begin, i, j);
        {
            i++;
            j--;
        }
    }
	return true;
}
