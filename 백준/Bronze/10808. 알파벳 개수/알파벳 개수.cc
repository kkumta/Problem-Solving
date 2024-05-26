#include <bits/stdc++.h>
using namespace std;

string S;
int cnt[26];

int main()
{
	cin >> S;
	for (char item : S)
		cnt[item - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << cnt[i] << ' ';
	return 0;
}