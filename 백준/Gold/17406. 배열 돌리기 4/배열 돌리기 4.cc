#include <bits/stdc++.h>
using namespace std;

int N, M, K, r, c, s, ret = 100 * 50;
pair<int, int> st, en;
int A[51][51], originA[51][51], nextA[51][51], rota[6][3];
int a[6];
bool visited[6];

void func()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			originA[i][j] = A[i][j];
	
	// 회전 연산을 K번 수행하기
	for (int i = 0; i < K; i++)
	{
		// 연산 꺼내오기
		r = rota[a[i]][0]; c = rota[a[i]][1]; s = rota[a[i]][2];
		st = make_pair(r - s, c - s);
		en = make_pair(r + s, c + s);
		
		// A -> originA
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= M; k++)
				nextA[j][k] = originA[j][k];
		
		// 연산 
		for (int j = 0; j < (en.first - st.first + 1) / 2; j++)
		{
			// 오른쪽으로
			for (int k = st.second + j; k < en.second - j; k++)
				nextA[st.first + j][k + 1] = originA[st.first + j][k];
			// 왼쪽으로
			for (int k = en.second - j; k > st.second + j; k--)
				nextA[en.first - j][k - 1] = originA[en.first - j][k];
			// 아래쪽으로
			for (int k = st.first + j; k < en.first - j; k++)
				nextA[k + 1][en.second - j] = originA[k][en.second - j];
			// 위쪽으로
			for (int k = en.first - j; k > st.first + j; k--)
				nextA[k - 1][st.second + j] = originA[k][st.second + j];					
		}
		
		// nextA -> originA
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= M; k++)
				originA[j][k] = nextA[j][k];
	}
	
	// 최솟값 구하기
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= M; j++)
			sum += originA[i][j];
		ret = min(sum, ret);	
	}	
}

void go(int k)
{
	if (k == K)
	{		
		func();
		return;
	}
	
	for (int i = 0; i < K; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			a[k] = i;
			go(k + 1);
			visited[i] = false;		
		}
	}	
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
		
	for (int i = 0; i < K; i++)
		cin >> rota[i][0] >> rota[i][1] >> rota[i][2];
	
	go(0);
	
	cout << ret;
}