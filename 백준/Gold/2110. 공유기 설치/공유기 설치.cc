#include <bits/stdc++.h>
using namespace std;

int N, C;
long long a[200000], l = 1, r = 1000000000, mid, ret = 1;

bool check(long long target)
{
	int lastIdx = 0, cnt = C - 1;
	for (int i = 1; i < N; i++)
	{
		if (a[i] >= a[lastIdx] + target)
		{
			lastIdx = i;
			cnt--;
		}
	}
	
	if (cnt <= 0) return true;
	else return false;
}

int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> a[i];
		
	sort(a, a + N);
	
	while (l <= r)
	{
		mid = (l + r) / 2;
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