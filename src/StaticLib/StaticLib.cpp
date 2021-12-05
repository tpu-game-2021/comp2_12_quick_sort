#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

/* 配列の要素を交換する */
void Swap(int x[], int i, int j)
{
    int temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください

    /*出来なかった
    int i, j, x;
    int k = 0;
    int array_1[NUMBER_1];
    int array_2[NUMBER_2];

    for (i = 0; i < NUMBER_2; i++)
    {

        for (j = 0; j < NUMBER_2; j++)
        {
            array_2[i][j] = array_1[k];
            k++;
        }
    }*/

    int i, j, left, right;

    int pivot;

    i = left;                      /* ソートする配列の一番小さい要素の添字 */
    j = right;                     /* ソートする配列の一番大きい要素の添字 */
    
    pivot = begin[(left + right) / 2].key; /* 基準値を配列の中央付近にとる */

    while (1) {                    /* 無限ループ */

        while (begin->key < pivot)       /* pivot より大きい値が */
            i++;                   /* 出るまで i を増加させる */

        while (pivot < begin->key)       /* pivot より小さい値が */
            j--;                   /*  出るまで j を減少させる */
        if (i >= j)                /* i >= j なら */
            break;                 /* 無限ループから抜ける */

        Swap(x, i, j);             /* x[i] と x[j]を交換 */
        i++;                       /* 次のデータ */
        j--;
    }

	return false;
}
