#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector <vector<pair<int, int>>> v(n + 1);
	vector<int> chk(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int stP, fnP;
	cin >> stP >> fnP;

	priority_queue<pair<int, int>> q;
	for (int i = 0; i < v[stP].size(); i++)
	{
		int gotoI = v[stP][i].first;
		int c = v[stP][i].second;

		chk[gotoI] = c;
		q.push({ c,gotoI });
	}

	while (!q.empty())
	{
		int nowI = q.top().second;
		int c = q.top().first;
		q.pop();

		if (c < chk[nowI])
			continue;

		for (int i = 0; i < v[nowI].size(); i++)
		{
			int gotoI = v[nowI][i].first;
			int cost = v[nowI][i].second;

			cost = min(cost, chk[nowI]);

			if (gotoI != stP && chk[gotoI] < cost && chk[fnP] < cost)
			{
				chk[gotoI] = cost;

				if (gotoI != fnP)
				{
					q.push({ cost, gotoI });
				}
			}
		}
	}

	cout << chk[fnP];
}