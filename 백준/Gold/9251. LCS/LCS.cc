#include <iostream>
using namespace std;

int n;
string str1, str2;
int d[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); i++)
	{
		for (int j = 0; j < str2.length(); j++)
		{
			if (str1[i] == str2[j])
				d[i + 1][j + 1] = d[i][j] + 1;
			else
				d[i + 1][j + 1] = max(d[i + 1][j], d[i][j + 1]);
		}
	}

	cout << d[str1.length()][str2.length()];
}