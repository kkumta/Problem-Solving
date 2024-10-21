#include <bits/stdc++.h>
using namespace std;

const int maxCost = 10001;
int N, M, mem[100], cost[100], d[maxCost], ret = maxCost;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> mem[i];
		
	for (int i = 0; i < N; i++)
		cin >> cost[i];
		
	for (int i = 0; i < N; i++)
	{
		for (int j = maxCost - 1; j >= cost[i]; j--)
			d[j] = max(d[j], d[j - cost[i]] + mem[i]);
	}
	
	for (int i = 0; i < maxCost; i++)
	{
		if (d[i] >= M)
			ret = min(ret, i);
	}
	
	cout << ret;
}