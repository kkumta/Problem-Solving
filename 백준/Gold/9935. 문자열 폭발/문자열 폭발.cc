#include <bits/stdc++.h>
using namespace std;

string a, b, ret;
stack<char> stk;

int main()
{
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		stk.push(a[i]);
		if (stk.size() >= b.size() && stk.top() == b[b.size() - 1])
		{
			string s = "";
			for (int j = 0; j < b.size(); j++)
			{
				s += stk.top();
				stk.pop();
			}
			reverse(s.begin(), s.end());
			
			if (s != b)
				for (char c : s)
					stk.push(c);
		}
	}
	
	if (stk.empty()) cout << "FRULA";
	else
	{
		while (!stk.empty())
		{
			ret += stk.top();
			stk.pop();
		}
		reverse(ret.begin(), ret.end());
		cout << ret;
	}
}