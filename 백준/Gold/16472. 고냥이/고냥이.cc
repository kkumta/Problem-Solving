#include <bits/stdc++.h>
using namespace std;

int N, cnt, len, ret, a[26];
string str;

int main()
{
	cin >> N >> str;
	
	int s = 0, e = 0;
	for (; e < str.size(); e++)
	{
		if (a[str[e] - 'a'] == 0) // 아직 안 쓴 알파벳이 쓰일 때 
		{
			if (cnt < N)
			{
				cnt++;
				a[str[e] - 'a']++;
				len++;
			}
			else // 기존에 쓰던 알파벳을 빼고 새로운 알파벳을 추가할 때 
			{
				while (cnt >= N)
				{
					a[str[s] - 'a']--;
					len--;
					if (a[str[s] - 'a'] == 0) cnt--;
					s++;
				}
				e--; 
			}
		}
		else // 이미 쓴 알파벳이 쓰일 때 
		{
			a[str[e] - 'a']++;
			len++;
		}
		
		ret = max(len, ret);
	}
	
	cout << ret;
}