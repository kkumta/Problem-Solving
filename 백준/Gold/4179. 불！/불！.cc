#include <bits/stdc++.h>
using namespace std;

int R, C, ret = 1000000;
char maps[1000][1000];
int f[1000][1000], jh[1000][1000];
pair<int, int> jStart;
vector<pair<int, int>> fList;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void bfsFire()
{
	queue<pair<int, int>> q;
	for (pair<int, int> fire : fList)
		q.push(fire);
	
	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			
			if (nextY >= R || nextY < 0 || nextX >= C || nextX < 0) continue;
			if (maps[nextY][nextX] == '#') continue;
			if (f[nextY][nextX] != 0 && f[nextY][nextX] <= f[curY][curX] + 1) continue;
			f[nextY][nextX] = f[curY][curX] + 1;
			q.push(make_pair(nextY, nextX));
		}
	}
}

void bfsJihoon()
{
	queue<pair<int, int>> q;
	q.push(jStart);
	
	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			
			if (nextY >= R || nextY < 0 || nextX >= C || nextX < 0) continue;
			if (maps[nextY][nextX] == '#') continue;
			if (jh[nextY][nextX] != 0) continue;
			if (f[nextY][nextX] != 0 && f[nextY][nextX] <= jh[curY][curX] + 1) continue;
			jh[nextY][nextX] = jh[curY][curX] + 1;
			q.push(make_pair(nextY, nextX));
		}
	}
	
	for (int i = 0; i < R; i++)
	{
		if (jh[i][0] != 0 && jh[i][0] < ret)
			ret = jh[i][0];
		if (jh[i][C - 1] != 0 && jh[i][C - 1] < ret)
			ret = jh[i][C - 1];		
	}
	for (int i = 1; i < C - 1; i++)
	{
		if (jh[0][i] != 0 && jh[0][i] < ret)
			ret = jh[0][i];
		if (jh[R - 1][i] != 0 && jh[R - 1][i] < ret)
			ret = jh[R - 1][i];		
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
		{
			if (tmp[j] == 'F')
			{
				fList.push_back(make_pair(i, j));
				f[i][j] = 1;
			}
			else if (tmp[j] == 'J')
			{
				jStart = make_pair(i, j);
				jh[i][j] = 1;
			}
			maps[i][j] = tmp[j];
		}
	}
	
	bfsFire();
	bfsJihoon();
	
	if (ret == 1000000) cout << "IMPOSSIBLE";
	else cout << ret;
}