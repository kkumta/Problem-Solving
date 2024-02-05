#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define row first
#define col second

int dx[]{ 0, 1, 0, -1 };
int dy[]{ 1, 0, -1, 0 };

int r, c;
pair<int, int> jPos;
vector<pair<int, int>> fPos;
char maze[1001][1001];
int fTime[1001][1001];
int jTime[1001][1001];

void findFTime(pair<int, int> pos)
{
	queue<pair<int, int>> q;
	q.push(pos);
	fTime[pos.row][pos.col] = 1;
	while (!q.empty())
	{
		pair<int, int> curPos = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nextPos = make_pair(curPos.row + dy[i], curPos.col + dx[i]);
			if (r <= nextPos.row || nextPos.row < 0 || c <= nextPos.col || nextPos.col < 0) continue;
			if (maze[nextPos.row][nextPos.col] == '#') continue;
			if (fTime[nextPos.row][nextPos.col] == 0 || fTime[nextPos.row][nextPos.col] > fTime[curPos.row][curPos.col] + 1)
			{
				fTime[nextPos.row][nextPos.col] = fTime[curPos.row][curPos.col] + 1;
				q.push(nextPos);
			}
		}
	}
}

bool FindJTime()
{
	queue<pair<int, int>> q;
	q.push(jPos);
	jTime[jPos.row][jPos.col] = 1;
	while (!q.empty())
	{
		pair<int, int> curPos = q.front(); q.pop();
		if (curPos.row == r - 1 || curPos.row == 0 || curPos.col == c - 1 || curPos.col == 0)
		{
			cout << jTime[curPos.row][curPos.col];
			return true;
		}
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nextPos = make_pair(curPos.row + dy[i], curPos.col + dx[i]);
			if (r <= nextPos.row || nextPos.row < 0 || c <= nextPos.col || nextPos.col < 0) continue;
			if (maze[nextPos.row][nextPos.col] == '#') continue;
			if (jTime[nextPos.row][nextPos.col] != 0) continue;
			if (fTime[nextPos.row][nextPos.col] != 0 && fTime[nextPos.row][nextPos.col] <= jTime[curPos.row][curPos.col] + 1) continue;
			jTime[nextPos.row][nextPos.col] = jTime[curPos.row][curPos.col] + 1;
			q.push(nextPos);
		}
	}

	return false;
}

int main()
{
	// 입력
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < c; j++)
		{
			if (row[j] == 'F') fPos.push_back(make_pair(i, j));
			else if (row[j] == 'J') jPos = make_pair(i, j);
			else maze[i][j] = row[j];
		}
	}

	// 각 위치별 불 도달 시간 구하기
	for (pair<int, int> pos : fPos)
		findFTime(pos);

	// 각 위치별 지훈이 도달 시간 구하기
	if (!FindJTime()) cout << "IMPOSSIBLE";
}