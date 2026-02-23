#include <iostream>
#include <vector>

using namespace std;

int n, x;
int maxN;
int maxD;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> x;
	vector<int> v(n + 1);

	int nowN = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];

		if (i <= x)
		{
			nowN += v[i];
			maxN += v[i];
			maxD = 1;
		}
		else
		{
			nowN -= v[i - x];
			nowN += v[i];

			if (nowN == maxN)
				maxD++;
			else if (nowN > maxN)
			{
				maxN = nowN;
				maxD = 1;
			}
		}
	}

	if (maxN == 0)
		cout << "SAD";
	else
		cout << maxN << "\n" << maxD;
}
