#include <bits/stdc++.h>
using namespace std;

int N, M, H, ret = 4;
vector<pair<int, int>> v;
bool visited[11][31];

bool check()
{
	for (int i = 1; i <= N; i++)
	{
		int pos = i;
		for (int j = 1; j <= H; j++)
		{
			if (pos < N && visited[pos][j])
				pos++;
			else if (pos > 1 && visited[pos - 1][j])
				pos--;
		}
		
		if (i != pos)
			return false;
	}
	
	return true;
}

void go(int start, int depth)
{	
	if (depth >= ret)
		return;
		
	if (check())
	{
		ret = depth;
		return;
	}
	
	for (int i = start; i < v.size(); i++)
	{
		if (!visited[v[i].first][v[i].second])
		{
			visited[v[i].first][v[i].second] = true;
			go(i + 1, depth + 1);
			visited[v[i].first][v[i].second] = false;
		}		
	}
}

int main()
{
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		visited[b][a] = true;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= H; j++)
			if (!visited[i][j])
				v.push_back(make_pair(i, j));
	}
	
	go(0, 0);
	
	if (ret == 4)
		cout << -1;
	else
		cout << ret;
}