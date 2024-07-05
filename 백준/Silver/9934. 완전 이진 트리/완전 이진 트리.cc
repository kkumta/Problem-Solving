#include <bits/stdc++.h>
using namespace std;

int K;
vector<int> v;
vector<int> ret[11];

void go(int start, int end, int depth)
{
	if (depth > K)
		return;
	
	int mid = (start + end) / 2; 
	ret[depth].push_back(v[mid]);
	go(start, mid, depth + 1);
	go(mid + 1, end, depth + 1);
}

int main()
{
	cin >> K;
	for (int i = 0; i < pow(2, K) - 1; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	go(0, pow(2, K) - 2, 1);
	
	for (int i = 1; i <= K; i++)
	{
		for (int j : ret[i])
			cout << j << ' ';
		cout << '\n';
	}
}