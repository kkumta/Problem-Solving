#include <bits/stdc++.h>
using namespace std;

long long S, C, sum, l = 1, mid, r, ret;
long long a[1000000];

bool check(int target)
{
	int cnt = 0;
	
	for (int i = 0; i < S; i++)
	{
		long long tmp = a[i];
		cnt += tmp / target;
	}
	
	if (cnt >= C) return true;
	return false;
}

int main()
{
	cin >> S >> C;
	for (int l = 0; l < S; l++)
	{
		cin >> a[l];
		r = max(a[l], r);
		sum += a[l];
	}
	
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			l = mid + 1;
			ret = max(mid, ret);
		}
		else
			r = mid - 1;
	}
	
	cout << sum - C * ret;
}