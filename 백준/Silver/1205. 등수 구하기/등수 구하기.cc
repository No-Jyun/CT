#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, score, p;
vector<int> v(51, -1);

int StartSolve()
{
	cin >> n >> score >> p;

	unordered_map<int, int> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		if (m[v[i]] == 0) m[v[i]] = i;
	}

	if (n == 0)return 1;

	int rank = -1;
	int insertIndex = -1;
	for (int i = 1; i <= n; i++)
	{
		if (score > v[i])
		{
			if (rank != -1) break;

			rank = m[v[i]];
			insertIndex = i;
			break;
		}
		else if (score == v[i])
		{
			rank = m[v[i]];
			insertIndex = i + 1;
		}
		else if (score < v[i])
		{
			rank = i + 1;
			if (i == n)
			{
				insertIndex = i + 1;
			}
		}
	}

	if (insertIndex > p) return -1;

	return rank;
}

int main()
{
	cout << StartSolve();
}