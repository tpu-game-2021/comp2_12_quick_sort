#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

static void swap(item* r,item* l)
{
    item* temp = l;
    l = r;
    r = temp;
}
// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
    if (begin == NULL || end == NULL) return false;
    if (end < begin) return false;

    int num = end - begin;
    item* pivot = begin;
    item* l = begin + 1;
    item* r = (begin + num) - 1;
    int count = 0;
    while (count!=0)
    {
        count = 0;
        while (1) {
            while (l < end) {
                if (l->key >= pivot->key)break;
                else l++;
            }
            while (r >= begin) {
                if (r->key <= pivot->key)break;
                else r--;
            }
            if (l >= r)break;
            swap(l, r);
            count++;
            l++;
            r--;
        }
        if (count == 0)break;
        swap(pivot, r);
    }

    return true;
}

