#include <stack>
#include <iostream>
using namespace std;

int N;
stack<pair<int, int>> s; // 높이, 번호

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int height;
		cin >> height;

		while (!s.empty())
		{
			pair<int, int> top = s.top();
			if (top.first >= height)
			{
				cout << top.second << ' ';
				break;
			}
			else
				s.pop();
		}
		if (s.empty()) cout << '0' << ' ';

		s.push(make_pair(height, i));
	}
}