#include <iostream>

using namespace std;

int n;
int dp[1001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
	}

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][1], dp[i - 1][0]);
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}