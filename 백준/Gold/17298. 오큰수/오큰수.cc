#include <bits/stdc++.h>
using namespace std;

int N, a;
stack<pair<int, int>> stk;
int ret[1000000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		while (!stk.empty() && stk.top().second < a)
		{
			ret[stk.top().first] = a;
			stk.pop();
		}
		stk.push(make_pair(i, a));
	}
	
	for (int i = 0; i < N; i++)
	{
		if (ret[i] == 0)
			cout << "-1 ";
		else
			cout << ret[i] << ' ';
	}
}