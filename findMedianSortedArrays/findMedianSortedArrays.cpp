// findMedianSortedArrays.cpp : �������̨Ӧ�ó������ڵ㡣
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
 * ���������������һ�����������ĵ���ֵ��Ҫ����ʱ�临�Ӷ���O(m+n)
 *
 * @param A[] �Ѿ�����õ�����
 * @param m ����ĳ���
 * @param B[] �Ѿ�����õ�����
 * @param n ����ĳ���
 * 
 * @return �������������֮�����ֵ
 *
 */
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	vector<int> lst;
	//����A���±�
	auto i = 0;
	//����B���±�
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

