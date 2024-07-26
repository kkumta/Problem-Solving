#include <bits/stdc++.h>
using namespace std;

int n, cnt, ret;
string str;
stack<int> stk;
bool d[200000];

int main()
{
	cin >> n >> str;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			stk.push(i);
		else if (str[i] == ')' && !stk.empty())
		{
			d[i] = d[stk.top()] = true;
			stk.pop();
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (d[i])
		{
			cnt++;
			ret = max(ret, cnt);	
		}
		else
			cnt = 0;
	}
	
	cout << ret;
}