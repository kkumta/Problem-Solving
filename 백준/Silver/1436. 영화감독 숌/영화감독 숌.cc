#include <bits/stdc++.h>
using namespace std;

int N, cnt;

int main()
{
	cin >> N;
	for (int ret = 666; ; ret++)
	{
		string s = to_string(ret);
		for (int i = 0; i < s.length() - 2; i++)
		{
			if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6')
			{
				cnt++;
				break;
			}
		}
		
		if (cnt == N)
		{
			cout << ret;
			return 0;
		}
	}
}