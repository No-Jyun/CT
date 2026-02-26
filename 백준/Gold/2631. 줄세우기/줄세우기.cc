#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	int maxN = 1;
	vector<int>dp(n + 1, 1);
	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (v[j] < v[i])
				dp[i] = max(dp[i], 1 + dp[j]);
		}
		maxN = max(maxN, dp[i]);
	}
	cout << n - maxN;
}

//3752614
//
//1 2 3 4 5 6 7
//1 2 2 1 3 1 2
//
//1 2 3 4 5 6 7
//6 5 4 3 2 1 0
//5 3 0 3 
//
//3526147
//
//1 2 3 4 5 6 7
//0 1 2 0 3 2 0
//
