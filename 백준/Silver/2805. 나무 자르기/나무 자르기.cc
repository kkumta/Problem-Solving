#include <bits/stdc++.h>
using namespace std;

int N;
long long M, a[1000000], l = 1, mid, r = 2000000000, ret;

bool check(long long target)
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
		sum += max(a[i] - target, 0LL);
	
	if (sum >= M) return true;
	else return false;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> a[i];
		
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		if (check(mid))
		{
			ret = max(mid, ret);
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	
	cout << ret;
}