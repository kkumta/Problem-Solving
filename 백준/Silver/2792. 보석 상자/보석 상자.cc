#include <bits/stdc++.h>
using namespace std;

int N, M, l = 1, r = 1000000000, mid, ret = 1000000000;
int K[300000];

bool check(int a)
{
	int cnt = N;
	for (int i = 0; i < M; i++)
	{
		cnt -= (K[i] / a);
		if (K[i] % a != 0) cnt--;
		if (cnt < 0) return false;
	}
	
	return true;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> K[i];
	
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			ret = min(mid, ret);
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	
	cout << ret;
}