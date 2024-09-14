#include <bits/stdc++.h>
using namespace std;

int N, ret;
int A[1000], len[1000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	fill(len, len + N, 1);
	
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && len[j] + 1 > len[i])
				len[i] = len[j] + 1;
		}
	}
	
	for (int i = 0; i < N; i++)
		ret = max(len[i], ret);
	
	cout << ret;
}