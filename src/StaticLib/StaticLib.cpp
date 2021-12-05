#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end == NULL)return false;
	if (begin > end) return false;


    int a = end - begin;
    item* pivot = begin;
    item* i = begin + 1;
    item* j = (begin + a) - 1;
    while (1)
    {
        while (i <= end)
        {
            if (i->key >= pivot->key)
                break;
            else 
                i++;
        }
        while (j >= begin)
        {
            if (j->key <= pivot->key)
                break;
            else j
                --;
        }
        if (i >= j)break;
    }
	return true;
}