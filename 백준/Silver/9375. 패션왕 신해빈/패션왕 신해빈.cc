#include <bits/stdc++.h>
using namespace std;

int M, N, ans;
string name, kind;

int main()
{
	cin >> M;
	
	for (int i = 0; i < M; i++)
	{
		map<string, int> mp;
		ans = 1;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> name >> kind;
			mp[kind]++;
		}
		
		for (auto iter = mp.begin(); iter != mp.end(); iter++)
		{
			ans *= iter->second + 1;
		}
		cout << ans - 1 << '\n';
	}
	
	return 0;
}