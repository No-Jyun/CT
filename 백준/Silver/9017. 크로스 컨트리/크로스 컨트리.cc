#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int t;
int teamNum[201];
int teamCount[201];

int StartSolve()
{
	int n;
	cin >> n;

	vector<int> arr(n + 1);
	vector<pair<int, int>> v(201);
	memset(teamNum, 0, sizeof(int) * 201);
	memset(teamCount, 0, sizeof(int) * 201);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		teamNum[arr[i]]++;
	}

	int score = 1;
	for (int i = 1; i <= n; i++)
	{
		if (teamNum[arr[i]] < 6) continue;

		teamCount[arr[i]]++;
		if (teamCount[arr[i]] == 5)
		{
			v[arr[i]].second = score;
		}

		if (teamCount[arr[i]] < 5) 
		{
			v[arr[i]].first += score;
		}
		score++;
	}

	v[0].first = 999999999;
	for (int i = 1; i <= 200; i++)
	{
		if (teamNum[i] < 6)continue;

		if (v[0].first > v[i].first)
		{
			v[0].first = v[i].first;
			v[0].second = i;
		}
		else if (v[0].first == v[i].first)
		{
			if (v[v[0].second].second > v[i].second)
			{
				v[0].first = v[i].first;
				v[0].second = i;
			}
		}
	}

	return v[0].second;
}

int main()
{
	cin >> t;

	while (t--)
	{
		cout << StartSolve() << "\n";
	}
}