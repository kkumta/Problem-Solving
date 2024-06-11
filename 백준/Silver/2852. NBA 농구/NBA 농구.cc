#include <bits/stdc++.h>
using namespace std;

int N, a, m, s;
string b, mstr, sstr;
vector<pair<int, int>> v;
int goal[2], ret[2];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		m = stoi(b.substr(0, 2));
		s = stoi(b.substr(3, 2));
		v.push_back(make_pair(a - 1, m * 60 + s));
	}
	v.push_back(make_pair(7, 48 * 60));
	
	for (int i = 0; i < N; i++)
	{
		goal[v[i].first]++;
		if (goal[v[i].first] > goal[(v[i].first + 1) % 2])
			ret[v[i].first] += v[i + 1].second - v[i].second;
		else if (goal[v[i].first] < goal[(v[i].first + 1) % 2])
			ret[(v[i].first + 1) % 2] += v[i + 1].second - v[i].second;		
	}
	
	for (int r : ret)
	{
		mstr = ""; sstr = "";
		
		if (r / 60 < 10)
			mstr = "0";
		mstr += to_string(r / 60);
		if (r % 60 < 10)
			sstr = "0";
		sstr += to_string(r % 60);
		
		cout << mstr << ':' << sstr << '\n';
	}
}