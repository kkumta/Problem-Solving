#include <bits/stdc++.h>
using namespace std;

int N, B;
vector<char> ret;

int main()
{
	cin >> N >> B;
	
	while (N != 0)
	{
		int tmp = N % B;
		tmp >= 10 ? ret.push_back('A' - 10 + tmp) : ret.push_back('0' + tmp);
		N /= B;
	}
	
	reverse(ret.begin(), ret.begin() + ret.size());
	for (char c : ret)
		cout << c;
}