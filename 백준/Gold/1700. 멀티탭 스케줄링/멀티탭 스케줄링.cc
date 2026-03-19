#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> order(k, 0);
	vector<int> plug(n, -1);

	int answer = 0;

	for (int i = 0; i < k; i++)
		cin >> order[i];

	for (int i = 0; i < k; i++)
	{
		bool notUnplug = false;
		int adP = 0;

		vector<int> chk(n, -1);
		for (int j = 0; j < n; j++)
		{
			if (plug[j] == -1 || plug[j] == order[i])
			{
				notUnplug = true;
				adP = j;
				break;
			}

			for (int x = i + 1; x < k; x++)
			{
				if (plug[j] == order[x])
				{
					chk[j] = x;
					break;
				}
			}
		}

		if (notUnplug)
		{
			plug[adP] = order[i];
		}
		else
		{
			notUnplug = false;
			for (int j = 0; j < n; j++)
			{
				if (chk[j] == -1)
				{
					notUnplug = true;
					answer++;
					plug[j] = order[i];
					break;
				}
			}

			if (notUnplug)
				continue;

			int maxIndex = -1;
			int nIndex = -1;
			for (int j = 0; j < n; j++)
			{
				if (maxIndex < chk[j])
				{
					maxIndex = chk[j];
					nIndex = j;
				}
			}

			answer++;
			plug[nIndex] = order[i];
		}
	}
	
	cout << answer;
}