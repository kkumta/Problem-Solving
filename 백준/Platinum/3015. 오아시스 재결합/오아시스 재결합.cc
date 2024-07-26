#include <bits/stdc++.h>
using namespace std;

int N;
long long ret;
int a[500000];
stack<pair<int, long long>> stk; // pair<height, cnt>

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		while (!stk.empty() && stk.top().first <= a[i])
		{
			ret += stk.top().second;
			if (stk.top().first == a[i])
				cnt = stk.top().second + 1;
			else
				cnt = 1;
			stk.pop();
		}
		
		if (!stk.empty())
			ret++;
		
		stk.push(make_pair(a[i], cnt));
	}
	
	cout << ret;
}