#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define DAME 9999999

int n, m, k;
int miro[1001][1001];
int chk[1001][1001][11];

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Movable(int a, int b)
{
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			miro[i][j] = str[j - 1];

			for (int t = 0; t <= k; t++)
				chk[i][j][t] = DAME;
		}
	}

	for (int t = 0; t <= k; t++)
		chk[1][1][t] = 1;

	queue<vector<int>> q;
	q.push({ 1,1,k });

	while (!q.empty())
	{
		int nowI = q.front()[0];
		int nowJ = q.front()[1];
		int nowK = q.front()[2];
		q.pop();

		if (nowI == n && nowJ == m)
			continue;

		//cout << "i : " << nowI << ", j : " << nowJ << ", k : " << nowK
		//	<< ", chk : " << chk[nowI][nowJ][nowK] << "\n";

		for (int d = 0; d < 4; d++)
		{
			int gotoI = nowI + mI[d];
			int gotoJ = nowJ + mJ[d];

			//cout << "i : " << nowI << ", j : " << nowJ << ", gotoi : " << gotoI
			//	<< ", gotoj : " << gotoJ << "\n";


			if (!Movable(gotoI, gotoJ))
				continue;

			if (miro[gotoI][gotoJ] == '0')
			{
				if (chk[gotoI][gotoJ][nowK] > chk[nowI][nowJ][nowK] + 1)
				{
					chk[gotoI][gotoJ][nowK] = chk[nowI][nowJ][nowK] + 1;
					q.push({ gotoI,gotoJ,nowK });
				}
			}
			else
			{
				if (nowK == 0)
					continue;

				if (chk[gotoI][gotoJ][nowK - 1] > chk[nowI][nowJ][nowK] + 1)
				{
					chk[gotoI][gotoJ][nowK - 1] = chk[nowI][nowJ][nowK] + 1;
					q.push({ gotoI,gotoJ,nowK - 1 });
				}
			}
		}
	}
	
	int minV = DAME;
	for (int i = 0; i <= k; i++)
	{
		minV = min(minV, chk[n][m][i]);
	}

	if (minV == DAME)
		cout << -1;
	else
		cout << minV;
}