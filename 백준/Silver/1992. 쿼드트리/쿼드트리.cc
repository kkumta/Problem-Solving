#include <bits/stdc++.h>
using namespace std;

int N;
int maps[64][64];

string go(int y, int x, int n)
{	
	// 모두 같은 숫자로만 되어 있을 경우
	int cnt[] = {0, 0}; 
	for (int i = y; i < y + n; i++)
		for (int j = x; j < x + n; j++)
		{
			if (maps[i][j] == 0) cnt[0]++;
			else cnt[1]++;
		}
	if (cnt[0] == 0) return "1";
	else if (cnt[1] == 0) return "0";
	
	// 모두 같은 숫자로만 되어 있지 않을 경우 
	string ret = "";
	ret += '(';
	ret += go(y, x, n / 2);
	ret += go(y, x + n / 2, n / 2);
	ret += go(y + n / 2, x, n / 2);
	ret += go(y + n / 2, x + n / 2, n / 2);
	ret += ')';
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
			maps[i][j] = s[j] - '0';
	}
	
	cout << go(0, 0, N);
}