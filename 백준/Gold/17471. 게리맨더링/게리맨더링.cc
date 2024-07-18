#include <bits/stdc++.h>
using namespace std;

int N, sum, isVisited, ret = 1000;
int a[10], b[1 << 10];

bool bfs(int visited)
{
	isVisited = 0;	
	
	int start = (visited & -visited);
		
	queue<int> q;
	q.push(start);
	isVisited |= start;
	
	while (!q.empty())
	{
		int curPos = q.front(); q.pop();
		for (int i = 1; i < (1 << N); i *= 2)
		{
			if (curPos == i)
				continue;
			if ((b[curPos] & i) && (visited & i) && !(isVisited & i))
			{
				isVisited |= i;
				q.push(i);
			}
		}
	}

	if (isVisited == visited)
		return true;
	return false;
}

void go(int idx, int visited)
{
	if (idx == N)
	{		
		if (visited == 0 || visited == (1 << N) - 1)
			return;
		
		// visited의 선거구들이 서로 연결되는지 확인
		// visited에 포함되지 않는 선거구들이 서로 연결되는지 확인 
		if (bfs(visited) && bfs(~visited & ((1 << N) - 1)))
		{					
			int c = 0;
			for (int i = 1; i < (1 << N); i *= 2)
			{
				if (visited & i)
					c += a[i];
			}

			ret = min(ret, abs(c - abs(sum - c)));
		}
		
		return;
	}
	
	go(idx + 1, visited);
	
	visited |= 1 << idx;
	go(idx + 1, visited);
}

int main()
{
	cin >> N;
	for (int i = 1; i < (1 << N); i *= 2)
	{
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i < (1 << N); i *= 2)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int p; 
			cin >> p;
			b[i] |= 1 << (p - 1);
		}
	}
	
	go(0, 0);
	
	if (ret == 1000)
		cout << -1;
	else
		cout << ret;
}