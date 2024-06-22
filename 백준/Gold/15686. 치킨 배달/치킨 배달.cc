#include <bits/stdc++.h>
using namespace std;

int N, M, ret = 100000000;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<pair<int, int>> curChickens;

int findChickenDistance()
{
	int sum = 0;
	
	for (int i = 0; i < houses.size(); i++)
	{
		int minDistance = 10000;
		for (int j = 0; j < curChickens.size(); j++)
		{
			int d = abs(houses[i].first - curChickens[j].first) + abs(houses[i].second - curChickens[j].second);
			if (d < minDistance) minDistance = d;
		}
		sum += minDistance;
	}
	
	return sum;
}

void go(int start, int depth)
{
	if (depth == M)
	{
		// 치킨집 폐업에 따른 치킨 거리 구하기
		ret = min(ret, findChickenDistance());
	}
	
	for (int i = start; i < chickens.size(); i++)
	{
		curChickens.push_back(chickens[i]);
		go(i + 1, depth + 1);
		curChickens.pop_back();			
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			if (a == 1) houses.push_back(make_pair(i, j));
			else if (a == 2)
			{
				chickens.push_back(make_pair(i, j));
			}
		}
	}
	
	// 폐업시키지 않을 치킨집 선택
	go(0, 0);
	
	cout << ret;
}