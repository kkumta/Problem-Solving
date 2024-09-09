#include <bits/stdc++.h>
using namespace std;

long long X, Y, Z, n, l = 1, r = 1000000001, ret = 1000000001;

bool check(int mid)
{
	long long nextX = X + mid, nextY = Y + mid;
	long long nextZ = nextY * 100 / nextX;
	
	if (Z == nextZ) return false;
	return true;
}

int main()
{
	cin >> X >> Y;
	Z = Y * 100 / X;
	
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		if (check(mid))
		{
			ret = min(mid, ret);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	
	if (ret == 1000000001) cout << -1;
	else cout << ret;
}