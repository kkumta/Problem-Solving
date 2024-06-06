// 2910 빈도 정렬
// map<int, pair<int, int>>에  수, <빈도, 등장 순서>를 저장하고 vector에 넣어 정렬한다.

#include <bits/stdc++.h>
using namespace std;

int N, C, tmp;
map<int, pair<int, int>> m;
vector<pair<int, pair<int, int>>> v;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	if (a.second.first == b.second.first)
		return a.second.second < b.second.second;
		
	return a.second.first > b.second.first;
}

int main()
{
	cin >> N >> C;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		if (m.find(tmp) == m.end())
			m[tmp] = make_pair(1, i);
		else
			m[tmp].first++;
	}
	
	for (auto it : m)
		v.push_back(make_pair(it.first, it.second));
	
	sort(v.begin(), v.end(), cmp);
	
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].second.first; j++)
			cout << v[i].first << ' ';
}