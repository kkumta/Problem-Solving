#include <bits/stdc++.h>
using namespace std;

int N, M, l, r, mid, ret = 1000000000;
int a[100000];

bool check(int k)
{
	int cnt = 0, curMoney = 0;
	for (int i = 0; i < N; i++)
	{
		if (curMoney < a[i])
		{
			cnt++;
			curMoney = k;
		}
		curMoney -= a[i];
		
		if (cnt > M) return false;
	}
	
	return true;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		l = max(a[i], l);
		r += a[i];
	}
	
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