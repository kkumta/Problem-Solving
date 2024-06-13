#include <bits/stdc++.h>
using namespace std;

int N, M, ret;
int originMap[8][8];
int newMap[8][8];
vector<pair<int, int>> zeroPoss;
vector<pair<int, int>> walls;
vector<pair<int, int>> virus;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void makeWall(int lastIdx, int depth, int maxSize);
void startVirus();
int findSafeArea();

void makeWall(int lastIdx, int depth, int maxSize)
{
	if (depth == maxSize)
	{
		// 2. 바이러스 퍼뜨리기
		copy(&originMap[0][0], &originMap[0][0] + 8 * 8, &newMap[0][0]);
		startVirus();
		
		// 3. 안전 영역 크기 구하기
		ret = max(findSafeArea(), ret); 
		return;
	}
	
	for (int i = lastIdx + 1; i < zeroPoss.size(); i++)
	{
		originMap[zeroPoss[i].first][zeroPoss[i].second] = 1;
		//walls.push_back(make_pair(i, j));
		makeWall(i, depth + 1, maxSize);
		originMap[zeroPoss[i].first][zeroPoss[i].second] = 0;
		//walls.pop_front();
	}
}

void startVirus()
{
	queue<pair<int, int>> q;
	for (pair<int, int> pos : virus)
		q.push(pos);
	
	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			
			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
			if (newMap[nextY][nextX] == 0)
			{
				newMap[nextY][nextX] = 2;
				q.push(make_pair(nextY, nextX));
			}
		}
	}
}

int findSafeArea()
{
	int cnt = 0;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (newMap[i][j] == 0)
				cnt++;
		}
	}
	
	return cnt;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> originMap[i][j];
			if (originMap[i][j] == 0)
				zeroPoss.push_back(make_pair(i, j));
			else if (originMap[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}
	
	// 1. 벽 세우기
	makeWall(-1, 0, 3);
	
	cout << ret;
}