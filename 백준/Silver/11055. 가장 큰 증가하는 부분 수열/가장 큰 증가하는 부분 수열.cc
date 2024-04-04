#include <iostream>
using namespace std;

int n, ans;
int a[1000], d[1000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	d[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
			if (a[i] > a[j] && d[j] > max)
				max = d[j];
		d[i] = max + a[i];
	}

	for (int i = 0; i < n; i++)
		if (d[i] > ans) ans = d[i];

	cout << ans;
}