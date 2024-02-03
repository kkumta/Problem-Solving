#include <iostream>
#include <stack>
using namespace std;

string input;
stack<char> s;
int num = 1, sum = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			s.push(input[i]);
			num *= 2;
		}
		else if (input[i] == '[')
		{
			s.push(input[i]);
			num *= 3;
		}
		else if (!s.empty() && s.top() == '(' && input[i] == ')')
		{
			if (input[i - 1] == '(') sum += num;
			s.pop();
			num /= 2;
		}
		else if (!s.empty() && s.top() == '[' && input[i] == ']')
		{
			if (input[i - 1] == '[') sum += num;
			s.pop();
			num /= 3;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}

	if (s.empty()) cout << sum;
	else cout << 0;
}