#include <bits/stdc++.h>
using namespace std;

int x, y, w, h, ret;

int main()
{
	cin >> x >> y >> w >> h;
	ret = min(x, y);
	ret = min(ret, w - x);
	ret = min(ret, h - y);
	cout << ret;
}