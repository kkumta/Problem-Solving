#include <bits/stdc++.h>
using namespace std;

const int N = 17;
int n;
int a[N][N], d[3][N][N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	
	d[0][1][2] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 3; j <= n; j++)
		{
			if (a[i][j] == 0)
			{
				d[0][i][j] = d[0][i][j - 1] + d[1][i][j - 1];
				d[2][i][j] = d[1][i - 1][j] + d[2][i - 1][j];
				if (a[i - 1][j] == 0 && a[i][j - 1] == 0)
					d[1][i][j] = d[0][i - 1][j - 1] + d[1][i - 1][j - 1] + d[2][i - 1][j - 1];
			}
		}
	}
	
	cout << d[0][n][n] + d[1][n][n] + d[2][n][n];
} 