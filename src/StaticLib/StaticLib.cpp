#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
    // ToDo: クイックソートで並び替えてください
    if (end == NULL || begin == NULL)return false;
    if (end < begin)return false;

    int num = end - begin;
    if (num == 1)return true;
    
    item* pivot = begin;
    item* i = begin + 1;
    item* j = begin + num - 1;
    while (1) {
        //pivot以上の数字を左側から探索
        while (i < end) {
            if (i->key >= pivot->key)break;
            else i++;
        }
        //pivot以下の数字を右側から探索
        while (j >= begin) {
            if (j->key <= pivot->key)break;
            else j--;
        }
        
        if (i >= j)break;
        
        //入れ替え
        item temp = *i;
        *i = *j;
        *j = temp;

        //交換後の数字の次から探索させる
        i++;
        j--;
    }
    item temp = *pivot;
    *pivot = *j;
    *j = temp;

    if (pivot - begin > 1)
        quick_sort(begin, pivot);
    if (end - pivot + 1 > 1)
        quick_sort(pivot + 1, end);

    return true;
}
