#include <bits/stdc++.h>
using namespace std;

int n, m, dist[101][101];
const int INF = 987654321;

int main()
{
	fill(&dist[0][0], &dist[0][0] + 101 * 101, INF);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j || dist[i][j] == INF) cout << "0 ";
			else cout << dist[i][j] << ' ';
		}		
		cout << '\n';
	}
}