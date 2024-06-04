#include <bits/stdc++.h>
using namespace std;

int N;
string c;
int stk[10000];
int s;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> c;
		if (c == "push") cin >> stk[s++];
		else if (c == "pop")
		{
			if (s == 0) cout << -1 << '\n';
			else cout << stk[--s] << '\n';
		}
		else if (c == "size") cout << s << '\n';
		else if (c == "empty")
		{
			if (s == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else
		{
			if (s == 0) cout << -1 << '\n';
			else cout << stk[s - 1] << '\n';
		}
	}
}