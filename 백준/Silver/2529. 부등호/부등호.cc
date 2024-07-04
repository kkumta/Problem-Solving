#include <bits/stdc++.h>
using namespace std;

int k;
char s[10];
vector<int> v; 
bool visited[10];
pair<string, string> ret;

void go(int depth)
{	
	if (depth == k + 1)
	{			
		string tmp;
		for (int i : v)
			tmp += to_string(i);
			
		ret.first = max(tmp, ret.first);
		ret.second = min(tmp, ret.second);
		
		return;
	}
	
	for (int i = 0; i <= 9; i++)
	{
		if (!visited[i])
		{
			if (depth == 0 || (s[depth - 1] == '<' && v[depth - 1] < i) || (s[depth - 1] == '>' && v[depth - 1] > i))
			{
				v.push_back(i);
				visited[i] = true;
				go(depth + 1);
				v.pop_back();
				visited[i] = false;
			}
		}
	}
}

int main()
{
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> s[i];
	
	ret.first = "0";
	ret.second = "9999999999";
		
	go(0);
	
	cout << ret.first << '\n' << ret.second;
}