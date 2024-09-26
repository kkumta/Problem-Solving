#include <bits/stdc++.h>
using namespace std;

int N, K, W, V;
int d[100001];

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> W >> V;
		for (int j = K; j >= W; j--)
			d[j] = max(d[j], d[j - W] + V);
	}
	
	cout << d[K];
}