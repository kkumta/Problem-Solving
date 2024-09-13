#include <bits/stdc++.h>
using namespace std;

int N, tmp, len;
const int INF = 1000000001;
int lis[1000000];
pair<int, int> ret[1000000];
stack<int> stk;

int main()
{
	cin >> N;
	fill(lis, lis + 1000000, INF);
	
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		int lowerIdx = lower_bound(lis, lis + N, tmp) - lis;
		if (lis[lowerIdx] == INF) len++;
		lis[lowerIdx] = tmp;
		ret[i].first = tmp;
		ret[i].second = lowerIdx;
	}
	cout << len << '\n';
		
	for (int i = N - 1; i >= 0; i--)
	{
		if (ret[i].second == len - 1)
		{
			stk.push(ret[i].first);
			len--;
		}
	}
	while (!stk.empty())
	{
		cout << stk.top() << ' ';
		stk.pop();
	}
}