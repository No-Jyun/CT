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

int m, n, chickenNum;
int minV = 999999999;
vector<pair<int, int>> chicken, city;
int chickIndex[14];

int ChkCitytoChick(int cityIndex) {
	int cityI = city[cityIndex].first;
	int cityJ = city[cityIndex].second;

	int tmp = 999999999;
	for (int i = 1; i <= m; i++) {
		int chickI = chicken[chickIndex[i]].first;
		int chickJ = chicken[chickIndex[i]].second;

		int length = abs(cityI - chickI) + abs(cityJ - chickJ);
		tmp = min(tmp, length);
	}
	return tmp;
}

void ChkLen() {
	int sum = 0;
	for (int i = 0; i < city.size(); i++) {
		sum += ChkCitytoChick(i);
	}
	minV = min(minV, sum);
}

void CHICKI(int index, int next) {
	if (index > m) {
		ChkLen();

		return;
	}

	for (int i = next + 1; i < chickenNum; i++) {
		chickIndex[index] = i;
		CHICKI(index + 1, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				city.push_back({ i,j });
			}
			else if (a == 2) {
				chicken.push_back({ i,j });
				chickenNum++;
			}
		}
	}

	CHICKI(1, -1);

	cout << minV;
}