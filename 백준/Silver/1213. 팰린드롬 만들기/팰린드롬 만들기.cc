#include <bits/stdc++.h>
using namespace std;

int cnt[26];
int oddCnt;
char oddChar;
string s1, s2, ret;

int main()
{
	cin >> s1;
	for (int i = 0; i < s1.length(); i++)
	{
		cnt[s1[i]-'A']++;
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] % 2 != 0)
		{
			oddCnt++;
			oddChar = 'A' + i;
		}
	}
	if (oddCnt > 1)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < cnt[i] / 2; j++)
			s2 += 'A' + i;
	}
	ret += s2;
	if (oddCnt == 1)
		ret += oddChar;
	reverse(s2.begin(), s2.end());
	ret += s2;
	
	cout << ret;
	
	return 0;
}