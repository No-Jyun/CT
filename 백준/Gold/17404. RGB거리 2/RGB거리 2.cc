#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int rgb[1001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}

	int answer = 999999999;

	for (int i = 1; i <= n; i++)
	{
		pair<int, int> chk[1001][3];
		pair<int, int> tmp = { 999999999 ,999999999 };
		fill(chk[0], chk[1001], tmp);

		chk[i][0] = { rgb[i][0], 0 };
		chk[i][1] = { rgb[i][1], 1 };
		chk[i][2] = { rgb[i][2], 2 };

		int exIndex = i;
		for (int j = 1; j < n; j++)
		{
			int curIndex = (i + j - 1) % n + 1;

			if (j == n - 1)
			{
				for (int k = 0; k < 3; k++)
				{
					int k1 = 0;
					if (k == 0)k1 = 2;
					int k2 = 1;
					if (k == 1)k2 = 2;

					// minK는 항상 k와 다른 값을 선택하므로 신경 X
					int minK = chk[exIndex][k1].first <= chk[exIndex][k2].first ? k1 : k2;

					// 더 작은 놈을 선택했는데 해당 값이 같은 k 번째 rgb에서 온 값이라면
					if (k == chk[exIndex][minK].second)
					{
						// 다른 값 선택
						minK = minK == k1 ? k2 : k1;

						// 둘 중 큰 값을 선택해도 해당 값이 같은 k 번째 rgb에서 온 값이라면 예외 처리
						if (k == chk[exIndex][minK].second)
							continue;
						else
							chk[curIndex][k] = { chk[exIndex][minK].first + rgb[curIndex][k], -1 };
					}
					else
					{
						chk[curIndex][k] = { chk[exIndex][minK].first + rgb[curIndex][k], -1 };
					}
				}
			}
			else
			{
				for (int k = 0; k < 3; k++)
				{
					int k1 = 0;
					if (k == 0)k1 = 2;
					int k2 = 1;
					if (k == 1)k2 = 2;

					int minK = chk[exIndex][k1].first <= chk[exIndex][k2].first ? k1 : k2;

					chk[curIndex][k] = { chk[exIndex][minK].first + rgb[curIndex][k], chk[exIndex][minK].second };
				}
			}
			
			exIndex = curIndex;
		}

		answer = min(answer, min(chk[exIndex][0].first, min(chk[exIndex][1].first, chk[exIndex][2].first)));
	}

	cout << answer;
}

//29   +   11   +   13   +   47   +   19   +   39   +   32   +   63