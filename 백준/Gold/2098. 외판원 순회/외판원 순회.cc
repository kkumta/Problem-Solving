#include <bits/stdc++.h>
using namespace std;

const int N = 16, inf = 160000000;
int n, b, ret;
int w[N][N], d[N][1 << N];

// here: 현재 위치한 도시, visited: 이미 방문한 도시 목록 
int tsp(int here, int visited)
{
	// 모든 도시를 방문한 경우 
	if (visited == (1 << n) - 1)
		return w[here][0] ? w[here][0] : inf;
	
	// 이미 계산된 값이 있으면 그 값을 반환	
	int& ret = d[here][visited];
	if (ret != -1) return ret;
	
	// 모든 도시를 순회하면서 아직 방문하지 않은 도시를 찾아서 이동 
	ret = inf;
	for (int i = 0; i < n; i++)
	{
		// 이미 방문한 도시 
		if (visited & (1 << i)) continue;
		// 방문할 수 없는 도시 
		if (w[here][i] == 0) continue;
		// 다음 도시로 이동하면서 최소 비용 갱신 
		ret = min(ret, tsp(i, visited | (1 << i)) + w[here][i]);
	}
	
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	
	fill(&d[0][0], &d[0][0] + N * (1 << N), -1);
	cout << tsp(0, 1 << 0);
}