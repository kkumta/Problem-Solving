#include <bits/stdc++.h>
using namespace std;

string password; 
int cnt;

bool isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

bool isAcceptable(string word)
{
	cnt = 0;
	for (int i = 0; i < password.length(); i++)
	{
		if (isVowel(password[i])) cnt++;
		if (i >= 1) 
			if (password[i] == password[i - 1] && password[i] != 'e' && password[i] != 'o')
				return false;
		if (i >= 2)
		{
			if (isVowel(password[i]) && isVowel(password[i - 1]) && isVowel(password[i - 2]))
				return false;
			if (!isVowel(password[i]) && !isVowel(password[i - 1]) && !isVowel(password[i - 2]))
				return false;
		}
	}
	if (cnt == 0) return false;
	
	return true;
}

int main()
{
	while(cin >> password)
	{
		if (password == "end") return 0;
		if (isAcceptable(password))
			cout << '<' << password << "> is acceptable.\n";
		else
			cout << '<' << password << "> is not acceptable.\n";
	}
}