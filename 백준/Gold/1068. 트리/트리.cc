#include <bits/stdc++.h>
using namespace std;

int N, parent, removedNode, ret;
vector<int> nodes[50];
int parents[50];
bool isRemoved[50];

void RemoveNode(int node)
{
	for (int i = 0; i < nodes[node].size(); i++)
	{
		RemoveNode(nodes[node][i]);
	}
	
	nodes[node].clear();
	isRemoved[node] = true;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> parent;
		parents[i] = parent;
		if (parent == -1) continue;
		nodes[parent].push_back(i);
	}
	
	cin >> removedNode;
	if (parents[removedNode] != -1) // removedNode의 부모에게서 removedNode 삭제
	{
		auto v = &nodes[parents[removedNode]];
		(*v).erase(remove_if((*v).begin(), (*v).end(), [](auto x) -> bool { return x == removedNode; }), (*v).end());
	}
	RemoveNode(removedNode); // removedNode와 그 자식 노드 모두 삭제 
	
	for (int i = 0; i < N; i++)
	{
		if (!isRemoved[i] && nodes[i].empty())
			ret++;
	}
	
	cout << ret;
}