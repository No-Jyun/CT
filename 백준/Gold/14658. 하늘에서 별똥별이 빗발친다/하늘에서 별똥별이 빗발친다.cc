#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>	// abs for float, double
#include <cstdlib> // abs for int, long int
#define ULL unsigned long long
#define INTMAX 2147483647
using namespace std;

int n, m, l, k;
vector<pair<int, int>> star;
int maxA, minA, maxB, minB;
int result;

bool C(pair<int, int> p) {
	int nowA = p.first, nowB = p.second;

	if (nowA > maxA) {
		if (nowA - minA <= l)maxA = nowA;
		else return false;
	}
	else if (nowA < minA) {
		if (maxA - nowA <= l)minA = nowA;
		else return false;
	}

	if (nowB > maxB) {
		if (nowB - minB <= l) maxB = nowB;
		else return false;
	}
	else if (nowB < minB) {
		if (maxB - nowB <= l)minB = nowB;
		else return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> l >> k;
	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		star.push_back({ a,b });
	}
	result = k;

	for (int i = 0; i < k; i++) {
		int tmp = 0;
		maxA = star[i].first, minA = star[i].first;
		maxB = star[i].second, minB = star[i].second;

		vector<pair<int, pair<int, int>>> sortedStar;

		for (int j = 0; j < k; j++) {
			int u = abs(star[i].first - star[j].first) + abs(star[i].second - star[j].second);
			sortedStar.push_back({ u,{star[j].first,star[j].second} });
		}
		sort(sortedStar.begin(), sortedStar.end());

		for (int j = 0; j < sortedStar.size(); j++) {
			if (!C(sortedStar[j].second))tmp++;
		}
		result = min(result, tmp);
	}

	cout << result;
}