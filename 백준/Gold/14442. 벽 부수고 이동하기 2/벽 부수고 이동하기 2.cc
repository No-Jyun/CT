#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define DAME 9999999

struct DATA
{
	int i, j, k, dist;
};

int n, m, k;
int miro[1001][1001];
bool chk[1001][1001][11];

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
		}
	}

	queue<DATA> q;
	q.push({ 1,1,k ,1 });
	int minV = -1;

	while (!q.empty())
	{
		DATA data = q.front();
		int nowI = data.i;
		int nowJ = data.j;
		int nowK = data.k;
		int dist = data.dist;
		q.pop();

		if (nowI == n && nowJ == m)
		{
			minV = dist;
			break;			
		}

		for (int d = 0; d < 4; d++)
		{
			int gotoI = nowI + mI[d];
			int gotoJ = nowJ + mJ[d];

			if (!Movable(gotoI, gotoJ))
				continue;

			if (miro[gotoI][gotoJ] == '0')
			{
				if (!chk[gotoI][gotoJ][nowK])
				{
					chk[gotoI][gotoJ][nowK] = true;
					q.push({ gotoI,gotoJ,nowK, dist + 1 });
				}
			}
			else
			{
				if (nowK == 0)
					continue;

				if (!chk[gotoI][gotoJ][nowK - 1])
				{
					chk[gotoI][gotoJ][nowK - 1] = true;
					q.push({ gotoI,gotoJ,nowK - 1, dist + 1 });
				}
			}
		}
	}
	
	cout << minV;
}