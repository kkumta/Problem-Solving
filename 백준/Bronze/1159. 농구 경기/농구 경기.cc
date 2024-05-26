#include <bits/stdc++.h>
using namespace std;

int N;
int cnt[26];
bool PREDAJA = true;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		cnt[name[0] - 'a']++;
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5)
		{
			PREDAJA = false;
			char c = 'a' + i;
			cout << c;
		}
	}
	
	if (PREDAJA)
		cout << "PREDAJA";
}