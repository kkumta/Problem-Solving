#include <bits/stdc++.h>
using namespace std;

string s;
int N;
int firstLen, lastLen;

int main()
{
	cin >> N >> s;
	
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 42)
		{	
			firstLen = i;
			lastLen = s.length() - (i + 1);	
			break;
		}
	}

	for (int i = 0; i < N; i++)
	{
		string fileName;
		cin >> fileName;
		
		if (fileName.length() <= firstLen || fileName.length() <= lastLen || fileName.length() < firstLen + lastLen)
		{
			cout << "NE" << '\n';
			continue;
		}
		
		if (s.substr(0, firstLen) == fileName.substr(0, firstLen) && s.substr(firstLen + 1, lastLen) == fileName.substr(fileName.length() - lastLen , lastLen))
			cout << "DA" << '\n';
		else
			cout << "NE" << '\n';
	}
}