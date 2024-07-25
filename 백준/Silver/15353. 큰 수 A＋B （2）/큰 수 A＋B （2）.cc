#include <bits/stdc++.h>
using namespace std;

string A, B;
int idx, nxt;
deque<int> ret;

int main()
{
	cin >> A >> B;
	
	if (B.size() > A.size()) swap(A, B);
	string tmp;
	for (int i = 0; i < A.size() - B.size(); i++)
		tmp += '0';
	B = tmp + B;
	
	idx = B.size() - 1;
	while(idx >= 0)
	{
		int sum = (A[idx] - '0') + (B[idx] - '0') + nxt;
		if (sum >= 10)
			nxt = sum / 10;
		else
			nxt = 0;
		ret.push_front(sum % 10);
		
		idx--;
	}
	if (nxt != 0)
		ret.push_front(nxt);
	
	while (!ret.empty())
	{
		cout << ret.front();
		ret.pop_front();
	}
}