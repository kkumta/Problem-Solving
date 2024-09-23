#include <bits/stdc++.h>
using namespace std;

int n, k;
const int inf = 100000;
set<int> s;
int d[100001];

int main()
{
	cin >> n >> k;
	fill(d, d + k + 1, inf);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		s.insert(tmp);
		d[tmp] = 1;
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j : s)
		{
			if (i - j >= 0) d[i] = min(d[i], d[i - j] + 1);
			else break;
		}
	}
	
	if (d[k] == inf) cout << -1;
	else cout << d[k];
}