#include <bits/stdc++.h>
using namespace std;

int N, ret;
bool flag;
bool isExist[26];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		flag = true;
		fill(&isExist[0], &isExist[0] + 26, false);
		string s; cin >> s;
		char lastAlpha = 'z' + 1;
		
		for (int i = 0; i < s.size(); i++)
		{
			if (!isExist[s[i] - 'a'])
			{
				isExist[s[i] - 'a'] = true;
				lastAlpha = s[i];
			}
			else if (s[i] != lastAlpha)
			{
				flag = false;
				break;
			}			
		}
		
		if (flag) ret++;
	}
	
	cout << ret;
}