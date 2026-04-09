// https://www.acmicpc.net/problem/8983
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using P = pair<int, int>;

// 7
// 1 2 3 4 5 6 8 9
// 0 1 2 3 4 5 6 7
int HighBound(int target, int left, int right, const vector<int>& array)
{
	int mid = (left + right) / 2;

	if (left > right) return right;

	if (array[mid] == target) return mid;
	
	else if (array[mid] < target) return HighBound(target, mid + 1, right, array);

	else if (array[mid] > target)return HighBound(target, left, mid - 1, array);
}

int LowBound(int target, int left, int right, const vector<int>& array)
{
	int mid = (left + right) / 2;

	if (left > right) return left;

	if (array[mid] == target) return mid;

	else if (array[mid] < target) return LowBound(target, mid + 1, right, array);

	else if (array[mid] > target)return LowBound(target, left, mid - 1, array);

}

bool CanShoot(int sadaeX, P animalPos, int range)
{
	int length = abs(sadaeX - animalPos.first) + animalPos.second;
	return length <= range;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, l;
	cin >> m >> n >> l;
	vector<int> sadae(m);
	vector<P> animals;

	for (int i = 0; i < m; i++) cin >> sadae[i];
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (b <= l)
			animals.emplace_back(P(a, b));
	}
	sort(sadae.begin(), sadae.end());

	int answer = 0;

	for (int i = 0; i < animals.size(); i++)
	{
		// i 번째 동물의 x좌표보다 작거나 같고 가장 가까운 인덱스 찾기
		int lowIndex = HighBound(animals[i].first, 0, m - 1, sadae);

		if (lowIndex >= 0 && CanShoot(sadae[lowIndex], animals[i], l))
		{
			answer++;
			continue;
		}

		// i 번째 동물의 x좌표보다 크거나 같고 가장 가까운 인덱스 찾기
		int highIndex = LowBound(animals[i].first, 0, m - 1, sadae);
		if (highIndex < m && CanShoot(sadae[highIndex], animals[i], l))
		{
			answer++;
		}
	}

	cout << answer;
}