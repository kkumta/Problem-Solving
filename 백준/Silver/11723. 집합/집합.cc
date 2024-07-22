#include <bits/stdc++.h>
using namespace std;

int M, S, x;
string command;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> M;
	
	for (int i = 0; i < M; i++)
	{
		cin >> command;
		if (command == "add")
		{
			cin >> x;
			S |= 1 << x; 	
		}
		else if (command == "remove")
		{
			cin >> x;
			S &= ~(1 << x);
		}
		else if (command == "check")
		{
			cin >> x;
			if (S & (1 << x))
				cout << "1\n";
			else 
				cout << "0\n";		
		}
		else if (command == "toggle")
		{
			cin >> x;
			if (S & (1 << x))
				S &= ~(1 << x);
			else
				S |= (1 << x);			
		}
		else if (command == "all")
			S = (1 << 21) - 1;
		else if (command == "empty")
			S = 0;	
	}
}