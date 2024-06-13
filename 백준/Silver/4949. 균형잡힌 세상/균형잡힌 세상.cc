#include <bits/stdc++.h>
using namespace std;

string str;
bool flag;
stack<char> stk;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true)
	{
		getline(cin, str);
		if (str == ".") break;
		
		flag = true;
		stk = stack<char>();
		for (char c : str)
		{
			if (c == '(' || c == '[') stk.push(c);
			else if (c == ')' || c == ']')
			{
				if (stk.empty() || (stk.top() == '(' && c == ']') || (stk.top() == '[' && c == ')'))
				{
					flag = false;
					break;
				}
				else
				{
					stk.pop();
				}
			}
		}
		
		if (flag && stk.empty()) cout << "yes\n";
		else cout << "no\n";
	}
	
	return 0;
}