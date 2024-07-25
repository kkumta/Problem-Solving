#include <bits/stdc++.h>
using namespace std;

int T, n;
string p, x;

vector<string> split(const string& input, string delimiter)
{
	if (input.size() == 0)
		return vector<string>();
	
	vector<string> result;
	auto start = 0;
	auto end = input.find(delimiter);
	while (end != string::npos)
	{
		result.push_back(input.substr(start, end - start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	result.push_back(input.substr(start));
	
	return result;
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		bool isFront = true, isError = false;
		deque<int> q;
		
		cin >> p >> n >> x;
		vector<string> v = split(x.substr(1, x.size() - 2), ",");
		for (string s : v)
			q.push_back(stoi(s));
		
		for (char command : p)
		{
			if (command == 'R')
				isFront = !isFront;
			else if (command == 'D')
			{
				if (q.empty())
				{
					isError = true;
					break;
				}
				
				if (isFront)
					q.pop_front();
				else
					q.pop_back();
			}
		}
		
		if (isError)
			cout << "error\n";
		else
		{
			if (!isFront)
				reverse(q.begin(), q.end());
			cout << '[';
			for (int j = 0; j < q.size(); j++)
			{
				cout << q[j];
				if (j != q.size() - 1)
					cout << ',';
			}
			cout << "]\n";
		}
	}
}