#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	if (begin == NULL || end == NULL) //NULLチェック
	{
		return false;
	}
	if (begin > end) //endのアドレスが小さいのはダメ
	{
		return false;
	}

	item* pivot;
	item* i;
	item* j; //iは左から、jは右から走査

	int i_flag = 0;
	int j_flag = 0; //入れ替え対象を見つけたら1になる

	item tmp; //入れ替え用
	item* temp2;

	pivot = begin;
	i = begin + sizeof(item);
	j = (item*)end;


	while (1)
	{
		while (1)
		{
			if (pivot->key < i->key) //pivotより大きいkeyを見つけたら
			{
				i_flag = 1;
			}

			if (pivot->key > j->key) //pivotより小さいkeyを見つけたら
			{
				j_flag = 1;
			}
			
			if (i_flag == 1 && j_flag == 1) //入れ替え対象が見つかったらbreak
			{
				break;
			}

			if (i_flag == 0)
			{
				i++;
			}
			if (j_flag == 0)
			{
				j--;
			}

			if (i - sizeof(item) == j + sizeof(item)) //iとjが交差していて、入れ替え対象がなかったら終わり
			{
				return true;
			}
		}

		if (i - sizeof(item) == j + sizeof(item)) //iとjが交差していたら
		{
			//pivotの入れ替え
			tmp = *pivot;
			*pivot = *j;
			*j = tmp;
		}
		else if (i_flag == 1 && j_flag == 1) //入れ替え対象が決まったら
		{
			tmp = *i; //入れ替え
			*i = *j;
			*j = tmp;

			i_flag = 0;
			j_flag = 0;

			temp2 = i; //iとjの位置が逆になってしまっているので戻す
			i = j;
			j = temp2;
		}
	}

	return false;
}