#include <bits/stdc++.h>
using namespace std;

int R, C, alpha, ret;
int maps[20][20];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(pair<int, int> here, int depth)
{
	ret = max(ret, depth);
	
	for (int i = 0; i < 4; i++)
	{
		auto there = make_pair(here.first + dy[i], here.second + dx[i]);
		if (there.first >= R || there.first < 0 || there.second >= C || there.second < 0)
			continue;
		if (alpha & (1 << maps[there.first][there.second]))
			continue;
		
		alpha |= (1 << maps[there.first][there.second]);
		dfs(there, depth + 1);
		alpha &= ~(1 << maps[there.first][there.second]);
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < C; j++)
			maps[i][j] = tmp[j] - 'A';
	}
	
	alpha |= (1 << maps[0][0]);
	dfs(make_pair(0, 0), 1);
	
	cout << ret;
}