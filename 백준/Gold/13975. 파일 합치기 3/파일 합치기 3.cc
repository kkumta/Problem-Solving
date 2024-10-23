#include <bits/stdc++.h>
using namespace std;

int T, K, tmp;
long long ret;

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		ret = 0;
		
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> tmp;
			pq.push(tmp);
		}
		
		while (pq.size() > 1)
		{
			long long sum = pq.top(); pq.pop();
			sum += pq.top(); pq.pop();
			ret += sum;
			pq.push(sum);
		}
		cout << ret << '\n';
	}
}