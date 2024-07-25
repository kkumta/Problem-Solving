#include <bits/stdc++.h>
using namespace std;

string S;
bool ret = true;

int main()
{
	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		if (i < S.size() - 1 && ((S[i] == 'p' && S[i + 1] == 'i') || S[i] == 'k' && S[i + 1] == 'a'))
			i += 1;
		else if (i < S.size() - 2 && S[i] == 'c' && S[i + 1] == 'h' && S[i + 2] == 'u')
			i += 2;
		else
		{
			ret = false;
			break;
		}
	}

	if (ret)
		cout << "YES";
	else
		cout << "NO";
}