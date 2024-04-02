#include <iostream>
using namespace std;

int n, ans;
int triangle[500][500], d[500][500];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> triangle[i][j];

	d[0][0] = triangle[0][0];
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			int max = 0;
			if (j > 0) max = d[i - 1][j - 1];
			if (j < i && max < d[i - 1][j]) max = d[i - 1][j];
			d[i][j] = max + triangle[i][j];
		}

	for (int i = 0; i < n; i++)
		if (d[n - 1][i] > ans)
			ans = d[n - 1][i];

	cout << ans;
}