#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int onepan[51][51];
int n, m, t;

void Spin(int nIndex, int count, int dir)
{
	int originpan[51];
	memcpy(originpan, onepan[nIndex], sizeof(int) * 51);
	
	for (int i = 1; i <= m; i++)
	{
		// 반시계라면 - 1번 1칸 움직이면 4번, 1번 3칸 움직이면 2번
		// 2번 1칸 움직이면 1번, 2번 3칸 움직이면 3번
		// 시계는 모듈러
		int switchIndex = 0;

		if (dir)
		{
			switchIndex = i - count;

			if (switchIndex <= 0) switchIndex += m;
		}
		else switchIndex = (i + count - 1) % m + 1;

		onepan[nIndex][switchIndex] = originpan[i];
	}
}

void PostProcess()
{
	int sum = 0;
	int nCount = 0;
	bool isSame = false;

	bool chk[51][51] = {};

	queue<pair<int, int>> restN;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum += onepan[i][j];
			if (onepan[i][j] != 0) 
			{
				nCount++;
				restN.push({ i,j });
			}

			if (onepan[i][j] == 0 || chk[i][j]) continue;

			queue<pair<int, int>> q;
			queue<pair<int, int>> ansQ;
			chk[i][j] = true;
			q.push({ i,j });

			while (!q.empty())
			{
				int nowI = q.front().first;
				int nowJ = q.front().second;
				ansQ.push(q.front());
				q.pop();

				// 시계방향 살펴보기
				int nextI = nowI;
				int nextJ = nowJ % m + 1;
				if (!chk[nextI][nextJ] && onepan[i][j] == onepan[nextI][nextJ])
				{
					chk[nextI][nextJ] = true;
					q.push({ nextI,nextJ });
				}

				// 반시계방향
				nextJ = nowJ - 1;
				if (nextJ == 0) nextJ = m;
				if (!chk[nextI][nextJ] && onepan[i][j] == onepan[nextI][nextJ])
				{
					chk[nextI][nextJ] = true;
					q.push({ nextI,nextJ });
				}

				nextJ = nowJ;

				// 위층
				if (nowI != 1)
				{
					nextI = nowI - 1;
					if (!chk[nextI][nextJ] && onepan[i][j] == onepan[nextI][nextJ])
					{
						chk[nextI][nextJ] = true;
						q.push({ nextI,nextJ });
					}
				}

				// 아래층
				if (nowI != n)
				{
					nextI = nowI + 1;
					if (!chk[nextI][nextJ] && onepan[i][j] == onepan[nextI][nextJ])
					{
						chk[nextI][nextJ] = true;
						q.push({ nextI,nextJ });
					}
				}				
			}

			if (ansQ.size() > 1)
			{
				isSame = true;
				while (!ansQ.empty())
				{
					onepan[ansQ.front().first][ansQ.front().second] = 0;
					ansQ.pop();
				}
			}
		}
	}

	if (!isSame)
	{
		while (!restN.empty())
		{
			int curN = onepan[restN.front().first][restN.front().second];

			if (curN * nCount > sum) onepan[restN.front().first][restN.front().second] = curN - 1;
			else if (curN * nCount < sum) onepan[restN.front().first][restN.front().second] = curN + 1;

			restN.pop();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> onepan[i][j];
		}
	}

	while (t--)
	{
		int x, d, k;
		cin >> x >> d >> k;

		for (int i = 1; i * x <= n; i++)
		{
			Spin(i * x, k, d);
		}

		PostProcess();
	}

	int answer = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			answer += onepan[i][j];

	cout << answer;
}