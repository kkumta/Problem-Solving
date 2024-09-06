#include <bits/stdc++.h>
using namespace std;

int N, M, tmp, ret;
map<int, int> m;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N + M; i++)
	{
		cin >> tmp;
		m[tmp]++;
	}
	for (pair<int, int> b : m)
	{
		if (b.second == 1) ret++;
	}
		
	cout << ret;
}