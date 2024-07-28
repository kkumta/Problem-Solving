#include <bits/stdc++.h>
using namespace std;

string s;
int ret;

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (i < s.size() - 2 && s.substr(i, 3) == "dz=")
			i += 2;
		else if (i < s.size() - 1)
		{
			string sstr = s.substr(i, 2);
			if (sstr == "c=" || sstr == "c-" || sstr == "d-" || sstr == "lj" || sstr == "nj" || sstr == "s=" || sstr == "z=")
				i++;
		}
		ret++;
	}
	
	cout << ret;
}