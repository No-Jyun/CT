#include <iostream>

using namespace std;

int n;
int rgb[1001][3];
int dp[1001][3];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}

	dp[1][0] = rgb[1][0];
	dp[1][1] = rgb[1][1];
	dp[1][2] = rgb[1][2];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int restC1 = 1;
			int restC2 = 2;
			if (j == 1) restC1 = 0;
			if (j == 2) restC2 = 0;

			int minV = min(dp[i - 1][restC1], dp[i - 1][restC2]);
			dp[i][j] = minV + rgb[i][j];
		}
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}