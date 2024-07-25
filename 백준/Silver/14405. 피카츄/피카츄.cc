#include <bits/stdc++.h>
using namespace std;

string S;
int _size;
bool ret = true;

int main()
{
	cin >> S;
	_size = S.size();
	for (int i = 0; i < S.size() - 1; i++)
	{
		if (S[i] == 'p' && S[i + 1] == 'i')
		{
			i += 1;
			_size -= 2;
		}
		else if (S[i] == 'k' && S[i + 1] == 'a')
		{
			i += 1;
			_size -= 2;
		}
		else if (i < S.size() - 2 && S[i] == 'c' && S[i + 1] == 'h' && S[i + 2] == 'u')
		{
			i += 2;
			_size -= 3;
		}
		else
		{
			ret = false;
			break;
		}
	}
	
	if (_size > 0)
		ret = false;
	
	if (ret)
		cout << "YES";
	else
		cout << "NO";
}