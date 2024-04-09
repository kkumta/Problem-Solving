#include <iostream>
using namespace std;

int n;
int t[1500001], p[1500001];
long long d[1500002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];

	for (int i = n; i >= 1; i--)
	{
		if (i + (t[i] - 1) > n)
			d[i] = d[i + 1];
		else
			d[i] = max(p[i] + d[i + t[i]], d[i + 1]);
	}

	cout << d[1];
}