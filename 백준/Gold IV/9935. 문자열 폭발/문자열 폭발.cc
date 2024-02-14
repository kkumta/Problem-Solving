#include <stack>
#include <iostream>
using namespace std;

stack<pair<char, int>> stk, ans;
string str1, str2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++)
	{
		if (!stk.empty() && str1[i] == str2[stk.top().second]) // 폭발 문자열의 문자가 연속된다
		{
			// 새로운 문자도 스택에 넣어 준다
			stk.push(make_pair(str1[i], stk.top().second + 1));
			if (stk.top().second == str2.size()) // 폭발!
			{
				for (int j = 0; j < str2.size(); j++)
					stk.pop();
			}
		}
		else if (str1[i] == str2[0]) // 폭발 문자열의 첫번째 문자가 str1[i]이다
		{
			stk.push(make_pair(str1[i], 1)); // 새로운 문자를 스택에 넣어 준다
			if (str2.size() == 1) // 폭발!
				stk.pop();
		}
		else // str1[i]가 폭발 문자열과 관련이 없다
			stk.push(make_pair(str1[i], 0));
	}

	if (stk.size() == 0) cout << "FRULA";
	else
	{
		while (!stk.empty())
		{
			ans.push(stk.top());
			stk.pop();
		}
		while (!ans.empty())
		{
			cout << ans.top().first;
			ans.pop();
		}
	}
}