#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
// 引数チェック
	if (!begin || !end || begin >= end) 
	{
		return false;
	}

	// 要素の範囲を計算
	int n = (int)(end - begin);
	if (n <= 1) return true;

	// ピボット（適当に真ん中付近を選択）
	int pivot = begin[n / 2].key;

	// パーティション分割
	item* i = begin;
	item* j = (item*)end - 1;

	while (i <= j)
	{
		while (i->key < pivot) i++;
		while (j->key > pivot) j--;

		if (i <= j)
		{
			// 値の入れ替え
			item temp = *i;
			*i = *j;
			*j = temp;
			i++;
			j--;
		}
	}

	if (begin < j)
	{
		quick_sort(begin, j + 1);
	}
	if (i < end)
	{
		quick_sort(i, end);
	}

	return true;
}
