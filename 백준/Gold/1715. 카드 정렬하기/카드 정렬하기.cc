#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int n;
long long answer;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int size;
		cin >> size;
		pq.push(size);
	}

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	while (pq.size() >= 2)
	{
		long long sum = 0;
		for (int i = 0; i < 2; i++)
		{
			sum += pq.top();
			pq.pop();
		}
		answer += sum;
		pq.push(sum);
	}

	cout << answer;
}