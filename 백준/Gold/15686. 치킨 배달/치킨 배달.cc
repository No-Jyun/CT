#include <iostream>
#include <cmath>

using namespace std;

int n, m;
int houseIndex = 0;
int chickenIndex = 0;
int answer = 999999999;

pair<int, int> house[100];
pair<int, int> chicken[13];
int selChicken[13];

void CalLength()
{
	int minSum = 0;
	for (int i = 0; i < houseIndex; i++)
	{
		int curI = house[i].first;
		int curJ = house[i].second;
		int minL = 999999999;

		for (int j = 0; j < m; j++)
		{
			int toI = chicken[selChicken[j]].first;
			int toJ = chicken[selChicken[j]].second;

			int length = abs(curI - toI) + abs(curJ - toJ);
			minL = minL > length ? length : minL;
		}
		minSum += minL;
	}

	answer = answer > minSum ? minSum : answer;
}

void SelectChicken(int curIndex, int index)
{
	if (curIndex >= m)
	{
		CalLength();
		return;
	}

	for (int i = index; i < chickenIndex; i++)
	{
		selChicken[curIndex] = i;
		SelectChicken(curIndex + 1, i + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int c;
			cin >> c;

			if (c == 2)
				chicken[chickenIndex++] = { i,j };
			else if (c == 1)
				house[houseIndex++] = { i,j };
		}
	}

	for (int i = 0; i < chickenIndex; i++)
	{
		selChicken[0] = i;
		SelectChicken(1, i + 1);
	}

	cout << answer;
}