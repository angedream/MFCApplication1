// Win32Project1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int sub(int a)
{
	a = 5;
	a = a - 1;
	return a;
}

int add(int a)
{
	a = 10;
	a++;
	return a;
}
int main()
{
	int a = 20;
	if (20 == a)
	{
		add(a);
	}
	else
		sub(a);
	getchar();
    return 0;
}

