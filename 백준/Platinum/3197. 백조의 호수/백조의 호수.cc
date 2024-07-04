#include <bits/stdc++.h>
using namespace std;

int R, C, ret;
char maps[1500][1500];
bool swanVisited[1500][1500], waterVisited[1500][1500];
queue<pair<int, int>> swanQueue, swanTmpQueue, waterQueue, waterTmpQueue;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool swanBfs()
{
	while (!swanQueue.empty())
	{
		int y = swanQueue.front().first;
		int x = swanQueue.front().second; swanQueue.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (swanVisited[ny][nx]) continue;
			if (maps[ny][nx] == 'L')
				return true;
			else if (maps[ny][nx] == '.')
			{
				swanVisited[ny][nx] = true;
				swanQueue.push(make_pair(ny, nx));
			}
			else if (maps[ny][nx] == 'X')
			{
				swanVisited[ny][nx] = true;
				swanTmpQueue.push(make_pair(ny, nx));
			}			
		}
	}
	
	return false;
}

void waterBfs()
{
	while (!waterQueue.empty())
	{
		int y = waterQueue.front().first;
		int x = waterQueue.front().second; waterQueue.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (waterVisited[ny][nx]) continue;
			if (maps[ny][nx] == '.')
			{
				waterVisited[ny][nx] = true;
				waterQueue.push(make_pair(ny, nx));
			}
			else if (maps[ny][nx] == 'X')
			{
				maps[ny][nx] = '.';
				waterVisited[ny][nx] = true;
				waterTmpQueue.push(make_pair(ny, nx));
			}			
		}
	}	
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string tmp; cin >> tmp;
		for (int j = 0; j < C; j++)
		{
			maps[i][j] = tmp[j];
			// 백조가 있는 위치일 때 
			if (maps[i][j] == 'L' && swanQueue.empty())
			{
				swanVisited[i][j] = true;
				swanQueue.push(make_pair(i, j));
			}
			// 물 혹은 백조가 있는 위치일 때 
			if (maps[i][j] == '.' || maps[i][j] == 'L')
			{
				waterVisited[i][j] = true;
				waterQueue.push(make_pair(i, j));
			}
		}
	}
	
	while (!swanBfs())
	{
		ret++;
		
		waterBfs();
		while (!swanTmpQueue.empty())
		{
			swanQueue.push(swanTmpQueue.front());
			swanTmpQueue.pop();	
		}	
		while (!waterTmpQueue.empty())
		{
			waterQueue.push(waterTmpQueue.front());
			waterTmpQueue.pop();	
		}	
	}
	
	cout << ret;
}