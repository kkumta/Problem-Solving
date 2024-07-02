#include <bits/stdc++.h>
using namespace std;

int N, K, ret;
const int MAX = 500000;
int visited[2][500001];
int d[1000002];

void bfs(int start)
{
	queue<pair<int, bool>> q; // bool: 짝수일 때 true 
	q.push(make_pair(start, true));
	visited[true][start] = 1;
	while (!q.empty())
	{
		int curPos = q.front().first;
		bool curFlag = q.front().second;
		q.pop();
		
		bool nextFlag = !curFlag;
		for (int nextPos : {curPos + 1, curPos - 1, curPos * 2})
		{
			if (nextPos >= 0 && nextPos <= MAX)
			{
				if (visited[nextFlag][nextPos] == 0)
				{
					visited[nextFlag][nextPos] = visited[curFlag][curPos] + 1;
					q.push(make_pair(nextPos, nextFlag));
				}
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	if (N == K)
	{
		cout << 0;
		return 0;
	}
	
	bfs(N);
	
	d[0] = K;
	for (int i = 1; ; i++)
	{
		d[i] = d[i - 1] + i;
		if (d[i] > MAX)
		{
			ret = -1;
			break;
		}
		if ((i % 2 == 0 && visited[true][d[i]] && visited[true][d[i]] - 1 <= i) || (i % 2 != 0 && visited[false][d[i]] && visited[false][d[i]] - 1 <= i))
		{
			ret = i;
			break;
		}
	}

	cout << ret;
}