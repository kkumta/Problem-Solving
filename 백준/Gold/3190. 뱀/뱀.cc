#include <bits/stdc++.h>
using namespace std;

int N, K, L, direction;
vector<pair<int, int>> curPos;
bool a[100][100];
pair<int, char> b[100];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int c, d;
		cin >> c >> d;
		a[c - 1][d - 1] = true;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
		cin >> b[i].first >> b[i].second;
	
	curPos.push_back(make_pair(0, 0));
	for (int i = 1, j = 0; i <= 1000000000; i++)
	{	
		// 이동 
		{
			pair<int, int> nextPos = make_pair(curPos[0].first + dy[direction], curPos[0].second + dx[direction]);
			// 벽에 닿는 경우			
			if (nextPos.first < 0 || nextPos.first >= N || nextPos.second < 0 || nextPos.second >= N)
			{
				cout << i;
				return 0;
			}
			// 자기자신의 몸과 부딪히는 경우			
			for (int k = 0; k < curPos.size(); k++)
				if (curPos[k] == nextPos)
				{
					cout << i;
					return 0;
				}	
			
			if (a[nextPos.first][nextPos.second]) // 사과가 있는 곳
			{
				a[nextPos.first][nextPos.second] = false;
				curPos.push_back(make_pair(0, 0));
				for (int k = curPos.size() - 2; k >= 0; k--)
					curPos[k + 1] = curPos[k];
				curPos[0] = nextPos;
			}
			else // 사과가 없는 곳 
			{
				for (int k = curPos.size() - 2; k >= 0; k--)
					curPos[k + 1] = curPos[k];
				curPos[0] = nextPos;				
			}		
		}
		
		// 방향 전환
		if (b[j].first == i)
		{
			if (b[j].second == 'D')
				direction++;
			else if (b[j].second == 'L')
				direction += 3;
			
			direction %= 4;
			j++;
		}
	}
}