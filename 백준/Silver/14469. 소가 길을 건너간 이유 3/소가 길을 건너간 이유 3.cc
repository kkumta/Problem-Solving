#include <bits/stdc++.h>
using namespace std;

int N, a, b, t;
vector<pair<int, int>> v;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < N; i++)
	{
		if (t < v[i].first) t = v[i].first;
		t += v[i].second;
	}
	
	cout << t;
}