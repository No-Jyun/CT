#include <iostream>

using namespace std;

long long f[1000001];
long long g[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	f[1] = 1;
	g[1] = 1;

	for (int i = 2; i <= 1000000; i++)
	{
		for (int j = 2; i * j <= 1000000; j++)
		{
			f[i * j] += i + j;

			if (i == j)
			{
				f[i * j] -= i;
			}
			else if (i > j)
			{
				f[i * j] -= i + j;
			}
		}

		f[i] += 1 + i;

		g[i] = g[i - 1] + f[i];
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << g[n] << '\n';
	}
}