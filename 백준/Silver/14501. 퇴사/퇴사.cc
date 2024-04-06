#include <iostream>
using namespace std;

int n, ans;
int d[16];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;
		if (i + t - 1 > n)
			continue;

		int maxP = 0;
		for (int j = 1; j < i; j++)
			if (d[j] > maxP)
				maxP = d[j];
		d[i + t - 1] = max(d[i + t - 1], p + maxP);
	}

	for (int i = 1; i <= n; i++)
		if (d[i] > ans)
			ans = d[i];

	cout << ans;
}