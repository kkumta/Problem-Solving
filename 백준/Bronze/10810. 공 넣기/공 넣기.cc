#include <bits/stdc++.h>
using namespace std;

int N, M, i, j, k;
int a[101];

int main()
{
	cin >> N >> M;
	for (int l = 0; l < M; l++)
	{
		cin >> i >> j >> k;
		for (int m = i; m <= j; m++)
			a[m] = k;
	}
	
	for (int l = 1; l <= N; l++)
		cout << a[l] << " ";
}