#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	pair<int, int> stP;

	vector<vector<int>> jido;
	vector<vector<int>> chk;

	jido.assign(n, vector<int>(m, 0));
	chk.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> jido[i][j];

			if (jido[i][j] == 2) stP = { i,j };
		}
	}

	chk[stP.first][stP.second] = 1;

	queue<pair<int, int>> q;
	q.push(stP);

	while (!q.empty())
	{
		int nowI = q.front().first;
		int nowJ = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int gotoI = nowI + mI[d];
			int gotoJ = nowJ + mJ[d];

			if (gotoI < 0 || gotoI >= n || gotoJ < 0 || gotoJ >= m) continue;

			if (jido[gotoI][gotoJ] != 0 && chk[gotoI][gotoJ] == 0)
			{
				chk[gotoI][gotoJ] = chk[nowI][nowJ] + 1;
				q.push({ gotoI, gotoJ });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == stP.first && j == stP.second) cout << "0 ";
			else
			{
				if (chk[i][j] == 0 && jido[i][j] == 0) cout << "0 ";
				else if (chk[i][j] == 0 && jido[i][j] == 1) cout << "-1 ";
				else cout << chk[i][j] - 1 << ' ';
			}
		}
		cout << "\n";
	}
}