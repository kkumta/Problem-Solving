#include <bits/stdc++.h>
using namespace std;

int T;
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		bool ret = true;
		cin >> str;
		stack<char> stk;
		for (char c : str)
		{
			if (c == '(') stk.push('(');
			else if (stk.empty()) 
			{
				ret = false; 
				break;
			}
			else stk.pop();
		}
		if (stk.empty() && ret) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}