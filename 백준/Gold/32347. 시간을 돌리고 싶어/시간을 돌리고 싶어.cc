#include <iostream>
#include <vector>

using namespace std;
// 1 2 3 5 6 7

int FindClosest(int target, int left, int right, const vector<int>& array)
{
	int mid = (left + right) / 2;

	if (left > right) return array[left];

	if (array[mid] == target) return array[mid];

	else if (array[mid] > target) return FindClosest(target, left, mid - 1, array);
	else if (array[mid] < target) return FindClosest(target, mid + 1, right, array);
}

bool CanGoBack(int t, int n, int k, const vector<int>& array)
{
	int count = 0;
	int curPos = n;
	while (++count <= k)
	{
		curPos -= t;
		if (curPos <= 1) return true;

		curPos = FindClosest(curPos, 0, array.size() - 1, array);
	}

	return false;
}

int FindFastest(int n, int k, int min, int max, const vector<int>& array)
{
	int mid = (min + max) / 2;

	if (min > max) return min;

	if (CanGoBack(mid, n, k, array))
		return FindFastest(n, k, min, mid - 1, array);
	else
		return FindFastest(n, k, mid + 1, max, array);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	
	vector<int> isPowerOn;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a == 1) isPowerOn.emplace_back(i + 1);
	}
		
	cout << FindFastest(n, k, 1, n, isPowerOn);
}