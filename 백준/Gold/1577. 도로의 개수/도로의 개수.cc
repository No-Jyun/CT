#include <iostream>

using namespace std;

int n, m, k;
pair<long long, int> dp[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	cin >> k;

	for (int i = 1; i <= k; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int isI = a - c;

		if (isI)
		{
			if (a > c) 
			{
				if (dp[a][b].second == 2)continue;
				if (dp[a][b].second == -1) dp[a][b].second = 2;
				else dp[a][b].second = 1;
			}
			else 
			{
				if (dp[c][d].second == 2)continue;
				if (dp[c][d].second == -1) dp[c][d].second = 2;
				else dp[c][d].second = 1;
			}
		}
		else
		{
			if (b > d)
			{
				if (dp[a][b].second == 2)continue;
				if (dp[a][b].second == 1)dp[a][b].second = 2;
				else dp[a][b].second = -1;
			}
			else 
			{
				if (dp[c][d].second == 2)continue;
				if (dp[c][d].second == 1) dp[c][d].second = 2;
				else dp[c][d].second = -1;
			}
		}
	}

	dp[0][0].first = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0].first = dp[i - 1][0].first;

		if (dp[i][0].second == 1)dp[i][0].first = 0;
	}

	for (int i = 1; i <= m; i++)
	{
		dp[0][i].first = dp[0][i - 1].first;

		if (dp[0][i].second == -1)dp[0][i].first = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			long long addI = dp[i - 1][j].first;
			long long addJ = dp[i][j - 1].first;

			if (dp[i][j].second)
			{
				if (dp[i][j].second == 1) addI = 0;
				if (dp[i][j].second == -1) addJ = 0;
				if (dp[i][j].second == 2)
				{
					addI = 0;
					addJ = 0;
				}
			}
			dp[i][j].first = addI + addJ;
		}
	}

	//cout << "\n";
	//for (int i = 0; i <= n; i++)
	//{
	//	for (int j = 0; j <= m; j++) cout << dp[i][j].first << ' ';
	//	cout << "\n";
	//}

	cout << dp[n][m].first;
}