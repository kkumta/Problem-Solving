#include <bits/stdc++.h>
using namespace std;

int T, N, M, ret;
int A[20000], B[20000];

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		ret = 0;
		cin >> N >> M;
		for (int j = 0; j < N; j++)
			cin >> A[j];
		for (int j = 0; j < M; j++)
			cin >> B[j];
			
		sort(A, A + N); sort(B, B + M);
		for (int j = 0; j < N; j++)
			ret += lower_bound(B, B + M, A[j]) - B;
		
		cout << ret << '\n';
	}
}