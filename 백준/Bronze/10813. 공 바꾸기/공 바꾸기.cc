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
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	for (int k = 1; k <= N; k++)
		cout << a[k] << ' ';
}