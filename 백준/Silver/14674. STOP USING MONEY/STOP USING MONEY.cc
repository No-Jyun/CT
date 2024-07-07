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
using namespace std;

int n, k;
vector<pair<int, pair<int, int>>> v;

bool SortGasung(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	long long gasungA = (long long)a.first * (long long)b.second.first;
	long long gasungB = (long long)b.first * (long long)a.second.first;
	if (gasungA == gasungB) {
		if (a.second.first == b.second.first)return a.second.second < b.second.second;
		else return a.second.first < b.second.first;
	}
	else return gasungA > gasungB;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int num, price, satis;
		cin >> num >> price >> satis;
		v.push_back({ satis,{price,num} });
	}

	sort(v.begin(), v.end(), SortGasung);

	for (int i = 0; i < k; i++) {
		cout << v[i].second.second << '\n';
	}
}