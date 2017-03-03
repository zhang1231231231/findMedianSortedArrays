// findMedianSortedArrays.cpp : 定义控制台应用程序的入口点。
//

/******************************************************************************************************
 *
 *  There are two sorted arrays A and B of size m and n respectively.
 *  Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
******************************************************************************************************/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/*
 *
 * 找两个排序好生成一个有序的数组的的中值，要求是时间复杂度是O(m+n)
 *
 * @param A[] 已经排序好的数组
 * @param m 数组的长度
 * @param B[] 已经排序好的数组
 * @param n 数组的长度
 * 
 * @return 两个数组排序好之后的中值
 *
 */
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	vector<int> lst;
	//数组A的下标
	auto i = 0;
	//数组B的下标
	auto j = 0;
	while (i < m&&j < n)
	{
		if (A[i] < B[j])
		{
			lst.push_back(A[i]);
			++i;
		}
		else
		{
			lst.push_back(B[j]);
			++j;
		}
	}

	if (i < m)
	{
		while (i < m)
		{
			lst.push_back(A[i]);
			++i;
		}
	}
	if (j < n)
	{
		while (j < n)
		{
			lst.push_back(B[j]);
			++j;
		}
	}
	auto mid = 0;
	if (lst.size() % 2 == 1)
	{
		mid = (lst.size() - 1) / 2;
		return double(lst[mid]);
	}
	else
	{
		mid = lst.size() / 2;
		return double(lst[mid - 1] + lst[mid]) / 2.0;
	}
}

int main()
{
	int a[4] = { 1,5,9,30 };
	int b[5] = { 2,30,40,55,89 };
	auto result = findMedianSortedArrays(a, 4, b, 5);
	std::cout << result << endl;
	system("PAUSE");
	return 0;
}

