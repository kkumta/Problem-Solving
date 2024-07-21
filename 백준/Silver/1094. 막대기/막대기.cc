#include <bits/stdc++.h>
using namespace std;

int X, sum = 64, tmp, ret;

int main()
{
	cin >> X;
	
	while (sum != X)
	{
		// 가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자르기 
		int shortRod = sum & -sum;
		sum &= ~shortRod;
		sum |= shortRod >> 1;
		
		sum |= tmp;
		tmp = 0;
		
		// 자른 막대 중 하나를 버리고 남아있는 막대의 길이의 합이 X보다 작다면, 자른 막대 중 하나를 저장하기 
		if (sum < X)
			tmp = shortRod >> 1;
	}
	
	for (int i = 0; i <= 6; i++)
		if (sum & (1 << i))
			ret++;
	
	cout << ret;
}