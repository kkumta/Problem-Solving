#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
map<string, int> m1;
map<int, string> m2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string name;
		cin >> name;
		m1[name] = i;
		m2[i] = name;
	}
	
	for (int i = 1; i <= M; i++)
	{
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') // 숫자일 경우 
			cout << m2[stoi(s)] << '\n';
		else // 문자열일 경우 
			cout << m1[s] << '\n';
	}
	
	return 0;
}