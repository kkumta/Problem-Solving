#include <bits/stdc++.h>
using namespace std;

int N, M, i, j;
int a[101];

int main()
{
	cin >> N >> M;
	for (int k = 1; k <= N; k++)
		a[k] = k;
	
	for (int k = 0; k < M; k++)
	{
		cin >> i >> j;
		int halfSize = (j - i + 1) / 2;
		for (int l = 0; l < halfSize; l++)
		{
			int tmp = a[i + l];
			a[i + l] = a[j - l];
			a[j - l] = tmp;
		}
	}
	
	for (int k = 1; k <= N; k++)
		cout << a[k] << ' ';	
}