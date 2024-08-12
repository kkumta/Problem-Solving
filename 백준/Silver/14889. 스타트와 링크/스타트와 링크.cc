#include <bits/stdc++.h>
using namespace std;

int N, ret = 1000000000;
int s[20][20];
bool a[20];

void calc()
{
	int asum = 0, bsum = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i])
		{
			for (int j = 0; j < N; j++)
				if (a[j]) asum += s[i][j];
		}
		else
		{
			for (int j = 0; j < N; j++)
				if (!a[j]) bsum += s[i][j];			
		}
	}
	
	ret = min(abs(asum - bsum), ret);
}

void func(int k, int n, int lastIdx)
{
	if (k == n) calc();
	
	for (int i = lastIdx + 1; i < N; i++)
	{
		a[i] = true;
		func(k + 1, n, i);
		a[i] = false;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> s[i][j];
	
	func(0, N / 2, -1);
	
	cout << ret;
}