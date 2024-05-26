#include <bits/stdc++.h>
using namespace std;

string S, ans;

int main()
{
	getline(cin, S);
	for (char c : S)
	{
		if (c >= 'a' && c <= 'z')
			ans += ((c - 'a' + 13) % 26) + 'a';
		else if (c >= 'A' && c <= 'Z')
			ans += ((c - 'A' + 13) % 26) + 'A';
		else
			ans += c;
	}
	
	cout << ans;
	
	return 0;
}