#include <iostream>
#include <stack>
using namespace std;

int n, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		stack<char> s;
		string word;
		cin >> word;
		for (int j = 0; j < word.size(); j++)
		{
			if (!s.empty() && s.top() == word[j]) s.pop();
			else s.push(word[j]);
		}
		if (s.empty()) ans++;
	}

	cout << ans;
}