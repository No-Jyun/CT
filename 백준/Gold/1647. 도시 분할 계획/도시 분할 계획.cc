#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Onion {
	int num;
	int parent;
}onionArray[100000];

int GetParent(int a)
{
	if (onionArray[a].num == onionArray[a].parent)
	{
		return onionArray[a].parent;
	}

	onionArray[a].parent = GetParent(onionArray[a].parent);
	return onionArray[a].parent;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<pair<int, pair<int, int>>> edges;

	for (int i = 0; i < n; i++)
	{
		onionArray[i].num = i;
		onionArray[i].parent = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edges.push_back({ c,{a - 1,b - 1} });
	}

	sort(edges.begin(), edges.end());

	int answer = 0;
	int maxE = n - 1;
	int countE = 0;
	int maxCost = 0;
	for (int i = 0; i < m; i++)
	{
		int curA = edges[i].second.first;
		int curB = edges[i].second.second;
		int curC = edges[i].first;

		int parentA = GetParent(curA);
		int parentB = GetParent(curB);

		if (parentA == parentB)
		{
			continue;
		}
		else
		{
			onionArray[parentA].parent = parentB;
			countE++;
			answer += curC;

			maxCost = maxCost > curC ? maxCost : curC;
		}

		if (countE >= maxE)
			break;
	}

	cout << answer - maxCost;
}